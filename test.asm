addi r2, r0, 10
addi r3, r0, 100

jal r5, func
;loop
loop:
	addi r1, r1, 1 	
	blt r1, r3, loop

jal r0, end
	
func:
    add r1, r2, r1
    jalr r0, r5, 0
    
end:
    ecall 
    