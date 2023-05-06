#include "lib.h"
#include <check.h>

START_TEST(test_evaluate_simple)
{
    char* expr = "2+3*4";
    double expected = 14.0;
    double result = calculator(expr);
    ck_assert_msg(result == expected, "Expected %f, but got %f", expected, result);
}
END_TEST

START_TEST(test_evaluate_with_parentheses)
{
    char* expr = "(2+3)*4";
    double expected = 20.0;
    double result = calculator(expr);
    ck_assert_msg(result == expected, "Expected %f, but got %f", expected, result);
}
END_TEST

START_TEST(test_evaluate_with_exponents)
{
    char* expr = "2^3";
    double expected = 8.0;
    double result = calculator(expr);
    ck_assert_msg(result == expected, "Expected %f, but got %f", expected, result);
}
END_TEST


int main(void)
{
    Suite *s = suite_create("Programing");
    TCase *tc_core = tcase_create("testproga");

    tcase_add_test(tc_core, test_evaluate_simple);
    tcase_add_test(tc_core, test_evaluate_with_parentheses);
    tcase_add_test(tc_core, test_evaluate_with_exponents);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

