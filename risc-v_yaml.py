# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 14:24:52 2019

@author: petrenko.a
"""

import yaml

with open("risc-v.yaml") as file:
    instructions = yaml.safe_load(file)["instructions"]
    for instr in instructions:
        print(instr)