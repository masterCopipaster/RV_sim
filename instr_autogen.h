class beq_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class bne_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class blt_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class bge_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class bltu_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class bgeu_instr : public instruction <be_B_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'bimm']
		proc.pc+=4;
		return 0;
	}
};
class jalr_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class jal_instr : public instruction <be_J_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'jimm20']
		proc.pc+=4;
		return 0;
	}
};
class lui_instr : public instruction <be_U_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'imm20']
		proc.pc+=4;
		return 0;
	}
};
class auipc_instr : public instruction <be_U_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'imm20']
		proc.pc+=4;
		return 0;
	}
};
class addi_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class slli_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class slti_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class sltiu_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class xori_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class srli_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class srai_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamt']
		proc.pc+=4;
		return 0;
	}
};
class ori_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class andi_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class add_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sub_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sll_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class slt_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sltu_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class xor_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class srl_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sra_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class or_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class and_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class addiw_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class slliw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class srliw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class sraiw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'shamtw']
		proc.pc+=4;
		return 0;
	}
};
class addw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class subw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sllw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class srlw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class sraw_instr : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'rs2']
		proc.pc+=4;
		return 0;
	}
};
class lb_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class lh_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class lw_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class ld_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class lbu_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class lhu_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class lwu_instr : public instruction <be_I_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rd', 'rs1', 'imm12']
		proc.pc+=4;
		return 0;
	}
};
class sb_instr : public instruction <be_S_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.pc+=4;
		return 0;
	}
};
class sh_instr : public instruction <be_S_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.pc+=4;
		return 0;
	}
};
class sw_instr : public instruction <be_S_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.pc+=4;
		return 0;
	}
};
class sd_instr : public instruction <be_S_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
	//['rs1', 'rs2', 'storeimm']
		proc.pc+=4;
		return 0;
	}
};
