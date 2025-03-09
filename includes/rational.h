#ifndef RATIONAL_H
#define RATIONAL_H
#include "integer.h"

//Rational number
typedef struct Rat{
    Int numerator;
    Int denominator;
    // sign: 1 is positive, -1 negative
    int sign;
} Rat;

Rat create_rational(char*);

Rat sum_rational(Rat, Rat);

Rat product_rational(Rat, Rat);

Rat div_rational(Rat, Rat);

char* rational_to_str(Rat);

#endif
