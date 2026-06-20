`timescale 1ns / 1ps

module tb_debounce_counter;
    logic clk = 0;
    logic rstn;
    logic raw;
    logic debounced;

    debounce_counter #(.MAX(5)) dut (
        .clk(clk), .rstn(rstn), .en(1'b1), .raw(raw), .debounced(debounced)
    );

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    // Inject random bounces for a duration, then force stable
    task bounce(input int cycles, input int pin);
        int t;
        for (int i = 0; i < cycles; i++) begin
            t = $urandom_range(1, 10);
            wait_cycles(t);
            if (i % 2 == 0) raw = pin;
            else raw = $urandom & 1;
        end
        raw = pin;  // settle
    endtask

    initial begin
        $display("=== debounce_counter fuzz test (MAX=50) ===");
        rstn = 0; raw = 0;
        wait_cycles(10); rstn = 1;
        wait_cycles(10);

        // 1. idle low
        $display("--- 1. idle low ---");
        `CHECK(debounced == 0, "starts low");

        // 2. clean press, hold, release
        $display("--- 2. clean press/release ---");
        raw = 1;
        wait_cycles(60);  // > MAX
        `CHECK(debounced == 1, "goes high after stable press");
        raw = 0;
        wait_cycles(60);
        `CHECK(debounced == 0, "goes low after stable release");

        // 3. fuzz: short glitch should be ignored
        $display("--- 3. glitch rejection ---");
        raw = 1;
        wait_cycles(10);  // << MAX
        raw = 0;
        wait_cycles(60);
        `CHECK(debounced == 0, "glitch rejected");

    // 4. fuzz: random bounces then settle high
    $display("--- 4. bouncy press ---");
    bounce($urandom_range(80, 150), 1);
    wait_cycles(60);  // > MAX for debouncer to register
    `CHECK(debounced == 1, "settles high after bounce");

    // 5. fuzz: random bounces then settle low  
    $display("--- 5. bouncy release ---");
    bounce($urandom_range(80, 150), 0);
    wait_cycles(60);
    `CHECK(debounced == 0, "settles low after bounce");

        // 6. multiple rapid presses
        $display("--- 6. rapid presses ---");
        for (int i = 0; i < 5; i++) begin
            raw = 1;
            wait_cycles($urandom_range(55, 100));
            `CHECK(debounced == 1, $sformatf("rapid press %0d high", i));
            raw = 0;
            wait_cycles($urandom_range(55, 100));
            `CHECK(debounced == 0, $sformatf("rapid press %0d low", i));
        end

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
