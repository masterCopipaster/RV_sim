# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 14:24:52 2019

@author: petrenko.a
"""

import yaml
import sys

f = open('instr_autogen.h', 'w')
sys.stdout = f

try:
    with open("risc-v.yaml") as file:
        instructions = yaml.safe_load(file)["instructions"]
        for instr in instructions:
            print("class " + instr["mnemonic"] + "_instr : public instruction_" + instr["format"] + "")
            print("{")
            print("	public:")
            print("\t" + instr["mnemonic"] + "_instr(uint32_t opcode):instruction_" + instr["format"] + "(opcode){}")
            print("	int execute(proc_state& proc)")
            print("	{")
            print("	//" + str(instr["fields"]))
            print("		proc.pc+=4;")
            print("		return 0;")
            print("	}")
            print("};")
except: pass
f.close()
        

        
