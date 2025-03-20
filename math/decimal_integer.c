#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../include/decimal_integer.h"

int create_dec_int(Dec_int* number, char* digits){
    /************
    RETURN:  0 if success,
             1 if empty string
             2 if invalid string
     * *********/

    int size_dig = strlen(digits);
    if (size_dig < 1){
        return 1;
    }

    int result_size = size_dig;
    int result_sign = 1;
    char* buffer = (char*) malloc(size_dig * sizeof(char));
    int pos = 0; //position in string used for lexing

    if (digits[pos] == '-'){
        result_sign = -1;    
        pos++;
        result_size--;
    } 

    //bool to track if initial zeroes have been cropped
    int crop_done = 0;

    for(int i=pos; i< size_dig; i++){
        char dig = digits[i];
        if (isdigit(dig)){
            if (dig == '0' && !crop_done){
                result_size--;
                continue;
            }
            crop_done = 1;
            buffer[size_dig - 1 - i] = digits[i];
        }
        else
            return 2;
    }

    char* result_digits = (char*) malloc(result_size * sizeof(char));
    for(int i=0; i<result_size; i++){
        result_digits[i] = buffer[i];
    }
    number->digits = result_digits;
    number->size = result_size;
    number->sign = result_sign;

    return 0;
}

Dec_int* sum_dec_int_abs(Dec_int* x, Dec_int* y){
    /* Evaluate the sum of the absolute value of two integers */

    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));

    char carry = 0;

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
        result->sign = 1;
        result->size = max->size;
        char* result_digits = (char*) calloc(max->size, sizeof(char));
        for(int i=0; i<max->size; i++){
            result_digits[i] = buffer[i];
        }
        result->digits = result_digits;
        free(buffer);
    }
    else{
        result->sign = 1;
        result->size = max->size + 1;
        result->digits = buffer;
    }

    return result;
}

Dec_int* sum_dec_int(Dec_int* x, Dec_int* y){
    /* Evaluate the sum of two integers */

    int x_sign = x->sign;
    int y_sign = y->sign;
    if(x_sign == y_sign){
        Dec_int* result = sum_dec_int_abs(x,y);
        result->sign = x_sign;
        return result;
    }
    if(x_sign != y_sign){
        if(x_sign==1){
            Dec_int* result = sub_dec_int_abs(x,y);
            return result;
        }
        if(x_sign==-1){
            Dec_int* result = sub_dec_int_abs(y,x);
            return result;
        }
    }
    return NULL;
}

Dec_int* sub_dec_int_abs(Dec_int* x, Dec_int* y){
    // Subtracts two positive integers.

    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    char* result_digits;

    int sign = -1;
    
    // Finds largest of the arguments
    Dec_int* max;
    Dec_int* min;
    if (is_gt_dec(x,y)){
        max = x;
        min = y;
        sign = 1;
    }
    else if(is_lt_dec(x,y)){
        max = y;
        min = x;
        sign = -1;
    }
    else if (is_equals_dec(x,y)){
        //if equal, exit early
        result_digits = (char*) malloc(sizeof(char));
        result_digits[0] = '0';
        result->digits = result_digits;
        result->size=1;
        result->sign=1;
        return result;
    }
    else{
        return NULL;
    }

    char* buffer = (char*) calloc(max->size, sizeof(char));

    // Start calculation
    char total = 0;
    char debt = 0;

    //Count zeros dangling on the left:
    //starts at 0; get incremented every time the total is zero
    //gets reset every time it encounters a non-zero total
    long unsigned int count = 0;

    for (long unsigned int i=0; i < max->size; i++){
        char max_dig = max->digits[i] - '0';
        char min_dig = min->digits[i] - '0';

        // Check if there was a previous borrow
        if(debt==1 && max_dig==0){
            max_dig += 9;
        }
        if(debt==1 && max_dig!=0){
            max_dig -= 1;
            debt = 0;
        }

        // Main calculation
        if(max_dig>=min_dig){
            total = max_dig - min_dig;
            buffer[i] = total + '0';
        }
        else{
            char ten = 10;
            total = ten + max_dig - min_dig;
            buffer[i] = total + '0';
            debt = 1;
            }
        count = (total == 0) ? count + 1 : 0;
    }

    
    //Allocation
    long unsigned int result_size = max->size - count;
    result_digits = (char*) calloc(result_size, sizeof(char));
    for(long unsigned int i=0; i<result_size; i++){
        result_digits[i] = buffer[i];
    }
    result->digits = result_digits;
    result->size = result_size;
    result->sign = sign;
    free(buffer);

    return result;
}

