#include "tinstruction.h"

tinstruction_R::tinstruction_R(uint32_t opcode)
{
	enc = *(be_R_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	rd = enc.rd;
	regs = (1 << rs1) | (1 << rs2);
	regd = 1 << rd;
}

int tinstruction_R::memory(tproc_state& proc) 
{
	return 0;
}

int tinstruction_R::writeback(tproc_state& proc)
{
	proc.reg[rd] = rdbuf;
	return 0;
}


tinstruction_I::tinstruction_I(uint32_t opcode)
{
	enc = *(be_I_type_enc*)&opcode;
	rs1 = enc.rs1;
	rd = enc.rd;
	imm12 = __IIMM12;
	regs = (1 << rs1);
	regd = 1 << rd;
}

int tinstruction_I::memory(tproc_state& proc)
{
	return 0;
}

int tinstruction_I::writeback(tproc_state& proc)
{
	proc.reg[rd] = rdbuf;
	return 0;
}

tinstruction_S::tinstruction_S(uint32_t opcode)
{
	enc = *(be_S_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	imm12 = __SIMM12;
	regs = (1 << rs1) | (1 << rs2);
	regd = 0;
}

int tinstruction_S::memory(tproc_state& proc)
{
	return 0;
}

int tinstruction_S::writeback(tproc_state& proc)
{
	return 0;
}

tinstruction_U::tinstruction_U(uint32_t opcode)
{
	enc = *(be_U_type_enc*)&opcode;
	rd = enc.rd;
	imm20 = __UIMM20;
	regs = 0;
	regd = 1 << rd;
}

int tinstruction_U::memory(tproc_state& proc)
{
	return 0;
}

int tinstruction_U::writeback(tproc_state& proc)
{
	proc.reg[rd] = rdbuf;
	return 0;
}

tinstruction_J::tinstruction_J(uint32_t opcode)
{
	enc = *(be_J_type_enc*)&opcode;
	rd = enc.rd;
	imm20 = __JIMM20;
	regs = 0;
	regd = 1 << rd;
}

int tinstruction_J::memory(tproc_state& proc)
{
	proc.reg[rd] = rdbuf;
	return 0;
}

int tinstruction_J::writeback(tproc_state& proc)
{
	proc.reg[rd] = rdbuf;
	return 0;
}

tinstruction_B::tinstruction_B(uint32_t opcode)
{
	enc = *(be_B_type_enc*)&opcode;
	rs1 = enc.rs1;
	rs2 = enc.rs2;
	imm12 = __BIMM12;
	regs = (1 << rs1) | (1 << rs2);
	regd = 0;
}

int tinstruction_B::memory(tproc_state& proc)
{
	return 0;
}

int tinstruction_B::writeback(tproc_state& proc)
{
	return 0;
}

tinstruction* make_tinstruction(uint32_t opcode)
{
	if ((opcode & 28799) == 99) return new beq_tinstr(opcode); //B
	if ((opcode & 28799) == 4195) return new bne_tinstr(opcode); //B
	if ((opcode & 28799) == 16483) return new blt_tinstr(opcode); //B
	if ((opcode & 28799) == 20579) return new bge_tinstr(opcode); //B
	if ((opcode & 28799) == 24675) return new bltu_tinstr(opcode); //B
	if ((opcode & 28799) == 28771) return new bgeu_tinstr(opcode); //B
	if ((opcode & 28799) == 103) return new jalr_tinstr(opcode); //I
	if ((opcode & 127) == 111) return new jal_tinstr(opcode); //J
	if ((opcode & 127) == 55) return new lui_tinstr(opcode); //U
	if ((opcode & 127) == 23) return new auipc_tinstr(opcode); //U
	if ((opcode & 28799) == 19) return new addi_tinstr(opcode); //I
	if ((opcode & 4227887231) == 4115) return new slli_tinstr(opcode); //R
	if ((opcode & 28799) == 8211) return new slti_tinstr(opcode); //I
	if ((opcode & 28799) == 12307) return new sltiu_tinstr(opcode); //I
	if ((opcode & 28799) == 16403) return new xori_tinstr(opcode); //I
	if ((opcode & 4227887231) == 20499) return new srli_tinstr(opcode); //R
	if ((opcode & 4227887231) == 1073762323) return new srai_tinstr(opcode); //R
	if ((opcode & 28799) == 24595) return new ori_tinstr(opcode); //I
	if ((opcode & 28799) == 28691) return new andi_tinstr(opcode); //I
	if ((opcode & 4261441663) == 51) return new add_tinstr(opcode); //R
	if ((opcode & 4261441663) == 1073741875) return new sub_tinstr(opcode); //R
	if ((opcode & 4261441663) == 4147) return new sll_tinstr(opcode); //R
	if ((opcode & 4261441663) == 8243) return new slt_tinstr(opcode); //R
	if ((opcode & 4261441663) == 12339) return new sltu_tinstr(opcode); //R
	if ((opcode & 4261441663) == 16435) return new xor_tinstr(opcode); //R
	if ((opcode & 4261441663) == 20531) return new srl_tinstr(opcode); //R
	if ((opcode & 4261441663) == 1073762355) return new sra_tinstr(opcode); //R
	if ((opcode & 4261441663) == 24627) return new or_tinstr(opcode); //R
	if ((opcode & 4261441663) == 28723) return new and_tinstr(opcode); //R
	if ((opcode & 28799) == 27) return new addiw_tinstr(opcode); //I
	if ((opcode & 4261441663) == 4123) return new slliw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 20507) return new srliw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 1073762331) return new sraiw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 59) return new addw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 1073741883) return new subw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 4155) return new sllw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 20539) return new srlw_tinstr(opcode); //R
	if ((opcode & 4261441663) == 1073762363) return new sraw_tinstr(opcode); //R
	if ((opcode & 28799) == 3) return new lb_tinstr(opcode); //I
	if ((opcode & 28799) == 4099) return new lh_tinstr(opcode); //I
	if ((opcode & 28799) == 8195) return new lw_tinstr(opcode); //I
	if ((opcode & 28799) == 12291) return new ld_tinstr(opcode); //I
	if ((opcode & 28799) == 16387) return new lbu_tinstr(opcode); //I
	if ((opcode & 28799) == 20483) return new lhu_tinstr(opcode); //I
	if ((opcode & 28799) == 24579) return new lwu_tinstr(opcode); //I
	if ((opcode & 28799) == 35) return new sb_tinstr(opcode); //S
	if ((opcode & 28799) == 4131) return new sh_tinstr(opcode); //S
	if ((opcode & 28799) == 8227) return new sw_tinstr(opcode); //S
	if ((opcode & 28799) == 12323) return new sd_tinstr(opcode); //S
	if ((opcode & 4294967295) == 115) return new ecall_tinstr(opcode); //ECALL
	return 0;
}

