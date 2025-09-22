# Créditos: Adptado do gemini

# Nome do compilador C que será usado
CC=gcc

# Flags de compilação para exibir todos os avisos (warnings) e erros, o que é uma ótima prática
CFLAGS=-Wall -Wextra -std=c99

# Nome do arquivo executável que será gerado
EXECUTAVEL=sig-recipes

# Lista de todos os arquivos-fonte (.c) do seu projeto
FILES=main.c telas.c utils.c receita.c usuario.c ingrediente.c

# Regra principal: é executada quando você digita apenas "make"
# Ela diz que para criar o executável, o Makefile depende de todos os arquivos-fonte
all: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(EXECUTAVEL)

# "clean": é usada para limpar os arquivos gerados pela compilação
clean:
	rm -f $(EXECUTAVEL) *.o

# "run": um atalho para compilar e executar o programa de uma vez
run: all
	./$(EXECUTAVEL)