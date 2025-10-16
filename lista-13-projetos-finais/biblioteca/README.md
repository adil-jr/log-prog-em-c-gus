# Projeto Integrador: Sistema de Gerenciamento de Biblioteca

Este projeto é a implementação de um **Sistema de Gerenciamento de Biblioteca** em C, desenvolvido como um dos projetos finais do curso de **[Lógica de Programação e Algoritmos](https://www.udemy.com/course/logica-e-algoritmos/)** do professor Gustavo Caetano.

## 🎯 Sobre o Projeto

O sistema permite gerenciar as operações básicas de uma biblioteca, como o cadastro de livros e usuários, e o controle de empréstimos e devoluções. Os dados são persistidos em arquivos de texto, garantindo que as informações não sejam perdidas ao fechar o sistema.

## ✨ Funcionalidades

O sistema oferece um menu interativo para gerenciar três áreas principais:

### 📚 Gerenciamento de Livros
- **Cadastrar novo livro:** Adiciona um novo livro ao acervo, com título, autor e quantidade.
- **Listar todos os livros:** Exibe todos os livros cadastrados, mostrando suas informações e a quantidade de exemplares disponíveis.

### 🧑 Gerenciamento de Usuários
- **Cadastrar novo usuário:** Registra um novo usuário no sistema, com nome e idade.
- **Listar todos os usuários:** Mostra todos os usuários cadastrados com seus respectivos códigos.

### 貸 Gerenciamento de Empréstimos
- **Registrar empréstimo:** Associa um livro a um usuário, decrementando a quantidade de exemplares disponíveis.
- **Registrar devolução:** Marca um empréstimo como inativo e incrementa a quantidade de exemplares do livro devolvido.
- **Listar empréstimos ativos:** Exibe todos os empréstimos que ainda não foram devolvidos.

## 🛠️ Estrutura de Arquivos

O projeto está organizado da seguinte forma:

```
.
├── include/         # Arquivos de cabeçalho (.h)
│   ├── arquivo.h
│   ├── emprestimo.h
│   ├── global.h
│   ├── livro.h
│   ├── menu.h
│   └── usuario.h
├── src/             # Código fonte (.c)
│   ├── arquivo.c
│   ├── emprestimo.c
│   ├── livro.c
│   ├── main.c
│   ├── menu.c
│   └── ususario.c
├── data/            # Dados persistidos (criado em tempo de execução)
│   ├── livros.txt
│   ├── usuarios.txt
│   └── emprestimos.txt
├── obj/             # Arquivos objeto (.o) (criado em tempo de execução)
├── Makefile         # Automatiza a compilação e execução
└── README.md        # Este arquivo
```

## ⚙️ Como Compilar e Executar

Para compilar e executar o projeto, você precisa ter o `gcc` e o `make` instalados.

1.  **Clone o repositório (ou navegue até a pasta do projeto).**
2.  **Abra um terminal na pasta `lista-13-projetos-finais/biblioteca/`.**
3.  **Use os seguintes comandos `make`:**

    - **Compilar o projeto:**
      ```bash
      make
      ```
      Isso criará o executável `biblioteca`.

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
      **Atenção:** Este comando remove também a pasta `data/`, apagando todos os livros, usuários e empréstimos cadastrados.

    - **Ver informações do projeto:**
      ```bash
      make info
      ```
      Exibe detalhes sobre os arquivos e os comandos `make` disponíveis.

## 👨‍🏫 Sobre o Curso

Este projeto é um reflexo prático dos conceitos aprendidos no curso de **Lógica de Programação e Algoritmos com C**, que aborda desde os fundamentos da programação até a manipulação de arquivos.

- **Professor:** [Gustavo Caetano](https://www.linkedin.com/in/oguscaetano/)
- **Curso:** [https://www.udemy.com/course/logica-e-algoritmos/](https://www.udemy.com/course/logica-e-algoritmos/)
