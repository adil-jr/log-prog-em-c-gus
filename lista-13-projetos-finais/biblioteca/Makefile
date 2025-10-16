CC = gcc
CFLAGS = -Wall -Wextra -g

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
DATA_DIR = data

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = biblioteca

GREEN = \033[0;32m
NC = \033[0m

all: $(DATA_DIR) $(TARGET)

$(DATA_DIR):
	@mkdir -p $(DATA_DIR)
	@echo "$(GREEN)✓ Diretório data/ criado$(NC)"

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "$(GREEN)✓ Compilação concluída: $(TARGET)$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "$(GREEN)✓ Arquivos de compilação removidos$(NC)"

cleanall: clean
	rm -rf $(DATA_DIR)
	@echo "$(GREEN)✓ Todos os arquivos removidos$(NC)"

run: $(TARGET)
	@echo "$(GREEN)Iniciando sistema...$(NC)"
	@./$(TARGET)

rebuild: clean all

info:
	@echo "=========================================="
	@echo "  Sistema de Gerenciamento de Biblioteca"
	@echo "=========================================="
	@echo "Arquivos fonte: $(SOURCES)"
	@echo "Arquivos objeto: $(OBJECTS)"
	@echo "Executável: $(TARGET)"
	@echo ""
	@echo "Comandos disponíveis:"
	@echo "  make         - Compila o projeto"
	@echo "  make run     - Compila e executa"
	@echo "  make clean   - Remove arquivos compilados"
	@echo "  make cleanall- Remove tudo (incluindo dados)"
	@echo "  make rebuild - Recompila do zero"
	@echo "  make info    - Mostra esta mensagem"

.PHONY: all clean cleanall run rebuild info