#include "decoder.h"

void print_R_type(uint32_t instr)
{
	be_R_type_enc is = *(be_R_type_enc*)&instr;
	printf(
		"opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nrs2 %x\nfunc7 %x\n",
		is.opcode, is.rd, is.func3, is.rs1, is.rs2, is.func7);
}

void print_R_type_str(be_R_type_enc is)
{
	printf(
		"opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nrs2 %x\nfunc7 %x\n",
		is.opcode, is.rd, is.func3, is.rs1, is.rs2, is.func7);
}

void print_I_type(uint32_t instr)
{
	be_I_type_enc is = *(be_I_type_enc*)&instr;
	printf(
		"opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nimm12 %x\n",
		is.opcode, is.rd, is.func3, is.rs1, is.imm12);
}

void print_I_type_str(be_I_type_enc is)
{
	printf(
		"opcode %x\nrd %x\nfunc3 %x\nrs1 %x\nimm12 %x\n",
		is.opcode, is.rd, is.func3, is.rs1, is.imm12);
}

void print_S_type(uint32_t instr)
{
	be_S_type_enc is = *(be_S_type_enc*)&instr;
	printf(
		"opcode %x\nimm5 %x\nfunc3 %x\nrs1 %x\nrs2 %x\nimm7 %x\n",
		is.opcode, is.imm5, is.func3, is.rs1, is.rs2, is.imm7);
}

void print_S_type_str(be_S_type_enc is)
{
	printf(
		"opcode %x\nimm5 %x\nfunc3 %x\nrs1 %x\nrs2 %x\nimm7 %x\n",
		is.opcode, is.imm5, is.func3, is.rs1, is.rs2, is.imm7);
}


void print_U_type(uint32_t instr)
{
	be_U_type_enc is = *(be_U_type_enc*)&instr;
	printf(
		"opcode %x\nrd %x\nimm20 %x\n",
		is.opcode, is.rd, is.imm20);
}

void print_U_type_str(be_U_type_enc is)
{
	printf(
		"opcode %x\nrd %x\nimm20 %x\n",
		is.opcode, is.rd, is.imm20);
}



