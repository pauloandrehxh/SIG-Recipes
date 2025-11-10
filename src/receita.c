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
    printf("\nExplique o modo de preparo: ");
    lerString(novaReceita->modoPreparo, sizeof(novaReceita->modoPreparo));

    novaReceita->id = gerarReceitaId();
    novaReceita -> status = 1;
    novaReceita -> id = 1;
    fwrite(novaReceita, sizeof(Receita), 1, arq_receita);
    fclose(arq_receita);
    free(novaReceita); 
    printf("\nReceita cadastrada com sucesso\n");
    return;
}

void listarReceitas(void)
{
    
    int encontrado = 0;
    Receita *leitura; // aqui estamos chamando o fomarto da ustruct receita, assim todos os tamanhos de variáveis já vem definidos no usuario.h
    leitura = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receita = fopen("./dados/dadosReceita.dat","rb");
    
    if (arq_receita == NULL)
    {
        printf("Nenhuma Receita Cadastrada!\n");
        free(leitura);
        return; 
    }            printf("id: %d\n", leitura -> id);

    limparTela();
    printf("╔═════════════════════════════════════════╗\n");
    printf("║           LISTAGEM DE RECEITAS          ║\n");
    printf("╚═════════════════════════════════════════╝\n\n");
    while (fread(leitura, sizeof(Receita),1 , arq_receita)) 
        {
            if (leitura -> status == 1) 
            {
            encontrado = 1;
            printf("=======================================\n");
            printf("id: %d\n", leitura -> id);
            printf("Nome da Receita: %s\n", leitura -> nome);
            printf("id do Ingrediente: %d\n", leitura -> idIngrediente);
            printf("id do Usuario: %d\n", leitura -> idUsuario);
            printf("Modo de Preparo: %s\n", leitura -> modoPreparo);

            }
        }
        if (!encontrado){
            printf("Nenhuma receita encontrada.\n");
        }
    printf("=======================================\n");
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
            printf("Modo de Preparo: %s\n", leitura -> modoPreparo);
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

void editarReceita(void)
{
    char idBusca[10];
    char novoTexto[200];
    char novoId[10];
    int op, encontrado = 0;
    Receita *altera = malloc(sizeof(Receita));

    FILE *arq_receita = fopen("./dados/dadosReceita.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

   if (!arq_receita) {
    printf("Nenhuma receita cadastrada!\n");
    free(altera);

        if (temp) {
        fclose(temp);
        remove("temp.dat");
            }

    return;
    }

    limparTela();
    printf("Digite o nome da receita que deseja editar: ");
    lerString(idBusca,10);


    while (fread(altera, sizeof(Receita), 1, arq_receita)) {
        if (altera-> status == 1 && altera->id == atoi(idBusca)) {
            encontrado = 1;
            printf("Receita encontrada:\n");
            printf("Nome: %s\n", altera->nome);
            printf("Id de Ingredientes %d\n", altera-> idIngrediente);
            printf("Id de usuários: %s\n", altera->idUsuario);
            printf("Modo de Preparo: %s\n", altera->modoPreparo);
            pressioneEnterParaContinuar();

            do {
                limparTela();
                telaEditarReceita();
                printf("Escolha uma opção: ");
                scanf("%d", &op);
                getchar();

                switch(op) {
                    case 1:
                        printf("Nome atual: %s\nNovo nome(ou pressione ENTER para manter): ", altera->nome);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->nome, novoTexto);
                        }
                        break;

                    case 2:
                        printf("Ingredientes atuais: %d\nNovos ingredientes(ou pressione ENTER para manter): ", altera->idIngrediente);
                        lerString(novoId, 10);
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->idIngrediente, atoi(novoId));
                        }
                        break;

                    case 3:
                        printf("Id de Usuário atual: %s\nNovo Id de usuário(ou pressione ENTER para manter): ", altera->idUsuario);
                        lerString(novoId, 10);
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->idUsuario, atoi(novoId));
                        }
                        break;                       

                    case 4:
                        printf("Modo de preparo atual: %s\nNovo modo de preparo(ou pressione ENTER para manter): ", altera->modoPreparo);
                        lerString(novoTexto, sizeof(novoTexto));
                        if (strlen(novoTexto) > 0){
                            strcpy(altera->modoPreparo, novoTexto);
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
        }

        fwrite(altera, sizeof(Receita), 1, temp);
    }

    fclose(arq_receita);
    fclose(temp);
    free(altera);

    if (!encontrado) {
        printf("Receita com o nome \"%s\" não encontrada.\n", nomeBusca);
        remove("temp.dat");
    } else {
        remove("receitas.dat");
        rename("temp.dat", "receitas.dat");
        printf("Receita atualizada com sucesso!\n");
    }

}
void excluirReceita() {
    int encontrado = 0;
    char nomeBusca[100];
    Receita *deleta;
    deleta = (Receita*) malloc (sizeof(Receita));
    FILE *arq_receita = fopen("receitas.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (arq_receita == NULL) 
    {
        printf("Nenhuma receita Cadastrada!!!!\n");
        if (temp != NULL)
        { // fecha se chegou a abrir
            fclose(temp);
            remove("temp.dat");
            free(deleta);
        } // garante que não fique lixo no disco
        return;
    }

    limparTela();
    printf("Digite o nome da receita que deseja excluir: ");
    lerString(nomeBusca, sizeof(nomeBusca));

    while (fread(deleta, sizeof(Receita), 1, arq_receita))
    {
       
        if ((strcmp(deleta->nome, nomeBusca) == 0) && (deleta-> status == 1)) {
            encontrado = 1;
            limparTela();
            printf("Usuário encontrado:\n");
            printf("Nome: %s\nModo de preparo: %s\nIngredientes: %s\n", 
                    deleta->nome, 
                    deleta->modoPreparo, 
                    deleta->ingredientes);
            printf("\nDeseja realmente excluir esta Receita (S/N): ");
            char confirmacao;
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                deleta-> status = 0; // “Exclusão lógica”
                printf("\nReceita marcado como inativo com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
        }

        // Salva todos os registros (alterado ou não)
        fwrite(deleta, sizeof(Receita), 1, temp);
    }

    fclose(arq_receita);
    fclose(temp);
    free(deleta);
    if (!encontrado) 
    {
        printf("\nReceita %s não encontrado ou já está inativo.\n", nomeBusca);
        remove("temp.dat");
        return;
    } 
    else 
    {
        remove("receitas.dat");
        rename("temp.dat", "receitas.dat");
        return;
    }

}