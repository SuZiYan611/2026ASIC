`timescale 1ns / 1ps
`include "defs.svh"

module state (
    input clk,
    input ready,
    input halt,
    input [1:0] bi,
    output state_t sys_state
);
  state_t state = IDLE;
  assign sys_state = state;

  always_ff @(posedge clk) begin
    case (state)
      IDLE: begin
        if (ready) state <= INIT;
      end
      INIT: begin
        state <= TRIGGERED;
      end
      TRIGGERED: begin
        if (halt) state <= SPAM;
        else if (ready) state <= MEASURING;
      end
      MEASURING: begin
        if (ready) state <= MEASURED;
      end
      MEASURED: begin
        if (ready) state <= IDLE;
      end
      SPAM: begin
        if (ready) state <= IDLE;
      end
      default: begin
      end
    endcase
  end
endmodule
