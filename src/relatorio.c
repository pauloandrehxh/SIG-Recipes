#include <stdio.h>
#include <stdlib.h>
#include "../include/telas.h"
#include "../include/relatorio.h"

void gerenciarRelatorio() {
    int opcao;
    do {
        telaRelatorio();
        
        printf("Escolha uma opção:");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                printf("Estamos trabalhando nisso ainda...");
                break;
            case 2:
                printf("Estamos trabalhando nisso ainda...");
                break;
            case 3:
                printf("Estamos trabalhando nisso ainda...");
                break;
            case 4:
                relatorioAtivo();
                break;
            case 5:
                telaRelatorioInativo();
                break;
            case 0:
                break;
            default:
                limparTela();
                printf("\nOpcao invalida! Tente novamente.\n");
                pressioneEnterParaContinuar();
                break;    
        }
    }
    while (opcao != 0);
}

void relatorioAtivo() {
    int opcao_usuario;
    do {
        telaRelatorioAtivo();

        
        printf("Escolha uma opção:");
        scanf("%d", &opcao_usuario);
        while (getchar() != '\n');

        switch(opcao_usuario) {
            case 1:
                printf("Estamos trabalhando nisso!");
                break;
            case 2:
                printf("Estamos trabalhando nisso!");
                break;
            case 3:
                printf("Estamos trabalhando nisso!");
                break;
            case 0:
                break; 
            default:
                limparTela();
                printf("\nOpcao invalida! Tente novamente.\n");
                pressioneEnterParaContinuar();
                break;               
        }
    }
    while (opcao_usuario != 0);
}

void relatorioInativo() {
    int opcao_usuario;
    do {
        telaRelatorioInativo();

        printf("Escolha uma opção:");
        scanf("%d", &opcao_usuario);
        while (getchar() != '\n');

        switch(opcao_usuario) {
            case 1:
                printf("Estamos trabalhando nisso!");
                break;
            case 2:
                printf("Estamos trabalhando nisso!");
                break;
            case 3:
                printf("Estamos trabalhando nisso!");
                break;
            case 0:
                break; 
            default:
                limparTela();
                printf("\nOpcao invalida! Tente novamente.\n");
                pressioneEnterParaContinuar();
                break;               
        }
    }
    while (opcao_usuario != 0);
}