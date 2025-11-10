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
                printf("Estamos trabalhando nisso ainda...\n");
                pressioneEnterParaContinuar();
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
    Usuario *leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat","rb");
        if (arq_cadastro == NULL){
            printf("Nenhum Usuário Cadastrado!\n");
            return;
    }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Usuario),1 , arq_cadastro)) 
    {   
        if (leitura -> ativo == 0) 
        {
        encontrado = 1;
        printf("=======================================\n");
        printf("ID: %d\n", leitura -> id);
        printf("Nome: %s\n", leitura -> nome);
        printf("Email: %s\n", leitura -> email);
        printf("CPF: %s\n", leitura -> cpf);
        printf("Senha: %s\n", leitura -> senha);
        }
    }
    if (!encontrado){
        printf("Nenhum usuário inativo encontrado.\n");
     }
    printf("=======================================\n");
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
    }            printf("id: %d\n", leitura -> id);

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           LISTAGEM DE RECEITAS          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    while (fread(leitura, sizeof(Receita),1 , arq_receita)) 
        {
            if (leitura -> status == 0) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("id: %d\n", leitura -> id);
            printf("Nome da Receita: %s\n", leitura -> nome);
            printf("id do Ingrediente: %d\n", leitura -> idIngrediente);
            printf("id do Usuario: %d\n", leitura -> idUsuario);
            printf("Modo de Preparo: %s\n", leitura -> modoPreparo);

            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada.\n");
        }
    printf("=======================================\n");
    fclose(arq_receita);
    free(leitura);
    return;

}

void listarIngredienteInativo() {
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
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         ESTOQUE DA DISPENSA             ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Ingrediente),1 , arqIngredientes)) 
    {
        if (leitura -> status == 0) 
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

