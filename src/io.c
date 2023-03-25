#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "sort.h"
#include "io.h"
#include "convert.h"

#define INPUT_FOLDER_NAME "arquivodeentrada"
#define OUTPUT_FOLDER_NAME "arquivodesaida"
#define OUTPUT_TIME_FOLDER_NAME "arquivodetempo"

typedef enum {
    INPUT,
    OUTPUT,
    TIME
} io_t;

static void create_directory(char *directory_name) {
    errno = 0;

    int error = mkdir(directory_name, S_IRWXU);

    if (error == -1) {
        switch (errno) {
        case EACCES:
            print_error_exit("o diretório pai não permite escrita.");
            break;
        case ENAMETOOLONG:
            print_error_exit("não foi possivel criar uma pasta. Nome muito longo.");
            break;
        case EEXIST:
            break;
        }
    }
}

static void write_input_file(const char *file_name, const int input_size, const generated_shape_option_t shape) {
    if (access(file_name, F_OK) != -1) return;
    
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        print_error_exit("não foi possivel criar o arquivo de input.");
    }

    fprintf(file, "%d\n", input_size);

    const int maximum_random = 999999, minimum_random = 1;

    if (shape == GROWING || shape == DECREASING) {
        int seed = (rand() % (maximum_random - minimum_random + 1)) + minimum_random;

        for (int i = 0; i < input_size; i++) {
            if (shape == GROWING) {
                fprintf(file, "%d\n", ++seed);
            } else {
                fprintf(file, "%d\n", --seed);
            }
        }
    } else if (shape == RANDOM) {
        for (int i = 0; i < input_size; i++) {
            int random_number = (rand() % (maximum_random - minimum_random + 1)) + minimum_random;

            fprintf(file, "%d\n", random_number);
        }
    }

    fclose(file);
}

static int *fill_array_entry(const char *input_file) {
    FILE *input_data = fopen(input_file, "r");
    if (input_data == NULL) {
        print_error_exit("não foi possivel criar o arquivo.");
    }

    int data_size = 0;
    fscanf(input_data, "%d\n", &data_size);

    int *data = (int *) malloc(sizeof(int) * data_size);

    int counter = 0;
    while ((fscanf(input_data, "%d\n", &data[counter])) != EOF) {
        counter++;
    }

    fclose(input_data);

    return data;
}

char *format_file_name(char *source_folder, const generated_shape_option_t shape, const option_size_t size, const io_t mode) {
    char shape_string[13], size_string[8], mode_string[8];

    strcpy(shape_string, shape_to_string(shape));
    strcpy(size_string, size_to_string(size));

    switch (mode) {
    case INPUT:
        strncpy(mode_string, "entrada", 8);
        break;
    case OUTPUT:
        strncpy(mode_string, "saida", 6);
        break;
    case TIME:
        strncpy(mode_string, "tempo", 6);
    }

    char *file_path = (char *) malloc(sizeof(char) * strlen(source_folder) + strlen(shape_string) + strlen(size_string) + 13);

    sprintf(file_path, "%s/%s%s%s.txt", source_folder, mode_string, shape_string, size_string);
    return file_path;
}

void generate_input(const generated_shape_option_t shape, const option_size_t size) {
    srand(time(NULL));

    char *file_path = format_file_name(INPUT_FOLDER_NAME, shape, size, INPUT);

    create_directory(INPUT_FOLDER_NAME);
    write_input_file(file_path, size_to_integer(size), shape);

    free(file_path);
}

void generate_output(const generated_shape_option_t shape, const option_size_t size, algorithm_option_t algorithm) {
    char sort_folder_name[strlen(OUTPUT_FOLDER_NAME) + 11 + strlen(algorithm_to_string(algorithm)) + 1];
    char sort_time_folder_name[strlen(OUTPUT_TIME_FOLDER_NAME) + 11 + strlen(algorithm_to_string(algorithm)) + 1];

    sprintf(sort_folder_name, "%sdoalgoritmo%s", OUTPUT_FOLDER_NAME, algorithm_to_string(algorithm));
    sprintf(sort_time_folder_name, "%sdoalgoritmo%s", OUTPUT_TIME_FOLDER_NAME, algorithm_to_string(algorithm));

    char *output_file_path = format_file_name(sort_folder_name, shape, size, OUTPUT);
    char *output_time_file_path = format_file_name(sort_time_folder_name, shape, size, TIME);
    char *input_file_path = format_file_name(INPUT_FOLDER_NAME, shape, size, INPUT);

    int *data = fill_array_entry(input_file_path);

    clock_t begin = clock();

    switch (algorithm) {
    case INSERTION_SORT:
        insertion_sort(data, size_to_integer(size));
        break;
    case SELECTION_SORT:
        selection_sort(data, size_to_integer(size));
        break;
    case BUBBLE_SORT:
        bubble_sort(data, size_to_integer(size));
        break;
    case SHELL_SORT:
        shell_sort(data, size_to_integer(size));
        break;
    default:
        break;
    }

    clock_t end = clock();

    double time = (double) (end - begin) / CLOCKS_PER_SEC;

    create_directory(sort_folder_name);
    create_directory(sort_time_folder_name);

    FILE *output_file = fopen(output_time_file_path, "w");

    fprintf(output_file, "%.5lf\n", time);

    fclose(output_file);

    output_file = fopen(output_file_path, "w");

    for (int i = 0; i < size_to_integer(size); i++) {
        fprintf(output_file, "%d\n", data[i]);
    }

    fclose(output_file);

    free(output_file_path);
    free(input_file_path);
    free(data);
}