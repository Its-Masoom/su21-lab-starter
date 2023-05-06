.section ".text", "ax", @progbits
.globl _start
_start:

.data
num:    .word 5        # 5 can be changed to desired number to calculate factorial
result: .word 0        # Initialized result to zero

.text
main:
    la a0, num         # load address of num
    lw a0, 0(a0)       # load value of num i.e 5
    la a2, result      # load the address of result to a2
    jal fact           # jump to fact and store return address to ra
    sw a1, 0(a2)       # store the calculated factorial to result
    j exit             # jump to exit
    
fact:
    addi sp, sp, -8    # decrement stack to store two words
    sw ra, 0(sp)       # store value of ra to stack
    sw s0, 4(sp)       # store value of s0 to stack
    li a1, 1           # load 1 to a1 i.e a1 = 1
    beq a0, x0, done   # a0(num) == 0 then jump to done label
    mv s0, a0          # s0 = a0
    addi a0, a0, -1    # decrement a0(num) by 1
    jal fact           # save the return address and jump back to fact i.e recursion
    mul a1, s0, a1     # a1 = a0 * a1

done:
    lw ra, 0(sp)       # load ra with the current value of sp
    lw s0, 4(sp)       # load ra with the value located at address sp+4
    addi sp, sp, 8     # increment stack or deallocate space
    jr ra              # jump to the return address

exit:
    addi a0, x0, 1     # a0 = 1 means to  print integer when ecall executes
    ecall              # perform the specific operation by looking at the value of a0
    addi a1, x0, '\n'  # load in ascii code for new line
    addi a0, x0, 11    
    ecall
    addi a0, x0, 10    
    ecall              # terminate program
