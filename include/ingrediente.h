#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct 
{
    char nome[50];
    float quantidade;
    char unidade[20]; // gramas, kilos, litros
    int ativo;
} Ingrediente;

void adicionarIngrediente(void);

void listarIngredientes(void);

void editarIngredientes(void);

void excluirIngredientes(void);

#endif