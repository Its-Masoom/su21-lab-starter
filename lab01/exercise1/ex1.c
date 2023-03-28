#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
 int count = 0;
    while (*str != '\0') {
        if (*str == letter) {
            count++;
        }
        str++;
    }
    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    int i = 0;
    int count_A = 0, count_C = 0, count_G = 0, count_T = 0;
    
    while(dna_seq->sequence[i] != '\0') {
        switch(dna_seq->sequence[i]) {
            case 'A':
                count_A++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
            case 'T':
                count_T++;
                break;
            default:
                break;
        }
        i++;
    }
    
    dna_seq->A_count = count_A;
    dna_seq->C_count = count_C;
    dna_seq->G_count = count_G;
    dna_seq->T_count = count_T;   
    return;
}
