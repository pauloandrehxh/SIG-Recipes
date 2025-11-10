#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/usuario.h"
#include "../include/utils.h"
#include "../include/telas.h"

void gerenciarUsuarios()
{
    int opcao_usuario;
    do
    {
        telaUsuario();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao_usuario);
        while (getchar() != '\n'); // Limpa o buffer

        switch (opcao_usuario)
        {
            case 1:
                cadastrarUsuario();
                pressioneEnterParaContinuar();
                break;
            case 2:
                editarUsuario();
                pressioneEnterParaContinuar();
                break;
            case 3:
                excluirUsuario();
                pressioneEnterParaContinuar();
                break;    
            case 4:
                listarUsuarios();
                pressioneEnterParaContinuar();
                break;
            case 5:
                buscarUsuario();
                pressioneEnterParaContinuar();
                break;    
            case 0:
                break;
            default:
                limparTela();
                printf("\nOpcao invalida! Tente novamente.\n");
                pressioneEnterParaContinuar();
                break;
        }
    } while (opcao_usuario != 0);
}

void cadastrarUsuario(void)
{ 
    Usuario *novoUsuario;
    novoUsuario = (Usuario*) malloc(sizeof(Usuario));
    FILE *arqUsuario;
    arqUsuario = fopen("./dados/dadosUsuario.dat", "ab");
    if (arqUsuario == NULL) {
        perror("Erro ao abrir o arquivo");       
        free(novoUsuario);
        return;
    }


    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║        ADICIONAR NOVO USUARIO           ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    printf("Nome do Usuário: ");
    lerString(novoUsuario->nome, sizeof(novoUsuario->nome));

    printf("\nEmail do Usuário: ");
    lerString(novoUsuario->email, sizeof(novoUsuario->email));
    
    printf("\nDigite o Número de CPF: ");
    lerString(novoUsuario->cpf, sizeof(novoUsuario->cpf));

    printf("\nCadastro de Senha (máx. 10 caracteres): ");
    lerString(novoUsuario->senha, sizeof(novoUsuario->senha));

    novoUsuario -> ativo = 1;
    novoUsuario -> id = gerarUsuarioId();
    fwrite(novoUsuario, sizeof(Usuario), 1, arqUsuario);
    fclose(arqUsuario);
    free(novoUsuario); 
    printf("\nUsuário cadastrado com sucesso!\n");
    return;
}

void listarUsuarios()
 {  
    int encontrado = 0;
    Usuario *leitura; // aqui estamos chamando o fomarto da ustruct usuario, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("./dados/dadosUsuario.dat","rb");
        if (arq_cadastro == NULL){
            printf("Nenhum Usuário Cadastrado!\n");
            return;
    }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         LISTA DE USUÁRIOS               ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    while (fread(leitura, sizeof(Usuario),1 , arq_cadastro)) 
    {   
        if (leitura -> ativo == 1) 
        {
        encontrado = 1;
        printf("=======================================\n");
        printf("ID: %d\n", leitura -> id);
        printf("Nome: %s\n", leitura -> nome);
        printf("Email: %s\n", leitura -> email);
        printf("CPF: %s\n", leitura -> cpf);
        printf("Senha: %s\n", leitura -> senha);
        }
    }
    if (!encontrado){
        printf("Nenhum usuário ativo encontrado.\n");
     }
    printf("=======================================\n");
    fclose(arq_cadastro);
    free(leitura);
    return;
    
}

