// An incomplete code is provided with the starting value of the dummy CSR "my_csr"; 
// perform the following steps on it in the *exact* same order:

// a. make the first bit of my_csr equal to 1 (or high)
// b. make the third bit (bit 2) equal to 0
// c. make bits 8 to 15 equal to 0xee
// d. extract bits 12 to 27 of the given ADDRESS and store them in bits 16-31 of the my_csr

// ** Incomplete code **

#include <stdio.h>
#define CSR_VAL 0x8000abcd00001234UL
#define ADDRESS 0x5300f000U
unsigned long int my_csr = CSR_VAL;

int main(void) {

// a. make the first bit of my_csr equal to 1 (or high)
    my_csr = CSR_VAL | 0x1UL;
//   printf("%lx \n", my_csr);

// b. make the third bit (bit 2) equal to 0
//   my_csr = my_csr & 0xFFFFFFFFFFFFFFFBUL;
// As 0xFFFFFFFFFFFFFFFBUL = ~0x4UL so we can use short form
    my_csr = my_csr & ~0x4UL;
//   printf("%lx \n", my_csr);

// c. make bits 8 to 15 equal to 0xee
//   my_csr = (my_csr & 0xFFFFFFFFFFFF00FFUL) | 0x000000000000EE00UL;
// As 0xFFFFFFFFFFFF00FFUL = ~0xFF00UL and 0x000000000000EE00UL = 0xEE00UL so we can use short form
    my_csr = (my_csr & ~0xFF00UL) | 0xEE00UL;
//   printf("%lx \n", my_csr);

// d. extract bits 12 to 27 of the given ADDRESS and store them in bits 16-31 of the my_csr
    unsigned long int extract = (ADDRESS & 0x0FFFF000UL) << 4;
//   printf("%lx \n", extract);
//   my_csr = (my_csr & 0xFFFFFFFF0000FFFFUL)| extract;
// As 0xFFFFFFFF0000FFFFUL = ~0xFFFF0000UL so we can use short form
    my_csr = (my_csr & ~0xFFFF0000UL) | extract;
//   printf("%lx \n", my_csr);

    printf("%lx \n", my_csr);
	return 0;

}
