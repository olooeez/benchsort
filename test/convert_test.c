#include <criterion/criterion.h>

#include "convert.h"

Test(convert, shape_to_string) {
    generated_shape_option_t shape1 = GROWING;
    generated_shape_option_t shape2 = DECREASING;
    generated_shape_option_t shape3 = RANDOM;

    cr_assert_str_eq(shape_to_string(shape1), "crescente");
    cr_assert_str_eq(shape_to_string(shape2), "decrescente");
    cr_assert_str_eq(shape_to_string(shape3), "random");
}

Test(convert, size_to_string) {
    option_size_t size1 = TEN;
    option_size_t size2 = THOUSAND;
    option_size_t size3 = HUNDRED_THOUSAND;

    cr_assert_str_eq(size_to_string(size1), "10");
    cr_assert_str_eq(size_to_string(size2), "1000");
    cr_assert_str_eq(size_to_string(size3), "100000");
}

Test(convert, size_to_integer) {
    option_size_t size1 = TEN;
    option_size_t size2 = THOUSAND;
    option_size_t size3 = HUNDRED_THOUSAND;

    cr_assert_eq(size_to_integer(size1), 10);
    cr_assert_eq(size_to_integer(size2), 1000);
    cr_assert_eq(size_to_integer(size3), 100000);
}
