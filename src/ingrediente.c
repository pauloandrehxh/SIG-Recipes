#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/ingrediente.h"
#include "../include/utils.h"

#define MAX_INGREDIENTES 50

Ingrediente despensa[MAX_INGREDIENTES];
int totalIngredientes = 0;

void adicionarIngrediente()
{

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO INGREDIENTE       ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    Ingrediente *novoIngrediente;
    novoIngrediente = malloc(sizeof(Ingrediente));
    memset(novoIngrediente, 0, sizeof(Ingrediente));
    FILE *arq_ingredientes;
    arq_ingredientes = fopen("ingredientes.dat", "wb");
   
    if (arq_ingredientes == NULL) {
            perror("Erro ao abrir o arquivo");      
            free(novoIngrediente);
            return;
         }

    printf("Digite o nome do ingrediente:");
    lerString(novoIngrediente->nome, sizeof(novoIngrediente->nome));

    printf("\nDigite a sua quantidade:");
    lerString(novoIngrediente->quantidade, sizeof(novoIngrediente->quantidade));

    printf("\nDigite as unidades:");
    lerString(novoIngrediente->unidade, sizeof(novoIngrediente->unidade));


    novoIngrediente -> ativo = 1;
    
    fwrite(novoIngrediente, sizeof(novoIngrediente), 1, arq_ingredientes);
    fclose(arq_ingredientes);
    free(novoIngrediente); 
    printf("\nReceita cadastrada com sucesso\n");
    return;
}

void listarIngredientes() {
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTAGEM DE INGREDIENTES        ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    int encontrado = 0;
    Ingrediente *leitura; // aqui estamos chamando o fomarto da ustruct receita, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arq_ingredientes = fopen("ingredientes.dat","rb");
    
    if (arq_ingredientes == NULL)
    {
        printf("Nenhuma Receita Cadastrada!");
        free(leitura);
        return; 
    }

    while (fread(leitura, sizeof(Ingrediente),1 , arq_ingredientes)) 
        {
            if (leitura -> ativo == 1) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("Nome dos Ingredientes: %s\n", leitura -> nome);
            printf("Quantidade(s): %s\n", leitura -> quantidade);
            printf("Unidade(s): %s\n", leitura -> unidade);
            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada.\n");
        }
    printf("=======================================\n");
    fclose(arq_ingredientes);
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

    FILE *arq_ingredientes = fopen("ingredientes.dat", "rb");
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
                telaEditarReceita();
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
                        printf("Modo de preparo atual: %s\nNovo modo de preparo(ou pressione ENTER para manter): ", altera->unidade);
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
        printf("Receita com o nome \"%s\" não encontrada.\n", nomeBusca);
        remove("temp.dat");
    } else {
        remove("receitas.dat");
        rename("temp.dat", "receitas.dat");
        printf("Receita atualizada com sucesso!\n");
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