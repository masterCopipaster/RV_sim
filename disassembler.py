# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 13:04:59 2019

@author: petrenko.a
"""

import yaml
import sys

sys.stdin = open("test.myhex")

file = open("risc-v.yaml")

data = yaml.safe_load(file)
fields = data["fields"]
instructions = data["instructions"]

lines = sys.stdin.readlines()

for line in lines:
    components = line.strip().split()
    try:
        addr, opcode = int(components[0], 16), int(components[1], 16)
        for instruction in instructions:
            if instruction["fixedvalue"] == instruction["fixedmask"] & opcode:
                print(format(addr, "X"),  instruction["mnemonic"])
                break
        else:
            print("instruction not detected")
    except:
        if components[0] == "EP:":
            print(line)