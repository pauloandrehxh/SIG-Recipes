//===========================================================================//
//              Universidade Federal do Rio Grande do Norte                  //
//                  Centro de Ensino Superior do Seridó                      //
//                Departamento de Computação e Tecnologia                    //
//                   Disciplina DCT1106 -- Programação                       //
//             Projeto Sistema de Gerenciamento de receitas Culinarias       //
//              Developed by  @pauloandrehxh e @nikcaellp                    //
//                              since august, 2025                           //
//===========================================================================//
//                    Semana 11 - Validação de dados                         //
//===========================================================================//

#include <stdio.h>
#include "include/telas.h"        // Incluindo funções de interface/telas
#include "include/utils.h"        // Incluindo funções utilitárias
#include "include/usuario.h"      // Incluindo funções de usuário
#include "include/receita.h"      // Incluindo funções de receita
#include "include/ingrediente.h"  // Incluindo funções de ingrediente


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
