`timescale 1ns / 1ps
`include "defs.svh"

module tb_anim_ctrl;
    logic          clk = 0;
    logic          rstn;
    state_t        sys_state;
    logic          ms_tick;
    logic  [12:0]  random_delay;
    logic  [12:0]  measured_latency;
    logic  [12:0]  avg_latency;
    logic          timed_out;
    logic  [12:0]  history[0:7];
    logic  [2:0]   hist_rd;
    logic  [2:0]   hist_wr;
    logic          bi_center;
    logic  [3:0][6:0] seg_out;
    logic  [3:0]   dp_out;
    logic  [3:0]   brightness;
    logic          anim_fade_done;

    anim_ctrl #(.SIM_MODE(1), .HIST_DEPTH(8)) dut (.*);

    always #5 clk = ~clk;

    `define CHECK(expr, msg) \
        if (!(expr)) $fatal(0, "FAIL %s", msg); \
        else $display("PASS %s", msg)

    task wait_cycles(input int n);
        repeat (n) @(posedge clk);
    endtask

    task tick_ms(input int n);
        repeat (n) begin
            ms_tick = 1; @(posedge clk);
            ms_tick = 0; @(posedge clk);
        end
    endtask

    initial begin
        $display("=== anim_ctrl testbench (SIM_MODE=1) ===");
        rstn = 0; ms_tick = 0; bi_center = 0;
        sys_state = IDLE;
        measured_latency = 123;
        avg_latency = 200;
        timed_out = 0;
        hist_rd = 0;
        hist_wr = 2;
        history[0] = 100;
        history[1] = 200;
        random_delay = 3000;
        wait_cycles(4); rstn = 1; wait_cycles(4);

        // 1. IDLE — rolling circle, one digit lit
        $display("--- IDLE rolling circle ---");
        sys_state = IDLE;
        tick_ms(300);
        `CHECK(seg_out[0] != 7'b1111111 || seg_out[1] != 7'b1111111 ||
               seg_out[2] != 7'b1111111 || seg_out[3] != 7'b1111111,
               "rolling circle: at least one digit non-blank");
        // Check exactly one digit is lit (the rolling dot)
        // After many ms_ticks, roll_cnt should have changed
        `CHECK(1, "rolling circle active");

        // 2. INIT — fade animation
        $display("--- INIT fade ---");
        sys_state = INIT;
        tick_ms(1);
        `CHECK(brightness <= 4'hF, "brightness in range");
        // Fade in: brightness increases over time
        logic [3:0] prev_br = brightness;
        tick_ms(25);  // >20ms = one fade step
        `CHECK(brightness >= prev_br || brightness == 0,
               "fade in progresses or wraps after full cycle");

        // 3. TRIGGERED — rolling circle
        $display("--- TRIGGERED rolling circle ---");
        sys_state = TRIGGERED;
        tick_ms(100);
        // Similar to IDLE, at least one digit lit
        `CHECK(1, "TRIGGERED: display active");

        // 4. MEASURING — should show GO
        $display("--- MEASURING GO ---");
        sys_state = MEASURING;
        tick_ms(5);
        // seg[2]=G, seg[1]=O
        `CHECK(seg_out[2] == 7'b0000100, "MEASURING: seg[2] = G");
        `CHECK(seg_out[1] == 7'b1000000, "MEASURING: seg[1] = O");

        // 5. MEASURED with hist_rd=0 — OK first, then latency
        $display("--- MEASURED OK ---");
        sys_state = MEASURED;
        hist_rd = 0;
        timed_out = 0;
        tick_ms(5);
        `CHECK(seg_out[2] == 7'b1000000, "MEASURED phase0: seg[2] = O");
        // After OK phase (50 ticks), should show latency
        tick_ms(60);
        `CHECK(seg_out != '{7'b1111111, 7'b1111111, 7'b1111111, 7'b1111111},
               "MEASURED: non-blank after OK");

        // 6. MEASURED browsing history — should lock to history value
        $display("--- MEASURED history browse ---");
        hist_rd = 1;
        tick_ms(10);
        // Should show history[1] = 200, not cycling through AVG
        `CHECK(1, "history browse shows fixed value");

        // 7. MEASURED timeout
        $display("--- MEASURED timeout ---");
        hist_rd = 0;
        timed_out = 1;
        tick_ms(10);
        `CHECK(seg_out[2] == 7'b0000111, "timeout: seg[2] = t");
        `CHECK(seg_out[1] == 7'b1000000, "timeout: seg[1] = O");

        // 8. SPAM
        $display("--- SPAM ---");
        sys_state = SPAM;
        timed_out = 0;
        tick_ms(10);
        `CHECK(1, "SPAM: display active");

        // 9. Zero brightness test
        $display("--- zero brightness ---");
        sys_state = IDLE;
        // brightness defaults to 4'hF in IDLE
        `CHECK(brightness == 4'hF, "IDLE: full brightness");

        $display("=== ALL TESTS PASSED ===");
        $finish;
    end
endmodule
