//
//  min_unit.c
//  min_unit 
//
//  Attribution: http://www.jera.com/techinfo/jtns/jtn002.html
//  No Copyrite reserved
//
//  Modified by Ashley Coleman
//

#include <string.h>

#define COLOR_RED   "\x1B[31m"
#define COLOR_GRN   "\x1B[32m"
#define COLOR_YEL   "\x1B[33m"
#define COLOR_RESET "\x1B[0m"

#ifndef min_unit_h
#define min_unit_h

#define mu_begin_case(name) \
    do { \
        if (test_cases_run > 0) { \
            printf("\n"); \
        } \
        test_steps_run = 0; \
        test_steps_failed = 0; \
        printf("TESTING " COLOR_YEL name COLOR_RESET ":\n"); \
    } while (0) 

#define mu_end_case(name) \
    do { \
        test_cases_run++; \
        printf("\n\t%d test steps of %d passed\n\n", test_steps_run - test_steps_failed, test_steps_run); \
        if (test_steps_failed > 0) { \
            test_cases_failed++; \
            printf("\t" COLOR_RED "FAILED" COLOR_RESET " " COLOR_YEL name COLOR_RESET "\n"); \
        } else {\
            printf("\t" COLOR_GRN "PASSED" COLOR_RESET " " COLOR_YEL name COLOR_RESET "\n"); \
        } \
    } while (0) 

#define mu_assert_i(message, expected, actual) \
    do { \
        test_steps_run++; \
        printf("\tTEST %i\t", test_steps_run); \
        if (expected != actual) { \
            test_steps_failed++; \
            printf(COLOR_RED "FAILED" COLOR_RESET "\t"); \
        } else {\
            printf(COLOR_GRN "PASSED" COLOR_RESET "\t"); \
        } \
        printf("%s\n", message); \
        if (expected != actual) { \
            printf("\t\tExpected: %d, Recieved: %d\n", expected, actual); \
        } \
    } while (0)

#define mu_assert_c(message, expected, actual) \
    do { \
        test_steps_run++; \
        printf("\tTEST %i\t", test_steps_run); \
        if (expected != actual) { \
            test_steps_failed++; \
            printf(COLOR_RED "FAILED" COLOR_RESET "\t"); \
        } else {\
            printf(COLOR_GRN "PASSED" COLOR_RESET "\t"); \
        } \
        printf("%s\n", message); \
        if (expected != actual) { \
            printf("\t\tExpected: '%c', Recieved: '%c'\n", expected, actual); \
        } \
    } while (0)

#define mu_assert_s(message, expected, actual) \
    do { \
        test_steps_run++; \
        printf("\tTEST %i\t", test_steps_run); \
        int passed = (strcmp(expected, actual) == 0); \
        if (!passed) { \
            test_steps_failed++; \
            printf(COLOR_RED "FAILED" COLOR_RESET "\t"); \
        } else {\
            printf(COLOR_GRN "PASSED" COLOR_RESET "\t"); \
        } \
        printf("%s\n", message); \
        if (!passed) { \
            printf("\t\tExpected: '%s', Recieved: '%s'\n", expected, actual); \
        } \
    } while (0)

#define mu_run(all_tests) \
    do { \
        all_tests(); \
        printf("\n%d tests of %d passed\n", test_cases_run - test_cases_failed, test_cases_run); \
        if (test_cases_failed == 0) { \
            printf("\n" COLOR_GRN "ALL TESTS PASSED\n\n" COLOR_RESET); \
        } else { \
            printf("\n" COLOR_RED "SOME TESTS FAILED\n\n" COLOR_RESET); \
        } \
    } while (0)

int test_steps_run = 0;
int test_steps_failed = 0;

int test_cases_run = 0;
int test_cases_failed = 0;

#endif /* min_unit_h */
