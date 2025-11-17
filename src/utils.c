#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") e system("clear")
#include <string.h>
#include "../include/utils.h"
#include "../include/usuario.h"
#include "../include/ingrediente.h"
#include "../include/receita.h"
void limparTela()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux e macOS
#endif
}

void inicializarIngredientes(){
    FILE *arqIngredientes;
    arqIngredientes = fopen("./dados/dadosIngrediente.dat", "rb");
    if (arqIngredientes == NULL){
        arqIngredientes = fopen("./dados/dadosIngrediente.dat", "wb");

        if (arqIngredientes == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqIngredientes);
    } else {
        fclose(arqIngredientes);
    }
}

void inicializarReceitas(){
    FILE *arqReceitas;
    arqReceitas = fopen("./dados/dadosReceita.dat", "rb");
    if (arqReceitas == NULL){
        arqReceitas = fopen("./dados/dadosReceita.dat", "wb");

        if (arqReceitas == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqReceitas);
    } else {
        fclose(arqReceitas);
    }
}

void inicializarUsuarios(){
    FILE *arqUsuarios;
    arqUsuarios = fopen("./dados/dadosUsuario.dat", "rb");
    if (arqUsuarios == NULL){
        arqUsuarios = fopen("./dados/dadosUsuario.dat", "wb");

        if (arqUsuarios == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqUsuarios);
    } else {
        fclose(arqUsuarios);
    }
}

void pressioneEnterParaContinuar()
{
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de entrada para evitar que leituras anteriores interfiram
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *destino, int tamanho)
{
    fgets(destino, tamanho, stdin);
    // Remove o '\n' que o fgets pode deixar no final da string
    for (int i = 0; i < tamanho; i++)
    {
        if (destino[i] == '\n')
        {
            destino[i] = '\0';
            break;
        }
    }
}
int gerarUsuarioId()
{
    int ultimo_num = 0;
    Usuario *verifica;
    verifica = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat", "rb");
    if (arq_cadastro == NULL) 
        {
        free(verifica); 
        return ultimo_num;
        }
      
    while (fread(verifica, sizeof(Usuario),1 , arq_cadastro))
        {
              ultimo_num =verifica->id;
        }
    fclose(arq_cadastro);
    return ultimo_num + 1;

}

int gerarIngredienteId()
{
    int ultimo_num = 0;
    Ingrediente *verifica;
    verifica = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arqIngredientes = fopen("./dados/dadosIngrediente.dat", "rb");
    if (arqIngredientes == NULL) 
        {
        free(verifica); 
        return ultimo_num; 
        }
      
    while (fread(verifica, sizeof(Ingrediente),1 , arqIngredientes))
        {
              ultimo_num =verifica->id;
        }
    fclose(arqIngredientes);
    return ultimo_num + 1;

}

int gerarReceitaId()
{
    int ultimo_num = 0;
    Receita *verifica;
    verifica = (Receita*) malloc (sizeof(Receita));
    FILE *arqReceitas = fopen("./dados/dadosReceita.dat", "rb");
    if (arqReceitas == NULL) 
        {
        free(verifica); 
        return ultimo_num; 
        }
      
    while (fread(verifica, sizeof(Receita),1 , arqReceitas))
        {
              ultimo_num =verifica->id;
        };
    fclose(arqReceitas);
    return ultimo_num + 1;
}

//funçõe abaixo foram adaptada do códigos cedidos pelo professor flavius via replit
//link:https://replit.com/@flaviusgorgonio/listasDeArquivos#main.c
void preencherUsuarioList(Usuario *usu, UsuarioLista *usuList){
    usuList->id = usu->id;
    strcpy(usuList->nome,usu->nome);
    strcpy(usuList->email,usu->email);
    strcpy(usuList->cpf,usu->cpf);
}

