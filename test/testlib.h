#ifndef __TESTLIB_H__
#define __TESTLIB_H__

#include <setjmp.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static jmp_buf _testlib_jmp_buf;

#define RUN_AS_TEST(test_case_name) \
    do { \
        int rc = setjmp(_testlib_jmp_buf); \
        if (rc != 0) { \
            printf("TEST %s: FAILED\n", #test_case_name); \
        } else { \
            test_case_name(); \
            printf("TEST %s: PASSED\n", #test_case_name); \
        } \
    } while (0)

#define REQUIRE(expr) \
    do { \
        if (!(expr)) { \
            printf("%s:%d (in %s) ASSERTION FAILED\n", __FILE__, __LINE__, __func__); \
            printf("    what: %s\n", #expr); \
            longjmp(_testlib_jmp_buf, 1); \
        } \
    } while (0)

#define REQUIRE_EQ(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            printf("%s:%d (in %s) ASSERTION FAILED\n", __FILE__, __LINE__, __func__); \
            printf("    expected: %ld (0x%lx)\n", (int64_t)(expected), (int64_t)(expected)); \
            printf("      actual: %ld (0x%lx)\n", (int64_t)(actual), (int64_t)(actual)); \
            longjmp(_testlib_jmp_buf, 1); \
        } \
    } while (0)

#define REQUIRE_EQFLT(expected, actual, margin) \
    do { \
        double delta = fabs((expected) - (actual)); \
        if (delta > (margin)) { \
            printf("%s:%d (in %s) ASSERTION FAILED\n", __FILE__, __LINE__, __func__); \
            printf("    expected: %lf\n", (double)(expected)); \
            printf("      actual: %lf\n", (double)(actual)); \
            printf("       delta: %lf (margin=%lf)\n", (delta), (double)(margin)); \
            longjmp(_testlib_jmp_buf, 1); \
        } \
    } while (0)


#define TEST_SUCCESS() printf("%s:%s: PASSED\n", __FILE__, __func__)

#endif
