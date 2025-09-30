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
    lerString(novoUsuario.email,99);
    printf("\nDigite o Numero de Cpf: ");
    lerString(novoUsuario.cpf,29);
    printf("\nCasdastro de Senha MAX(10)caracteres: ");
    lerString(novoUsuario.senha,19);
   
    novoUsuario.ativo = 1;
    novoUsuario.id = totalUsuarios + 1; // ID sequencial
    
    /*cadastro[totalUsuarios] = novoUsuario;
    totalUsuarios ++;*/

    // Escrever coisas em um arquivo.
    FILE *arq_usuario = fopen("usuarios.csv", "at");
    if (arq_usuario == NULL) {
        printf("Error ao abrir o arquivo!!!.");
        return;
    }    
      fprintf(arq_usuario, "%d;%s;%s;%s;%s;%d\n",
            novoUsuario.id,           
            novoUsuario.nome,
            novoUsuario.email,
            novoUsuario.cpf,
            novoUsuario.senha,
            novoUsuario.ativo);

        fclose(arq_usuario);
    printf("\nUsuário cadastrado com sucesso!\n");
    }
void listarUsuarios()
 {
    Usuario leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    FILE *arq_usuario = fopen("usuarios.csv","rt");
        if (arq_usuario == NULL){
            printf("Error ao abrir o Arquvo");
            return 1;
        }
    while (fscanf(arq_usuario,"%d",&leitura.id)==1)
        {
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%99[^;]",leitura.nome);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%99[^;]",leitura.email);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%29[^;]",leitura.cpf);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%19[^;]",leitura.senha);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%d",&leitura.ativo);
            fgetc(arq_usuario);
            
            printf("=======================================\n");
            printf("ID:%d\n",leitura.id);
            printf("Nome:%s\n",leitura.nome);
            printf("Email:%s\n",leitura.email);
            printf("CPF:%s\n",leitura.cpf);
            printf("Senha:%s\n",leitura.senha);
            printf("Ativo:%d\n",leitura.ativo);
            
        }
      printf("=======================================\n");

    /*if (totalUsuarios == 0) // Verificação se existe Usuários na array 
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
    }   */
}