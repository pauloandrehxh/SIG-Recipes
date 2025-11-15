#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario Usuario;
struct usuario{
    int id;
    char nome[100];
    char email[100];
    char cpf[30];
    int ativo; // 1 para ativo, 0 para inativo/excluído
};
typedef struct usuarioLista UsuarioLista;
struct usuarioLista{
    int id;
    char nome[100];
    char email[100];
    char cpf[30];
    struct usuarioLista *prox;   
};

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

#endif