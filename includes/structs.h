#ifndef STRUCTS_H
#define STRUCTS_H

// Integer
typedef struct Int{
    long unsigned int* digits;
    long unsigned int size;
    // sign: 1 is positive, -1 negative
    int sign;
} Int;

// Integer in decimal form
typedef struct Dec_int{
    char* digits;
    long unsigned int size;
    // sign: 1 is positive, -1 negative
    int sign;
} Dec_int;

//Rational number
typedef struct Rat{
    Int numerator;
    Int denominator;
    // sign: 1 is positive, -1 negative
    int sign;
} Rat;

#endif
