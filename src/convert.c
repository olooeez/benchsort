#include <stdlib.h>

#include "convert.h"

char *shape_to_string(const generated_shape_option_t shape) {
    switch (shape) {
    case GROWING:
        return "crescente";
    case DECREASING:
        return "decrescente";
    case RANDOM:
        return "random";
    default:
        break;
    }

    return NULL;
}

char *size_to_string(const option_size_t size) {
    switch (size) {
    case TEN:
        return "10";
    case HUNDRED:
        return "100";
    case THOUSAND:
        return "1000";
    case TEN_THOUSAND:
        return "10000";
    case HUNDRED_THOUSAND:
        return "100000";
    case A_MILLION:
        return "1000000";
    default:
        break;
    }

    return NULL;
}

int size_to_integer(const option_size_t size) {
    int return_size = atoi(size_to_string(size));

    if (return_size == 0) {
        print_error_exit("não foi possivel converter o tamanho dos dados");
    }

    return return_size;
}

char *algorithm_to_string(const algorithm_option_t algorithm) {
    switch (algorithm) {
    case INSERTION_SORT:
        return "insertion";
    case SELECTION_SORT:
        return "selection";
    case BUBBLE_SORT:
        return "bubble";
    case SHELL_SORT:
        return "shell";
    default:
        break;
    }

    return NULL;
}