/**
 * @brief Limpa a tela do console.
 * Funciona em diferentes sistemas operacionais.
 */
void limparTela();

/**
 * @brief Pausa o programa até que o usuário pressione a tecla Enter.
 */
void pressioneEnterParaContinuar();

/**
 * @brief Função para ler strings com espaços de forma segura.
 */
void lerString(char *destino, int tamanho);
/**
 * @brief Função de verificação de ID sequencial para Usuario, garantindo sempre uma sequencia na numeração de dados.
 */
int gerarUsuarioId(void);
void inicializarIngredientes(void);
void inicializarUsuarios(void);
void inicializarReceitas(void);
int gerarIngredienteId(void);
int gerarReceitaId(void);