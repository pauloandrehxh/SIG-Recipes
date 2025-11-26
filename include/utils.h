#include "usuario.h"
#include "ingrediente.h"
#include "receita.h"

void limparTela();
void pressioneEnterParaContinuar();
void lerString(char *destino, int tamanho);
int gerarUsuarioId(void);
int gerarIngredienteId(void);
int gerarReceitaId(void);

void inicializarIngredientes(void);
void inicializarUsuarios(void);
void inicializarReceitas(void);

void preencherListaUsuario(UsuarioLista*);
void appendUsuario(UsuarioLista*, Usuario*);
UsuarioLista* newUsuarioList(void);
void clearUsuario(UsuarioLista*);
void deleteUsuario(UsuarioLista*);
void preencherListaIngrediente(IngredienteLista*);
void appendIngrediente(IngredienteLista*, Ingrediente*);
IngredienteLista* newIngredienteList(void);
void clearIngrediente(IngredienteLista*);
void deleteIngrediente(IngredienteLista*);
void preencherListaReceita(ReceitaLista*);
void appendReceita(ReceitaLista*, Receita*);
ReceitaLista* newReceitaList(void);
void clearReceita(ReceitaLista*);
void deleteReceita(ReceitaLista*);
int validarUsuario(char*, char*, char*);
int validarEmail(char*);
int validarCpf(char*);
int validarNome(char*);
int ehVogal(char);
int ehLetra(char);
int validarNomeObjeto(char*);