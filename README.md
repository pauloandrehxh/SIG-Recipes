# SIG-Recipes - Caderno Virtual de Receitas

Um sistema de **gerenciamento de receitas culinárias**, desenvolvido em **C**, para a disciplina de Programação (DCT1106) do curso Sistemas de Informação na UFRN.

## Sobre o Projeto

O **SIG-Recipes** é um sistema robusto e modular, escrito puramente em **linguagem C**, que simula um caderno virtual de receitas. Desenvolvido com uma interface textual (TUI) interativa, o sistema permite que múltiplos usuários se registrem, façam login e gerenciem suas próprias receitas culinárias de forma privada e intuitiva via terminal.

## Funcionalidades

### Implementado

- **Interface de Terminal (TUI):**
  - [x] Menus principais e telas estáticas (Sobre, Créditos).
  - [x] Estilo padronizado com bordas e layouts consistentes.

- **Modularização Inicial:**
  - [x] Módulos telas (interface) e utils (utilitários) implementados.
  - [x] Estrutura de arquivos criada para os módulos usuario, receita e dados.

### Em Desenvolvimento

- **Gerenciamento de Receitas:**
  - [x] Adicionar e listar receitas
  - [ ] Visualizar, editar e excluir receitas.

- **Gerenciamento de Ingredientes:**
  - [x] Adicionar e listar ingredientes
  - [ ] Visualizar, editar e excluir ingredientes.[x] Adicionar e listar ingredientes

- **Sistema de Usuários:**
  - [ ] Cadastro de novos usuários.
  - [ ] Login e autenticação.
  - [ ] Sessão para acesso individual de receitas.

>OBS: No momento é complicado fazer uma autenticação de usuário funcional, 
logo faremos um CRUD simples de usuário de início, e depois o objetivo é fazer a autenticação.

- **Persistência de Dados:**
  - [ ] Salvamento e carregamento de dados dos usuários e receitas.

## Estrutura do Projeto

O projeto segue uma arquitetura modular para melhor organização e manutenibilidade.

| Módulo                        | Arquivos                        |  Responsabilidade                                          |
|-------------------------------|---------------------------------|------------------------------------------------------------|
| `principal`                   |     `main.c`                    | Fluxo principal do sistema, login e navegação de receitas. |
| `telas`                       | `telas.h`, `telas.c`            | Interface com o usuário: menus, telas e bordas.            |
| `usuario`                     | `usuario.h`, `usuario.c`        | Cadastro, login, logout e controle de sessão.              |
| `receita`                     | `receita.h`, `receita.c`        | Lógica de receitas: criação, edição, exclusão, etc.        |
| `ingrediente`                 | `ingrediente.h`, `ingrediente.c`| Lógica de despensa para ingredientes que o usuário dispõe. |
| `utils`                       | `utils.h`, `utils.c`            | Funções auxiliares: limpar tela, validações, pausas, etc.  |
| `dados`   (Falta Implementar) | `dados.h`, `dados.c`            | Salvamento e carregamento de dados em arquivos.            |


## Como Executar

### Pré-requisitos

- Compilador C (recomendado: **GCC**)
- **Git** instalado para clonar o repositório

### Passos

```bash
# 1. Clone o repositório
git clone https://github.com/pauloandrehxh/SIG-Recipes.git

# 2. Acesse o diretório
cd SIG-Recipes

# 3. Compile o projeto
gcc -g -Wall -o sig-recipes *.c

# 4. Execute o programa
# No Linux/macOS:
./sig-recipes

# No Windows:
sig-recipes.exe
```
## Status do Projeto

**Em desenvolvimento** — Semana 5

## Desenvolvedores

| [<img src="https://avatars.githubusercontent.com/u/96096146?v=4" width="115"/>](https://github.com/pauloandrehxh) | [<img src="https://avatars.githubusercontent.com/u/226210918?v=4" width="115"/>](https://github.com/nikcaellp) |
|:---:|:---:|
| **Paulo André** | **Nikcael Lopes** |
| [@pauloandrehxh](https://github.com/pauloandrehxh) | [@nikcaellp](https://github.com/nikcaellp) |