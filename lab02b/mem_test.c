// The purpose of the mem_test is to check different types of loads/stores by writing specific values
// in an array structure and then comparing with the given expected array structure.

// The C file has 5 empty functions i.e. main, store_byte_test, store_half_word_test, store_word_test 
// and store_double_word_test. You have to complete these functions. See example below for details.

// After completing the code, compile it with gcc and run it.

// For example: For store_byte_test function, you have to write (EF, BE, AD, DE, EF, BE, AD, DE) in array 
// store_byte_data in a way that matches its corresponding expected array i.e. store_byte_expected_data. 
// Once the values are written in store_byte_data array, compare the array content with store_byte_expected_data
//  array in the same function and print any mismatches and return pass/fail.

// Note:

// - You should not modify any content in expected data arrays.
// - You cannot use C library functions.
#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEFF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };

// Function to compare expected value with actual value and print whether test passed or failed
void print_status (arr_t *actual, arr_t *expected, int *pass_count, int *fail_count){

   printf("*********** Comparing Actual with Expected Values ***********\n");
   printf("\033[0;96m  Actual Values                                 Expected Values                                    Status\033[0m\n");
   int i = 0;
   while (i < 8){
      if ((actual[i].double_word[0] == expected[i].double_word[0]) && (actual[i].double_word[1] == expected[i].double_word[1])){
         printf("{ 0x%016llx, 0x%016llx }  = { 0x%016llx, 0x%016llx } ......... \033[0;32mTest Passed!\033[0m\n", actual[i].double_word[0], actual[i].double_word[1], expected[i].double_word[0],expected[i].double_word[1]);
         *pass_count = *pass_count + 1;
      }
      else {
         printf("{ 0x%016llx, 0x%016llx } != { 0x%016llx, 0x%016llx } ......... \033[0;31mTest Failed!\033[0m\n", actual[i].double_word[0], actual[i].double_word[1], expected[i].double_word[0],expected[i].double_word[1]);
         *fail_count = *fail_count + 1;
      }
      i++;
   }
}

int store_byte_test (arr_t *actual, arr_t *expected, int *pass_count, int *fail_count) {

   // EF, BE, AD, DE, EF, BE, AD, DE
   unsigned long long arr[] = {0xEFUL, 0xBEUL, 0xADUL, 0xDEUL, 0xEFUL, 0xBEUL, 0xADUL, 0xDEUL};
   int i = 0;
   int j = 8;
   while (i < 8){
      if ((i*j)+8 <= 64){
      actual[i].double_word[0] = arr[i] << (i*j);
      i = i + 1;
      }
      else{
      actual[i].double_word[1] = arr[i] << (i*j); 
      i = i + 1;
      }
   }
   printf("\n");
   printf("\033[0;33m*************** Running store_byte_data Tests ***************\033[0m\n");
   print_status (actual, expected, pass_count, fail_count);

} // store_byte_test


int store_half_word_test (arr_t *actual, arr_t *expected, int *pass_count, int *fail_count) {

   // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
   unsigned long long arr[] = {0xBEEFUL, 0xADBEUL, 0xDEADUL, 0xEFDEUL, 0xBEEFUL, 0xADBEUL, 0xDEADUL, 0xEFDEUL};
   int i = 0;
   int j = 8;
   while (i < 8){
      if ((i*j)+8 < 64){
      actual[i].double_word[0] = arr[i] << (i*j);
      i = i + 1;
      }
      else{
      actual[i].double_word[0] = arr[i] << (i*j); 
      actual[i].double_word[1] = (arr[i] << (j-8)) >> 8; 
      // actual[i].double_word[1] = (arr[i] << (j-8)) >> 0; 
      i = i + 1;
      }
   }
   printf("\n");
   printf("\033[0;33m************* Running store_half_word_data Tests ************\033[0m\n");
   print_status(actual, expected, pass_count, fail_count);

} // store_half_word_test


int store_word_test (arr_t *actual, arr_t *expected, int *pass_count, int *fail_count) {

   // DEADBEEF, F00DC0DE
   unsigned long long arr[] = {0xDEADBEEFUL, 0xF00DC0DEUL};
   int i = 0;
   int j = 8;
   while (i < 8){
      if ((i < 4) && ((i*j)+8 <= 32)){
      actual[i].double_word[0] = 0xDEADBEEFUL << (i*j);
      i = i + 1;
      }
      else if ((i > 4) && ((i*j)+8 <= 32)){
      actual[i].double_word[0] = 0xF00DC0DEUL << (i*j);
      i = i + 1;
      }
      else{
      actual[i].double_word[0] = 0xF00DC0DEUL << (i*j);
      actual[i].double_word[1] = (0xF00DC0DEUL << (j-8)) >> (-8*i) + 64;
      // actual[i].double_word[1] = (0xF00DC0DEUL << (j-8)) >> 0;
      i = i + 1;
      }

   }
   printf("\n");
   printf("\033[0;33m****************** Running store_word Tests *****************\033[0m\n");
   print_status(actual, expected, pass_count, fail_count);

} // store_word_test


int store_double_word_test (arr_t *actual, arr_t *expected, int *pass_count, int *fail_count) {

   // DEADBEEFF00DC0DE
   unsigned long long val = 0xDEADBEEFF00DC0DE;
   int i = 0;
   int j = 8;
   while ( i < 8 ){
      if ((i*j)+8 < 16){
      actual[i].double_word[0] = val << i*j;
      i = i + 1;
      }
      else{
      actual[i].double_word[0] = val << i*j;  
      actual[i].double_word[1] = (val << (j-8)) >> (-8*i) + 64;
      i = i + 1;  
      }
   }
   printf("\n");
   printf("\033[0;33m************** Running store_double_word Tests **************\033[0m\n");
   print_status (actual, expected, pass_count, fail_count);

} // store_double_word_test


int main() {
   int pass_count = 0;
   int fail_count = 0;
   store_byte_test(store_byte_data, store_byte_expected_data, &pass_count, &fail_count);
   store_half_word_test(store_half_word_data, store_half_word_expected_data, &pass_count, &fail_count);
   store_word_test(store_word_data, store_word_expected_data, &pass_count, &fail_count);
   store_double_word_test(store_half_word_data, store_double_word_expected_data, &pass_count, &fail_count);
   printf("\n");
   printf("\033[0;32mNumber of Tests passed are: %d\033[0m\n", pass_count);
   printf("\033[0;31mNumber of Tests failed are: %d\033[0m\n", fail_count);
   printf("\n");
   if (fail_count == 0){
      printf ("\033[38;2;255;215;0mCongratulations! You have passed all the tests!!!\033[0m\n");
   }
   return 0;

} // main
