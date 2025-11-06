#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/utils.h"
#include "../include/relatorio.h"
#include "../include/usuario.h" 

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
                buscarUsuario();
                pressioneEnterParaContinuar();
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


/*
Listagem dos módulos
*/



void buscarUsuario(void) 
{
    int idBusca, encontrado = 0;
    Usuario *leitura;
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("cadastro.dat", "rb");

    if (arq_cadastro == NULL) {
        printf("Nenhum Usuário Cadastrado!\n");
        free(leitura);
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja buscar: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer

    while (fread(leitura, sizeof(Usuario), 1, arq_cadastro)) {
        if ((leitura->id == idBusca) && (leitura->ativo == 1)) {
            encontrado = 1;
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", leitura->id);
            printf("Nome: %s\n", leitura->nome);
            printf("Email: %s\n", leitura->email);
            printf("CPF: %s\n", leitura->cpf);
            printf("Senha: %s\n", leitura->senha);
            break; // Sai do loop após encontrar o usuário
        }
    }

    if (!encontrado) {
        printf("Usuário com ID %d não encontrado ou está inativo.\n", idBusca);
    }

    fclose(arq_cadastro);
    free(leitura);
    return;
}