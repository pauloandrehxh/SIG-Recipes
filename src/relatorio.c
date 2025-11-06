#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/utils.h"
#include "../include/relatorio.h"
#include "../include/usuario.h" 
#include "../include/receita.h"

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
                pressioneEnterParaContinuar();
                break;
            case 2:
                printf("Estamos trabalhando nisso ainda...");
                pressioneEnterParaContinuar();
                break;
            case 3:
                printf("Estamos trabalhando nisso ainda...");
                pressioneEnterParaContinuar();
                break;
            case 4:
                relatorioAtivo();
                pressioneEnterParaContinuar();
                break;
            case 5:
                relatorioInativo();
                pressioneEnterParaContinuar();
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
                listarUsuarios();
                pressioneEnterParaContinuar();
                break;
            case 2:
                listarReceitas();
                pressioneEnterParaContinuar();
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
                listarUsuarios();
                pressioneEnterParaContinuar();
                break;
            case 2:
                listarReceitas();
                pressioneEnterParaContinuar();
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





