# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 13:04:59 2019

@author: petrenko.a
"""

import yaml
import sys

#sys.stdin = open("../tests/test.myhex")

#sys.stdout = open("test.lst", "w")

file = open("pytools/risc-v.yaml")

data = yaml.safe_load(file)
fields = data["fields"]
instructions = data["instructions"]

def gen_bit_mask(msb, lsb):
    res = 0
    for i in range(lsb, msb+1):
        res |= 1 << i
    return res

def extract_bitf(msb, lsb, fromb, tob, val):
    return ((gen_bit_mask(msb, lsb) & val) >> lsb) << tob

def extract_field(field, val):
    res = 0
    for bitf in field["location"]["bits"]:
        res |= extract_bitf(bitf["msb"], bitf["lsb"], bitf["from"], bitf["to"], val)
    return res

def sign_extend(value, bits):
    sign_bit = 1 << (bits - 1)
    return (value & (sign_bit - 1)) - (value & sign_bit)

#lines = sys.stdin.readlines()

#for line in lines:
    #components = line.strip().split()
while 1:
    components = input().strip().split()
    if len(components) == 0: continue
    try:
        addr, opcode = int(components[0], 16), int(components[1], 16)
        for instruction in instructions:
            if instruction["fixedvalue"] == instruction["fixedmask"] & opcode:
                fieldss = ""
                for field in instruction["fields"]:
                    fieldval = extract_field(fields[field], opcode)
                    if field == "jimm20" or field == "imm20":
                        fieldval = sign_extend(fieldval, 20)
                    if field == "bimm" or field == "storeimm" or field == "imm12":
                        fieldval = sign_extend(fieldval, 12)
                    fieldss += fields[field]["name"] + "=" + str(fieldval) + ",\t"
                    
                print(format(addr, "08X"), format(opcode, "08X"), instruction["mnemonic"] + "\t" + fieldss[:-2])
                break
        else:
            print(format(addr, "08X"), format(opcode, "08X"),  "instruction not detected")
    except:
        if components[0] == "EP:":
            print(line)
        else: print("че за херня??", line) 
