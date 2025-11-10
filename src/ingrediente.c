#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/ingrediente.h"
#include "../include/utils.h"

void gerenciarModuloIngredientes()
{
    int opcao_ingred;
    do
    {
        telaIngredientes();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao_ingred);
        while (getchar() != '\n'); // Limpa o buffer

        switch (opcao_ingred)
        {
        case 1:
            adicionarIngrediente();
            pressioneEnterParaContinuar();
            break;
        case 2:
            listarIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 3:
            editarIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 4:
            excluirIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 0:
            break;
        default:
            limparTela();
            printf("\nOpção inválida! Tente novamente.\n");
            pressioneEnterParaContinuar();
            break;
        }
    } while (opcao_ingred != 0);
}

void adicionarIngrediente()
{
    Ingrediente *novoIngrediente;
    novoIngrediente = malloc(sizeof(Ingrediente));
    memset(novoIngrediente, 0, sizeof(Ingrediente));
    FILE *arqIngredientes;
    arqIngredientes = fopen("./dados/dadosIngrediente.dat", "ab");
   
    if (arqIngredientes == NULL) {
            perror("Erro ao abrir o arquivo"); // Mostra o motivo real do erro       
            free(novoIngrediente);
            return;
         }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO INGREDIENTE       ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome do ingrediente: ");
    lerString(novoIngrediente->nome, sizeof(novoIngrediente->nome));

    printf("\nQuantidade: ");
    lerString(novoIngrediente->quantidade,sizeof(novoIngrediente->quantidade));
    
    printf("\nUnidade de medida do Ingrediente(ex: g, ml, unidade): ");
    lerString(novoIngrediente->unidade, sizeof(novoIngrediente->unidade));
    /* Função de salvamento de arquivos de teste*/
    novoIngrediente->status = 1;
    novoIngrediente->id = gerarIngredienteId();
    fwrite(novoIngrediente, sizeof(Ingrediente), 1, arqIngredientes);
    fclose(arqIngredientes);
    free(novoIngrediente);

    printf("\nIngrediente adicionado com sucesso!");
}

void listarIngredientes() {
   int encontrado = 0;
    Ingrediente *leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos em Ingrediente.h
    leitura = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arqIngredientes = fopen("estoque.dat","rb");
        if (arqIngredientes == NULL)
        {
            printf("Nenhum Ingrediente Cadastrado!\n");
            free(leitura);
            return;
        }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         ESTOQUE DA DISPENSA             ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Ingrediente),1 , arqIngredientes)) 
    {
        if (leitura -> status == 1) 
        {
            encontrado = 1;
            printf("=======================================\n");
            printf("ID: %d\n", leitura ->id);
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
    fclose(arqIngredientes);
    free(leitura);
    return;
}

void editarIngredientes() {
    char novoTexto[200];
    int op, encontrado = 0;
    char idBusca[10];
    Ingrediente *altera;
    altera = malloc(sizeof(Ingrediente));

    FILE *arq_ingredientes = fopen("./dados/dadosIngrediente.dat", "rb");
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
    lerString(idBusca,10);
    getchar();
    while (fread(altera, sizeof(Ingrediente), 1, arq_ingredientes)) {
        if (altera->status == 1 && altera->id == atoi(idBusca)) {
            encontrado = 1;
            printf("Ingrediente encontrado!!\n");
            printf("ID: %d\n", altera->id);
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
        fseek(arq_ingredientes, -1 * sizeof(Ingrediente), SEEK_CUR);
        fwrite(altera, sizeof(Ingrediente), 1, temp);
    }

    fclose(arq_ingredientes);
    fclose(temp);
    free(altera);

    if (!encontrado) {
        printf("Ingrediente com o ID \"%s\" não encontrado.\n", idBusca);
        remove("temp.dat");
    } else {
        remove("./dados/dadosIngrediente.dat");
        rename("temp.dat", "./dados/dadosIngrediente.dat");
        printf("Ingrediente atualizado com sucesso!\n");
    }

}

void excluirIngredientes() {
     int encontrado = 0;
    char idBusca[10];
    Ingrediente *deleta;
    deleta = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arq_despensa = fopen("./dados/dadosIngrediente", "rb");

    if (arq_despensa == NULL) 
    {
        printf("Nenhum ingrediente Cadastrado!\n");
    }

    limparTela();
    printf("Digite o nome do Ingrediente que deseja excluir: ");
    lerString(idBusca, sizeof(idBusca));

    while (fread(deleta, sizeof(Ingrediente), 1, arq_despensa))
    {
       
        if (deleta->id == atoi(idBusca) && (deleta->status == 1)) {
            encontrado = 1;
            limparTela();
            printf("Ingredientes encontrado:\n");
            printf("ID: %d\nNome: %s\nModo de preparo: %s\nIngredientes: %s\n", 
                    deleta->id,
                    deleta->nome, 
                    deleta->quantidade, 
                    deleta->unidade);
            printf("\nDeseja realmente excluir este Ingrediente (S/N): ");
            char confirmacao;
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                deleta->status = 0; // “Exclusão lógica”
                printf("\nIngrediente marcado como inativo com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
        }

        fseek(arq_despensa,-1*sizeof(deleta), SEEK_CUR);
        fwrite(deleta, sizeof(Ingrediente), 1, arq_despensa);
    }

    fclose(arq_despensa);
    free(deleta);
    if (!encontrado) 
    {
        printf("\nIngrediente não encontrado ou já está inativo.\n");
        return;
    } 

}