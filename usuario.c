#include "usuario.h"
#include <stdio.h>

void cadastrarUsuario(void)
{
    Usuario novoUsuario;
    printf("## Cadastrar Novo Usuário ##\n");
    printf("Nome: ");
    scanf(" %[^\n]", novoUsuario.nome); // Lê o nome com espaços
    printf("Email: ");
    scanf(" %[^\n]", novoUsuario.email);
    printf("Senha: ");
    scanf(" %[^\n]", novoUsuario.senha);
    novoUsuario.ativo = 1;

    // todo: código para salvar o usuário no banco de dados ou arquivo
    printf("\nUsuário cadastrado com sucesso!\n");
}