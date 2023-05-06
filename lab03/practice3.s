.data
t2:  .word 0    

.text:
main:
    addi t2, x0, 29
    lw a1, 0(t2)
    addi a0, x0, 1
    ecall

    addi t2, x0, -214
    lw a1, 0(t2)
    addi a0, x0, 1
    ecall


    lui t2, 0xABCDE
    lw a1, 0(t2)
    addi a0, x0, 1
    ecall


    lui t2, 0xEDCBA
    addi t2, t2, 0x123
    lw a1, 0(t2)
    addi a0, x0, 1
    ecall


    # lui t2, 0xEEEED
    # addi t2, t2, 0xEAB
    # lw a1, 0(t2)
    # addi a0, x0, 1
    # ecall

    addi a0, x0, 10    
    ecall              # terminate program
