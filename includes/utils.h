#ifndef UTILS_H
#define UTILS_H
#include "structs.h"

int is_digit(char);
int is_valid_number(Rat);
int convert_to_int(char*);
char convert_to_char(int);

Int int_sum(Int,Int);
Int int_product(Int,Int);
Dec_int dec_int_sum(Dec_int,Dec_int);
Dec_int dec_int_product(Dec_int,Dec_int);
Rat sum(Rat, Rat);
Rat product(Rat, Rat);
int size_of_int(void);
int size_of_long_int(void);
Dec_int str_to_dec(char*);
void print_dec(Dec_int);
void print_dec_ln(Dec_int);
void print_int(Int);

#endif
