#include <stdio.h>
#include <string.h>
#include "test.h"
#include "utils.h"

int main(int x, char** y){
    fn_test();
    unsigned int temp = 1;
    /* for (int i=0; i < 40; i++){ */
    /*     printf("%d: %u\n", i, temp); */
    /*     temp *= 2; */
    /* } */
    int size = size_of_int();
    int size_long_int = size_of_long_int();
    printf("Size of int: %d\n", size);
    printf("Size of long int: %d\n", size_long_int);
    long unsigned int test_over = 1;
    for(int i = 0; i < size/2; i++){
        test_over *= 256;
    }
    printf("Test overflow: %lu\n", test_over);
    printf("Test overflow 2: %lu\n", (test_over - 1)*(test_over - 1));
    int div_test = 17/2;
    printf("Int div test: %d\n", div_test);
    printf("\n");

    // Test of inputs
    for (int i=0; i < x; i++){
        printf("Input test[%d]: %s\n", i, y[i]);
        printf("String size[%d]: %ld\n", i, strlen(y[i]));
    }
    printf("Input size test: %d\n", x);
    printf("\n");

    // Test of Rat struct
    /* Rat test_rat; */
    /* long unsigned int num[2] = {1 , 7}; */
    /* test_rat.numerator = num; */
    /* printf("Rat test: %lu\n", test_rat.numerator[0]); */
    /* printf("Rat test: %lu\n", test_rat.numerator[1]); */
    printf("\n");

    //Test of ascii to int conversion
    int test_aoit = '7' - '0';
    char test_itoa = test_aoit + '0';
    /* long unsigned int test_aoit_2 = '8' - '0'; */
    /* int counter = 0; */

    /* printf("atoi test: %lu\n", test_aoit + test_aoit_2); */
    printf("itoa test: %c\n", test_itoa);
    /* while(1){ */
    /*     long unsigned int temp = test_aoit + test_aoit + 2; */  
    /*     if(temp < test_aoit || counter > 75){ */
    /*         break; */
    /*     } */
    /*     test_aoit = temp; */
    /*     printf("while loop aoit at %d: %ld\n", counter, test_aoit); */
    /*     counter++; */
    /* } */
    printf("\n");

    //Test of int to long casting and arithmetic
    unsigned int test_size_1 = 2;
    unsigned int test_size_2 = 4;
    long unsigned int test_long_1 = test_size_1;
    long unsigned int test_long_2 = test_size_2;
    long unsigned int test_long = (test_long_1 << 32) + test_long_2;
    printf("test_long_1: %lx\n", test_long_1 << 32);
    printf("test_long_2: %lx\n", test_long_2);
    long unsigned int base = 65536;
    long unsigned int zeroes = base*base-1;
    printf("Zeroes: %lx\n", zeroes);
    test_long = test_long & zeroes;
    printf("Int to long size test: %lx\n", test_long);
    printf("\n");


    Int number_1;
    Int number_2;
    long unsigned int fff = 65536;
    fff = fff*fff-1;
    long unsigned int digits_1[1] = {1};
    long unsigned int digits_2[4] = {fff, fff, fff, fff};
    number_1.digits= digits_1;
    number_1.size = 1;
    number_2.digits= digits_2;
    number_2.size = 4;
    Int res = int_sum(number_1, number_2);
    for(int i=0; i < res.size; i++){
        printf("%lx\n", res.digits[i]);
    }
    printf("\n");

    //Test modular arithmetic
    int test_mod_1 = 13;

    printf("Test original %d\n", test_mod_1);
    printf("Test mod: %d\n", test_mod_1 % 10);
    printf("Test mod div by 10: %d\n", test_mod_1 / 10);
    printf("Test mod reconstruction: %d\n", (test_mod_1 / 10)*10 +(test_mod_1%10));
    printf("\n");

    // Test dec_int_sum
    Dec_int dec_number_1;
    char numb_1_dig[2] = {'1','5'};
    dec_number_1.digits = numb_1_dig; 
    dec_number_1.size = 2;
    print_dec_ln(dec_number_1);
    Dec_int dec_number_2;
    char numb_2_dig[3] = {'3','7'};
    dec_number_2.digits = numb_2_dig; 
    dec_number_2.size = 2;
    print_dec_ln(dec_number_2);
    Dec_int dec_res = dec_int_sum(dec_number_1, dec_number_2);
    printf("Dec result: ");
    print_dec(dec_res);
    /* for(int i=0; i<dec_res.size; i++){ */
    /*     printf("%c", dec_res.digits[dec_res.size - 1 -i]); */
    /* } */
    printf("\n");

    // Sum inputs test
    if (x>2){
        printf("\n");
        printf("Sum of inputs\n");
        Dec_int test_dec_input_1 = str_to_dec(y[1]);
        Dec_int test_dec_input_2 = str_to_dec(y[2]);
        printf("Arg 1: ");
        print_dec(test_dec_input_1);
        printf("\n");
        printf("Size of arg1: %lu\n", test_dec_input_1.size);
        printf("\n");
        printf("Arg 2: ");
        print_dec(test_dec_input_2);
        printf("\n");
        printf("Size of arg2: %lu\n", test_dec_input_2.size);
        printf("\n");
        printf("\n");
        Dec_int res_input = dec_int_sum(test_dec_input_1, test_dec_input_2);
        printf("Result: ");
        print_dec(res_input);
        printf("\n");
        printf("Size of res: %lu", res_input.size);
        printf("\n");
        printf("\n");
    }

    // Fibonnaci test
    int N = 1000;
    printf("Nth Fibonacci = %d\n", N+2);
    Dec_int fib1 = str_to_dec("1");
    Dec_int fib2 = str_to_dec("1");
    Dec_int temp_fib = str_to_dec("1");
    /* print_dec(fib2); */
    /* printf("\n"); */
    /* print_dec(fib2); */
    /* printf("\n"); */
    for(int i=0; i<N; i++){
        temp_fib = dec_int_sum(fib1, fib2);
        fib1 = fib2;
        fib2 = temp_fib;
        /* print_dec(fib2); */
        /* printf("\n"); */
    }
    print_dec(fib2);
    printf("\n");



    return 85;
}
