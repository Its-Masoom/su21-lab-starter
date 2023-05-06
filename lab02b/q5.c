// Complete the function given below that swaps the values of two ints. 
// Write a C code that calls the function swap and prints out the values in main()
// before calling the function and after coming out of the function. 

// Note: The values should remain swapped after returning from the function

#include <stdio.h>

void swap(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main() {
    int x = 15;
    int y = 30;
    printf("Before swap x = %d and y = %d\n", x, y);
    // Calling swap function
    swap (&x, &y);
    printf("After  swap x = %d and y = %d\n", x, y);
    return 0;
}
