#include "instruction.h"

instruction_R::instruction_R(uint32_t opcode)
{
	enc = *(be_R_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	rd = enc.rd;
}

instruction_I::instruction_I(uint32_t opcode)
{
	enc = *(be_I_type_enc*)&opcode;
	rs1 = enc.rs1;
	rd = enc.rd;
	imm12 = __IIMM12;
}

instruction_S::instruction_S(uint32_t opcode)
{
	enc = *(be_S_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	imm12 = __SIMM12;
}

instruction_U::instruction_U(uint32_t opcode)
{
	enc = *(be_U_type_enc*)&opcode;
	rd = enc.rd;
	imm20 = __UIMM20;
}

instruction_J::instruction_J(uint32_t opcode)
{
	enc = *(be_J_type_enc*)&opcode;
	rd = enc.rd;
	imm20 = __JIMM20;
}

instruction_B::instruction_B(uint32_t opcode)
{
	enc = *(be_B_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	imm12 = __BIMM12;
}

instruction* make_instruction(uint32_t opcode)
{
	if ((opcode & 28799) == 99) return new beq_instr(opcode); //B
	if ((opcode & 28799) == 4195) return new bne_instr(opcode); //B
	if ((opcode & 28799) == 16483) return new blt_instr(opcode); //B
	if ((opcode & 28799) == 20579) return new bge_instr(opcode); //B
	if ((opcode & 28799) == 24675) return new bltu_instr(opcode); //B
	if ((opcode & 28799) == 28771) return new bgeu_instr(opcode); //B
	if ((opcode & 28799) == 103) return new jalr_instr(opcode); //I
	if ((opcode & 127) == 111) return new jal_instr(opcode); //J
	if ((opcode & 127) == 55) return new lui_instr(opcode); //U
	if ((opcode & 127) == 23) return new auipc_instr(opcode); //U
	if ((opcode & 28799) == 19) return new addi_instr(opcode); //I
	if ((opcode & 4227887231) == 4115) return new slli_instr(opcode); //R
	if ((opcode & 28799) == 8211) return new slti_instr(opcode); //I
	if ((opcode & 28799) == 12307) return new sltiu_instr(opcode); //I
	if ((opcode & 28799) == 16403) return new xori_instr(opcode); //I
	if ((opcode & 4227887231) == 20499) return new srli_instr(opcode); //R
	if ((opcode & 4227887231) == 1073762323) return new srai_instr(opcode); //R
	if ((opcode & 28799) == 24595) return new ori_instr(opcode); //I
	if ((opcode & 28799) == 28691) return new andi_instr(opcode); //I
	if ((opcode & 4261441663) == 51) return new add_instr(opcode); //R
	if ((opcode & 4261441663) == 1073741875) return new sub_instr(opcode); //R
	if ((opcode & 4261441663) == 4147) return new sll_instr(opcode); //R
	if ((opcode & 4261441663) == 8243) return new slt_instr(opcode); //R
	if ((opcode & 4261441663) == 12339) return new sltu_instr(opcode); //R
	if ((opcode & 4261441663) == 16435) return new xor_instr(opcode); //R
	if ((opcode & 4261441663) == 20531) return new srl_instr(opcode); //R
	if ((opcode & 4261441663) == 1073762355) return new sra_instr(opcode); //R
	if ((opcode & 4261441663) == 24627) return new or_instr(opcode); //R
	if ((opcode & 4261441663) == 28723) return new and_instr(opcode); //R
	if ((opcode & 28799) == 27) return new addiw_instr(opcode); //I
	if ((opcode & 4261441663) == 4123) return new slliw_instr(opcode); //R
	if ((opcode & 4261441663) == 20507) return new srliw_instr(opcode); //R
	if ((opcode & 4261441663) == 1073762331) return new sraiw_instr(opcode); //R
	if ((opcode & 4261441663) == 59) return new addw_instr(opcode); //R
	if ((opcode & 4261441663) == 1073741883) return new subw_instr(opcode); //R
	if ((opcode & 4261441663) == 4155) return new sllw_instr(opcode); //R
	if ((opcode & 4261441663) == 20539) return new srlw_instr(opcode); //R
	if ((opcode & 4261441663) == 1073762363) return new sraw_instr(opcode); //R
	if ((opcode & 28799) == 3) return new lb_instr(opcode); //I
	if ((opcode & 28799) == 4099) return new lh_instr(opcode); //I
	if ((opcode & 28799) == 8195) return new lw_instr(opcode); //I
	if ((opcode & 28799) == 12291) return new ld_instr(opcode); //I
	if ((opcode & 28799) == 16387) return new lbu_instr(opcode); //I
	if ((opcode & 28799) == 20483) return new lhu_instr(opcode); //I
	if ((opcode & 28799) == 24579) return new lwu_instr(opcode); //I
	if ((opcode & 28799) == 35) return new sb_instr(opcode); //S
	if ((opcode & 28799) == 4131) return new sh_instr(opcode); //S
	if ((opcode & 28799) == 8227) return new sw_instr(opcode); //S
	if ((opcode & 28799) == 12323) return new sd_instr(opcode); //S
	if ((opcode & 4294967295) == 115) return new ecall_instr(opcode); //ECALL
	return 0;
}

