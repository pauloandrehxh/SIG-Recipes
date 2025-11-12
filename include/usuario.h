#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario
{
    int id;
    char nome[100];
    char email[100];
    char cpf[30];
    char senha[30];
    int ativo; // 1 para ativo, 0 para inativo/excluído
} Usuario;

void gerenciarUsuarios();
/** 
 * @brief Função Protótipo de Cadastro de novo Usuário
**/
void cadastrarUsuario(void);

/** 
 * @brief Função Protótipo de Listagem dos Usuários
**/
void listarUsuarios(void);
/** 
 * @brief Função Protótipo para edição de dados de um Usuário
**/
void editarUsuario(void);
/** 
 * @brief Função Protótipo para exclusão Lógica de dados de um Usuário
**/
void excluirUsuario(void);
/**
 * @brief Função Protótipo para busca de dados de um Usuário
**/
void buscarUsuario(void);
void buscarUsuarioInativo();
void buscarUsuarioNome();

#endif