#include "../include/telas.h"
#include "../include/utils.h"
#include <stdio.h>

void exibirMenu() {
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║ _____ _____ _____      ______ _____ _____ ___________ _____ _____  ║\n");
    printf("║/  ___|_   _|  __ \\     | ___ \\  ___/  __ \\_   _| ___ \\  ___/  ___| ║\n");
    printf("║\\ `--.  | | | |  \\/_____| |_/ / |__ | /  \\/ | | | |_/ / |__ \\ `--.  ║\n");
    printf("║ `--. \\ | | | | _|______|    /|  __║ |      | | |  __/|  __| `--. \\ ║\n");
    printf("║/\\__/ /_| |_| |_\\ \\     | |\\ \\| |___| \\__/\\_| |_| |   | |___/\\__/ / ║\n");
    printf("║\\____/ \\___/ \\____/     \\_| \\_\\____/ \\____/\\___/\\_|   \\____/\\____/  ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Menu de Receitas                                              ║\n");
    printf("║  [2] Menu de Ingredientes                                          ║\n");
    printf("║  [3] Menu de Usuários                                              ║\n");
    printf("║  [4] Menu de Relatórios                                            ║\n");
    printf("║  [5] Sobre o Projeto                                               ║\n");
    printf("║  [6] Creditos                                                      ║\n");
    printf("║  [0] Sair                                                          ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}

void telaPrincipal() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         CADERNO DE RECEITAS                        ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Adicionar Nova Receita                                        ║\n");
    printf("║  [2] Listar Minhas Receitas                                        ║\n");
    printf("║  [3] Buscar Receita                                                ║\n");
    printf("║  [4] Editar Receita                                                ║\n");
    printf("║  [5] Excluir Receita                                               ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}
void telaUsuario() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         GESTÃO DE USUÁRIOS                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Cadastrar novo Usuário                                        ║\n");
    printf("║  [2] Alterar Dados de Usuário                                      ║\n");
    printf("║  [3] Excluir Usuário                                               ║\n");
    printf("║  [4] Listar dados                                                  ║\n");
    printf("║  [5] Buscar Usuário                                                ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}
void telaIngredientes() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                 GESTÃO DE INGREDIENTES (DESPENSA)                  ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Adicionar Novo Ingrediente                                    ║\n");
    printf("║  [2] Listar Meus Ingredientes                                      ║\n");
    printf("║  [3] Editar Ingrediente                                            ║\n");
    printf("║  [4] Excluir Ingrediente                                           ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}

void telaSobre() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         SOBRE O PROJETO                            ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  SIG-Recipes é um sistema de gerenciamento de receitas             ║\n");
    printf("║  culinarias desenvolvido como um projeto de estudo da              ║\n");
    printf("║  linguagem C.                                                      ║\n");
    printf("║                                                                    ║\n");
    printf("║  Objetivo: Permitir que os usuarios criem, visualizem,             ║\n");
    printf("║  editem e excluam suas receitas favoritas, tudo isso               ║\n");
    printf("║  atraves de uma interface de console simples e intuitiva           ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");

    
    pressioneEnterParaContinuar();
}

void telaCreditos() {
    limparTela();
    printf("╔═════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              CREDITOS                               ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════╣\n");
    printf("║  Este projeto foi desenvolvido por:                                 ║\n");
    printf("║                        Idealizadores                                ║\n");
    printf("║    -> Paulo André A. Moura                                          ║\n");
    printf("║       - GitHub: @pauloandrehxh                                      ║\n");
    printf("║                                                                     ║\n");
    printf("║    -> Nikcael Lopes                                                 ║\n");
    printf("║       - GitHub: @nikcaellp                                          ║\n");
    printf("║                         Finalizadores                               ║\n");
    printf("║    -> Guilherme Fernandes                                           ║\n");
    printf("║       - GitHub: @GuiFS05                                            ║\n");
    printf("║                                                                     ║\n");
    printf("║                                                                     ║\n");
    printf("║  Disciplina: Programação                                            ║\n");
    printf("║  Professor(a): Flavius Gorgônio                                     ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════╝\n\n");

    pressioneEnterParaContinuar();
}
void telaEditarUser(){
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                 Editando Dados de Usuario                          ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Alterar Nome                                                  ║\n");
    printf("║  [2] Alterar Email                                                 ║\n");
    printf("║  [3] Alterar Cpf                                                   ║\n");
    printf("║  [4] Alterar Senha                                                 ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}
void telaEditarReceita() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                   Editando Dados da Receita                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Alterar Nome                                                  ║\n");
    printf("║  [2] Alterar Id de Ingredientes                                    ║\n");
    printf("║  [3] Alterar Id de Usuários                                        ║\n");
    printf("║  [4] Alterar Tempo de Preparo                                       ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}
void telaEditarIngrediente() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                   Editando Dados de Ingrediente                    ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Alterar Nome                                                  ║\n");
    printf("║  [2] Alterar Tipo                                                  ║\n");
    printf("║  [3] Alterar Quantidade                                            ║\n");
    printf("║  [4] Alterar Unidade de Medida                                     ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}

void telaRelatorio() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       RELATORIO (Listagem)                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Usuários                                                      ║\n");
    printf("║  [2] Receitas                                                      ║\n");
    printf("║  [3] Ingredeintes                                                  ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}
void telaRelatorioUsuarios() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       RELATORIO (Usuários)                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Ativos                                                        ║\n");
    printf("║  [2] Inativos                                                      ║\n");
    printf("║  [3] Nome                                                          ║\n"); 
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}

void telaRelatorioReceitas() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       RELATORIO (Receitas)                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Ativas                                                        ║\n");
    printf("║  [2] Inativas                                                      ║\n");
    printf("║  [3] Tempo de preparo                                              ║\n");
    printf("║  [4] Usuário                                                       ║\n");
    printf("║  [5] Ingrediente                                                   ║\n");
    printf("║  [6] Sem Ingrediente                                               ║\n");    
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}

void telaRelatorioIngrediente() {
    limparTela();
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       RELATÓRIO (Ingredientes)                     ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] Ativos                                                        ║\n");
    printf("║  [2] Inativos                                                      ║\n");
    printf("║  [3] Filtrados por tipo                                            ║\n");
    printf("║  [0] Voltar ao Menu anterior                                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
}