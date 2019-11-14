addi r3, r0, 1000
lui r1, 1
lui r4, 1000000
;loop
loop:
    add r1, r1, r3
    sw r1, r1, 0	
    bltu r1, r4, loop

jal r0, end
	
func:
    add r1, r2, r1
    jalr r0, r5, 0
    
end:
    ecall 
    