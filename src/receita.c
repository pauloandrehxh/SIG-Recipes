#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/receita.h"
#include "../include/utils.h" 
#include "../include/telas.h" 

void gerenciarReceitas()
{
    int opcao_princ;
    do
    {
        telaPrincipal();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao_princ);
        while (getchar() != '\n'); // Limpa o buffer

        switch (opcao_princ)
        {
        case 1:
            cadastrarReceita();
            pressioneEnterParaContinuar();
            break;
        case 2:
            listarReceitas();
            pressioneEnterParaContinuar();
            break;
        case 3:
            buscarReceita();
            pressioneEnterParaContinuar();
            break;
        case 4:
            editarReceita();
            pressioneEnterParaContinuar();
            break;
        case 5:
            excluirReceita();
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
    } while (opcao_princ != 0);
}

void cadastrarReceita(void)
{
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║         CADASTRAR NOVA RECEITA          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");

    Receita *novaReceita;
    novaReceita = malloc(sizeof(Receita));
    char idIngr[10];
    char idUsu[10];
    memset(novaReceita, 0, sizeof(Receita));
    FILE *arq_receita;
    arq_receita = fopen("./dados/dadosReceita.dat", "ab");
   
    if (arq_receita == NULL) {
            perror("Erro ao abrir o arquivo");     
            free(novaReceita);
            return;
         }

    printf("Digite o nome da receita:");
    lerString(novaReceita->nome, sizeof(novaReceita->nome));

    printf("\nDigite o id dos ingredientes: ");
    lerString(idIngr, 10);
    novaReceita->idIngrediente = atoi(idIngr);
    printf("\nDigite o id dos usuário: ");
    lerString(idUsu, 10);
    novaReceita->idUsuario = atoi(idUsu);
    printf("\nExplique o tempo de preparo(ex: 1:30h): ");
    lerString(novaReceita->tempoPreparo, sizeof(novaReceita->tempoPreparo));

    if (validarReceita(novaReceita->nome,novaReceita->idIngrediente,novaReceita->idUsuario,novaReceita->tempoPreparo) == 1)
    {
        novaReceita->id = gerarReceitaId();
        novaReceita -> status = 1;
        fwrite(novaReceita, sizeof(Receita), 1, arq_receita);
        fclose(arq_receita);
        free(novaReceita); 
        printf("\nReceita cadastrada com sucesso!\n");
        return;
    }else
    {
        fclose(arq_receita);
        free(novaReceita); 
        printf("\nNome, id de usuário, id de ingrediente ou tempo de preparo estão errados!\n");
    }
    
}

