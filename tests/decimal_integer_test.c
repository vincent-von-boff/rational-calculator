#include <stdio.h>
#include <stdlib.h>
#include "../includes/decimal_integer.h"
#include "include/test_helper.h"

Dec_int* fib(int N){
    if ( N == 1 || N == 2){
        Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
        create_dec_int(result, "1");
        return result;
    }
    if(N<1){
        return NULL;
    }
    int K = N - 2;
    Dec_int fib1;
    create_dec_int(&fib1, "1");
    Dec_int fib2;
    create_dec_int(&fib2, "1");
    Dec_int temp_fib;
    create_dec_int(&temp_fib, "1");

    for(int i=0; i<K; i++){
        Dec_int temp_for_freeing = fib1;
        temp_fib = *sum_dec_int(&fib1, &fib2);
        fib1 = fib2;
        free_dec_dig(&temp_for_freeing);
        fib2 = temp_fib;
    }
    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    memcpy(result, &fib2, sizeof(Dec_int));
    return result;
}

TEST(test_sum_dec_int){
    Dec_int x;
    Dec_int y;
    create_dec_int(&x, "87147587");
    create_dec_int(&y, "98789340");
    Dec_int* result;
    result = sum_dec_int(&x,&y);
    char* expect = "185936927";
    ASSERT_STR_EQ(dec_to_str(result), expect);
}

TEST(fib_test){
    // fib(100)
    char* expect = "354224848179261915075";
    Dec_int* result;
    result = fib(100);
    puts("fib(100)");
    ASSERT_STR_EQ(dec_to_str(result), expect);
    
    expect = "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875";
    result = fib(1000);
    puts("fib(1000)");
    ASSERT_STR_EQ(dec_to_str(result), expect);
}

int test_dec_int(int argc, char** argv){
    // Test comparison
    /* Dec_int cmp_1; */
    /* create_dec_int(&cmp_1, "-82436234769872437"); */
    /* Dec_int cmp_2; */
    /* create_dec_int(&cmp_2, "-82436234769872438"); */
    /*  */
    /* char* is_gt = is_gt_dec(&cmp_1, &cmp_2) ? "Yes" : "No"; */
    /* char* is_lt = is_lt_dec(&cmp_1, &cmp_2) ? "Yes" : "No"; */
    /* char* is_eq = is_equals_dec(&cmp_1, &cmp_2) ? "Yes" : "No"; */
    /*  */
    /* printf("%s > %s ? %s\n", dec_to_str(&cmp_1), */
    /*                          dec_to_str(&cmp_2), */
    /*                          is_gt); */
    /* printf("%s < %s ? %s\n", dec_to_str(&cmp_1), */
    /*                          dec_to_str(&cmp_2), */
    /*                          is_lt); */
    /* printf("%s = %s ? %s\n", dec_to_str(&cmp_1), */
    /*                          dec_to_str(&cmp_2), */
    /*                          is_eq); */

    RUN_TEST(test_sum_dec_int);
    RUN_TEST(fib_test);



    return 0;
}
