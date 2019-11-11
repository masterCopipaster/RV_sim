# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 14:24:52 2019

@author: petrenko.a
"""

import yaml
import sys

#f = open('instr_autogen.h', 'w')
#sys.stdout = f

classgen = 0
ifgen = True

try:
    with open("risc-v.yaml") as file:
        instructions = yaml.safe_load(file)["instructions"]
        for instr in instructions:
            if classgen:
                print("class " + instr["mnemonic"] + "_instr : public instruction_" + instr["format"] + "")
                print("{")
                print("	public:")
                print("\t" + instr["mnemonic"] + "_instr(uint32_t opcode):instruction_" + instr["format"] + "(opcode){}")
                print("	int execute(proc_state& proc)")
                print("	{")
                if instr["format"] == "R": print("\t\tproc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];")
                print("	//" + str(instr["fields"]))
                print("		proc.pc+=4;")
                print("		return 0;")
                print("	}")
                print("};")
            if ifgen:   
                print("if((opcode & " + str(instr["fixedmask"]) + ") == " + str(instr["fixedvalue"]) + ") return new " + instr["mnemonic"] + "_instr(opcode); //" + instr["format"])
except:
    pass
    print(str(sys.exc_info()))
#f.close()
        

        
