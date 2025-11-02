#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/receita.h"
#include "include/utils.h" 

void cadastrarReceita(void)
{
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         CADASTRAR NOVA RECEITA          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    Receita *novaReceita;
    novaReceita = malloc(sizeof(Receita));
    memset(novaReceita, 0, sizeof(Receita));
    FILE *arq_receitas;
    arq_receitas = fopen("dados/receitas.dat", "ab");
   
    if (arq_receitas == NULL) {
            perror("Erro ao abrir o arquivo"); // Mostra o motivo real do erro       
            free(novaReceita);
            return;
         }

    printf("Digite o nome da receita:");
    lerString(novaReceita->nome, sizeof(novaReceita->nome));

    printf("\nDigite os Ingredientes: ");
    lerString(novaReceita->ingredientes, sizeof(novaReceita->ingredientes));
    
    printf("\nExplique o modo de preparo: ");
    lerString(novaReceita->modoPreparo, sizeof(novaReceita->modoPreparo));


    novaReceita -> ativo = 1;
    novaReceita -> id = 1;
    /*novaReceita -> id ++; // ID sequencial
    //totalUsuarios = gerarId();*/

    fwrite(novaReceita, sizeof(Receita), 1, arq_receitas);
    fclose(arq_receitas);
    free(novaReceita); 
    printf("\nReceita cadastrada com sucesso\n");
    return;
}

void listarReceitas(void)
{
    
    int encontrado = 0;
    Receita *leitura; // aqui estamos chamando o fomarto da ustruct receita, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receitas = fopen("dados/receitas.dat","rb");
    
    if (arq_receitas == NULL)
    {
        printf("Nenhuma Receita Cadastrada!");
        free(leitura);
        return; 
    }

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           LISTAGEM DE RECEITAS          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    while (fread(leitura, sizeof(Receita),1 , arq_receitas)) 
        {
            if (leitura -> ativo == 1) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("Nome da Receita: %s\n", leitura -> nome);
            printf("Ingredientes: %s\n", leitura -> ingredientes);
            printf("Modo de Preparo: %s\n", leitura -> modoPreparo);

            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada.\n");
        }
    printf("=======================================\n");
    fclose(arq_receitas);
    free(leitura);
    return;

}

void buscarReceita(void)
{
    char nomeBusca[100];
    int encontrado = 0;
    Receita *leitura;
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receitas = fopen("dados/receitas.dat","rb");
        if (arq_receitas == NULL){
            printf("Nenhuma Receita Cadastrada!");
            free(leitura);
            return; }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           BUSCAR RECEITA                ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    printf("Digite o nome da receita que deseja buscar: ");
    lerString(nomeBusca, sizeof(nomeBusca));

    while (fread(leitura, sizeof(Receita),1 , arq_receitas)) 
        {
            if (leitura -> ativo == 1 && strcmp(leitura->nome, nomeBusca) == 0) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("Nome da Receita: %s\n", leitura -> nome);
            printf("Ingredientes: %s\n", leitura -> ingredientes);
            printf("Modo de Preparo: %s\n", leitura -> modoPreparo);
            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada com esse nome.\n");
        }
    printf("=======================================\n");
    fclose(arq_receitas);
    free(leitura);
    return;

}

void editarReceita(void)
{
    char nomeBusca[100];
    char novoTexto[200];
    int op, encontrado = 0;
    Receita *altera = malloc(sizeof(Receita));

    FILE *arq_receitas = fopen("dados/receitas.dat", "rb");
    FILE *temp = fopen("dados/temp.dat", "wb");

    if (!arq_receitas) {
        printf("Nenhuma receita cadastrada!\n");
        free(altera);
        if (temp) fclose(temp);{
        remove("dados/temp.dat");
    }
        return;
    }

    limparTela();
    printf("Digite o nome da receita que deseja editar: ");
    lerString(nomeBusca, sizeof(nomeBusca));

    while (fread(altera, sizeof(Receita), 1, arq_receitas)) {
        if (altera->ativo == 1 && strcmp(altera->nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("Receita encontrada:\n");
            printf("Nome: %s\n", altera->nome);
            printf("Ingredientes: %s\n", altera->ingredientes);
            printf("Modo de Preparo: %s\n", altera->modoPreparo);
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
                        printf("Ingredientes atuais: %s\nNovos ingredientes(ou pressione ENTER para manter): ", altera->ingredientes);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->ingredientes, novoTexto);
                        }
                        break;

                    case 3:
                        printf("Modo de preparo atual: %s\nNovo modo de preparo(ou pressione ENTER para manter): ", altera->modoPreparo);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->modoPreparo, novoTexto);
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

        fwrite(altera, sizeof(Receita), 1, temp);
    }

    fclose(arq_receitas);
    fclose(temp);
    free(altera);

    if (!encontrado) {
        printf("Receita com o nome \"%s\" não encontrada.\n", nomeBusca);
        remove("dados/temp.dat");
    } else {
        remove("dados/receitas.dat");
        rename("dados/temp.dat", "dados/receitas.dat");
        printf("Receita atualizada com sucesso!\n");
    }

}