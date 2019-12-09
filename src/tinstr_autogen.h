class beq_tinstr : public tinstruction_B
{
	public:
	beq_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_TRS1 == _TRS2)
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class bne_tinstr : public tinstruction_B
{
	public:
	bne_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_TRS1 != _TRS2)
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class blt_tinstr : public tinstruction_B
{
	public:
	blt_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if (_TRS1 < _TRS2)
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class bge_tinstr : public tinstruction_B
{
	public:
	bge_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if(_TRS1 >= _TRS2) 
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class bltu_tinstr : public tinstruction_B
{
	public:
	bltu_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)_TRS1 < (uint32_t)_TRS2) 
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class bgeu_tinstr : public tinstruction_B
{
	public:
	bgeu_tinstr(uint32_t opcode):tinstruction_B(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		if((uint32_t)_TRS1 >= (uint32_t)_TRS2) 
		{
			_TPC = _PCB + _BIMM12;
			_SETBR;
		}
		else _TPC+=4;
		return 0;
	}
};
class jalr_tinstr : public tinstruction_I
{
	public:
	jalr_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		uint32_t buf = _PCB + 4;
		_TPC = (_TRS1 + _IIMM12);
		_TPC &= ~1;
		_TRD = buf;
		_SETBR;
		return 0;
	}
};
class jal_tinstr : public tinstruction_J
{
	public:
	jal_tinstr(uint32_t opcode):tinstruction_J(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'jimm20']
		//printf("%08X\n", _JIMM20);
		_TRD = _PCB + 4;
		_TPC += _JIMM20;
		_SETBR;
		return 0;
	}
};
class lui_tinstr : public tinstruction_U
{
	public:
	lui_tinstr(uint32_t opcode):tinstruction_U(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'imm20']
	//printf("lui r%d %d\n", enc.rd, _UIMM20);
		_TRD = _UIMM20 << 12;
		_TPC+=4;
		return 0;
	}
};
class auipc_tinstr : public tinstruction_U
{
	public:
	auipc_tinstr(uint32_t opcode):tinstruction_U(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'imm20']
		_TRD = _PCB + (_UIMM20 << 12);
		_TPC+=4;
		return 0;
	}
};
class addi_tinstr : public tinstruction_I
{
	public:
	addi_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = _TRS1 + _IIMM12;
		_TPC+=4;
		return 0;
	}
};
class slli_tinstr : public tinstruction_R
{
	public:
	slli_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 << enc.rs2;
	//['rd', 'rs1', 'shamt']
		_TPC+=4;
		return 0;
	}
};
class slti_tinstr : public tinstruction_I
{
	public:
	slti_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = _TRS1 < _IIMM12 ? 1 : 0;
		_TPC+=4;
		return 0;
	}
};
class sltiu_tinstr : public tinstruction_I
{
	public:
	sltiu_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = (uint32_t)_TRS1 < (uint32_t)_IIMM12 ? 1 : 0;
		_TPC+=4;
		return 0;
	}
};
class xori_tinstr : public tinstruction_I
{
	public:
	xori_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = _TRS1 ^ _IIMM12;
		_TPC+=4;
		return 0;
	}
};
class srli_tinstr : public tinstruction_R
{
	public:
	srli_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		_TRD = _TRS1 >> enc.rs2;
		_TPC+=4;
		return 0;
	}
};
class srai_tinstr : public tinstruction_R
{
	public:
	srai_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		int32_t signbits = (_TRS1 > 0 ? 0x00000000 : 0xFFFFFFFF) << (32 - enc.rs2);
		_TRD = (_TRS1 >> enc.rs2) | signbits;
		_TPC+=4;
		return 0;
	}
};
class ori_tinstr : public tinstruction_I
{
	public:
	ori_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = _TRS1 | _IIMM12;
		_TPC+=4;
		return 0;
	}
};
class andi_tinstr : public tinstruction_I
{
	public:
	andi_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = _TRS1 & _IIMM12;
		_TPC+=4;
		return 0;
	}
};
class add_tinstr : public tinstruction_R
{
	public:
	add_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sub_tinstr : public tinstruction_R
{
	public:
	sub_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 - _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sll_tinstr : public tinstruction_R
{
	public:
	sll_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 << _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class slt_tinstr : public tinstruction_R
{
	public:
	slt_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 < _TRS2 ? 1 : 0;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sltu_tinstr : public tinstruction_R
{
	public:
	sltu_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = (uint32_t)_TRS1 < (uint32_t)_TRS2 ? 1 : 0;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class xor_tinstr : public tinstruction_R
{
	public:
	xor_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 ^ _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class srl_tinstr : public tinstruction_R
{
	public:
	srl_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 >> _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sra_tinstr : public tinstruction_R
{
	public:
	sra_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		int32_t signbits = (_TRS1 > 0 ? 0x00000000 : 0xFFFFFFFF) << (32 - _TRS2);
		_TRD = (_TRS1 >> _TRS2) | signbits;
		_TPC+=4;
		return 0;
	}
};
class or_tinstr : public tinstruction_R
{
	public:
	or_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 | _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class and_tinstr : public tinstruction_R
{
	public:
	and_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 & _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class addiw_tinstr : public tinstruction_I
{
	public:
	addiw_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TPC+=4;
		return 0;
	}
};
class slliw_tinstr : public tinstruction_R
{
	public:
	slliw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'shamtw']
		_TPC+=4;
		return 0;
	}
};
class srliw_tinstr : public tinstruction_R
{
	public:
	srliw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'shamtw']
		_TPC+=4;
		return 0;
	}
};
class sraiw_tinstr : public tinstruction_R
{
	public:
	sraiw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'shamtw']
		_TPC+=4;
		return 0;
	}
};
class addw_tinstr : public tinstruction_R
{
	public:
	addw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class subw_tinstr : public tinstruction_R
{
	public:
	subw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sllw_tinstr : public tinstruction_R
{
	public:
	sllw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class srlw_tinstr : public tinstruction_R
{
	public:
	srlw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class sraw_tinstr : public tinstruction_R
{
	public:
	sraw_tinstr(uint32_t opcode):tinstruction_R(opcode){}
	int execute(tproc_state& proc)
	{
		_TRD = _TRS1 + _TRS2;
	//['rd', 'rs1', 'rs2']
		_TPC+=4;
		return 0;
	}
};
class lb_tinstr : public tinstruction_I
{
	public:
	lb_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = proc.memif->read8(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class lh_tinstr : public tinstruction_I
{
	public:
	lh_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = proc.memif->read16(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class lw_tinstr : public tinstruction_I
{
	public:
	lw_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = proc.memif->read32(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class ld_tinstr : public tinstruction_I
{
	public:
	ld_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = proc.memif->read32(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class lbu_tinstr : public tinstruction_I
{
	public:
	lbu_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = (uint32_t)proc.memif->read8(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class lhu_tinstr : public tinstruction_I
{
	public:
	lhu_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = (uint32_t)proc.memif->read16(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class lwu_tinstr : public tinstruction_I
{
	public:
	lwu_tinstr(uint32_t opcode):tinstruction_I(opcode){}
	int execute(tproc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		_TRD = (uint32_t)proc.memif->read32(_TRS1 + _IIMM12);
		_TPC+=4;
		return 0;
	}
};
class sb_tinstr : public tinstruction_S
{
	public:
	sb_tinstr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write8(_TRS1 + _SIMM12, _TRS2);
		_TPC+=4;
		return 0;
	}
};
class sh_tinstr : public tinstruction_S
{
	public:
	sh_tinstr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write16(_TRS1 + _SIMM12, _TRS2);
		_TPC+=4;
		return 0;
	}
};
class sw_tinstr : public tinstruction_S
{
	public:
	sw_tinstr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_TRS1 + _SIMM12, _TRS2); 
		_TPC+=4;
		return 0;
	}
};
class sd_tinstr : public tinstruction_S
{
	public:
	sd_tinstr(uint32_t opcode):tinstruction_S(opcode){}
	int execute(tproc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.memif->write32(_TRS1 + _SIMM12, _TRS2);
		_TPC+=4;
		return 0;
	}
};

