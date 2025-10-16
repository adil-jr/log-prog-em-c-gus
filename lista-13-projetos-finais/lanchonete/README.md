# Projeto Integrador: Gerenciador de Pedidos de uma Lanchonete

Este projeto é a implementação de um **Gerenciador de Pedidos de uma Lanchonete** em C, desenvolvido como um dos projetos finais do curso de **[Lógica de Programação e Algoritmos](https://www.udemy.com/course/logica-e-algoritmos/)** do professor Gustavo Caetano.

## 🎯 Sobre o Projeto

O sistema permite gerenciar as operações básicas de uma lanchonete, como o cadastro de produtos e clientes, e o registro de novos pedidos. Os dados são persistidos em arquivos de texto, garantindo que as informações não sejam perdidas ao fechar o sistema.

## ✨ Funcionalidades

O sistema oferece um menu interativo para gerenciar três áreas principais:

### 🍔 Gerenciamento de Produtos
- **Cadastrar novo produto:** Adiciona um novo item ao cardápio, com nome e preço.
- **Listar todos os produtos:** Exibe todos os produtos cadastrados e seus respectivos preços.

### 🧑 Gerenciamento de Clientes
- **Cadastrar novo cliente:** Registra um novo cliente no sistema, com nome e telefone.
- **Listar todos os clientes:** Mostra todos os clientes cadastrados com seus respectivos códigos.

### 📝 Gerenciamento de Pedidos
- **Registrar novo pedido:** Associa um ou mais produtos a um cliente, gerando um novo pedido.
- **Listar pedidos:** Exibe todos os pedidos realizados, detalhando os clientes e os produtos incluídos.

## 🛠️ Estrutura de Arquivos

O projeto está organizado da seguinte forma:

```
.
├── include/         # Arquivos de cabeçalho (.h)
│   ├── arquivo.h
│   ├── cliente.h
│   ├── global.h
│   ├── menu.h
│   ├── pedido.h
│   └── produto.h
├── src/             # Código fonte (.c)
│   ├── arquivo.c
│   ├── cliente.c
│   ├── main.c
│   ├── menu.c
│   ├── pedido.c
│   └── produto.c
├── data/            # Dados persistidos (criado em tempo de execução)
│   ├── clientes.txt
│   ├── produtos.txt
│   └── pedidos.txt
├── obj/             # Arquivos objeto (.o) (criado em tempo de execução)
├── Makefile         # Automatiza a compilação e execução
└── README.md        # Este arquivo
```

## ⚙️ Como Compilar e Executar

Para compilar e executar o projeto, você precisa ter o `gcc` e o `make` instalados.

1.  **Clone o repositório (ou navegue até a pasta do projeto).**
2.  **Abra um terminal na pasta `lista-13-projetos-finais/lanchonete/`.**
3.  **Use os seguintes comandos `make`:**

    - **Compilar o projeto:**
      ```bash
      make
      ```
      Isso criará o executável `lanchonete`.

    - **Executar o sistema:**
      ```bash
      make run
      ```
      Este comando compila (se necessário) e inicia o programa.

    - **Limpar arquivos de compilação:**
      ```bash
      make clean
      ```
      Remove o executável e os arquivos objeto (`.o`).

    - **Limpar tudo (incluindo dados):**
      ```bash
      make cleanall
      ```
      **Atenção:** Este comando remove também a pasta `data/`, apagando todos os produtos, clientes e pedidos cadastrados.

    - **Ver informações do projeto:**
      ```bash
      make info
      ```
      Exibe detalhes sobre os arquivos e os comandos `make` disponíveis.

## 👨‍🏫 Sobre o Curso

Este projeto é um reflexo prático dos conceitos aprendidos no curso de **Lógica de Programação e Algoritmos com C**, que aborda desde os fundamentos da programação até a manipulação de arquivos.

- **Professor:** [Gustavo Caetano](https://www.linkedin.com/in/oguscaetano/)
- **Curso:** [https://www.udemy.com/course/logica-e-algoritmos/](https://www.udemy.com/course/logica-e-algoritmos/)
