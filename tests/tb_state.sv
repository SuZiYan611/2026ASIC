`timescale 1ns / 1ps
`include "defs.svh"

module tb_state;
  logic       clk;
  logic       ready;
  logic       halt;
  logic [1:0] bi;
  state_t     sys_state;

  state dut (.*);

  always #5 clk = ~clk;

  `define CHECK(expr, msg) \
    if (!(expr)) $fatal(0, "FAIL %s", msg); \
    else $display("PASS %s", msg)

  task wait_cycles(input int n);
    repeat (n) @(posedge clk);
  endtask

  task go_idle;
    // Cycle through any state back to IDLE (need 5 ready pulses)
    ready = 1; wait_cycles(5);
    ready = 0; wait_cycles(1);
  endtask

  task go_triggered;
    // First ensure we're in IDLE
    repeat (6) begin
        if (sys_state == IDLE) break;
        ready = 1; @(posedge clk);
    end
    ready = 0; @(posedge clk);
    // Now go IDLE -> INIT -> TRIGGERED
    ready = 1; @(posedge clk);  // IDLE -> INIT
    ready = 0; @(posedge clk);  // INIT -> TRIGGERED (auto, ready low)
  endtask

  initial begin
    $display("=== state testbench (edge-triggered FSM) ===");
    clk = 0; ready = 0; halt = 0; bi = 0;
    wait_cycles(2);

    // 1. Normal cycle
    $display("--- normal cycle ---");
    ready = 1;  @(posedge clk);  // IDLE -> INIT
    `CHECK(sys_state == INIT, "IDLE -> INIT");
    ready = 0;  @(posedge clk);
    `CHECK(sys_state == TRIGGERED, "INIT -> TRIGGERED");

    ready = 1;  @(posedge clk);  // TRIGGERED -> MEASURING
    `CHECK(sys_state == MEASURING, "TRIGGERED -> MEASURING");
    ready = 0;  @(posedge clk);
    ready = 1;  @(posedge clk);  // MEASURING -> MEASURED
    `CHECK(sys_state == MEASURED, "MEASURING -> MEASURED");
    ready = 0;  @(posedge clk);
    ready = 1;  @(posedge clk);  // MEASURED -> IDLE
    `CHECK(sys_state == IDLE, "MEASURED -> IDLE");
    ready = 0;  @(posedge clk);

    // 2. Ready ignored in INIT (auto-advances)
    $display("--- ready ignored in INIT ---");
    go_idle;
    ready = 1;  @(posedge clk);  // IDLE -> INIT
    `CHECK(sys_state == INIT, "in INIT");
    // ready stays high — INIT auto-advances regardless
    @(posedge clk);
    `CHECK(sys_state != INIT, "left INIT despite ready high");
    ready = 0;  wait_cycles(1);

    // 3. Halt during TRIGGERED -> SPAM
    $display("--- halt / SPAM ---");
    go_triggered;
    `CHECK(sys_state == TRIGGERED, "in TRIGGERED");

    halt = 1;  @(posedge clk);
    `CHECK(sys_state == SPAM, "TRIGGERED -> SPAM via halt");
    halt = 0;  @(posedge clk);
    `CHECK(sys_state == SPAM, "stays in SPAM after halt deassert");

    ready = 1;  @(posedge clk);
    `CHECK(sys_state == IDLE, "SPAM -> IDLE via ready");
    ready = 0;

    // 4. Halt ignored outside TRIGGERED
    $display("--- halt ignored in IDLE ---");
    halt = 1;  @(posedge clk);
    `CHECK(sys_state == IDLE, "halt ignored in IDLE");
    halt = 0;

    // 5. Rapid pulses
    $display("--- rapid pulses ---");
    go_triggered;
    ready = 1;  @(posedge clk);  // TRIGGERED -> MEASURING
    ready = 1;  @(posedge clk);  // MEASURING -> MEASURED
    ready = 1;  @(posedge clk);  // MEASURED -> IDLE
    `CHECK(sys_state == IDLE, "rapid: full cycle back to IDLE");

    $display("=== ALL TESTS PASSED ===");
    $finish;
  end
endmodule
