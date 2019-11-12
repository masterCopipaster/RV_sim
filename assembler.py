# -*- coding: utf-8 -*-
"""
Created on Tue Nov 12 14:19:54 2019

@author: petrenko.a
"""

import yaml
import sys

sys.stdin = open("test.asm")

file = open("risc-v.yaml")

data = yaml.safe_load(file)
fields = data["fields"]
instructions = data["instructions"]

def gen_bit_mask(msb, lsb):
    res = 0
    for i in range(lsb, msb+1):
        res |= 1 << i
    return res

def gen_bitf(msb, lsb, fromb, tob, val):
    return ((gen_bit_mask(fromb, tob) & val) >> tob) << lsb

def gen_field(field, val):
    res = 0
    for bitf in field["location"]["bits"]:
        res |= gen_bitf(bitf["msb"], bitf["lsb"], bitf["from"], bitf["to"], val)
    return res

def gen_opcode(instr, args):
    res = instr["fixedvalue"]
    for field in instr["fields"]:
        res |= gen_field(fields[field], int(args[instr["fields"].index(field)]))
    return res
    



lines = sys.stdin.readlines()


addr = 0

for line in lines:
    components = line.split()
    args = " ".join(components[1:]).split(",")
    istr = 0
    for instr in instructions:
        if instr["mnemonic"] == components[0]: break
    
    print(addr, format(gen_opcode(instr, args), "08X"))
    addr += 4

