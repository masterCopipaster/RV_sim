#ifndef _DECODER_H
#define _DECODER_H

typedef struct
{
	unsigned opcode : 7;
	unsigned rd : 5;
	unsigned func3 : 3;
	unsigned rs1 : 5;
	unsigned rs2 : 5;
	unsigned func7 : 7;
} be_R_type_enc;

void print_R_type(uint32_t instr)
{
	be_R_type_enc is = *(be_R_type_enc*) &instr;
        printf(
        "opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nrs2 %x\nfunc7 %x\n",
        is.opcode, is.rd, is.func3, is.rs1, is.rs2, is.func7);
}

void print_R_type(be_R_type_enc is)
{
        printf(
        "opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nrs2 %x\nfunc7 %x\n",
        is.opcode, is.rd, is.func3, is.rs1, is.rs2, is.func7);
}

typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned imm12 : 12;
} be_I_type_enc;

void print_I_type(uint32_t instr)
{
        be_I_type_enc is = *(be_I_type_enc*) &instr;
        printf(
        "opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nimm12 %x\n",
        is.opcode, is.rd, is.func3, is.rs1, is.imm12);
}

void print_I_type(be_I_type_enc is)
{
        printf(
        "opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nimm12 %x\n",
        is.opcode, is.rd, is.func3, is.rs1, is.imm12);
}

typedef struct
{
        unsigned opcode : 7;
        unsigned imm5 : 5;
        unsigned func3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        unsigned imm7 : 7;
} be_S_type_enc;

void print_S_type(uint32_t instr)
{
        be_S_type_enc is = *(be_S_type_enc*) &instr;
        printf(
        "opcode %x\nimm5 %x\nfunc3 %x\nrs1 %x\nrs2 %x\nimm7 %x\n",
        is.opcode, is.imm5, is.func3, is.rs1, is.rs2, is.imm7);
}

void print_S_type(be_S_type_enc is)
{
        printf(
        "opcode %x\nimm5 %x\nfunc3 %x\nrs1 %x\nrs2 %x\nimm7 %x\n",
        is.opcode, is.imm5, is.func3, is.rs1, is.rs2, is.imm7);
}

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

void print_U_type(uint32_t instr)
{
        be_U_type_enc is = *(be_U_type_enc*) &instr;
        printf(
        "opcode %x\nrd %x\nimm20 %x\n",
        is.opcode, is.rd, is.imm20);
}

void print_U_type(be_U_type_enc is)
{
        printf(
        "opcode %x\nrd %x\nimm20 %x\n",
        is.opcode, is.rd, is.imm20);
}

typedef struct
{
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned imm20 : 20;
} be_J_type_enc;

#endif
