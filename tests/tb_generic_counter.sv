`timescale 1ns / 1ps

module tb_generic_counter;
    logic       clk = 0;
    logic       rstn;
    logic       en;
    logic [3:0] x;
    logic       ending;

    generic_counter #(.MAX(10), .N(4)) dut (.*);

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    initial begin
        $display("=== generic_counter testbench (MAX=10) ===");
        rstn = 0; en = 0;
        wait_cycles(2); rstn = 1; wait_cycles(2);

        `CHECK(x == 0, "starts at 0");
        `CHECK(ending == 0, "ending low at 0");

        // Count to 9 (MAX-1), check ending fires
        $display("--- count to MAX-1 ---");
        en = 1;
        repeat (9) @(posedge clk);
        `CHECK(x == 9, "reached MAX-1 (9)");
        `CHECK(ending == 1, "ending high at MAX-1");

        // Next cycle: wraps to 0
        @(posedge clk);
        `CHECK(x == 0, "wraps to 0");
        `CHECK(ending == 0, "ending low after wrap");

        // Disable en — counter should freeze
        $display("--- en gating ---");
        en = 0;
        repeat (5) @(posedge clk);
        `CHECK(x == 0, "stays 0 while en=0");
        en = 1; @(posedge clk);
        `CHECK(x == 1, "resumes counting when en=1");

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
