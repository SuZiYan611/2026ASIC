`timescale 1ns / 1ps

module tb_generic_countdown_counter;
    logic        clk = 0;
    logic        rstn;
    logic        en;
    logic [15:0] load_val;
    logic        load;
    logic        done;

    generic_countdown_counter #(.MAX(65536), .N(16)) dut (.*);

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    initial begin
        $display("=== generic_countdown_counter testbench ===");
        rstn = 0; en = 0; load = 0; load_val = 0;
        wait_cycles(2); rstn = 1; wait_cycles(2);

        `CHECK(done == 1, "done high at 0");

        // Load value at zero
        $display("--- load ---");
        load_val = 100;
        load = 1;
        @(posedge clk);  // load fires
        load = 0;
        @(posedge clk);
        `CHECK(done == 0, "done low after load (accepts value)");

        // Count down to 0
        $display("--- count down ---");
        en = 1;
        repeat (50) @(posedge clk);
        `CHECK(done == 0, "not done yet at 50");
        repeat (49) @(posedge clk);
        `CHECK(done == 0, "not done yet at 99");
        @(posedge clk);
        `CHECK(done == 1, "done at 0");

        // Stays at 0 when en is high (done prevents further counting)
        en = 0;
        repeat (5) @(posedge clk);
        `CHECK(done == 1, "done stays high");

        // Reload at zero
        $display("--- reload ---");
        load_val = 50;
        load = 1; @(posedge clk); load = 0;
        `CHECK(done == 0, "done low after reload");

        en = 1;
        repeat (50) @(posedge clk);
        `CHECK(done == 1, "done after counting down 50");

        // Reset
        $display("--- reset ---");
        rstn = 0; wait_cycles(2); rstn = 1; wait_cycles(2);
        `CHECK(done == 1, "done high after reset");

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
