#ifndef DECIMAL_INTEGER_H
#define DECIMAL_INTEGER_H

// Integer in decimal form
typedef struct Dec_int{
    char* digits;
    long unsigned int size;
    // sign: 1 is positive, -1 negative
    int sign;
} Dec_int;

int create_dec_int(Dec_int*, char*);

Dec_int* sum_dec_int_abs(Dec_int*, Dec_int*);

Dec_int* sum_dec_int(Dec_int*, Dec_int*);

Dec_int* sub_dec_int(Dec_int*, Dec_int*);

Dec_int* sub_dec_int_abs(Dec_int*, Dec_int*);

Dec_int* dec_int_abs(Dec_int*);

int compare_dec(Dec_int*, Dec_int*);

int is_gt_dec(Dec_int*, Dec_int*);

int is_lt_dec(Dec_int*, Dec_int*);

int is_equals_dec(Dec_int*, Dec_int*);

Dec_int* mul_dig_by_dec_int(char, Dec_int*);

Dec_int* mul_dec_int(Dec_int*, Dec_int*);

Dec_int* create_zero_dec_int();

Dec_int* left_shift_dec_int(Dec_int*, long unsigned int);

Dec_int* right_shift_dec_int(Dec_int*, long unsigned int);

Dec_int* div_dec_int(Dec_int*, Dec_int*);

char* dec_to_str(Dec_int*);

void free_dec_int(Dec_int*);
void free_dec_dig(Dec_int*);


#endif
