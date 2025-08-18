#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") e system("clear")

// Protótipos das funções (declarações para que o compilador as conheça)
void limparTela();
void pressioneEnterParaContinuar();
void exibirMenu();
void telaPrincipal();
void telaSobre();
void telaCreditos();

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

/**
 * @brief Limpa a tela do console.
 * Funciona em diferentes sistemas operacionais.
 */
void limparTela() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux e macOS
    #endif
}

/**
 * @brief Pausa o programa até que o usuário pressione a tecla Enter.
 */
void pressioneEnterParaContinuar() {
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de entrada para evitar que leituras anteriores interfiram
    while (getchar() != '\n'); // Limpa o buffer do teclado (importante!)
    getchar(); // Aguarda o Enter
}

/**
 * @brief Exibe o menu de navegação principal.
 */
void exibirMenu() {
    printf("/======================================================================\\\n");
    printf("|| _____ _____ _____      ______ _____ _____ ___________ _____ _____  ||\n");
    printf("||/  ___|_   _|  __ \\     | ___ \\  ___/  __ \\_   _| ___ \\  ___/  ___| ||\n");
    printf("||\\ `--.  | | | |  \\/_____| |_/ / |__ | /  \\/ | | | |_/ / |__ \\ `--.  ||\n");
    printf("|| `--. \\ | | | | _|______|    /|  __|| |     | | |  __/|  __| `--. \\ ||\n");
    printf("||/\\__/ /_| |_| |_\\ \\     | |\\ \\| |___| \\__/\\_| |_| |   | |___/\\__/ / ||\n");
    printf("||\\____/ \\___/ \\____/     \\_| \\_\\____/ \\____/\\___/\\_|   \\____/\\____/  ||\n");
    printf("||====================================================================||\n");
    printf("||  [1] Caderno de Receitas (Tela Principal)                          ||\n");
    printf("||  [2] Sobre o Projeto                                               ||\n");
    printf("||  [3] Creditos                                                      ||\n");
    printf("||  [0] Sair                                                          ||\n");
    printf("\\======================================================================/\n\n");
}

/**
 * @brief Exibe a tela principal do sistema de receitas.
 */
void telaPrincipal() {
    limparTela();
    printf("/======================================================================\\\n");
    printf("||                         CADERNO DE RECEITAS                        ||\n");
    printf("||====================================================================||\n");
    printf("||  Aqui voce pode gerenciar suas receitas                            ||\n");
    printf("\\======================================================================/\n\n");

    //
    // AQUI ENTRARIA O SUB-MENU E AS FUNÇÕES
    // Ex: Opções para Adicionar, Listar, Buscar Receitas...
    //
    
    printf("... (Funcionalidades de receitas a serem implementadas aqui) ...\n");
    
    pressioneEnterParaContinuar();
}

/**
 * @brief Exibe informações sobre o projeto SIG-Recipes.
 */
void telaSobre() {
    limparTela();
    printf("/======================================================================\\\n");
    printf("||                         SOBRE O PROJETO                            ||\n");
    printf("||====================================================================||\n");
    printf("||  SIG-Recipes e um sistema de gerenciamento de receitas             ||\n");
    printf("||  culinarias desenvolvido como um projeto de estudo da              ||\n");
    printf("||  linguagem C.                                                      ||\n");
    printf("||  Objetivo: Permitir que os usuarios criem, visualizem,             ||\n");
    printf("||  editem e excluam suas receitas favoritas, tudo isso               ||\n");
    printf("||  atraves de uma interface de console simples e intuitiva           ||\n");
    printf("\\======================================================================/\n\n");

    
    pressioneEnterParaContinuar();
}

/**
 * @brief Exibe os créditos dos desenvolvedores do projeto.
 */
void telaCreditos() {
    limparTela();
    printf("/======================================================================\\\n");
    printf("||                              CREDITOS                              ||\n");
    printf("||====================================================================||\n");
    printf("||  Este projeto foi desenvolvido por:                                ||\n");
    printf("||                                                                    ||\n");
    printf("||    -> Paulo André A. Moura                                        ||\n");
    printf("||       - GitHub: @pauloandrehxh                                     ||\n");
    printf("||                                                                    ||\n");
    printf("||    -> Nikcael Lopes                                                ||\n");
    printf("||       - GitHub: @nikcaellp                                         ||\n");
    printf("||                                                                    ||\n");
    printf("||  Disciplina: Programação                                         ||\n");
    printf("||  Professor(a): Flavius Gorgônio                                   ||\n");
    printf("\\======================================================================/\n\n");

    pressioneEnterParaContinuar();
}