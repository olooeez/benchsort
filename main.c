#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "interface.h"
#include "io.h"
#include "convert.h"

int main(void) {
    algorithm_option_t algorithm_selected;

    begin:

    while (true) {
        algorithm_selected = interface_select_algorithm();

        if (algorithm_selected > 5 || algorithm_selected < 0) {
            interface_invalid_option(algorithm_selected);
        } else {
            break;
        }
    }

    if (algorithm_selected == EXIT) {
        puts("Exiting the program. Thanks for using!");
        return EXIT_SUCCESS;
    }

    generated_shape_option_t selected_shape;

    shape:
    while (true) {
        selected_shape = interface_select_shape();

        if (selected_shape > 3 || selected_shape < 0) {
            interface_invalid_option(selected_shape);
        } else {
            break;
        }
    }

    if (selected_shape == ROLLBACK_SHAPE) {
        goto begin;
    }

    option_size_t selected_size;

    while (true) {
        selected_size = interface_select_size();

        if (selected_size > 6 || selected_size < 0) {
            interface_invalid_option(selected_size);
        } else {
            break;
        }
    }

    if (selected_size == ROLLBACK_SIZE) {
        goto shape;
    }

    interface_benchmark(selected_shape, selected_size, algorithm_selected);

    puts("Program completed successfully!");

    return EXIT_SUCCESS;
}