#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario Usuario;
struct usuario{
    int id;
    char nome[100];
    char email[100];
    char cpf[30];
    int ativo; // 1 para ativo, 0 para inativo/excluído
};
typedef struct usuarioLista UsuarioLista;
struct usuarioLista{
    int id;
    char nome[100];
    char email[100];
    char cpf[30];
    struct usuarioLista *prox;   
};

void gerenciarUsuarios();
void cadastrarUsuario(void);
void listarUsuarios(void);
void editarUsuario(void);
void excluirUsuario(void);
void buscarUsuario(void);
char* buscarUsuarioNome(int, UsuarioLista*);
int buscarUsuarioID(char[], UsuarioLista*);

#endif