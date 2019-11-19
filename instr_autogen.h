class beq_instr : public instruction_B
{
	public:
	beq_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(proc.reg[enc.rs1] == proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class bne_instr : public instruction_B
{
	public:
	bne_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(proc.reg[enc.rs1] != proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class blt_instr : public instruction_B
{
	public:
	blt_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(proc.reg[enc.rs1] < proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class bge_instr : public instruction_B
{
	public:
	bge_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(proc.reg[enc.rs1] >= proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class bltu_instr : public instruction_B
{
	public:
	bltu_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)proc.reg[enc.rs1] < (uint32_t)proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class bgeu_instr : public instruction_B
{
	public:
	bgeu_instr(uint32_t opcode):instruction_B(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)proc.reg[enc.rs1] >= (uint32_t)proc.reg[enc.rs2]) proc.pc += B_type_imm_repair(enc);
		else proc.pc+=4;
		return 0;
	}
};
class jalr_instr : public instruction_I
{
	public:
	jalr_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		uint32_t buf = proc.pc + 4;
		proc.pc = (_RS1 + enc.imm12);
		proc.pc &= ~1;
		_RD = buf;
		return 0;
	}
};
class jal_instr : public instruction_J
{
	public:
	jal_instr(uint32_t opcode):instruction_J(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'jimm20']
		//printf("%08X\n", J_type_imm_repair(enc));
		_RD = proc.pc + 4;
		proc.pc += J_type_imm_repair(enc);
		return 0;
	}
};
class lui_instr : public instruction_U
{
	public:
	lui_instr(uint32_t opcode):instruction_U(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'imm20']
	//printf("lui r%d %d\n", enc.rd, enc.imm20);
		_RD = enc.imm20 << 12;
		proc.pc+=4;
		return 0;
	}
};
class auipc_instr : public instruction_U
{
	public:
	auipc_instr(uint32_t opcode):instruction_U(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'imm20']
		_RD = proc.pc + (enc.imm20 << 12);
		proc.pc+=4;
		return 0;
	}
};
class addi_instr : public instruction_I
{
	public:
	addi_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 + enc.imm12;
		proc.pc+=4;
		return 0;
	}
};
class slli_instr : public instruction_R
{
	public:
	slli_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] << proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class slti_instr : public instruction_I
{
	public:
	slti_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class sltiu_instr : public instruction_I
{
	public:
	sltiu_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class xori_instr : public instruction_I
{
	public:
	xori_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class srli_instr : public instruction_R
{
	public:
	srli_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] >> proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class srai_instr : public instruction_R
{
	public:
	srai_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class ori_instr : public instruction_I
{
	public:
	ori_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class andi_instr : public instruction_I
{
	public:
	andi_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class add_instr : public instruction_R
{
	public:
	add_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sub_instr : public instruction_R
{
	public:
	sub_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sll_instr : public instruction_R
{
	public:
	sll_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class slt_instr : public instruction_R
{
	public:
	slt_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sltu_instr : public instruction_R
{
	public:
	sltu_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class xor_instr : public instruction_R
{
	public:
	xor_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class srl_instr : public instruction_R
{
	public:
	srl_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sra_instr : public instruction_R
{
	public:
	sra_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class or_instr : public instruction_R
{
	public:
	or_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class and_instr : public instruction_R
{
	public:
	and_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class addiw_instr : public instruction_I
{
	public:
	addiw_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class slliw_instr : public instruction_R
{
	public:
	slliw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class srliw_instr : public instruction_R
{
	public:
	srliw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class sraiw_instr : public instruction_R
{
	public:
	sraiw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class addw_instr : public instruction_R
{
	public:
	addw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class subw_instr : public instruction_R
{
	public:
	subw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sllw_instr : public instruction_R
{
	public:
	sllw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class srlw_instr : public instruction_R
{
	public:
	srlw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sraw_instr : public instruction_R
{
	public:
	sraw_instr(uint32_t opcode):instruction_R(opcode){}
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class lb_instr : public instruction_I
{
	public:
	lb_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read8(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class lh_instr : public instruction_I
{
	public:
	lh_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read16(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class lw_instr : public instruction_I
{
	public:
	lw_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read32(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class ld_instr : public instruction_I
{
	public:
	ld_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read32(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class lbu_instr : public instruction_I
{
	public:
	lbu_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read8(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class lhu_instr : public instruction_I
{
	public:
	lhu_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read16(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class lwu_instr : public instruction_I
{
	public:
	lwu_instr(uint32_t opcode):instruction_I(opcode){}
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read32(_RS1 + enc.imm12);
		proc.pc+=4;
		return 0;
	}
};
class sb_instr : public instruction_S
{
	public:
	sb_instr(uint32_t opcode):instruction_S(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write8(_RS1 + S_type_imm_repair(enc), _RS2);
		proc.pc+=4;
		return 0;
	}
};
class sh_instr : public instruction_S
{
	public:
	sh_instr(uint32_t opcode):instruction_S(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write16(_RS1 + S_type_imm_repair(enc), _RS2);
		proc.pc+=4;
		return 0;
	}
};
class sw_instr : public instruction_S
{
	public:
	sw_instr(uint32_t opcode):instruction_S(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_RS1 + S_type_imm_repair(enc), _RS2); 
		proc.pc+=4;
		return 0;
	}
};
class sd_instr : public instruction_S
{
	public:
	sd_instr(uint32_t opcode):instruction_S(opcode){}
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_RS1 + S_type_imm_repair(enc), _RS2);
		proc.pc+=4;
		return 0;
	}
};

