`timescale 1ns / 1ps

module tb_lfsr;
    logic        clk = 0;
    logic        rstn;
    logic        en;
    wire  [12:0] out;

    logic [12:0] prev;

    lfsr #(.MIN(1000), .MAX(6234)) dut (.*);

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    initial begin
        $display("=== lfsr testbench (MIN=1000, MAX=6234) ===");
        rstn = 0; en = 0;
        wait_cycles(2); rstn = 1; wait_cycles(2);

        `CHECK(out >= 1000, "out >= MIN after reset");

        // Range check over 500 cycles
        $display("--- range check ---");
        en = 1;
        for (int i = 0; i < 500; i++) begin
            @(posedge clk);
            if (out < 1000 || out >= 6234)
                $fatal(0, "FAIL out=%0d out of range [1000,6234)", out);
        end
        $display("PASS all 500 values in [1000, 6234)");

        // Non-determinism check
        $display("--- non-determinism ---");
        prev = out;
        wait_cycles(10);
        `CHECK(out != prev, "values change over time");

        // en gating
        $display("--- en gating ---");
        prev = out;
        en = 0;
        repeat (10) @(posedge clk);
        `CHECK(out == prev, "stays constant while en=0");
        en = 1; @(posedge clk);
        `CHECK(out != prev, "changes when en=1");

        // Reset
        $display("--- reset ---");
        rstn = 0; wait_cycles(2); rstn = 1; wait_cycles(2);
        `CHECK(out >= 1000, ">= MIN after reset");

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
