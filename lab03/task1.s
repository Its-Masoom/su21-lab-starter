# C code snippet
# int i, a = 7, b[3];
# for (i = 0; i < 3; i++) {
# b[i] = a + (i * a);
# }
# Convert the C code into equivalent RISC-V assembly code.
# Instructions:
# Use s0 to hold i.
# Use s1 to hold a;
# Use s2 to hold &b i.e base address of b
# Clearly comment on your code

.data
b:  .word 0, 0, 0    # reserve 3 words of memory for b

.text
main:
    addi s0, x0, 0     # s0 = 0 or i = 0
    addi s1, x0, 7     # s1 = 7 or a = 7
    la s2, b           # s2 = &b i.e s2 store the base address of b
    addi t0, x0, 3     # t0 = 3 which represents number of elements in b array

loop:
    beq s0, t0, exit   # if s0 == t0 then exit or if i == 3 then exit
    mul t1, s0, s1     # t1 = s0 * s1 or t1 = i * a
    add t1, s1, t1     # t1 = s1 + t1 or t1 = a + (i * a)
    sw t1, 0(s2)       # store t1 in b[i]
    addi s2, s2, 4     # increment b to point to next element
    addi s0, s0, 1     # increment s0 (loop counter) or i = i + 1
    sw t1, 0(s2)       # store the value of t1 (i.e, a + (i * a)) in s2 
    lw a1, 0(s2)       # load a + (i * a) to s1
    j print            # jump to print label and print ith element

print:
    addi a0, x0, 1     # a0 = 1 means to  print integer when ecall executes
    ecall              # perform the specific operation by looking at the value of a0
    addi a1, x0, '\n'  # load in ascii code for newline
    addi a0, x0, 11    
    ecall              # next element will print in next line not in the same line of previous element
    j loop             # jump to loop label to perform opeartions on next element of array
    
exit:
    addi a0, x0, 10    
    ecall              # terminate program




    












