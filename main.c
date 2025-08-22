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
#include "telas.h"     // Incluindo funções de interface/telas
#include "utils.h"  // Incluindo funções utilitárias 

int main() {
    int opcao;

    // O loop do-while garante que o menu seja exibido pelo menos uma vez
    // e continue aparecendo até que o usuário escolha a opção 0 para sair.
    do {
        limparTela();
        exibirMenu();
        
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // O switch direciona o fluxo do programa com base na escolha do usuário
        switch (opcao) {
            case 1:
                telaPrincipal();
                break;
            case 2:
                telaSobre();
                break;
            case 3:
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