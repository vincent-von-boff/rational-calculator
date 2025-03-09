#include <stdlib.h>
#include <string.h>
#include "includes/utils.h"

Dec_int create_dec_int(char* digits){
    int size_dig = strlen(digits);
    Dec_int result;
    char* result_digits = (char*) malloc(size_dig * sizeof(char));
    for(int i=0; i< size_dig; i++){
        result_digits[size_dig - 1 - i] = digits[i];
    }
    result.digits = result_digits;
    result.size = size_dig;

    return result;
}

Dec_int sum_dec_int(Dec_int x, Dec_int y){

    Dec_int result;

    int carry = 0;
    int size_int = size_of_int();

    // Finds largest of the arguments
    long unsigned int max;
    if (x.size >= y.size){
        max = x.size;
    }
    else{
        max = y.size;
    }

    int* buffer =
        (int*) calloc(3*(max+1), size_int);
    for(int i=0; i<x.size; i++){
        int temp;
        temp = x.digits[i] - '0';
        buffer[i] = temp;
    }
    for(int i=0; i<y.size; i++){
        int temp;
        temp = y.digits[i] - '0';
        buffer[(max+1) + i] = temp;
    }
    /* for (int j=0; j<3*max;j++){ */
    /*     printf("Debug calloc: %d, %x\n", j, buffer[j]); */
    /* } */

    // Main calculation
    for (int i=0; i < max+1; i++){
        int total =
            buffer[i] + buffer[(max+1) + i] + carry;
        /* printf("Debug total: i=%d, total=%x\n", i, total); */
        buffer[2*(max+1) + i] = total % 10;
        carry = total/10;
        /* printf("Debug carry: i=%d, carry=%x\n", i, carry); */
    }

    char* result_digits = (char*) calloc(max+1,1);
    
    for(int i=0; i<max+1; i++){
        char temp = buffer[2*(max+1) + i] + '0';
        result_digits[i] = temp;
    }

    result.digits = result_digits;
    result.size = max;
    if(result.digits[max]!='0'){
        result.size++;
    }

    free(buffer);

    return result;
}


char* dec_to_str(Dec_int numb){
    char* str_buffer = malloc( (numb.size+1) * sizeof(char) );
    str_buffer[numb.size] = '\0';
    for(int i=0; i<numb.size; i++){
        str_buffer[i] = numb.digits[numb.size - 1 - i];
    }
    
    return str_buffer;
}

/* void print_dec(Dec_int x){ */
/*     for(int i=0; i < x.size; i++){ */
/*         printf("%c", x.digits[x.size - 1 - i]); */
/*     } */
/* } */
/*  */
/* void print_dec_ln(Dec_int x){ */
/*     for(int i=0; i < x.size; i++){ */
/*         printf("%c", x.digits[x.size - 1 - i]); */
/*     } */
/*     printf("\n"); */
/* } */

void free_dec_int(Dec_int numb){
    free(numb.digits);
}
