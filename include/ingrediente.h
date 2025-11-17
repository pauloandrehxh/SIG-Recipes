#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct ingrediente
{
    int id;
    char nome[50];
    char quantidade[20];
    char unidade[20];
    char tipo[20];
    int status;
} Ingrediente;
typedef struct ingredienteLista
{
    int id;
    char nome[50];
    char quantidade[20];
    char unidade[20];
    char tipo[20];
    struct ingredienteLista* prox;
} IngredienteLista;

void gerenciarModuloIngredientes();

void adicionarIngrediente(void);

void listarIngredientes(void);

void editarIngredientes(void);

void excluirIngredientes(void);

#endif