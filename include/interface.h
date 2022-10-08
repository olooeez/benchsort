#ifndef INCLUDE_INTERFACE_H
#define INCLUDE_INTERFACE_H

typedef enum {
    INSERTION_SORT,
    EXIT
} algorithm_option_t;

typedef enum {
    RANDOM,
    GROWING,
    DECREASING,
    ROLLBACK_SHAPE
} generated_shape_option_t;

typedef enum {
    TEN,
    HUNDRED,
    THOUSAND,
    TEN_THOUSAND,
    HUNDRED_THOUSAND,
    A_MILLION,
    ROLLBACK_SIZE
} option_size_t;

algorithm_option_t interface_select_algorithm(void);
generated_shape_option_t interface_select_shape(void);
option_size_t interface_select_size(void);
void interface_invalid_option(const int option_selected);
void print_error_exit(char *message);
void interface_benchmark(generated_shape_option_t shape, option_size_t size);

#endif