#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"
#include "telas.h"

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
    lerString( novoUsuario.nome,sizeof(novoUsuario.nome)); 
    printf("\nEmail do Usuário: ");
    lerString(novoUsuario.email,sizeof(novoUsuario.email));
    printf("\nDigite o Numero de Cpf: ");
    lerString(novoUsuario.cpf,sizeof(novoUsuario.cpf));
    printf("\nCasdastro de Senha MAX(20)caracteres: ");
    lerString(novoUsuario.senha,sizeof(novoUsuario.senha));
   
    novoUsuario.ativo = 1;
    novoUsuario.id = verificaNum();
    novoUsuario.id ++; // ID sequencial
    
    /*cadastro[totalUsuarios] = novoUsuario;
    */
     totalUsuarios = verificaNum();

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
    printf("\nID do Usuário:%d\n",novoUsuario.id);

    }
void listarUsuarios()
 {  
    int ativo = 0;
    Usuario leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    FILE *arq_usuario = fopen("usuarios.csv","rt");
        if (arq_usuario == NULL){
            printf("Nenhum Usuário Cadastrado!!!!");
            return;
        }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

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
            ativo = leitura.ativo;
            
            if (ativo == 1)
            {
                printf("=======================================\n");
                printf("ID:%d\n",leitura.id);
                printf("Nome:%s\n",leitura.nome);
                printf("Email:%s\n",leitura.email);
                printf("CPF:%s\n",leitura.cpf);
            }
            
        }
    printf("=======================================\n");
    fclose(arq_usuario);
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

void editarUsuario() {
    int idBusca, op, encontrado = 0;
    char novoNome[100]; //Serve para a alteração de nome e para email tbm
    char novaConfig[30]; 
    Usuario altera;
    FILE *arq_usuario = fopen("usuarios.csv", "rt");
    FILE *temp = fopen("temp.csv", "wt");

    if (arq_usuario == NULL) 
    {
        printf("Nenhum Usuário Cadastrado!!!!\n");
        if (temp != NULL) fclose(temp);
        { // fecha se chegou a abrir
            remove("temp.csv");
        } // garante que não fique lixo no disco
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja alterar: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer

    while (fscanf(arq_usuario, "%d", &altera.id) == 1)
    {
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%99[^;]", altera.nome);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%99[^;]", altera.email);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%29[^;]", altera.cpf);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%19[^;]", altera.senha);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%d", &altera.ativo);
        fgetc(arq_usuario);

        if ((altera.id == idBusca) && (altera.ativo == 1)) 
        {
            encontrado = 1;
            printf("Usuário encontrado!!!\n");
            printf("Nome: %s\nEmail: %s\nCPF: %s\n", altera.nome, altera.email, altera.cpf);
            pressioneEnterParaContinuar();

            do 
            {
                limparTela();
                telaEditar(); // Menu de Tela visual das opções de alterações
                printf("Digite uma opção: ");
                scanf("%d", &op);
                getchar();

                switch (op) 
                {
                    case 1:
                        printf("Nome atual: %s\n", altera.nome);
                        printf("Novo nome (ou pressione ENTER para manter): ");
                        lerString(novoNome, sizeof(novoNome));
                        if (strlen(novoNome) > 0)
                        {
                            strcpy(altera.nome, novoNome);
                        }
                        break;

                    case 2:
                        printf("Email atual: %s\n", altera.email);
                        printf("Novo email (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera.email, novaConfig);
                        }
                        break;

                    case 3:
                        printf("CPF atual: %s\n", altera.cpf);
                        printf("Novo CPF (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera.cpf, novaConfig);
                        }
                        break;

                    case 4:
                        printf("Senha atual: %s\n", altera.senha);
                        printf("Nova senha (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera.senha, novaConfig);
                        }
                        break;

                    case 0:
                        printf("Alterações concluídas!\n");
                        break;

                    default:
                        printf("Opção inválida!\n");
                        pressioneEnterParaContinuar();
                        break;
                }

            }while (op != 0);
        }

        // Salva todos os registros (alterado ou não)
        fprintf(temp, "%d;%s;%s;%s;%s;%d\n",
                altera.id,
                altera.nome,
                altera.email,
                altera.cpf,
                altera.senha,
                altera.ativo);
    }

    fclose(arq_usuario);
    fclose(temp);

    if (!encontrado) {
        printf("Usuário com ID %d não encontrado.\n", idBusca);
        remove("temp.csv");
    } else {
        remove("usuarios.csv");
        rename("temp.csv", "usuarios.csv");
        printf("Dados atualizados com sucesso!\n");
    }
}

void excluirUsuario() {
    int idBusca, encontrado = 0;
    Usuario deleta;
    FILE *arq_usuario = fopen("usuarios.csv", "rt");
    FILE *temp = fopen("temp.csv", "wt");

    if (arq_usuario == NULL) 
    {
        printf("Nenhum Usuário Cadastrado!!!!\n");
        if (temp != NULL) fclose(temp);
        { // fecha se chegou a abrir
            remove("temp.csv");
        } // garante que não fique lixo no disco
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer

    while (fscanf(arq_usuario, "%d", &deleta.id) == 1) {
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%99[^;]", deleta.nome);
        fgetc(arq_usuario); 
        fscanf(arq_usuario, "%99[^;]", deleta.email);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%29[^;]", deleta.cpf);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%19[^;]", deleta.senha);
        fgetc(arq_usuario);
        fscanf(arq_usuario, "%d", &deleta.ativo);
        fgetc(arq_usuario);

        if ((deleta.id == idBusca) && (deleta.ativo == 1)) {
            encontrado = 1;
            limparTela();
            printf("Usuário encontrado:\n");
            printf("ID: %d\nNome: %s\nEmail: %s\nCPF: %s\n", 
                    deleta.id, deleta.nome, deleta.email, deleta.cpf);
            printf("\nDeseja realmente excluir este usuário? (S/N): ");
            char confirmacao;
            scanf("%c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                deleta.ativo = 0; // “Exclusão lógica”
                printf("\nUsuário marcado como inativo com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
        }

        // Salva todos os registros (alterado ou não)
        fprintf(temp, "%d;%s;%s;%s;%s;%d\n",
                deleta.id,
                deleta.nome,
                deleta.email,
                deleta.cpf,
                deleta.senha,
                deleta.ativo);
    }

    fclose(arq_usuario);
    fclose(temp);

    if (!encontrado) {
        printf("\nUsuário com ID %d não encontrado ou já está inativo.\n", idBusca);
        remove("temp.csv");
    } else {
        remove("usuarios.csv");
        rename("temp.csv", "usuarios.csv");
    }

}

