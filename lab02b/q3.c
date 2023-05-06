// Given a set of numbers where all elements occur an even number of times except one number,
// find the odd occurring number. The solution is to XOR all the elements together and 
// the answer will be equal to the odd occurring element. 
#include <stdio.h>

int odd_occuring_num(int test_arr[], int length){
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result ^ test_arr[i];
    }
    return result;
}


int main(){
    int test_arr[] = {12, 12, 14, 90, 14, 14, 14};
    // int test_arr[] = {1,1,2,2,3};
    // int test_arr[] = {4, 4, 5, 5, 5, 6, 6};
    // int test_arr[] =  {0, 0, 0, 0, 0, 0, 1};
    // I have also run it on all the above arrays which are commented and it is working fine

    int length = sizeof(test_arr) / sizeof(test_arr[0]); 
    printf("Number which is occuring odd times is: %d\n", odd_occuring_num(test_arr, length));
    }