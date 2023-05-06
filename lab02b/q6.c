// Complete the function given below that returns the number of bytes in a string. 
// Write a C code that calls the function mystrlen and prints out the number of bytes
// in a string declared in main().

// Note: Do not use strlen.

#include <stdio.h>
#include <string.h>

int mystrlen(char* str) {

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(){
    char my_str[] = "This is my testing string whose bytes I have to find";
    // char my_str[] = "Again, Testing!";
    // Checking Size of a Char
    // printf("Size of a character in bytes is: %ld\n", sizeof(char));
    // Using mystrlen function to check length of string
    printf("Number of bytes in the string is: %d\n", mystrlen(my_str));
    // Using strlen() to cross check the length of string 
    // int length = strlen(my_str);
    // printf("Number of bytes in the string is: %d\n", length);
    return 0;

}



