#include <stdio.h>
#include "usuario.h"
#include "utils.h"


#define MAX_USUARIOS 100
Usuario cadastro[MAX_USUARIOS];
int todosUsuarios = 0;

void cadastrarUsuario(void)
{
    if(todosUsuarios>=MAX_USUARIOS){
        printf("Maximo de Usuarios Cadastrados!\n");
        return;
    }
    Usuario novoUsuario;
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO USUARIO           ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    // todo esse Bloco é pra ser somente um protótipo, essa função será melhorada no futuro
    printf("Nome do Usuário: ");
    lerString( novoUsuario.nome,99); 
    printf("\nEmail do Usuário: ");
    lerString(novoUsuario.email,30);
    printf("\nDigite o Numero de Cpf: ");
    lerString(novoUsuario.cpf,20);
    printf("\nCasdastro de Senha MAX(10)caracteres: ");
    lerString(novoUsuario.senha,10);
    novoUsuario.ativo = 1;

    cadastro[todosUsuarios] = novoUsuario;
    todosUsuarios ++;

    printf("\nUsuário cadastrado com sucesso!\n");
}