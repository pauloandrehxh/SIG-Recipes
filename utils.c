#include "utils.h"
#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") e system("clear")

void limparTela() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux e macOS
    #endif
}

void pressioneEnterParaContinuar() {
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de entrada para evitar que leituras anteriores interfiram
    while (getchar() != '\n'); // Limpa o buffer do teclado (importante!)
    getchar(); // Aguarda o Enter
}