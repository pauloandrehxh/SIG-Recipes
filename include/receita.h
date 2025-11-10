#ifndef RECEITA_H
#define RECEITA_H

typedef struct receita 
{
    int id;
    char nome[100];
    int idIngrediente;
    int idUsuario;
    char modoPreparo[1000];
    int status;
} Receita;

void gerenciarReceitas();
/**
 * @brief Função para cadastrar uma nova receita.
 */
void cadastrarReceita(void);

/**
 * @brief Função para listar todas as receitas cadastradas.
 */
void listarReceitas(void);
/**
 * @brief Função para buscar uma receita pelo nome.
 */
void buscarReceita(void);
/**
 * @brief Função para editar os dados de uma receita.
 */
void editarReceita(void);
/**
 * @brief Função para excluir uma receita.
 */
void excluirReceita(void);
void buscarReceitaInativa(void);
#endif