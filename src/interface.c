#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "interface.h"
#include "io.h"

algorithm_option_t interface_select_algorithm(void) {
    puts("Hello and welcome to benchsort!");
    puts("> Choose the algorithm (or an option) to make the benchmark:");
    puts("1-Insertion Sort");
    puts("2-Selection Sort");
    puts("3-Bubble Sort");
    puts("4-Shell sort");
    puts("5-Exit");

    int option_selected;
    printf("• Choose your option: ");
    scanf("%d", &option_selected);

    return (algorithm_option_t) option_selected-1;
}

generated_shape_option_t interface_select_shape(void) {
    puts("> Now choose a way (or an option) in which the instances will be generated:");
    puts("1-Random numbers");
    puts("2-Growing numbers");
    puts("3-Decreasing numbers");
    puts("4-Back to previous menu");

    int option_selected;
    printf("• Choose your option: ");
    scanf("%d", &option_selected);

    return (generated_shape_option_t) option_selected-1;
}

option_size_t interface_select_size(void) {
    puts("> Finally, choose the size (or an option) for the generated instances:");
    puts("1-Size 10");
    puts("2-Size 100");
    puts("3-Size 1.000");
    puts("4-Size 10.000");
    puts("5-Size 100.000");
    puts("6-Size 1.000.000");
    puts("7-Back to previous menu");

    int option_selected;
    printf("• Choose your option: ");
    scanf("%d", &option_selected);

    return (option_size_t) option_selected-1;
}

void interface_invalid_option(const int option_selected) {
    fprintf(stderr, "> Error: Typed option (%d) is invalid!\n", option_selected+1);
}

void print_error_exit(char *message) {
    fprintf(stderr, "> Error: Something unexpected happened (%s).\n", message);
    exit(EXIT_FAILURE);
}

void interface_benchmark(generated_shape_option_t shape, option_size_t size, algorithm_option_t algorithm) {
    puts("> Generating the input.");
    generate_input(shape, size);
    puts("> Generating the output (benchmark).");
    generate_output(shape, size, algorithm);
    puts("> End of benchmark.");
}