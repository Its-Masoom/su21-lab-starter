#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    // x >> n will right shift x by a factor of n so now we have our required value at 0th bit
    unsigned shift = x >> n;
    // Taking & with 1 give us the value at 0th bit
    unsigned req_bit = shift & 1; 
    return req_bit;
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* YOUR CODE HERE */
    // Firstly there should be zero at the nth bit 
    // So we will create mask on the required bit if n = 2 mask will be 100
    unsigned mask = 1 << n;
    // Taking not(~) because we want the index value of required bit to be 0 and all other indexes value 1
    // if n = 2 we will  have n_mask = 011
    unsigned n_mask = ~mask;
    // if n_mask =     011
    // if *x     = 1001110
    // unset_bit = 1001010
    unsigned unset_bit = n_mask & *x;
    // Shifting v by the value of n so if v = 1 then set_bit = 100 and if v = 0 then set_bit = 000
    unsigned set_bit = v << n;
    // Taking or with unset_bit 
    // 
    *x = unset_bit | set_bit;
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
    // We will create mask on the required bit if n = 2 mask will be 100
    unsigned mask = 1 << n;
    // Taking xor with mask will flip the bit
    // if mask =     100
    // *x      = 1001110
    // xor     = 1001010
    *x = (*x)^mask;
}

