#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/telas.h"
#include "../include/utils.h"
#include "../include/relatorio.h"
#include "../include/usuario.h" 
#include "../include/receita.h"
#include "../include/ingrediente.h"

void gerenciarRelatorio() {
    int opcao;
    do {
        telaRelatorio();
        
        printf("Escolha uma opção:");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                listarUsuarioNome();
                break;
            case 2:
                printf("Estamos trabalhando nisso ainda...\n");
                pressioneEnterParaContinuar();
                break;
            case 3:
                printf("Estamos trabalhando nisso ainda...\n");
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
                listarIngredientes();
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
                listarUsuarioInativo();
                pressioneEnterParaContinuar();
                break;
            case 2:
                listarReceitaInativa();
                pressioneEnterParaContinuar();
                break;
            case 3:
                listarIngredienteInativo();
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
    while (opcao_usuario != 0);
}

//Módulos das funções

void listarUsuarioInativo()
{  
    int encontrado = 0;
    Usuario *leitura;
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat","rb");
    
    if (arq_cadastro == NULL){
        printf("Nenhum Usuário Cadastrado!\n");
        return;
    }
    
    limparTela();
    printf("================================ LISTA DE USUÁRIOS INATIVOS ================================\n");
    printf("ID\tNome\t\t\tEmail\t\t\t\tCPF\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(leitura, sizeof(Usuario), 1, arq_cadastro)) 
    {   
        if (leitura -> ativo == 0) 
        {
            encontrado = 1;
            printf("%d\t%-20s\t%-25s\t%-14s\n", 
                   leitura -> id, 
                   leitura -> nome, 
                   leitura -> email, 
                   leitura -> cpf);
        }
    }
    
    if (!encontrado){
        printf("Nenhum usuário inativo encontrado.\n");
    }
    
    printf("===========================================================================================\n");
    fclose(arq_cadastro);
    free(leitura);
    return;   
}

void listarReceitaInativa()
{
    int encontrado = 0;
    Receita *leitura; 
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receita = fopen("./dados/dadosReceita.dat","rb");
    
    if (arq_receita == NULL)
    {
        printf("Nenhuma Receita Cadastrada!\n");
        free(leitura);
        return; 
    }

    limparTela();
    printf("================================ LISTA DE RECEITAS INATIVAS ================================\n");
    printf("ID\tNome da Receita\t\t\tID Ingrediente\tID Usuário\tModo de Preparo\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(leitura, sizeof(Receita), 1, arq_receita)) 
    {
        if (leitura -> status == 0) 
        {
            encontrado = 1;
            printf("%d\t%-25s\t%-14d\t%-11d\t%s\n", 
                   leitura -> id, 
                   leitura -> nome, 
                   leitura -> idIngrediente, 
                   leitura -> idUsuario, 
                   leitura -> modoPreparo);
        }
    }
    
    if (!encontrado){
        printf("Nenhuma receita inativa encontrada.\n");
    }
    
    printf("===========================================================================================\n");
    fclose(arq_receita);
    free(leitura);
    return;
}

void listarIngredienteInativo()
{
    int encontrado = 0;
    Ingrediente *leitura; 
    leitura = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arqIngredientes = fopen("./dados/dadosIngrediente.dat","rb");
    
    if (arqIngredientes == NULL)
    {
        printf("Nenhum Ingrediente Cadastrado!\n");
        free(leitura);
        return;
    }
    
    limparTela();
    printf("=============================== INGREDIENTES INATIVOS - INGREDIENTES ==========================\n");
    printf("ID\tNome\t\t\tTipo\t\t\tQuantidade\tUnidade\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    while (fread(leitura, sizeof(Ingrediente), 1, arqIngredientes)) 
    {
        if (leitura -> status == 0) 
        {
            encontrado = 1;
            printf("%d\t%-20s\t%-20s\t%-12s\t%s\n", 
                   leitura -> id, 
                   leitura -> nome, 
                   leitura ->tipo,
                   leitura -> quantidade, 
                   leitura -> unidade);
        }
    }
    
    if (!encontrado)
    {   
        printf("Nenhum ingrediente inativo encontrado.\n");
    }
    
    printf("===============================================================================================\n");
    fclose(arqIngredientes);
    free(leitura);
    return;
}

void listarUsuarioNome () {
    char nomeBusca[30];
    int encontrados = 0;
    UsuarioLista *lista = newUsuarioList();
    printf("Digite o nome de usuário:");
    lerString(nomeBusca,30);
    preencherListaUsuario(lista);
    UsuarioLista* temp = lista->prox;
    printf("\n=== RESULTADOS DA BUSCA POR '%s' ===\n", nomeBusca);
    printf("ID\tNome\t\t\tEmail\t\t\tCPF\n");
    printf("------------------------------------------------------------\n");
    while (temp != NULL )
    {
        if (strstr(temp->nome,nomeBusca)!= NULL) 
            {
                printf("%d\t%-20s\t%-12s\t%s\n", 
                    temp -> id, 
                    temp -> nome, 
                    temp -> email, 
                    temp -> cpf);
                    encontrados++;
            }
        temp = temp->prox; 
    }
    if (encontrados == 0) {
        printf("Nenhum usuário encontrado com '%s' no nome.\n", nomeBusca);
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total encontrado: %d usuário(s)\n", encontrados);
    }
    deleteUsuario(lista);
    pressioneEnterParaContinuar();
}

void listarIngredienteNome () {
    char nomeBusca[30];
    int encontrado = 0;
    IngredienteLista *lista = newIngredienteList();
    printf("Digite o nome de usuário:");
    lerString(nomeBusca,30);
    preencherListaIngrediente(lista);
    IngredienteLista* temp = lista->prox;
    printf("\n=== RESULTADOS DA BUSCA POR '%s' ===\n", nomeBusca);
    printf("ID\tNome da Receita\t\t\tID Ingrediente\tID Usuário\tModo de Preparo\n");
    printf("------------------------------------------------------------\n");
    while (temp != NULL )
    {
        if (strstr(temp->nome,nomeBusca)!= NULL) 
        {
            printf("%d\t%-20s\t%-20s\t%-12s\t%s\n", 
                   temp -> id, 
                   temp -> nome, 
                   temp ->tipo,
                   temp -> quantidade, 
                   temp -> unidade);
            encontrado++;
        }
        temp = temp->prox; 
    }
    if (encontrado == 0) {
        printf("Nenhum usuário encontrado com '%s' no nome.\n", nomeBusca);
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total encontrado: %d usuário(s)\n", encontrado);
    }
    deleteIngrediente(lista);
    pressioneEnterParaContinuar();
}