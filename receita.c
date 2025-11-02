#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receita.h"
#include "utils.h" 

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