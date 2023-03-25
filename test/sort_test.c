#include <criterion/criterion.h>

#include "sort.h"

Test(insertion_sort, test_insertion_sort) {
    int data[] = {4, 2, 8, 1, 3, 7, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};

    insertion_sort(data, 8);

    for (int i = 0; i < 8; i++) {
        cr_assert_eq(data[i], expected[i], "Element %d did not sort correctly.", i);
    }
}

Test(selection_sort, test_selection_sort) {
    int data[] = {4, 2, 8, 1, 3, 7, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};

    selection_sort(data, 8);

    for (int i = 0; i < 8; i++) {
        cr_assert_eq(data[i], expected[i], "Element %d did not sort correctly.", i);
    }
}

Test(bubble_sort, test_bubble_sort) {
    int data[] = {4, 2, 8, 1, 3, 7, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};

    bubble_sort(data, 8);

    for (int i = 0; i < 8; i++) {
        cr_assert_eq(data[i], expected[i], "Element %d did not sort correctly.", i);
    }
}

Test(shell_sort, test_shell_sort) {
    int data[] = {4, 2, 8, 1, 3, 7, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};

    shell_sort(data, 8);

    for (int i = 0; i < 8; i++) {
        cr_assert_eq(data[i], expected[i], "Element %d did not sort correctly.", i);
    }
}
