#include <stdio.h>
#include "usuario.h"
#include "utils.h"


#define MAX_USUARIOS 100
Usuario cadastro[MAX_USUARIOS];
int totalUsuarios = 0;

void cadastrarUsuario(void)
{ 
    if(totalUsuarios>=MAX_USUARIOS){
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
    novoUsuario.id = totalUsuarios + 1; // ID sequencial
    cadastro[totalUsuarios] = novoUsuario;
    totalUsuarios ++;

    // Escrever coisas em um arquivo.
    FILE *arq_usuario = fopen("usuarios.csv", "at");
    char linha[255];
    if (arq_usuario == NULL) {
        printf("Ops! Esse arquivo não existe ainda.");
        exit(1);
    }    
        printf("\nUsuário cadastrado com sucesso!\n");

    //while (fscanf(arq_usuario,"%[^\n]", linha) == 1) {
        fprintf(arq_usuario, "%s;%s;%s;%s;%d\n", novoUsuario.nome, novoUsuario.email, 
        novoUsuario.cpf, novoUsuario.senha, novoUsuario.ativo);
        //fgetc(arq_usuario);
    //}
        printf("\nUsuário cadastrado com sucesso!\n");

    fclose(arq_usuario);

    printf("\nUsuário cadastrado com sucesso!\n");
}
void listarUsuarios()
 {
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    if (totalUsuarios == 0) // Verificação se existe Usuários na array 
    {    
        printf("Nenhum Usuário foi Encontrado.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) // Ao passar pelo if Imprime a lista de dados de Usuário
    {   
        printf("=======================================\n");
        printf(" Usuário ID:%d\n",cadastro[i].id);
        printf(" NOME: %s\n", cadastro[i].nome);
        printf(" EMAIL: %s\n", cadastro[i].email);
        printf(" CPF: %s\n", cadastro[i].cpf);
        printf("=======================================\n");
    }
}