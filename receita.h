#ifndef RECEITA_H
#define RECEITA_H

typedef struct
{
    // Para quando for implementar a funcionalidade de múltiplos usuários
    // int id;
    // int idUsuario;
    
    char nome[100];
    char ingredientes[500];
    char modoPreparo[1000];
    int ativo;
} Receita;

/**
 * @brief Função para cadastrar uma nova receita.
 */
void cadastrarReceita(void);

/**
 * @brief Função para listar todas as receitas cadastradas.
 */
void listarReceitas(void);

// ... outras declarações

#endif