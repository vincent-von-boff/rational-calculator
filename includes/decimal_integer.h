#ifndef DECIMAL_INTEGER_H
#define DECIMAL_INTEGER_H

// Integer in decimal form
typedef struct Dec_int{
    char* digits;
    long unsigned int size;
    // sign: 1 is positive, -1 negative
    int sign;
} Dec_int;

Dec_int* create_dec_int(char*);

Dec_int* sum_dec_int(Dec_int*, Dec_int*);

Dec_int* sub_dec_int(Dec_int*, Dec_int*);

Dec_int* prod_dec_int(Dec_int*, Dec_int*);

Dec_int* div_dec_int(Dec_int*, Dec_int*);

char* dec_to_str(Dec_int*);

void free_dec_int(Dec_int*);


#endif
