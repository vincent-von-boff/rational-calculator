#ifndef INTEGER_H
#define INTEGER_H
#include "boolean.h"

// Integer
typedef struct Int{
    long unsigned int* digits;
    long unsigned int size;
    // sign: 1 is positive, -1 negative
    int sign;
} Int;

Int create_integer(char*);

Int sum_integer(Int, Int);

Int sub_integer(Int, Int);

Int product_integer(Int, Int);

Int div_integer(Int, Int);

char* integer_to_str(Int);


#endif
