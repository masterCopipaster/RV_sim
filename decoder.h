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
        unsigned imm12 : 12;
} be_I_type_enc;


typedef struct
{
        unsigned opcode : 7;
        unsigned imm5 : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        unsigned imm7 : 7;
} be_S_type_enc;


typedef struct
{
        unsigned opcode : 7;
        unsigned imm5 : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        unsigned imm7 : 7;
} be_B_type_enc;

typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned imm20 : 20;
} be_U_type_enc;


typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned imm20 : 20;
} be_J_type_enc;

void print_R_type(uint32_t instr);
void print_R_type_str(be_R_type_enc is);
void print_I_type(uint32_t instr);
void print_I_type_str(be_I_type_enc is);
void print_S_type(uint32_t instr);
void print_S_type_str(be_S_type_enc is);
void print_U_type(uint32_t instr);
void print_U_type_str(be_U_type_enc is);

#endif
