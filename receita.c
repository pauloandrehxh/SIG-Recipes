#include <stdio.h>
#include "receita.h"
#include "utils.h" 

// Banco de dados em memória 
#define MAX_RECEITAS 50

Receita listaDeReceitas[MAX_RECEITAS];
int totalReceitas = 0;

void cadastrarReceita(void)
{
    if (totalReceitas >= MAX_RECEITAS) {
        printf("Limite de receitas atingido!\n");
        return;
    }

    Receita novaReceita;

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         CADASTRAR NOVA RECEITA          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome da Receita: ");
    lerString(novaReceita.nome, 100);

    printf("\nIngredientes (use ';' para separar os itens):\n");
    lerString(novaReceita.ingredientes, 500);

    printf("\nModo de Preparo:\n");
    lerString(novaReceita.modoPreparo, 1000);

    novaReceita.ativo = 1; // Define a receita como ativa

    // Adiciona a receita na lista de receitas
    listaDeReceitas[totalReceitas] = novaReceita;

    totalReceitas++;

    FILE *arqReceita = fopen("receitas.csv", "a");
    if (arqReceita == NULL) {
        printf("Error ao abrir o arquivo!!!.");
        return;
    } 
    /*Salva todas as informações em uma linha só em um arquivo Csv*/
    fprintf(arqReceita,"%s;%s;%s\n",
            novaReceita.nome,
            novaReceita.ingredientes,
            novaReceita.modoPreparo);
    fclose(arqReceita);
    printf("\nReceita cadastrada com sucesso!\n");
}

void listarReceitas(void)
{
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           LISTAGEM DE RECEITAS          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    if (totalReceitas == 0){
        printf("Nenhuma receita cadastrada ainda.\n");
        return;
    }

    for (int i = 0; i < totalReceitas; i++) {
        printf("--------------------------------------\n");
        printf("Nome: %s\n", listaDeReceitas[i].nome);
        printf("Ingredientes: %s\n", listaDeReceitas[i].ingredientes);
        printf("Modo de preparo: %s\n", listaDeReceitas[i].modoPreparo);
        printf("--------------------------------------\n");
    }
    
}