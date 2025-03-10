#include <stdio.h>
#include "includes/decimal_integer.h"

int main(int argc, char** argv){
    // Sum inputs test
    if (argc > 2){
        printf("\n");
        printf("Sum of inputs\n");
        Dec_int test_dec_input_1 = create_dec_int(argv[1]);
        Dec_int test_dec_input_2 = create_dec_int(argv[2]);
        printf("Arg 1: ");
        printf("%s", dec_to_str(test_dec_input_1));
        printf("\n");
        printf("Size of arg1: %lu\n", test_dec_input_1.size);
        printf("\n");
        printf("Arg 2: ");
        printf("%s", dec_to_str(test_dec_input_2));
        printf("\n");
        printf("Size of arg2: %lu\n", test_dec_input_2.size);
        printf("\n");
        printf("\n");
        Dec_int res_input = sum_dec_int(test_dec_input_1, test_dec_input_2);
        printf("Result: ");
        printf("%s", dec_to_str(res_input));
        printf("\n");
        printf("Size of res: %lu", res_input.size);
        printf("\n");
        printf("\n");
    }

    // Fibonnaci test
    int N = 1000;
    printf("Nth Fibonacci = %d\n", N+2);
    Dec_int fib1 = create_dec_int("1");
    Dec_int fib2 = create_dec_int("1");
    Dec_int temp_fib = create_dec_int("1");
    /* print_dec(fib2); */
    /* printf("\n"); */
    /* print_dec(fib2); */
    /* printf("\n"); */
    for(int i=0; i<N; i++){
        temp_fib = sum_dec_int(fib1, fib2);
        fib1 = fib2;
        fib2 = temp_fib;
        /* print_dec(fib2); */
        /* printf("\n"); */
    }
    printf("%s", dec_to_str(fib2));
    printf("\n");



    return 85;
}
