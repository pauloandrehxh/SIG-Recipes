#ifndef RECEITA_H
#define RECEITA_H

typedef struct
{
    int id;
    int idUsuario; // Para saber a quem a receita pertence
    char nome[100];
    char ingredientes[500];
    char modoPreparo[1000];
    int ativo;
} Receita;

Receita cadastrarReceita(void);

// ... outras declarações

#endif