Dec_int* sub_dec_int(Dec_int* x, Dec_int* y){
    // Subtracts two positive integers.

    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    char* result_digits;

    int sign = -1;
    
    // Finds largest of the arguments
    Dec_int* max;
    Dec_int* min;
    if (is_gt_dec(x,y)){
        max = x;
        min = y;
        sign = 1;
    }
    else if(is_lt_dec(x,y)){
        max = y;
        min = x;
        sign = -1;
    }
    else if (is_equals_dec(x,y)){
        //if equal, exit early
        result_digits = (char*) malloc(sizeof(char));
        result_digits[0] = '0';
        result->digits = result_digits;
        result->size=1;
        result->sign=1;
        return result;
    }
    else{
        return NULL;
    }

    char* buffer = (char*) calloc(max->size, sizeof(char));

    // Start calculation
    char total = 0;
    char debt = 0;

    //Count zeros dangling on the left:
    //starts at 0; get incremented every time the total is zero
    //gets reset every time it encounters a non-zero total
    long unsigned int count = 0;

    for (long unsigned int i=0; i < max->size; i++){
        char max_dig = max->digits[i] - '0';
        char min_dig = min->digits[i] - '0';

        // Check if there was a previous borrow
        if(debt==1 && max_dig==0){
            max_dig += 9;
        }
        if(debt==1 && max_dig!=0){
            max_dig -= 1;
            debt = 0;
        }

        // Main calculation
        if(max_dig>=min_dig){
            total = max_dig - min_dig;
            buffer[i] = total + '0';
        }
        else{
            char ten = 10;
            total = ten + max_dig - min_dig;
            buffer[i] = total + '0';
            debt = 1;
            }
        count = (total == 0) ? count + 1 : 0;
    }

    
    //Allocation
    long unsigned int result_size = max->size - count;
    result_digits = (char*) calloc(result_size, sizeof(char));
    for(long unsigned int i=0; i<result_size; i++){
        result_digits[i] = buffer[i];
    }
    result->digits = result_digits;
    result->size = result_size;
    result->sign = sign;
    free(buffer);

    return result;
}


Dec_int* prod_dec_int(Dec_int* x, Dec_int* y){
    // Product of two positive integers.

    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    char* result_digits;

    int sign = -1;
    
    // Finds largest of the arguments
    Dec_int* max;
    Dec_int* min;
    if (is_gt_dec(x,y)){
        max = x;
        min = y;
        sign = 1;
    }
    else if(is_lt_dec(x,y)){
        max = y;
        min = x;
        sign = -1;
    }
    else if (is_equals_dec(x,y)){
        //if equal, exit early
        result_digits = (char*) malloc(sizeof(char));
        result_digits[0] = '0';
        result->digits = result_digits;
        result->size=1;
        result->sign=1;
        return result;
    }
    else{
        return NULL;
    }

    char* buffer = (char*) calloc(max->size, sizeof(char));

    // Start calculation
    char total = 0;
    char debt = 0;

    //Count zeros dangling on the left:
    //starts at 0; get incremented every time the total is zero
    //gets reset every time it encounters a non-zero total
    long unsigned int count = 0;

    for (long unsigned int i=0; i < max->size; i++){
        char max_dig = max->digits[i] - '0';
        char min_dig = min->digits[i] - '0';

        // Check if there was a previous borrow
        if(debt==1 && max_dig==0){
            max_dig += 9;
        }
        if(debt==1 && max_dig!=0){
            max_dig -= 1;
            debt = 0;
        }

        // Main calculation
        if(max_dig>=min_dig){
            total = max_dig - min_dig;
            buffer[i] = total + '0';
        }
        else{
            char ten = 10;
            total = ten + max_dig - min_dig;
            buffer[i] = total + '0';
            debt = 1;
            }
        count = (total == 0) ? count + 1 : 0;
    }

    
    //Allocation
    long unsigned int result_size = max->size - count;
    result_digits = (char*) calloc(result_size, sizeof(char));
    for(long unsigned int i=0; i<result_size; i++){
        result_digits[i] = buffer[i];
    }
    result->digits = result_digits;
    result->size = result_size;
    result->sign = sign;
    free(buffer);

    return result;
}

int compare_dec(Dec_int* x, Dec_int* y){
    /*******************
    RETURN: 0 if x<y
            1 if x>y,
            2 if equals
    ********************/
    
    // if different signs, return early
    if (x->sign != y->sign){
        return x->sign > y->sign;
    }
    int sign = x->sign;
 
    // if one of them has more digits, return early
    if (x->size != y->size){
        if(sign==1)  return x->size > y->size;
        if(sign==-1) return x->size < y->size;
    }
    unsigned long int size = x->size;

    // else compare digit by digit
    for(int i=size-1; i>=0; i--){
        char x_dig = x->digits[i];
        char y_dig = y->digits[i];
        if(x_dig != y_dig && sign == 1){
            return x_dig > y_dig;
        }
        if(x_dig != y_dig && sign == -1){
            return x_dig < y_dig;
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
    char* str_buffer;
    if (numb->sign == 1){
        str_buffer = (char*) malloc( ((numb->size)+1) * sizeof(char) );
        str_buffer[numb->size] = '\0';
        for(int i=0; i<numb->size; i++){
            str_buffer[i] = numb->digits[numb->size - 1 - i];
        }
    }
    else{
        str_buffer = (char*) malloc( ((numb->size)+2) * sizeof(char) );
        str_buffer[numb->size+1] = '\0';
        str_buffer[0] = '-';
        for(int i=0; i<numb->size; i++){
            str_buffer[i+1] = numb->digits[numb->size - 1 - i];
        }
    }
    
    return str_buffer;
}

void free_dec_dig(Dec_int* numb){
    //free digits of Dec_int struct
    free(numb->digits);
}
