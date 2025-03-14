#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/structs.h"
#include "includes/utils.h"

Dec_int* create_dec_int(char* digits){
    int size_dig = strlen(digits);
    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    char* result_digits = (char*) malloc(size_dig * sizeof(char));
    for(int i=0; i< size_dig; i++){
        result_digits[size_dig - 1 - i] = digits[i];
    }
    result->digits = result_digits;
    result->size = size_dig;

    return result;
}

Dec_int* sum_dec_int(Dec_int* x, Dec_int* y){

    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));

    char carry = 0;
    int size_int = size_of_int();

    // Finds largest of the arguments
    Dec_int* max;
    Dec_int* min;
    if (x->size >= y->size){
        max = x;
        min = y;
    }
    else{
        max = y;
        min = x;
    }

    char* buffer = (char*) calloc(max->size+1, sizeof(char));

    // Main calculation
    char total = 0;
    for (int i=0; i < max->size+1; i++){
        if (i<min->size){
            total =
                (x->digits[i] - '0') + (y->digits[i] - '0') + carry;
            buffer[i] = total % 10 + '0';
            carry = total/10;
        }
        else if(i<max->size){
            total =
                (max->digits[i]-'0') + carry;
            buffer[i] = total % 10 + '0';
            carry = total/10;
        }
        else{
            buffer[max->size] = carry + '0';
        }
    }

    if(buffer[max->size]=='0'){
        result->size = max->size;
        char* result_digits = (char*) calloc(max->size, sizeof(char));
        for(int i=0; i<max->size; i++){
            result_digits[i] = buffer[i];
        }
        result->digits = result_digits;
        free(buffer);
    }
    else{
        result->size = max->size + 1;
        result->digits = buffer;
    }

    return result;
}

// IN PROGRESS
/* Dec_int* sub_dec_int(Dec_int* x, Dec_int* y){ */
/*  */
/*     Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int)); */
/*  */
/*     char carry = 0; */
/*     int size_int = size_of_int(); */
/*  */
/*     // Finds largest of the arguments */
/*     Dec_int* max; */
/*     Dec_int* min; */
/*     if (x->size >= y->size){ */
/*         max = x; */
/*         min = y; */
/*     } */
/*     else{ */
/*         max = y; */
/*         min = x; */
/*     } */
/*  */
/*     char* buffer_x = (char*) calloc(max->size+1, sizeof(char)); */
/*     char* buffer_y = (char*) calloc(max->size+1, sizeof(char)); */
/*     char* buffer_res = (char*) calloc(max->size+1, sizeof(char)); */
/*  */
/*     // Main calculation */
/*     char total = 0; */
/*     for (int i=0; i < max->size+1; i++){ */
/*         if (i<min->size){ */
/*             total = */
/*                 (x->digits[i] - '0') + (y->digits[i] - '0') + carry; */
/*             buffer[i] = total % 10 + '0'; */
/*             carry = total/10; */
/*         } */
/*         else if(i<max->size){ */
/*             total = */
/*                 (max->digits[i]-'0') + carry; */
/*             buffer[i] = total % 10 + '0'; */
/*             carry = total/10; */
/*         } */
/*         else{ */
/*             buffer[max->size] = carry + '0'; */
/*         } */
/*     } */
/*  */
/*     if(buffer[max->size]=='0'){ */
/*         result->size = max->size; */
/*         char* result_digits = (char*) calloc(max->size, sizeof(char)); */
/*         for(int i=0; i<max->size; i++){ */
/*             result_digits[i] = buffer[i]; */
/*         } */
/*         result->digits = result_digits; */
/*         free(buffer); */
/*     } */
/*     else{ */
/*         result->size = max->size + 1; */
/*         result->digits = buffer; */
/*     } */
/*  */
/*     return result; */
/* } */


int compare_dec(Dec_int* x, Dec_int* y){
    /*******************
    RETURN: 0 if x<y
            1 if x>y,
            2 if equals
    ********************/
 
    // if x has more digits, return early
    if (x->size != y->size){
        return x->size > y->size;
    }

    // else compare digit by digit
    unsigned long int size = x->size;
    for(int i=size-1; i>=0; i--){
        char x_dig = x->digits[i];
        char y_dig = y->digits[i];
        if(x_dig != y_dig){
            return x_dig > y_dig;
        }
    }
    return 2;
}

int is_gt_dec(Dec_int* x, Dec_int* y){
    // Is greater than?
    if(compare_dec(x,y) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_lt_dec(Dec_int* x, Dec_int* y){
    // Is less than?
    if(compare_dec(x,y) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int is_equals_dec(Dec_int* x, Dec_int* y){
    if(compare_dec(x,y) == 2){
        return 1;
    }
    else{
        return 0;
    }
}



char* dec_to_str(Dec_int* numb){
    char* str_buffer = (char*) malloc( ((numb->size)+1) * sizeof(char) );
    str_buffer[numb->size] = '\0';
    for(int i=0; i<numb->size; i++){
        str_buffer[i] = numb->digits[numb->size - 1 - i];
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

void free_dec_int(Dec_int* numb){
    free(numb->digits);
    free(numb);
    numb = NULL;
}
