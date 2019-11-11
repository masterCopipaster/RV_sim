# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 14:24:52 2019

@author: petrenko.a
"""

import yaml

with open("risc-v.yaml") as file:
    instructions = yaml.safe_load(file)["instructions"]
    for instr in instructions:
        print("class " + instr["mnemonic"] + "_instr : public instruction <be_" + instr["format"] + "_type_enc>")
        print("{")
        print("	public:")
        print("	int execute(proc_state& proc)")
        print("	{")
        print("	//" + str(instr["fields"]))
        print("		proc.pc+=4;")
        print("		return 0;")
        print("	}")
        print("};")
        
