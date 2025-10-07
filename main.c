//===========================================================================//
//              Universidade Federal do Rio Grande do Norte                  //
//                  Centro de Ensino Superior do Seridó                      //
//                Departamento de Computação e Tecnologia                    //
//                   Disciplina DCT1106 -- Programação                       //
//             Projeto Sistema de Gerenciamento de receitas Culinarias       //
//              Developed by  @pauloandrehxh e @nikcaellp                    //
//                              since august, 2025                           //
//===========================================================================//
//                    Semana 5 - Modularizando o Projeto                     //
//===========================================================================//

#include <stdio.h>
#include "telas.h"        // Incluindo funções de interface/telas
#include "utils.h"        // Incluindo funções utilitárias
#include "usuario.h"      // Incluindo funções de usuário
#include "receita.h"      // Incluindo funções de receita
#include "ingrediente.h"  // Incluindo funções de ingrediente

// Protótipos das funções
void gerenciarReceitas();
void gerenciarUsuarios();
void gerenciarModuloIngredientes();

int main()
{
    int opcao;
    do
    {
        limparTela();
        exibirMenu();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer

        // O switch direciona o fluxo do programa com base na escolha do usuário
        switch (opcao)
        {
        case 1:
            gerenciarReceitas();
            break;
        case 2:
            gerenciarModuloIngredientes();
            break;
        case 3:
            gerenciarUsuarios();
            break;
        case 4:
            telaSobre();
            break;
        case 5:
            telaCreditos();
            break;
        case 0:
            printf("\nObrigado por usar o SIG-Recipes! Ate mais.\n\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            pressioneEnterParaContinuar();
            break;
        }

    } while (opcao != 0);

    return 0;
}

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
            limparTela();
            cadastrarReceita();
            pressioneEnterParaContinuar();
            break;
        case 2:
            limparTela();
            listarReceitas();
            pressioneEnterParaContinuar();
            break;
        case 3:
            limparTela();
            printf("\nBuscando receita...\n");
            // funcionalidade a ser implementada
            pressioneEnterParaContinuar();
            break;
        case 4:
            limparTela();
            printf("\nEditando receita...\n");
            // funcionalidade a ser implementada
            pressioneEnterParaContinuar();
            break;
        case 5:
            limparTela();
            printf("\nExcluindo receita...\n");
            // funcionalidade a ser implementada
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

void gerenciarModuloIngredientes()
{
    int opcao_ingred;
    do
    {
        telaIngredientes();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao_ingred);
        while (getchar() != '\n'); // Limpa o buffer

        switch (opcao_ingred)
        {
        case 1:
            adicionarIngrediente();
            pressioneEnterParaContinuar();
            break;
        case 2:
            listarIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 3:
            editarIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 4:
            excluirIngredientes();
            pressioneEnterParaContinuar();
            break;
        case 0:
            break;
        default:
            limparTela();
            printf("\nOpção inválida! Tente novamente.\n");
            pressioneEnterParaContinuar();
            break;
        }
    } while (opcao_ingred != 0);
}

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
                limparTela();
                printf("\nBuscando usuario...\n");
                // funcionalidade a ser implementada
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