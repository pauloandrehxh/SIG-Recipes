#include <stdio.h>
#include "ingrediente.h"
#include "utils.h"

#define MAX_INGREDIENTES 50

Ingrediente despensa[MAX_INGREDIENTES];
int totalIngredientes = 0;

void adicionarIngrediente()
{
    if (totalIngredientes >= MAX_INGREDIENTES) {
        printf("Limite de ingredientes atingido!.\n");
        return;
    }

    Ingrediente novoIngrediente;

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO INGREDIENTE       ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome da ingrediente: ");
    lerString(novoIngrediente.nome, 50);

    printf("\nQuantidade: ");
    scanf("%f", &novoIngrediente.quantidade);
    while (getchar() != '\n'); // Limpa o buffer do teclado

    printf("\nUnidade (ex: g, ml, unidade): ");
    lerString(novoIngrediente.unidade, 20);

    novoIngrediente.ativo = 1;

    despensa[totalIngredientes] = novoIngrediente;
    totalIngredientes++;

    printf("\nIngrediente adicionado com sucesso!");
}

void listarIngredientes() {
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTAGEM DE INGREDIENTES        ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    if (totalIngredientes == 0) {
        printf("Nenhum ingrediente foi adicionado na despensa.\n");
        return;
    }

    for (int i = 0; i < totalIngredientes; i++) {
        printf("--------------------------------------\n");
        printf("Item: %s\n", despensa[i].nome);
        printf("Estoque: %.2f %s\n", despensa[i].quantidade, despensa[i].unidade);
        printf("--------------------------------------\n");
    }
}

void editarIngredientes() {
    limparTela();
    printf("\nEditando ingrediente...\n");
    // A lógica será parecida com a de editar receita:
    // 1. Pedir o nome do ingrediente a ser editado.
    // 2. Buscar no array 'despensa'.
    // 3. Se encontrar, pedir os novos dados.
}

void excluirIngredientes() {
    limparTela();
    printf("\nExcluindo ingrediente...\n");
    // A lógica será parecida com a de excluir receita:
    // 1. Pedir o nome do ingrediente a ser excluído.
    // 2. Buscar no array 'despensa'.
    // 3. Se encontrar, mudar o campo 'ativo' para 0.
}