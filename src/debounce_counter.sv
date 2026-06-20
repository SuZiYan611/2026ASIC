`timescale 1ns / 1ps

module debounce_counter #(
    parameter unsigned MAX = 10
) (
    input clk,
    input rstn,
    input en,
    input raw,
    output reg debounced
);
  localparam N = $clog2(MAX);
  reg [N-1:0] counter = 0;

  always @(posedge clk, negedge rstn) begin
    if (!rstn) begin
      counter    <= 0;
      debounced  <= 0;
    end else if (en) begin
      if (raw != debounced) begin
        if (counter == N'(MAX - 1)) begin
          debounced <= raw;
          counter   <= 0;
        end else begin
          counter <= counter + 1;
        end
      end else begin
        counter <= 0;
      end
    end
  end
endmodule
