#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct ingrediente
{
    int id;
    char nome[50];
    char quantidade[20];
    char unidade[20]; // gramas, kilos, litros
    int status;
} Ingrediente;

void gerenciarModuloIngredientes();

void adicionarIngrediente(void);

void listarIngredientes(void);

void editarIngredientes(void);

void excluirIngredientes(void);

#endif