//funções abaixo foram retiradas do códigos cedidos pelo professor flavius via Sigaa
UsuarioLista* newUsuarioList(void) {
    UsuarioLista* l = (UsuarioLista*) malloc(sizeof(UsuarioLista));
    if (l == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}
void appendUsuario(UsuarioLista *l, Usuario* data) {
    UsuarioLista* novo = (UsuarioLista*) malloc(sizeof(UsuarioLista));
    if (novo == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    novo->id = data->id;
    strcpy(novo->nome, data->nome);
    strcpy(novo->email, data->email);
    strcpy(novo->cpf, data->cpf);
    novo->prox = NULL;
    UsuarioLista* temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
}
void preencherListaUsuario(UsuarioLista *lista) {
    int encontrado = 0;
    Usuario *leitura;
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat", "rb");
    if (arq_cadastro == NULL) {
        printf("Nenhum Usuário Cadastrado!\n");
        return;
    }
    leitura = (Usuario*) malloc(sizeof(Usuario));
    
    while (fread(leitura, sizeof(Usuario), 1, arq_cadastro)) {
        if (leitura->ativo == 1) {
            encontrado = 1;
            Usuario *novoUsuario = (Usuario*) malloc(sizeof(Usuario));
            *novoUsuario = *leitura;
            appendUsuario(lista, novoUsuario);
        }
    }
    if (!encontrado) {
        printf("Nenhum usuário ativo encontrado.\n");
    }
    fclose(arq_cadastro);
    free(leitura);  
    return;   
}

void clearUsuario(UsuarioLista* l) {
    UsuarioLista* temp = l->prox;
    UsuarioLista* next;
    while (temp != NULL) {
        next = temp->prox;
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteUsuario(UsuarioLista* l) {
    clearUsuario(l);
    free(l);
}

//funçõe abaixo foram adaptada do códigos cedidos pelo professor flavius via replit
//link:https://replit.com/@flaviusgorgonio/listasDeArquivos#main.c
void preencherIngredienteList(Ingrediente *ingre, IngredienteLista *ingreList){
    ingreList->id = ingre->id;
    strcpy(ingreList->nome,ingre->nome);
    strcpy(ingreList->tipo,ingre->tipo);
    strcpy(ingreList->unidade,ingre->unidade);
    strcpy(ingreList->quantidade,ingre->quantidade);
}

//funções abaixo foram retiradas do códigos cedidos pelo professor flavius via Sigaa
IngredienteLista* newIngredienteList(void) {
    IngredienteLista* l = (IngredienteLista*) malloc(sizeof(IngredienteLista));
    if (l == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}
void appendIngrediente(IngredienteLista *l, Ingrediente* data) {
    IngredienteLista* novo = (IngredienteLista*) malloc(sizeof(IngredienteLista));
    if (novo == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    preencherIngredienteList(data,l);
    novo->prox = NULL;
    IngredienteLista* temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
}
void preencherListaIngrediente(IngredienteLista *lista){
    int encontrado = 0;
    Ingrediente *leitura;
    leitura = (Ingrediente*) malloc(sizeof(Ingrediente));
    FILE *arqIngrediente = fopen("./dados/dadosIngrediente.dat","rb");
    if (arqIngrediente == NULL){
        printf("Nenhum Usuário Cadastrado!\n");
        return;
    }
    while (fread(leitura, sizeof(Ingrediente), 1, arqIngrediente)) 
    {
        if (leitura -> status == 1) 
        {
        encontrado =1;
        Ingrediente *novoIngrediente = (Ingrediente*) malloc (sizeof(Ingrediente));
        novoIngrediente = leitura;
        appendIngrediente(lista,novoIngrediente);
        }
    }
    if (!encontrado){
        printf("Nenhum usuário ativo encontrado.\n");
    }
    fclose(arqIngrediente);
    free(leitura);
    return;   
}

void clearIngrediente(IngredienteLista* l) {
    IngredienteLista* temp = l->prox;
    IngredienteLista* next;
    while (temp != NULL) {
        next = temp->prox;
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteIngrediente(IngredienteLista* l) {
    clearIngrediente(l);
    free(l);
}