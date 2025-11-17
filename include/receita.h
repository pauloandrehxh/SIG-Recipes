#ifndef RECEITA_H
#define RECEITA_H

typedef struct receita Receita;
struct receita{
    int id;
    char nome[100];
    int idIngrediente;
    int idUsuario;
    char tempoPreparo[10];
    int status;
};

typedef struct receitaLista ReceitaLista;
struct receitaLista{
    int id;
    char nome[100];
    int idIngrediente;
    int idUsuario;
    char tempoPreparo[10];
    struct receitaLista *prox;
};

void gerenciarReceitas();
void cadastrarReceita(void);
void listarReceitas(void);
void buscarReceita(void);
void editarReceita(void);
void excluirReceita(void);
#endif