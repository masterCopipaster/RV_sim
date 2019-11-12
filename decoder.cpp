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
		is.opcode, is.imm4_0, is.func3, is.rs1, is.rs2, is.imm11_5);
}

void print_S_type_str(be_S_type_enc is)
{
	printf(
		"opcode %x\nimm5 %x\nfunc3 %x\nrs1 %x\nrs2 %x\nimm7 %x\n",
		is.opcode, is.imm4_0, is.func3, is.rs1, is.rs2, is.imm11_5);
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

int32_t B_type_imm_repair(be_B_type_enc enc)
{	//imm[12] imm[10:5] rs2 rs1 funct3 imm[4:1] imm[11] opcode B-type
	//return (enc.imm11 << 11) | (enc.imm10_5 << 5) | (enc.imm4_1 << 1) * (enc.imm12 ? -1 : 1);
	int32_t buf = (enc.imm11 << 11) | (enc.imm10_5 << 5) | (enc.imm4_1 << 1);
	printf("%08X\n", buf);
	return (enc.imm12 ? buf | 0xfffff000 : buf);
}

int32_t J_type_imm_repair(be_J_type_enc enc)
{	//imm[20] imm[10:1] imm[11] imm[19:12] rd opcode J-type
	//return (enc.imm11 << 11) | (enc.imm19_12 << 12) | (enc.imm10_1 << 1) * (enc.imm20 ? -1 : 1);
	int32_t buf = (enc.imm19_12 << 12) | (enc.imm11 << 11) | (enc.imm10_1 << 1);
	//printf("%08X\n", buf);
	return (enc.imm20 ? buf | 0xfff00000 : buf);
}

int32_t S_type_imm_repair(be_S_type_enc enc)
{
	return (enc.imm11_5 << 5) | enc.imm4_0;
}

