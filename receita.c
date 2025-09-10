#include <stdio.h>
#include "receita.h"
#include "utils.h" // Para usar limparTela()

// Função principal para cadastrar a receita
Receita cadastrarReceita(void)
{
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

    printf("\nReceita cadastrada com sucesso!\n");

    // No futuro, aqui você chamará uma função para salvar 'novaReceita' em um arquivo.

    return novaReceita;
}