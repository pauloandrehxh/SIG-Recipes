#include "utils.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") e system("clear")

void limparTela()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux e macOS
#endif
}

void pressioneEnterParaContinuar()
{
    printf("\nPressione Enter para continuar...");
    // Limpa o buffer de entrada para evitar que leituras anteriores interfiram
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *destino, int tamanho)
{
    fgets(destino, tamanho, stdin);
    // Remove o '\n' que o fgets pode deixar no final da string
    for (int i = 0; i < tamanho; i++)
    {
        if (destino[i] == '\n')
        {
            destino[i] = '\0';
            break;
        }
    }
}
int verificaId()
{
    Usuario verifica;
    FILE *arq_usuario = fopen("usuarios.csv", "rt");
    if (arq_usuario == NULL) 
        {
        return 1; // se não existe arquivo ainda, começa do ID 0
       }
      
      int ultimo_num = 0;
    // lê até o final, pegando sempre o último ID
    while (fscanf(arq_usuario,"%d",&verifica.id)==1)
        {
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%99[^;]",verifica.nome);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%99[^;]",verifica.email);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%29[^;]",verifica.cpf);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%19[^;]",verifica.senha);
            fgetc(arq_usuario);
            fscanf(arq_usuario,"%d",&verifica.ativo);
            fgetc(arq_usuario);
             ultimo_num =verifica.id;
        }
    fclose(arq_usuario);
    ultimo_num ++;
    return ultimo_num;

}