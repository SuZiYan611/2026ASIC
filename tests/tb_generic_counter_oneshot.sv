`timescale 1ns / 1ps

module tb_generic_counter_oneshot;
    logic       clk = 0;
    logic       rstn;
    logic       en;
    logic [3:0] x;
    logic       ending;

    generic_counter #(.MAX(5), .ONESHOT(1), .N(4)) dut (.*);

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    initial begin
        $display("=== generic_counter oneshot testbench (MAX=5, ONESHOT=1) ===");
        rstn = 0; en = 0;
        wait_cycles(2); rstn = 1; wait_cycles(2);

        // Count to MAX-1 (4)
        en = 1;
        repeat (4) @(posedge clk);
        `CHECK(x == 4, "reached MAX-1");
        `CHECK(ending == 1, "ending high");

        // Should stay at MAX-1 (oneshot holds)
        repeat (10) @(posedge clk);
        `CHECK(x == 4, "stays at MAX-1");
        `CHECK(ending == 1, "ending stays high");

        en = 0;
        wait_cycles(5);
        `CHECK(x == 4, "stays when en=0");

        // Reset
        rstn = 0; wait_cycles(2); rstn = 1; wait_cycles(2);
        `CHECK(x == 0, "resets to 0");
        `CHECK(ending == 0, "ending low after reset");

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
