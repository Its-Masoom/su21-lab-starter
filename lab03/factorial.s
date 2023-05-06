.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    addi s2, x0, 1      # s2 = 1 or fact = 1
    add s3, x0, x0      # s3 = 0 or i = 0
loop:
    beq s3, a0, exit    # while (s3 != a0)  or while (i != n)
    addi s3, s3, 1      # Increment s3 by 1 or i = i + 1
    mul s4, s3, s2      # s4 = s3 * s2      or result = i * fact
    add s2, s4, x0      # s2 = s4           or fact = result
    j loop
exit:
    add a0, s4, x0      # a0 = s4 Notice that a0 contains return value
    jr ra

    