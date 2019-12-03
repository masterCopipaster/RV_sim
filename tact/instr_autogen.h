class beq_instr : public tinstruction_B
{
	public:
	beq_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_RS1 == _RS2)
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class bne_instr : public tinstruction_B
{
	public:
	bne_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_RS1 != _RS2)
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class blt_instr : public tinstruction_B
{
	public:
	blt_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_RS1 < _RS2)
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class bge_instr : public tinstruction_B
{
	public:
	bge_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(_RS1 >= _RS2) 
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class bltu_instr : public tinstruction_B
{
	public:
	bltu_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)_RS1 < (uint32_t)_RS2) 
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class bgeu_instr : public tinstruction_B
{
	public:
	bgeu_instr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)_RS1 >= (uint32_t)_RS2) 
		{
			_PC += _BIMM12;
			_SETBR;
		}
		else _PC+=4;
		return 0;
	}
};
class jalr_instr : public tinstruction_I
{
	public:
	jalr_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		uint32_t buf = _PC + 4;
		_PC = (_RS1 + _IIMM12);
		_PC &= ~1;
		_RD = buf;
		_SETBR;
		return 0;
	}
};
class jal_instr : public tinstruction_J
{
	public:
	jal_instr(uint32_t opcode):tinstruction_J(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'jimm20']
		//printf("%08X\n", _JIMM20);
		_RD = _PC + 4;
		_PC += _JIMM20;
		_SETBR;
		return 0;
	}
};
class lui_instr : public tinstruction_U
{
	public:
	lui_instr(uint32_t opcode):tinstruction_U(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'imm20']
	//printf("lui r%d %d\n", enc.rd, _UIMM20);
		_RD = _UIMM20 << 12;
		_PC+=4;
		return 0;
	}
};
class auipc_instr : public tinstruction_U
{
	public:
	auipc_instr(uint32_t opcode):tinstruction_U(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'imm20']
		_RD = _PC + (_UIMM20 << 12);
		_PC+=4;
		return 0;
	}
};
class addi_instr : public tinstruction_I
{
	public:
	addi_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 + _IIMM12;
		_PC+=4;
		return 0;
	}
};
class slli_instr : public tinstruction_R
{
	public:
	slli_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 << enc.rs2;
	//['rd', 'rs1', 'shamt']
		_PC+=4;
		return 0;
	}
};
class slti_instr : public tinstruction_I
{
	public:
	slti_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 < _IIMM12 ? 1 : 0;
		_PC+=4;
		return 0;
	}
};
class sltiu_instr : public tinstruction_I
{
	public:
	sltiu_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)_RS1 < (uint32_t)_IIMM12 ? 1 : 0;
		_PC+=4;
		return 0;
	}
};
class xori_instr : public tinstruction_I
{
	public:
	xori_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 ^ _IIMM12;
		_PC+=4;
		return 0;
	}
};
class srli_instr : public tinstruction_R
{
	public:
	srli_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		_RD = _RS1 >> enc.rs2;
		_PC+=4;
		return 0;
	}
};
class srai_instr : public tinstruction_R
{
	public:
	srai_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		int32_t signbits = (_RS1 > 0 ? 0x00000000 : 0xFFFFFFFF) << (32 - enc.rs2);
		_RD = (_RS1 >> enc.rs2) | signbits;
		_PC+=4;
		return 0;
	}
};
class ori_instr : public tinstruction_I
{
	public:
	ori_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 | _IIMM12;
		_PC+=4;
		return 0;
	}
};
class andi_instr : public tinstruction_I
{
	public:
	andi_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = _RS1 & _IIMM12;
		_PC+=4;
		return 0;
	}
};
class add_instr : public tinstruction_R
{
	public:
	add_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sub_instr : public tinstruction_R
{
	public:
	sub_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 - _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sll_instr : public tinstruction_R
{
	public:
	sll_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 << _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class slt_instr : public tinstruction_R
{
	public:
	slt_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 < _RS2 ? 1 : 0;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sltu_instr : public tinstruction_R
{
	public:
	sltu_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = (uint32_t)_RS1 < (uint32_t)_RS2 ? 1 : 0;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class xor_instr : public tinstruction_R
{
	public:
	xor_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 ^ _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class srl_instr : public tinstruction_R
{
	public:
	srl_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 >> _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sra_instr : public tinstruction_R
{
	public:
	sra_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		int32_t signbits = (_RS1 > 0 ? 0x00000000 : 0xFFFFFFFF) << (32 - _RS2);
		_RD = (_RS1 >> _RS2) | signbits;
		_PC+=4;
		return 0;
	}
};
class or_instr : public tinstruction_R
{
	public:
	or_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 | _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class and_instr : public tinstruction_R
{
	public:
	and_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 & _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class addiw_instr : public tinstruction_I
{
	public:
	addiw_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_PC+=4;
		return 0;
	}
};
class slliw_instr : public tinstruction_R
{
	public:
	slliw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'shamtw']
		_PC+=4;
		return 0;
	}
};
class srliw_instr : public tinstruction_R
{
	public:
	srliw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'shamtw']
		_PC+=4;
		return 0;
	}
};
class sraiw_instr : public tinstruction_R
{
	public:
	sraiw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'shamtw']
		_PC+=4;
		return 0;
	}
};
class addw_instr : public tinstruction_R
{
	public:
	addw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class subw_instr : public tinstruction_R
{
	public:
	subw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sllw_instr : public tinstruction_R
{
	public:
	sllw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class srlw_instr : public tinstruction_R
{
	public:
	srlw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class sraw_instr : public tinstruction_R
{
	public:
	sraw_instr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_RD = _RS1 + _RS2;
	//['rd', 'rs1', 'rs2']
		_PC+=4;
		return 0;
	}
};
class lb_instr : public tinstruction_I
{
	public:
	lb_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read8(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class lh_instr : public tinstruction_I
{
	public:
	lh_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read16(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class lw_instr : public tinstruction_I
{
	public:
	lw_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read32(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class ld_instr : public tinstruction_I
{
	public:
	ld_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = proc.memif->read32(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class lbu_instr : public tinstruction_I
{
	public:
	lbu_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read8(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class lhu_instr : public tinstruction_I
{
	public:
	lhu_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read16(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class lwu_instr : public tinstruction_I
{
	public:
	lwu_instr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_RD = (uint32_t)proc.memif->read32(_RS1 + _IIMM12);
		_PC+=4;
		return 0;
	}
};
class sb_instr : public tinstruction_S
{
	public:
	sb_instr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write8(_RS1 + _SIMM12, _RS2);
		_PC+=4;
		return 0;
	}
};
class sh_instr : public tinstruction_S
{
	public:
	sh_instr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write16(_RS1 + _SIMM12, _RS2);
		_PC+=4;
		return 0;
	}
};
class sw_instr : public tinstruction_S
{
	public:
	sw_instr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_RS1 + _SIMM12, _RS2); 
		_PC+=4;
		return 0;
	}
};
class sd_instr : public tinstruction_S
{
	public:
	sd_instr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_RS1 + _SIMM12, _RS2);
		_PC+=4;
		return 0;
	}
};

