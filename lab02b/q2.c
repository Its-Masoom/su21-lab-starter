// Program that returns an integer value by using a static inline function
#include <stdio.h>

static inline int multiply (int a, int b){
    int c = a*b;
    return c;
}

int main(){

    printf("The result of Multiplication is: %d", multiply(10,20));
}