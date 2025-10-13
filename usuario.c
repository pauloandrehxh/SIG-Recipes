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
    Usuario *novoUsuario;
    novoUsuario = malloc(sizeof(Usuario));

    if(totalUsuarios>=MAX_USUARIOS){
        printf("Maximo de Usuarios Cadastrados!\n");
        return;
    }
    
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO USUARIO           ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome do Usuário:");
    scanf("%c", &novoUsuario -> nome[100]);
    lerString(novoUsuario -> nome,99); 
    printf("\nEmail do Usuário:");
    scanf("%c", &novoUsuario -> email[30]);
    lerString(novoUsuario -> email,30);
    printf("\nDigite o Numero de Cpf:");
    scanf("%c", &novoUsuario -> cpf[20]);
    lerString(novoUsuario -> cpf,20);
    printf("\nCasdastro de Senha MAX(10)caracteres:");
    scanf("%c", &novoUsuario -> senha[10]);
    lerString(novoUsuario -> senha,10);

    novoUsuario -> ativo = 1;
    novoUsuario -> id = verificaNum();
    novoUsuario -> id ++; // ID sequencial
    totalUsuarios = verificaNum();

    // Escrever coisas em um arquivo.
    FILE *arq_cadastro;
    arq_cadastro = fopen("cadastro.dat", "w+b");
    if (arq_cadastro == NULL) {
        printf("Arquivo inexistente\n");
        exit(1);
    }
    fwrite(novoUsuario, sizeof(Usuario), 1, arq_cadastro);
    fclose(arq_cadastro);
    free(novoUsuario); 
}


void listarUsuarios()
 {  
    Usuario *leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = malloc (sizeof(leitura));
    FILE *arq_cadastro = fopen("usuarios.","r+b");
        if (arq_cadastro == NULL){
            printf("Nenhum Usuário Cadastrado!");
            exit(1);
    }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Usuario),1 , arq_cadastro) && (leitura -> ativo ==1)) {
        printf("Nome: %c\n", leitura -> nome[100]);
        printf("Email: %c\n", leitura -> email[100]);
        printf("CPF: %c\n", leitura -> cpf[30]);
        printf("Idade: %d\n", leitura -> senha[30]);
    }
    fclose(arq_cadastro);
    free(leitura);
    /*if (totalUsuarios == 0) // Verificação se existe Usuários na array 
        {    
        printf("Nenhum Usuário foi Encontrado.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) // Ao passar pelo if Imprime a lista de dados de Usuário
    {   novoUsuario
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

