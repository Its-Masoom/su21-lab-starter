# C code
## void dataArray (int num) {
## int i;
## int array[10];
## for ( i=0; i<10; i=i+1)
## array[i] = compare(num, i);
## }
## int compare (int a, int b) {
## if (sub(a, b) >= 0)
## return 1;
## else 
## return 0;
## }
## int sub (int a, int b) {
## return a - b;
## }
# Convert the C code above to the RISC-V assembly language.
# Instructions:
# Use s0 to hold i variable.
# Use a0 to hold num variable. 
# Clearly comment on your code
# Handle stack pointer appropriately. The array is stored on the stack of dataArray function.

.text
main:
    addi a0, x0, 5     # a0 = 5 or num = 5 (Argument that is passed to dataArray function in C code)

dataArray:
    addi s0, x0, 0     # s0 = 0  or i = 0
    addi sp, sp, -40   # allocate stack space for 10 elements of array
    add s1, sp, x0     # storing base address of the array in s1
    addi t0, x0, 10    # t0 = 10 which represents number of elements in dataArray

loop_dataArray:
    beq s0, t0, exit   # if s0 == t0 or if i == 10 then exit 
    jal ra, compare    # jump to compare function, storing the return address to ra
    addi s0, s0, 1     # increment s0 (loop counter) or i = i + 1
    addi s1, s1, 4     # incrementing 4 from the base address of array to point to next element of array
    j loop_dataArray

compare:
    addi sp, sp, -8    # allocate space for return address and a0
    sw ra, 0(sp)       # store return address on stack
    sw a0, 4(sp)       # store a0 on stack
    jal ra, sub        # jump to sub function, storing the return address to ra
    sw a1, 0(s1)       # store the result of compare function to the corresponding index in array
    addi a0, x0, 1     # a0 = 1 means to  print integer when ecall executes
    ecall              # perform the specific operation by looking at the above value of a0
    addi a1, x0, '\n'  # load in ascii code for newline
    addi a0, x0, 11    
    ecall              # perform the specific operation by looking at the above value of a0
    lw a0, 4(sp)       # restore the value of a0 from stack
    lw ra, 0(sp)       # restore return address value from stack
    addi sp, sp, 8     # deallocate space that was created to store return address and a0
    jr ra              # jump to loop_dataArray 3rd instruction

sub:
    sub a1, a0, s0     # a1 = a0 - s0 or a1 = 5 - i
    bge a1, x0, true   # if a1 >= 0 then branch to true
    addi a1, x0, 0     # if a1 < 0 then a1 = 0
    jr ra              # jump to compare's 5th instruction

true:
    addi a1, x0, 1     # a1 = 1 
    jr ra              # jump to compare's 5th instruction

exit:
    addi sp, sp, 40    # deallocate stack space that was assigned to 10 elements of array
    addi a0, x0, 10    
    ecall              # terminate program