void listarReceitas(void)
{
    int encontrado = 0;
    Receita *leitura; 
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receita = fopen("./dados/dadosReceita.dat","rb");
    
    if (arq_receita == NULL)
    {
        printf("Nenhuma Receita Cadastrada!\n");
        free(leitura);
        return; 
    }

    limparTela();
    printf("================================ LISTA DE RECEITAS INATIVAS ================================\n");
    printf("ID\tNome da Receita\t\t\tID Ingrediente\tID Usuário\ttempo de Preparo\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(leitura, sizeof(Receita), 1, arq_receita)) 
    {
        if (leitura -> status == 1) 
        {
            encontrado = 1;
            printf("%d\t%-25s\t%-14d\t%-11d\t%s\n", 
                   leitura -> id, 
                   leitura -> nome, 
                   leitura -> idIngrediente, 
                   leitura -> idUsuario, 
                   leitura -> tempoPreparo);
        }
    }
    
    if (!encontrado){
        printf("Nenhuma receita inativa encontrada.\n");
    }
    
    printf("===========================================================================================\n");
    fclose(arq_receita);
    free(leitura);
    return;
}
void buscarReceita(void)
{
    char nomeBusca[100];
    int encontrado = 0;
    Receita *leitura;
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receita = fopen("./dados/dadosReceita.dat","rb");
        if (arq_receita == NULL){
            printf("Nenhuma Receita Cadastrada!\n");
            free(leitura);
            return; }
    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           BUSCAR RECEITA                ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    printf("Digite o nome da receita que deseja buscar: ");
    lerString(nomeBusca, sizeof(nomeBusca));

    while (fread(leitura, sizeof(Receita),1 , arq_receita)) 
        {
            if (leitura -> status == 1 && strcmp(leitura->nome, nomeBusca) == 0) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("id: %d\n", leitura -> id);
            printf("Nome da Receita: %s\n", leitura -> nome);
            printf("id do Ingrediente: %d\n", leitura -> idIngrediente);
            printf("id do Usuario: %d\n", leitura -> idUsuario);
            printf("tempo de Preparo: %s\n", leitura -> tempoPreparo);
            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada com esse nome.\n");
        }
    printf("=======================================\n");
    fclose(arq_receita);
    free(leitura);
    return;
}

void editarReceita(void) {
    char idBusca[10];
    char novoTexto[50];
    char novoId[10];
    int op, encontrado = 0;
    Receita *altera = malloc(sizeof(Receita));

    FILE *arq_receita = fopen("./dados/dadosReceita.dat", "r+b"); 

    if (!arq_receita) {
        printf("Nenhuma receita cadastrada!\n");
        free(altera);
        return;
    }

    limparTela();
    printf("Digite o ID da receita que deseja editar: ");
    lerString(idBusca, 10);

    while (fread(altera, sizeof(Receita), 1, arq_receita)) {
        if (altera->status == 1 && altera->id == atoi(idBusca)) {
            encontrado = 1;
            long posicao = ftell(arq_receita) - sizeof(Receita);
            
            printf("Receita encontrada:\n");
            printf("ID: %d\n", altera->id);
            printf("Nome: %s\n", altera->nome);
            printf("Id de Ingredientes: %d\n", altera->idIngrediente);
            printf("Id de usuários: %d\n", altera->idUsuario);
            printf("tempo de Preparo: %s\n", altera->tempoPreparo);
            pressioneEnterParaContinuar();

            do {
                limparTela();
                telaEditarReceita();
                printf("Escolha uma opção: ");
                scanf("%d", &op);
                getchar();

                switch(op) {
                    case 1:
                        printf("Nome atual: %s\nNovo nome: ", altera->nome);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0  && (validarNomeObjeto(novoTexto)==1)) {
                            strcpy(altera->nome, novoTexto);
                            printf("Nome alterado com sucesso!");
                            pressioneEnterParaContinuar();
                        }else{
                            printf("Nome inválido!");
                            pressioneEnterParaContinuar();
                        }
                        break;

                    case 2:
                        printf("Ingredientes atuais: %d\nNovos ingredientes: ", altera->idIngrediente);
                        lerString(novoId, 10);
                        if (strlen(novoId) > 0 && (validarIdIngrediente(atoi(novoId)) == 1)) { 
                            altera->idIngrediente = atoi(novoId);
                            printf("Id de ingredientes alterado com sucesso!");
                            pressioneEnterParaContinuar();
                        }else{
                            printf("Id de ingrediente Inválido");
                            pressioneEnterParaContinuar();
                        }
                        
                        break;

                    case 3:
                        printf("Id de Usuário atual: %d\nNovo Id de usuário: ", altera->idUsuario);
                        lerString(novoId, 10);
                        if (strlen(novoId) > 0 && (validarIdUsuario(atoi(novoId)) == 1)) { 
                            altera->idUsuario = atoi(novoId);
                            printf("Id de usuário alterado com sucesso!");
                            pressioneEnterParaContinuar();
                        }else{
                            printf("Id de usuário Inválido");
                            pressioneEnterParaContinuar();
                        }
                        break;                       

                    case 4:
                        printf("tempo de preparo atual: %s\nNovo tempo de preparo: ", altera->tempoPreparo);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0 && (validarTempoPreparo(novoTexto)==1)) {
                            strcpy(altera->tempoPreparo, novoTexto);
                            printf("Tempo de preparo alterado com sucesso!");
                            pressioneEnterParaContinuar();
                        }else{
                            printf("Tempo de preparo Inválido");
                            pressioneEnterParaContinuar();
                        }
                        break;

                    case 0:
                        printf("Alterações concluídas!\n");
                        break;

                    default:
                        printf("Opção inválida!\n");
                        pressioneEnterParaContinuar();
                }

            } while (op != 0);

            fseek(arq_receita, posicao, SEEK_SET);
            fwrite(altera, sizeof(Receita), 1, arq_receita);
            break; 
        }
    }

    fclose(arq_receita);
    free(altera);

    if (!encontrado) {
        printf("Receita com o ID \"%s\" não encontrada.\n", idBusca);
    } else {
        printf("Receita atualizada com sucesso!\n");
    }
}

void excluirReceita() {
    int encontrado = 0;
    char idBusca[10];
    Receita *deleta;
    deleta = (Receita*) malloc(sizeof(Receita));
    FILE *arq_receita = fopen("./dados/dadosReceita.dat", "r+b"); // tempo leitura e escrita

    if (arq_receita == NULL) {
        printf("Nenhuma receita Cadastrada!!!!\n");
        free(deleta);
        return;
    }

    limparTela();
    printf("Digite o ID da receita que deseja excluir: ");
    lerString(idBusca, sizeof(idBusca));

    while (fread(deleta, sizeof(Receita), 1, arq_receita)) {
        if ((deleta->id == atoi(idBusca)) && (deleta->status == 1)) {
            encontrado = 1;
            long posicao = ftell(arq_receita) - sizeof(Receita); // Guarda a posição
            
            limparTela();
            printf("Receita encontrada:\n");
            printf("ID: %d\n", deleta->id);
            printf("Nome: %s\n", deleta->nome);
            printf("tempo de preparo: %s\n", deleta->tempoPreparo);
            printf("Ingredientes: %d\n", deleta->idIngrediente);
            printf("Id de Usuário: %d\n", deleta->idUsuario);
            printf("\nDeseja realmente excluir esta Receita (S/N): ");
            char confirmacao;
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                deleta->status = 0; 
                fseek(arq_receita, posicao, SEEK_SET);
                fwrite(deleta, sizeof(Receita), 1, arq_receita);
                printf("\nReceita marcada como inativa com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
            break;
        }
    }

    fclose(arq_receita);
    free(deleta);

    if (!encontrado) {
        printf("\nReceita com ID %s não encontrada ou já está inativa.\n", idBusca);
    }
}