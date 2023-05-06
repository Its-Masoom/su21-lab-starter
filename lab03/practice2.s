.data
b:  .word 5, 8    # h = 5, g = 8

.text
main:
    la s2, b
    lw a1, 0(s2)       # a1 = 5 = h
    lw a2, 4(s2)      # a2 = 8 = g
    bge a1, a2, break1
    li a1, 0
    j print

break1:
    li a2, 0
    mv a1, a2
    j print

print:
    addi a0, x0, 1
    ecall
    j exit

exit:
    addi a0, x0, 10    
    ecall              # terminate program
