//===========================================================================//
//              Universidade Federal do Rio Grande do Norte                  //
//                  Centro de Ensino Superior do Seridó                      //
//                Departamento de Computação e Tecnologia                    //
//                   Disciplina DCT1106 -- Programação                       //
//             Projeto Sistema de Gerenciamento de receitas Culinarias       //
//              Developed by  @pauloandrehxh e @nikcaellp                    //
//                              since august, 2025                           //
//===========================================================================//
//                                 Semana 1                                  //
//===========================================================================//

#include <stdio.h>
#include "telas.h" // Incluindo funções de interface/telas
#include "utils.h" // Incluindo funções utilitárias

int main()
{
    int opcao, opcao_princ;

    // O loop do-while garante que o menu seja exibido pelo menos uma vez
    // e continue aparecendo até que o usuário escolha a opção 0 para sair.
    do
    {   
        limparTela();
        exibirMenu();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // O switch direciona o fluxo do programa com base na escolha do usuário
        switch (opcao)
        {
        case 1:
            do
            {
                telaPrincipal();
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao_princ);
                switch (opcao_princ)
                {
                case 1:
                    limparTela();
                    printf("\nCadastrando nova receita...\n");
                    // funcionalidade a ser implementada
                    pressioneEnterParaContinuar();
                    break;
                case 2:
                    limparTela();
                    printf("\nLista de receitas...\n");
                    // funcionalidade a ser implementada
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
                case 6:
                    telaIngredientes();
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao_princ);
                    limparTela();
                    printf("\nGerenciando ingredientes...\n");
                    // funcionalidade a ser implementada
                    pressioneEnterParaContinuar();
                    break;
                case 0:
                    printf("\nRetornando ao menu anterior.\n");
                    pressioneEnterParaContinuar();
                    break;
                default:
                    limparTela();
                    printf("\nOpcao invalida! Tente novamente.\n");
                    pressioneEnterParaContinuar();
                    break;
                }
            } while (opcao_princ != 0);
            break;
        case 2:
            telaUsuario();
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            limparTela();
            printf("\nGerenciando Usuários...\n");
            pressioneEnterParaContinuar();
            break;
        case 3:
            telaSobre();
            break;
        case 4:
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