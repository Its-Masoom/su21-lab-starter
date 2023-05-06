.import lotsofaccumulators.s

.data
inputarray:     .word   1,2,3,4,5,6,7,0
inputarray_other: .word 0,1,2,3,4,5,6,7,0

TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
# Tests if the given implementation of accumulate is correct.
#Input: a0 contains a pointer to the version of accumulate in question. See lotsofaccumulators.s for more details
#
#
#
#The main function currently runs a simple test that checks if accumulator works on the given input array. All versions of accumulate should pass this.
#Modify the test so that you can catch the bugs in four of the five solutions!
main:
    ## ----------Default Test Condition provided----------
    ## This condition will be passed by all accumulators
    # la a0 inputarray
    # jal accumulatorone      # Replace one with two or three or four or five - > All test will pass 
    # li t0 28
    # beq a0 t0 Pass
    
    # #-----------Test Condition accumulatorone-----------
    # # This condition will only failed by accumulatorone while passed by all other accumulators
    # la a0 inputarray
    # li s0, 10               # Added by me
    # jal accumulatorone
    # li t0, 10               # Added by me
    # bne t0, s0, Fail        # Added by me
    # li t0 28
    # beq a0 t0 Pass

    # # -----------Test Condition accumulatortwo-----------
    # # This condition will only failed by accumulatortwo while passed by all other accumulators
    # addi sp, sp -8          # Added by me
    # la a0 inputarray        
    # li t4, 15               # Added by me
    # li t5, 30               # Added by me
    # sw t4, 0(sp)            # Added by me
    # sw t5, 4(sp)            # Added by me
    # jal accumulatortwo
    # lw t6, 0(sp)            # Added by me
    # lw t0, 4(sp)            # Added by me
    # addi sp, sp, 8          # Added by me
    # bne t4, t6, Fail        # Added by me
    # bne t5, t0, Fail        # Added by me
    # li t0 28
    # beq a0 t0 Pass

    # -----------Test Condition accumulatorfour----------
    # This condition will only failed by accumulatorfour while passed by all other accumulators
    # la a0 inputarray
    # li t2 10                # Added by me
    # jal accumulatorfour
    # li t0 28
    # beq a0 t0 Pass

    # # -----------Test Condition accumulatorfive----------
    # # This condition will only passed by accumulatorfive while failed by all other accumulators
    # la a0 inputarray_other
    # jal accumulatorfive      
    # li t0 28
    # beq a0 t0 Pass

    # -----------Combining all Test Cases----------------
    # This combine condition will only passed by accumulatorfive while failed by all other accumulators
    la a0 inputarray_other
    li s0, 10               # Added by me (for accumulatorone)
    addi sp, sp -8          # Added by me (for accumulatortwo)
    li t4, 15               # Added by me (for accumulatortwo)
    li t5, 30               # Added by me (for accumulatortwo)
    sw t4, 0(sp)            # Added by me (for accumulatortwo)
    sw t5, 4(sp)            # Added by me (for accumulatortwo)
    li t2 10                # Added by me (for accumulatorfour)
    jal accumulatorfive 
    li t0, 10               # Added by me (for accumulatorone)
    bne t0, s0, Fail        # Added by me (for accumulatorone)  
    lw t6, 0(sp)            # Added by me (for accumulatortwo)
    lw t0, 4(sp)            # Added by me (for accumulatortwo)
    addi sp, sp, 8          # Added by me (for accumulatortwo)
    bne t4, t6, Fail        # Added by me (for accumulatortwo)
    bne t5, t0, Fail        # Added by me (for accumulatortwo)
    li t0 28
    beq a0 t0 Pass

Fail:
    la a0 TestFailed
    jal print_string
    j End
Pass:
    la a0 TestPassed
    jal print_string
End:
    jal exit

print_int:
	mv a1 a0
    li a0 1
    ecall
    jr ra
    
print_string:
	mv a1 a0
    li a0 4
    ecall
    jr ra
    
exit:
    li a0 10
    ecall