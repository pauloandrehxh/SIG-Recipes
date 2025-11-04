#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/ingrediente.h"
#include "../include/utils.h"

/*#define MAX_INGREDIENTES 50

Ingrediente despensa[MAX_INGREDIENTES];
int totalIngredientes = 0;*/

void adicionarIngrediente()
{
    /*if (totalIngredientes >= MAX_INGREDIENTES) {
        printf("Limite de ingredientes atingido!.\n");
        return;
    }*/
    Ingrediente *novoEstoque;
    novoEstoque = malloc(sizeof(Ingrediente));
    memset(novoEstoque, 0, sizeof(Ingrediente));
    FILE *arq_despensa;
    arq_despensa = fopen("estoque.dat", "wb");
   
    if (arq_despensa == NULL) {
            perror("Erro ao abrir o arquivo"); // Mostra o motivo real do erro       
            free(novoEstoque);
            return;
         }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO INGREDIENTE       ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome do ingrediente: ");
    lerString(novoEstoque->nome, sizeof(novoEstoque->nome));

    printf("\nQuantidade: ");
    lerString(novoEstoque->quantidade,sizeof(novoEstoque->quantidade));
    
    printf("\nUnidade de medida do Ingrediente(ex: g, ml, unidade): ");
    lerString(novoEstoque->unidade, sizeof(novoEstoque->unidade));
    /* Função de salvamento de arquivos de teste*/
    novoEstoque->ativo = 1;
    fwrite(novoEstoque, sizeof(Ingrediente), 1, arq_despensa);
    fclose(arq_despensa);
    free(novoEstoque);
    
    /*despensa[totalIngredientes] = novoIngrediente;
    totalIngredientes++;*/

    printf("\nIngrediente adicionado com sucesso!");
}

void listarIngredientes() {
   int encontrado = 0;
    Ingrediente *leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos em Ingrediente.h
    leitura = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arq_despensa = fopen("estoque.dat","rb");
        if (arq_despensa == NULL)
        {
            printf("Nenhum Ingrediente Cadastrado!\n");
            free(leitura);
            return;
        }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         ESTOQUE DA DISPENSA             ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Ingrediente),1 , arq_despensa)) 
    {
        if (leitura -> ativo == 1) 
        {
            encontrado = 1;
            printf("=======================================\n");
            printf("Nome: %s\n", leitura ->nome);
            printf("Quantidade: %s\n", leitura -> quantidade);
            printf("Unidades(gr,kgs,etc): %s\n", leitura -> unidade);
        }
    }
        if (!encontrado)
        {   
            limparTela();
            printf("Nenhum Ingrediente ativo foi encontrado.\n");
        }
    printf("=======================================\n");
    fclose(arq_despensa);
    free(leitura);
    return;
}

void editarIngredientes() {
    limparTela();
    char nomeBusca[100];
    char novoTexto[200];
    int op, encontrado = 0;
    Ingrediente *altera;
    altera = malloc(sizeof(Ingrediente));

    FILE *arq_ingredientes = fopen("estoque.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!arq_ingredientes) {
    printf("Nenhum ingrediente cadastrado!\n");
    free(altera);
        if (temp) {
        fclose(temp);
        remove("temp.dat");
            }
    return;
    }


    limparTela();
    printf("Digite o nome do ingrediente que deseja editar: ");
    lerString(nomeBusca, sizeof(nomeBusca));

    while (fread(altera, sizeof(Ingrediente), 1, arq_ingredientes)) {
        if (altera->ativo == 1 && strcmp(altera->nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("Ingrediente encontrado:\n");
            printf("Nome: %s\n", altera->nome);
            printf("Quantidade: %s\n", altera->quantidade);
            printf("Unidade: %s\n", altera->unidade);
            pressioneEnterParaContinuar();

            do {
                limparTela();
                telaEditarIngrediente();
                printf("Escolha uma opção: ");
                scanf("%d", &op);
                getchar();

                switch(op) {
                    case 1:
                        printf("Nome atual: %s\nNovo nome(ou pressione ENTER para manter): ", altera->nome);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->nome, novoTexto);
                        }
                        break;

                    case 2:
                        printf("Quantidades atuais: %s\nNovas quantidades(ou pressione ENTER para manter): ", altera->quantidade);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->quantidade, novoTexto);
                        }
                        break;
                    case 3:
                        printf("Unidade de medida atual: %s\nNova Unidade de medida(ou pressione ENTER para manter): ", altera->unidade);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->unidade, novoTexto);
                        }
                        break;

                    case 0:
                        printf("Alterações concluídas!\n");
                        break;

                    default:
                        printf("Opção inválida!\n");
                        pressioneEnterParaContinuar();
                }

            } while (op != 0);
        }

        fwrite(altera, sizeof(Ingrediente), 1, temp);
    }

    fclose(arq_ingredientes);
    fclose(temp);
    free(altera);

    if (!encontrado) {
        printf("Ingrediente com o nome \"%s\" não encontrada.\n", nomeBusca);
        remove("temp.dat");
    } else {
        remove("estoque.dat");
        rename("temp.dat", "estoque.dat");
        printf("Ingrediente atualizado com sucesso!\n");
    }

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