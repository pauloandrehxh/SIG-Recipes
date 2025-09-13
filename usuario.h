#ifndef USUARIO_H
#define USUARIO_H

typedef struct
{
    int id;
    char nome[100];
    char email[100];
    char senha[50];
    int ativo; // 1 para ativo, 0 para inativo/excluído
} Usuario;

void cadastrarUsuario(void);
// Outras declarações de funções que você precisará...

#endif