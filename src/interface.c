#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "interface.h"
#include "io.h"

#define CLEAR_SCREEN system("cls||clear")
#define SLEEP_SCREEN sleep(2.5)

algorithm_option_t interface_select_algorithm(void) {
    CLEAR_SCREEN;
    puts("Olá, seja bem vindo!");
    puts("Escolha abaixo um algoritimo (ou uma opção) para fazer o teste de benchmark:");
    puts("1-Insertion Sort");
    puts("2-Sair");

    int option_selected;
    printf("> ");
    scanf("%d", &option_selected);

    return (algorithm_option_t) option_selected-1;
}

generated_shape_option_t interface_select_shape(void) {
    CLEAR_SCREEN;
    puts("Agora escolha uma forma (ou uma opção) em que serão geradas as instâncias:");
    puts("1-Números randômicos");
    puts("2-Números crescentes");
    puts("3-Números descrescentes");
    puts("4-Voltar para menu anterior");

    int option_selected;
    printf("> ");
    scanf("%d", &option_selected);

    return (generated_shape_option_t) option_selected-1;
}

option_size_t interface_select_size(void) {
    CLEAR_SCREEN;
    puts("Por fim, escolha o tamanho (ou uma opção) para as instâncias geradas:");
    puts("1-Tamanho 10");
    puts("2-Tamanho 100");
    puts("3-Tamanho 1.000");
    puts("4-Tamanho 10.000");
    puts("5-Tamanho 100.000");
    puts("6-Tamanho 1.000.000");
    puts("7-Voltar para menu anterior");

    int option_selected;
    printf("> ");
    scanf("%d", &option_selected);

    return (option_size_t) option_selected-1;
}

void interface_invalid_option(const int option_selected) {
    fprintf(stderr, "Opção digitada (%d) é inválida!\n", option_selected+1);
    fprintf(stderr, "Aperte enter para digitar novamente...\n");
    SLEEP_SCREEN;
}

void print_error_exit(char *message) {
    fprintf(stderr, "Algo inesperado aconteceu...\n");
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void interface_benchmark(generated_shape_option_t shape, option_size_t size) {
    CLEAR_SCREEN;
    puts("Gerando a entrada.");
    generate_input(shape, size);
    puts("Gerando a saida (benchmark).");
    generate_output(shape, size);
    puts("Benchmark completo.");
}