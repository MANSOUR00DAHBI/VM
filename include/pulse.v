module pulse(
    input clk,
    output reg beat 
);

always (posedge clk) begin
    beat <= ~beat;
end 

endmodule 
