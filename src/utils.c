#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
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
    novo->id = data->id;
    strcpy(novo->nome, data->nome);
    strcpy(novo->tipo, data->tipo);
    strcpy(novo->unidade, data->unidade);
    strcpy(novo->quantidade, data->quantidade);
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

//funções abaixo foram retiradas do códigos cedidos pelo professor flavius via Sigaa
ReceitaLista* newReceitaList(void) {
    ReceitaLista* l = (ReceitaLista*) malloc(sizeof(ReceitaLista));
    if (l == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}
void appendReceita(ReceitaLista *l, Receita* data) {
    ReceitaLista* novo = (ReceitaLista*) malloc(sizeof(ReceitaLista));
    if (novo == NULL) {
        fprintf(stderr, "Memoria indisponível\n");
        exit(EXIT_FAILURE);
    }
    novo->id = data->id;
    strcpy(novo->nome, data->nome);
    novo->idIngrediente = data->idIngrediente;
    novo->idUsuario = data->idUsuario;
    strcpy(novo->tempoPreparo, data->tempoPreparo);
    novo->prox = NULL;
    ReceitaLista* temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
}
void preencherListaReceita(ReceitaLista *lista){
    int encontrado = 0;
    Receita *leitura;
    leitura = (Receita*) malloc(sizeof(Receita));
    FILE *arqReceita = fopen("./dados/dadosReceita.dat","rb");
    if (arqReceita == NULL){
        printf("Nenhum Usuário Cadastrado!\n");
        return;
    }
    while (fread(leitura, sizeof(Receita), 1, arqReceita)) 
    {
        if (leitura -> status == 1) 
        {
        encontrado =1;
        Receita *novoReceita = (Receita*) malloc (sizeof(Receita));
        novoReceita = leitura;
        appendReceita(lista,novoReceita);
        }
    }
    if (!encontrado){
        printf("Nenhum usuário ativo encontrado.\n");
    }
    fclose(arqReceita);
    free(leitura);
    return;   
}

void clearReceita(ReceitaLista* l) {
    ReceitaLista* temp = l->prox;
    ReceitaLista* next;
    while (temp != NULL) {
        next = temp->prox;
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteReceita(ReceitaLista* l) {
    clearReceita(l);
    free(l);
}
//Validações cedidas por Thomas vindas do projeto SIW-Wine
//link: https://github.com/ThomasReyel/SIG-Wine.git
int ehLetra(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ehVogal(char c) {
    char vogais[] = "AEIOUaeiou";
    for (int i = 0; vogais[i] != '\0'; i++) {
        if (c == vogais[i])
            return 1;
    }
    return 0;
}

int validarNome(char* nome) {
    int tamanho = strlen(nome);
    int temVogal = 0;
    int repeticoes = 1;

    if (tamanho < 2 || tamanho > 30)
        return 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!ehLetra(nome[i]))
            return 0; 

        if (ehVogal(nome[i]))
            temVogal = 1;

        if (i > 0) {
            if (nome[i] == nome[i - 1]) {
                repeticoes++;
                if (repeticoes >= 3)
                    return 0; 
            } else {
                repeticoes = 1;
            }
        }
    }
    if (!temVogal)
        return 0;

    return 1;
}

int validarCpf(char *cpf){
    int i;
    int tamanho = strlen(cpf);
    if(tamanho != 11){
        return 0;
    }
    for(i = 0; i < tamanho; i++){
      if(!isdigit(cpf[i])){
          return 0;
      }
    }
    return 1;
}

int validarEmail(char *email){
    
    const char *arroba = strchr(email, '@');
    const char *ponto = strrchr(email, '.');

   
    if (!arroba || !ponto) return 0;
    if (arroba == email || ponto == email) return 0;
    if (ponto < arroba + 2) return 0;      
    if (ponto == email + strlen(email) - 1) return 0; 

    return 1; 
}

int validarUsuario(char* email, char* cpf, char* nome){
    if ((validarCpf(cpf) == 1) && (validarEmail(email) == 1) && (validarNome(nome) == 1)){
        return 1;
    }else{
        return 0;
    }   
}

int validarNomeObjeto(char* nome) {
    int len = strlen(nome);
    int temAlnum = 0;
    if (len < 0) return 0; 
    for (int i = 0; nome[i] != '\0'; i++) {
        unsigned char c = (unsigned char) nome[i];
        if (isalnum(c)) {
            temAlnum = 1;
            continue;
        }
        if (c == ' ' || c == '-' || c == '.' || c == ',' || c == '&' || c == '/') {
            continue;
        }
        return 0;
    }
    if (!temAlnum) return 0;
    return 1;
}

int validarIdIngrediente(int id){
    Ingrediente *leitura;
    leitura = (Ingrediente*) malloc (sizeof(Ingrediente));
    FILE *arqIngrediente = fopen("./dados/dadosIngrediente.dat","rb");
        if (arqIngrediente == NULL){
            printf("Nenhuma Ingrediente Cadastrada!\n");
            free(leitura);
            return 0; }
    while (fread(leitura, sizeof(Ingrediente),1 , arqIngrediente)) 
        {
            if ((leitura -> status == 1) && (id == leitura->id)) 
            {
                fclose(arqIngrediente);
                free(leitura);
                return 1;
            }
        }

    return 0;
}
int validarIdUsuario(int id){
    Usuario *leitura;
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat", "rb");

    if (arq_cadastro == NULL) {
        printf("Nenhum Usuário Cadastrado!\n");
        free(leitura);
        return 0;
    }
    while (fread(leitura, sizeof(Usuario), 1, arq_cadastro)) {
        if ((leitura->id == id) && (leitura->ativo == 1)) {
            fclose(arq_cadastro);
            free(leitura);
            return 1;
        }
    }
    fclose(arq_cadastro);
    free(leitura);
    return 0;
}

int validarTempoPreparo(char* tempo) {
    int len = strlen(tempo);
    int temDoisPontos = 0;
    int temDigito = 0; 
    if (len < 2 || len > 10) return 0;   
    for (int i = 0; tempo[i] != '\0'; i++) {
        unsigned char c = (unsigned char) tempo[i];    
        if (isdigit(c)) { 
            temDigito = 1;
            continue;
        }
        if (c == ':' || c == 'h' || c == ' ') {
            if (c == ':' && temDoisPontos) return 0;
            if (c == ':') temDoisPontos = 1;
            if (c == 'h' && tempo[i+1] != '\0') return 0; 
            continue;
        } 
        return 0; 
    }
    return temDigito; 
}

int validarReceita(char* nomeObjeto, int idIngre, int idUsu, char* tempo){
    if ((validarNomeObjeto(nomeObjeto) == 1) && (validarIdIngrediente(idIngre) == 1) &&
    (validarIdUsuario(idUsu) == 1) && (validarTempoPreparo(tempo) == 1)){
        return 1;
    }else{
        return 0;
    }
}

int validarQuantidade(char* quant){
    int i;
    int tamanho = strlen(quant);
    if(tamanho == 0){
        return 0;
    }
    for(i = 0; i < tamanho; i++){
      if(!isdigit(quant[i])){
          return 0;
      }
    }
    return 1;
}

int validarIngrediente(char* nome, char* quant,char* unidade, char* tipo){
    if ((validarNomeObjeto(nome)==1 && (validarQuantidade(quant)==1) && 
    (validarNomeObjeto(unidade)==1) && (validarNomeObjeto(tipo)==1))){
        return 1;
    }else{
        return 0;
    }
    
    
}