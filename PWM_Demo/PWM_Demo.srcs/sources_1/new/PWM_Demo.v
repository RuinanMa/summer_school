`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/09/05 16:46:22
// Design Name: 
// Module Name: PWM_Demo
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module PWM_Demo(
    output PWM,
    input clk_100MHz
    );
    
    reg [31:0]Freq=2000; //周期20us
    reg [6:0]Duty=50;  //占空比30%
    reg Rst=1;
    reg En=1;
    Driver_PWM Driver_PWM0(
        .clk_100MHz(clk_100MHz),
        .Freq(Freq),
        .Duty(Duty),
        .Rst(Rst),
        .En(En),
        .PWM(PWM)
        );
endmodule
