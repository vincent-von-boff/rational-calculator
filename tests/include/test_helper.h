#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

// Very small test helpers
#define TEST(name) void name()
#define RUN_TEST(name) \
    puts("\n_______________________________________________________________");\
    printf("|\033[1m%s\n\033[0m|\n", #name); name()
#define ASSERT(expr) if (!(expr)) { \
  int failed = 1; \
  printf("|----\033[0;31mFAIL: %s\n\033[0m", #expr); \
} else { \
  int failed = 0; \
  printf("|----\033[0;32mPASS: %s\n\033[0m", #expr); \
}
#define ASSERT_STR_EQ(str1, str2) if (!(strcmp(str1, str2) == 0)) { \
  int failed = 1; \
  printf("|----\033[0;31mFAIL: %s != %s\n\033[0m", str1, str2); \
} else { \
  int failed = 0; \
  printf("|----\033[0;32mPASS: %s == %s\n\033[0m", str1, str2); \
}
// End of test helpers

int test_dec_int(int, char**);

#endif
