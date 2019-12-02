#ifndef _DECODER_H
#define _DECODER_H

#include <stdint.h>
#include <stdio.h>

typedef struct
{
	unsigned opcode : 7;
	unsigned rd : 5;
	unsigned func3 : 3;
	unsigned rs1 : 5;
	unsigned rs2 : 5;
	unsigned func7 : 7;
} be_R_type_enc;


typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        signed imm12 : 12;
} be_I_type_enc;

//imm[11:5] rs2 rs1 funct3 imm[4:0] opcode S-type
typedef struct
{
        unsigned opcode : 7;
        unsigned imm4_0 : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        signed imm11_5 : 7;
} be_S_type_enc;

int32_t S_type_imm_repair(be_S_type_enc enc);

//imm[12] imm[10:5] rs2 rs1 funct3 imm[4:1] imm[11] opcode B-type
typedef struct
{
        unsigned opcode : 7;
        unsigned imm11 : 1;
        unsigned imm4_1 : 4;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        unsigned imm10_5 : 6;
        unsigned imm12 : 1;
} be_B_type_enc;

int32_t B_type_imm_repair(be_B_type_enc enc);

typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned imm20 : 20;
} be_U_type_enc;

//imm[20] imm[10:1] imm[11] imm[19:12] rd opcode J-type
typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned imm19_12 : 8;
        unsigned imm11 : 1;
        unsigned imm10_1 : 10;
        unsigned imm20 : 1;
} be_J_type_enc;

int32_t J_type_imm_repair(be_J_type_enc enc);

void print_R_type(uint32_t instr);
void print_R_type_str(be_R_type_enc is);
void print_I_type(uint32_t instr);
void print_I_type_str(be_I_type_enc is);
void print_S_type(uint32_t instr);
void print_S_type_str(be_S_type_enc is);
void print_U_type(uint32_t instr);
void print_U_type_str(be_U_type_enc is);

#endif
