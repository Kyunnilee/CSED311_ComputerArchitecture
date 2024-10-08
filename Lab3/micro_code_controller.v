`include "state_def.v"

`define pc 1'b0
`define A 1'b1
`define B 2'b00
`define four 2'b01
`define imm 2'b10

module micro_code_controller (input [2:0] current_state,
                        input [6:0] opcode,
                        output reg is_ecall,
                        output reg PCWriteNotCond,
                        output reg PCWrite,
                        output reg IorD,
                        output reg MemRead,
                        output reg MemWrite,
                        output reg MemtoReg,
                        output reg IRWrite,
                        output reg PCSource,
                        output reg [1:0] ALUOp,
                        output reg [1:0] ALUSrcB,
                        output reg ALUSrcA,
                        output reg RegWrite);

always @(*) begin
        PCWriteNotCond = 0;
        PCWrite = 0;
        IorD = 0;
        MemRead = 0;
        MemWrite = 0;
        MemtoReg = 0;
        IRWrite = 0;
        PCSource = 0;
        ALUOp = 2'b00;
        ALUSrcB = `B;
        ALUSrcA = `pc;
        RegWrite = 0;
        is_ecall = 0;

    case(current_state)
        `IF: begin      // instruction fetch stage
            MemRead = 1;
            IRWrite = 1;
            IorD = 0;
        end
        `ID: begin      // instruction decode stage
            ALUSrcA = `pc;
            ALUSrcB = `four;
            ALUOp = 2'b00;
            if (opcode == `ECALL) begin
                is_ecall = 1;
                PCWrite = 1;
                PCSource = 0;
            end
        end
        `EX_1: begin    // execution stage
            if (opcode == `ARITHMETIC) begin
                ALUSrcA = `A;
                ALUSrcB = `B;
                ALUOp = 2'b10;
            end
            else if (opcode == `ARITHMETIC_IMM) begin
                ALUSrcA = `A;
                ALUSrcB = `imm;
                ALUOp = 2'b10;
            end
            else if (opcode == `LOAD || opcode == `STORE) begin
                ALUSrcA = `A;
                ALUSrcB = `imm;
                ALUOp = 2'b00;
            end
            else if (opcode == `BRANCH) begin
                ALUSrcA = `A;
                ALUSrcB =`B;
                ALUOp = 2'b10;
                PCWriteNotCond = 1;
                PCSource = 1;
            end
            else if (opcode == `JALR) begin
                ALUSrcA = `pc;
                ALUSrcB = `four;
                ALUOp = 2'b00;   
            end
            else begin //JAL
                ALUSrcA = `pc;
                ALUSrcB = `four;
                ALUOp = 2'b00;              
            end
        end
        `EX_2: begin    // execution stage(branch taken)
            if(opcode == `BRANCH) begin 
                ALUSrcA = `pc;
                ALUSrcB = `imm;
                ALUOp = 2'b00;
                PCWrite = 1;
                PCSource = 0;
            end        
        end
        `MEM: begin     // Memory stage
            if (opcode == `LOAD) begin
                MemRead = 1;
                IorD = 1;
            end
            else begin  // STORE
                MemWrite = 1;
                IorD = 1;
                ALUSrcA = `pc;
                ALUSrcB = `four;
                ALUOp = 2'b00; 
                PCSource = 0;
                PCWrite = 1;
            end
        end
        `WB: begin      // write back stage
            if (opcode == `ARITHMETIC || opcode == `ARITHMETIC_IMM) begin
                PCWrite = 1;
                MemtoReg = 0;
                RegWrite = 1;
                ALUSrcA = `pc;
                ALUSrcB = `four;
                ALUOp = 2'b00;
                PCSource = 0;
            end
            else if (opcode == `LOAD) begin
                PCWrite = 1;
                MemtoReg = 1; 
                RegWrite = 1;
                ALUSrcA = `pc;
                ALUSrcB = `four;
                ALUOp = 2'b00;
                PCSource = 0;
            end
            else if (opcode == `JAL) begin
                PCWrite = 1;
                MemtoReg = 0;
                RegWrite = 1;
                ALUSrcA = `pc;
                ALUSrcB = `imm;
                ALUOp = 2'b00;
                PCSource = 0;
            end
            else if (opcode == `JALR) begin
                PCWrite = 1;
                MemtoReg = 0;
                RegWrite = 1;
                ALUSrcA = `A;
                ALUSrcB = `imm;
                ALUOp = 2'b00;
                PCSource = 0;
            end

        end
        default: begin
            
        end
    endcase
end

endmodule
