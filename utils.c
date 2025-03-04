#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_of_int(void){
    int size = 1;
    int base = 256;
    int factor = 256;
    while (base != 0){
        base *= factor;
        size++;
    }
    return size;
}

int size_of_long_int(void){
    int size = 1;
    long int base = 256;
    int factor = 256;
    while (base != 0){
        base *= factor;
        size++;
    }
    return size;
}
int convert_to_int(char* digits){

}

Int int_sum(Int x, Int y){
    Int result;

    long unsigned int carry = 0;
    long unsigned int size_long = size_of_long_int();
    long unsigned int abs_size_long = 0;
    for (int i=0; i<size_long/2;i++){
        abs_size_long += 8;
    }

    long unsigned int max;
    if (x.size >= y.size){
        max = x.size;
    }
    else{
        max = y.size;
    }

    long unsigned int* buffer =
        (long unsigned int*) calloc(3*max, size_long);
    memcpy(buffer, x.digits, x.size*size_long);
    memcpy(buffer + max, y.digits, y.size*size_long);
    for (int j=0; j<3*max;j++){
        printf("Debug calloc: %d, %lx\n", j, buffer[j]);
    }

    long unsigned int filter = 1;
    for (int k=0; k < size_long/2; k++){
        filter *= 256;
    }
    filter -= 1;

    for (int i=0; i < max; i++){
        long unsigned int total =
            buffer[i] + buffer[max + i] + carry;
        printf("Debug total: i=%d, total=%lx\n", i, total);
        buffer[2*max + i] = total & filter;
        carry = total >> (abs_size_long);
        printf("Debug carry: i=%d, carry=%lx\n", i, carry);
    }


    long unsigned int* result_digits;

    if(carry!=0){
        result_digits = (long unsigned int*) malloc((max+1)*size_long);
        memcpy(result_digits, buffer + 2*max, max*size_long);
        result_digits[max] = carry;
        result.size = max + 1;
    }
    else{
        result_digits = (long unsigned int*) malloc((max)*size_long);
        memcpy(result_digits, buffer + 2*max, max*size_long);
        result.size = max;
    }
    result.digits = result_digits;

    free(buffer);

    return result;
}

Dec_int dec_int_sum(Dec_int x, Dec_int y){
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

Dec_int str_to_dec(char* digits){
    int size_dig = strlen(digits);
    Dec_int result;
    char* result_digits = (char*) malloc(size_dig);
    for(int i=0; i< size_dig; i++){
        result_digits[size_dig - 1 - i] = digits[i];
    }
    result.digits = result_digits;
    result.size = size_dig;

    return result;
}

void print_dec(Dec_int x){
    for(int i=0; i < x.size; i++){
        printf("%c", x.digits[x.size - 1 - i]);
    }
}

void print_dec_ln(Dec_int x){
    for(int i=0; i < x.size; i++){
        printf("%c", x.digits[x.size - 1 - i]);
    }
    printf("\n");
}

void print_int(Int x){
    for(int i=0; i < x.size; i++){
        printf("%lx:", x.digits[x.size - 1 - i]);
    }
}

Rat product(Rat x, Rat y){

}