void editarUsuario() {
    int idBusca, op, encontrado = 0;
    char novoNome[100]; //Serve para a alteração de nome e para email tbm
    char novaConfig[30]; 
    Usuario *altera;
    altera = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("cadastro.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (arq_cadastro == NULL) 
    {
        printf("Nenhum Usuário Cadastrado!!!!\n");
        if (temp != NULL) fclose(temp);
        { // fecha se chegou a abrir
            remove("temp.dat");
            free(altera);
        } // garante que não fique lixo no disco
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja alterar: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer
    
    while (fread(altera, sizeof(Usuario), 1, arq_cadastro))
    {
        if ((altera -> id == idBusca) && (altera -> ativo == 1)) 
        {
            encontrado = 1;
            printf("Usuário encontrado!!!\n");
            printf("ID: %d\n", altera -> id);
            printf("Nome: %s\n", altera -> nome);
            pressioneEnterParaContinuar();

            do 
            {
                limparTela();
                telaEditarUser(); // Menu de Tela visual das opções de alterações
                printf("Digite uma opção: ");
                scanf("%d", &op);
                getchar();

                switch (op) 
                {
                    case 1:
                        printf("Nome atual: %s\n", altera -> nome);
                        printf("Novo nome (ou pressione ENTER para manter): ");
                        lerString(novoNome, sizeof(novoNome));
                        if (strlen(novoNome) > 0)
                        {
                            strcpy(altera -> nome, novoNome);
                        }
                        break;

                    case 2:
                        printf("Email atual: %s\n", altera -> email);
                        printf("Novo email (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera -> email, novaConfig);
                        }
                        break;

                    case 3:
                        printf("CPF atual: %s\n", altera -> cpf);
                        printf("Novo CPF (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera -> cpf, novaConfig);
                        }
                        break;

                    case 4:
                        printf("Senha atual: %s\n", altera -> senha);
                        printf("Nova senha (ou pressione ENTER para manter): ");
                        lerString(novaConfig, sizeof(novaConfig));
                        if (strlen(novaConfig) > 0)
                        {
                            strcpy(altera -> senha, novaConfig);
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
        fwrite(altera, sizeof(Usuario), 1, temp);
    }
        // Salva todos os registros (alterado ou não)
    fclose(arq_cadastro);
    fclose(temp);
    free(altera);

    if (!encontrado) {
        printf("Usuário com ID %d não encontrado.\n", idBusca);
        remove("temp.dat");
        return;
    } else {
        remove("cadastro.dat");
        rename("temp.dat", "cadastro.dat");
        printf("Dados atualizados com sucesso!\n");
        return;
    }
}

void excluirUsuario() {
    int idBusca, encontrado = 0;
    Usuario *deleta;
    deleta = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_usuario = fopen("cadastro.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (arq_usuario == NULL) 
    {
        printf("Nenhum Usuário Cadastrado!!!!\n");
        if (temp != NULL)
        { // fecha se chegou a abrir
            fclose(temp);
            remove("temp.dat");
            free(deleta);
        } // garante que não fique lixo no disco
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer

    while (fread(deleta, sizeof(Usuario), 1, arq_usuario))
    {
       
        if ((deleta->id == idBusca) && (deleta->ativo == 1)) {
            encontrado = 1;
            limparTela();
            printf("Usuário encontrado:\n");
            printf("ID: %d\nNome: %s\nEmail: %s\nCPF: %s\n", 
                    deleta->id, 
                    deleta->nome, 
                    deleta->email, 
                    deleta->cpf);
            printf("\nDeseja realmente excluir este usuário? (S/N): ");
            char confirmacao;
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                deleta->ativo = 0; // “Exclusão lógica”
                printf("\nUsuário marcado como inativo com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
        }

        // Salva todos os registros (alterado ou não)
        fwrite(deleta, sizeof(Usuario), 1, temp);
    }

    fclose(arq_usuario);
    fclose(temp);
    free(deleta);
    if (!encontrado) {
        printf("\nUsuário com ID %d não encontrado ou já está inativo.\n", idBusca);
        remove("temp.dat");
        return;
    } else {
        remove("cadastro.dat");
        rename("temp.dat", "cadastro.dat");
        return;
    }

}

void buscarUsuario(void) 
{
    int idBusca, encontrado = 0;
    Usuario *leitura;
    leitura = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("cadastro.dat", "rb");

    if (arq_cadastro == NULL) {
        printf("Nenhum Usuário Cadastrado!\n");
        free(leitura);
        return;
    }

    limparTela();
    printf("Digite o ID do usuário que deseja buscar: ");
    scanf("%d", &idBusca);
    getchar(); // limpa buffer

    while (fread(leitura, sizeof(Usuario), 1, arq_cadastro)) {
        if ((leitura->id == idBusca) && (leitura->ativo == 1)) {
            encontrado = 1;
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", leitura->id);
            printf("Nome: %s\n", leitura->nome);
            printf("Email: %s\n", leitura->email);
            printf("CPF: %s\n", leitura->cpf);
            printf("Senha: %s\n", leitura->senha);
            break; // Sai do loop após encontrar o usuário
        }
    }

    if (!encontrado) {
        printf("Usuário com ID %d não encontrado ou está inativo.\n", idBusca);
    }

    fclose(arq_cadastro);
    free(leitura);
    return;
}

