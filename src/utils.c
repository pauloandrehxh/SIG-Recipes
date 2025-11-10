#include <stdio.h>
#include <stdlib.h> // Necessário para system("cls") e system("clear")
#include "../include/utils.h"
#include "../include/usuario.h"
void limparTela()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Linux e macOS
#endif
}

void inicializarIngredientes(){
    FILE *arqIngredientes;
    arqIngredientes = fopen("./dados/dadosIngrediente.dat", "rb");
    if (arqIngredientes == NULL){
        arqIngredientes = fopen("./dados/dadosIngrediente.dat", "wb");

        if (arqIngredientes == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqIngredientes);
    } else {
        fclose(arqIngredientes);
    }
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
int gerarId()
{
    int ultimo_num = 0;
    Usuario *verifica;
    verifica = (Usuario*) malloc (sizeof(Usuario));
    FILE *arq_cadastro = fopen("cadastro.dat", "rb");
    if (arq_cadastro == NULL) 
        {
        free(verifica); 
        return ultimo_num; // se não existe arquivo ainda, começa do ID 0
        }
      
    // lê até o final, pegando sempre o último ID
    while (fread(verifica, sizeof(Usuario),1 , arq_cadastro))
        {
              ultimo_num =verifica->id;
        }
    fclose(arq_cadastro);
    return ultimo_num;

}