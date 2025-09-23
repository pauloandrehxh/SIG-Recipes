#ifndef USUARIO_H
#define USUARIO_H

typedef struct
{
    int id;
    char nome[100];
    char email[50];
    char cpf[30];
    char senha[30];
    int ativo; // 1 para ativo, 0 para inativo/excluído
} Usuario;
/** 
 * @brief Função Protótipo de Cadastro de novo Usuário
**/
void cadastrarUsuario(void);

/** 
 * @brief Função Protótipo de Listagem dos Usuários
**/
void listarUsuarios(void);
#endif