#include <stdio.h>
#include <stdlib.h>
#include "../include/decimal_integer.h"
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
        temp_fib = *sum_dec_int_abs(&fib1, &fib2);
        fib1 = fib2;
        free_dec_dig(&temp_for_freeing);
        fib2 = temp_fib;
    }
    Dec_int* result = (Dec_int*) malloc(sizeof(Dec_int));
    memcpy(result, &fib2, sizeof(Dec_int));
    return result;
}

TEST(test_order){
    Dec_int x;
    Dec_int y;
    int is_eq;
    int is_gt;
    int is_lt;
    char* arg1;
    char* arg2;
    int true;

    arg1 = "-1111111";
    arg2 = "-1111111";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    is_eq = is_equals_dec(&x,&y);
    is_gt = is_gt_dec(&x,&y);
    is_lt = is_lt_dec(&x,&y);
    true = 1;
    printf("|--Testing if %s == %s:\n", arg1, arg2);
    ASSERT(is_eq == true);
    ASSERT(is_gt != true);
    ASSERT(is_lt != true);
    puts("|\n|");

    arg1 = "-111111111";
    arg2 = "-1111111";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    is_eq = is_equals_dec(&x,&y);
    is_gt = is_gt_dec(&x,&y);
    is_lt = is_lt_dec(&x,&y);
    true = 1;
    printf("|--Testing if %s == %s:\n", arg1, arg2);
    ASSERT(is_eq != true);
    ASSERT(is_gt != true);
    ASSERT(is_lt == true);
    }

TEST(test_sum_dec_int_abs){
    Dec_int x;
    Dec_int y;
    Dec_int* result;
    char* arg1;
    char* arg2;
    char* expect;

    arg1 = "87147587";
    arg2 = "98789340";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    result = sum_dec_int_abs(&x,&y);
    expect = "185936927";
    printf("|--Testing %s + %s:\n", arg1, arg2);
    ASSERT_STR_EQ(dec_to_str(result), expect);
    }

TEST(test_sub_dec_int_abs){
    Dec_int x;
    Dec_int y;
    Dec_int* result;
    char* arg1;
    char* arg2;
    char* expect;

    arg1 = "87147587";
    arg2 = "98789340";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    result = sub_dec_int_abs(&x,&y);
    expect = "-11641753";
    printf("|--Testing %s - %s:\n", arg1, arg2);
    ASSERT_STR_EQ(dec_to_str(result), expect);
    puts("|\n");

    arg1 = "111110001";
    arg2 = "111110002";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    result = sub_dec_int_abs(&x,&y);
    expect = "-1";
    printf("|--Testing %s - %s:\n", arg1, arg2);
    ASSERT_STR_EQ(dec_to_str(result), expect);
    puts("|\n");

    arg1 = "-1111111";
    arg2 = "-1111111";
    create_dec_int(&x, arg1);
    create_dec_int(&y, arg2);
    result = sub_dec_int_abs(&x,&y);
    expect = "0";
    printf("|--Testing %s - %s:\n", arg1, arg2);
    ASSERT_STR_EQ(dec_to_str(result), expect);
    /* puts("|\n"); */
}

TEST(fib_test){
    // fib(100)
    char* expect = "354224848179261915075";
    Dec_int* result;
    result = fib(100);
    puts("|--Testing fib(100)");
    ASSERT_STR_EQ(dec_to_str(result), expect);
    
    expect = "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875";
    result = fib(1000);
    puts("|--Testing fib(1000)");
    ASSERT_STR_EQ(dec_to_str(result), expect);
}

int test_dec_int(int argc, char** argv){

    RUN_TEST(test_order);
    RUN_TEST(test_sum_dec_int_abs);
    RUN_TEST(test_sub_dec_int_abs);
    RUN_TEST(fib_test);



    return 0;
}
