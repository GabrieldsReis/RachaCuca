# Racha Cuca

**Um quebra-cabeça deslizante desenvolvido em C++ com Raylib.**

Projeto acadêmico da disciplina **SIN216 — Programação e Estruturas de Dados II**, do curso de Bacharelado em Sistemas de Informação da Universidade Federal de Viçosa (UFV), Campus Rio Paranaíba.

## Sobre o projeto

O Racha Cuca é um simulador de quebra-cabeça deslizante (*sliding puzzle*). A proposta é carregar uma imagem, dividi-la em peças organizadas em um tabuleiro de dimensão **N × N** e permitir que o jogador reorganize as peças utilizando o espaço vazio.

O projeto prevê tabuleiros de dimensão **2 × 2 até 6 × 6**. A última região da imagem, no canto inferior direito, é removida para representar o espaço vazio do quebra-cabeça.

O foco do desenvolvimento é aplicar conceitos de programação e estruturas de dados em uma aplicação gráfica, mantendo a implementação simples, organizada e compreensível.

## Tecnologias utilizadas

- **C++** — linguagem de programação.
- **Raylib** — carregamento de imagens, criação da janela e renderização gráfica.
- **STL (`std::vector`)** — armazenamento das peças, texturas e representação lógica do tabuleiro.
- **Git e GitHub** — versionamento e registro da evolução do projeto.

## Estado atual do desenvolvimento

O projeto está em desenvolvimento. Esta seção diferencia o que já foi implementado do que ainda está sendo construído.

### Implementado

- Carregamento e validação da imagem de entrada.
- Divisão da imagem em regiões conforme o valor de **N**.
- Cálculo dos limites dos recortes para imagens cujas dimensões não são divisíveis igualmente por **N**.
- Remoção do recorte inferior direito, reservado ao espaço vazio.
- Conversão dos recortes em texturas da Raylib.
- Exibição das peças em uma grade dimensionada conforme **N**.
- Representação lógica do tabuleiro por um vetor de inteiros: cada posição guarda o identificador de uma peça, enquanto **-1** representa o espaço vazio.
- Protótipo de identificação da célula selecionada pelo mouse, convertendo as coordenadas da janela em linha, coluna e índice do vetor.

### Em desenvolvimento

- Validação completa dos cliques dentro dos limites do tabuleiro.
- Movimentação de peças somente quando houver adjacência ao espaço vazio.
- Embaralhamento por movimentos válidos e verificação de conclusão do jogo.
- Apresentação de uma sequência de solução.
- Histórico de movimentos em árvore, com desfazer, refazer e preservação de ramificações.
- Exportação e importação do histórico no formato exigido pelo projeto.
- Reprodução de uma ramificação do histórico.
- Testes dos diferentes tamanhos de tabuleiro e dos casos de entrada inválida.

## Organização do repositório

```text
RachaCuca/
├── codigo/
│   ├── assets/
│   │   └── imagem_teste.png
│   └── src/
│       └── main.cpp
├── versoes/
│   ├── 2026-11-21_imagem_recortes_texturas_2x2.cpp
│   ├── 2026-11-22_recorte_e_exibicao_estatica.cpp
│   ├── 2026-11-24_antes_tabuleiro_logico.cpp
│   └── 2026-11-24_identificacao_cliques_mouse.cpp
├── .gitignore
└── README.md
```

A pasta `versoes/` mantém cópias de etapas anteriores, permitindo acompanhar a evolução da implementação. O código principal em desenvolvimento está em `codigo/src/main.cpp`.

## Próximas etapas

As próximas entregas priorizam a integração das funcionalidades essenciais: primeiro tornar o quebra-cabeça jogável, depois implementar o histórico e os recursos de persistência, e por fim realizar os testes e finalizar as instruções de compilação e execução.

> **Status:** projeto acadêmico em desenvolvimento — funcionalidades concluídas e pendentes estão identificadas separadamente para manter o progresso transparente.# Racha Cuca

**Um quebra-cabeça deslizante desenvolvido em C++ com Raylib.**

Projeto acadêmico da disciplina **SIN216 — Programação e Estruturas de Dados II**, do curso de Bacharelado em Sistemas de Informação da Universidade Federal de Viçosa (UFV), Campus Rio Paranaíba.

## Sobre o projeto

O Racha Cuca é um simulador de quebra-cabeça deslizante (*sliding puzzle*). A proposta é carregar uma imagem, dividi-la em peças organizadas em um tabuleiro de dimensão **N × N** e permitir que o jogador reorganize as peças utilizando o espaço vazio.

O projeto prevê tabuleiros de dimensão **2 × 2 até 6 × 6**. A última região da imagem, no canto inferior direito, é removida para representar o espaço vazio do quebra-cabeça.

O foco do desenvolvimento é aplicar conceitos de programação e estruturas de dados em uma aplicação gráfica, mantendo a implementação simples, organizada e compreensível.

## Tecnologias utilizadas

- **C++** — linguagem de programação.
- **Raylib** — carregamento de imagens, criação da janela e renderização gráfica.
- **STL (`std::vector`)** — armazenamento das peças, texturas e representação lógica do tabuleiro.
- **Git e GitHub** — versionamento e registro da evolução do projeto.

## Estado atual do desenvolvimento

O projeto está em desenvolvimento. Esta seção diferencia o que já foi implementado do que ainda está sendo construído.

### Implementado

- Carregamento e validação da imagem de entrada.
- Divisão da imagem em regiões conforme o valor de **N**.
- Cálculo dos limites dos recortes para imagens cujas dimensões não são divisíveis igualmente por **N**.
- Remoção do recorte inferior direito, reservado ao espaço vazio.
- Conversão dos recortes em texturas da Raylib.
- Exibição das peças em uma grade dimensionada conforme **N**.
- Representação lógica do tabuleiro por um vetor de inteiros: cada posição guarda o identificador de uma peça, enquanto **-1** representa o espaço vazio.
- Protótipo de identificação da célula selecionada pelo mouse, convertendo as coordenadas da janela em linha, coluna e índice do vetor.

### Em desenvolvimento

- Validação completa dos cliques dentro dos limites do tabuleiro.
- Movimentação de peças somente quando houver adjacência ao espaço vazio.
- Embaralhamento por movimentos válidos e verificação de conclusão do jogo.
- Apresentação de uma sequência de solução.
- Histórico de movimentos em árvore, com desfazer, refazer e preservação de ramificações.
- Exportação e importação do histórico no formato exigido pelo projeto.
- Reprodução de uma ramificação do histórico.
- Testes dos diferentes tamanhos de tabuleiro e dos casos de entrada inválida.

## Organização do repositório

```text
RachaCuca/
├── codigo/
│   ├── assets/
│   │   └── imagem_teste.png
│   └── src/
│       └── main.cpp
├── versoes/
│   ├── 2026-11-21_imagem_recortes_texturas_2x2.cpp
│   ├── 2026-11-22_recorte_e_exibicao_estatica.cpp
│   ├── 2026-11-24_antes_tabuleiro_logico.cpp
│   └── 2026-11-24_identificacao_cliques_mouse.cpp
├── .gitignore
└── README.md
```

A pasta `versoes/` mantém cópias de etapas anteriores, permitindo acompanhar a evolução da implementação. O código principal em desenvolvimento está em `codigo/src/main.cpp`.

## Próximas etapas

As próximas entregas priorizam a integração das funcionalidades essenciais: primeiro tornar o quebra-cabeça jogável, depois implementar o histórico e os recursos de persistência, e por fim realizar os testes e finalizar as instruções de compilação e execução.

> **Status:** projeto acadêmico em desenvolvimento — funcionalidades concluídas e pendentes estão identificadas separadamente para manter o progresso transparente.# Racha Cuca

**Um quebra-cabeça deslizante desenvolvido em C++ com Raylib.**

Projeto acadêmico da disciplina **SIN216 — Programação e Estruturas de Dados II**, do curso de Bacharelado em Sistemas de Informação da Universidade Federal de Viçosa (UFV), Campus Rio Paranaíba.

## Sobre o projeto

O Racha Cuca é um simulador de quebra-cabeça deslizante (*sliding puzzle*). A proposta é carregar uma imagem, dividi-la em peças organizadas em um tabuleiro de dimensão **N × N** e permitir que o jogador reorganize as peças utilizando o espaço vazio.

O projeto prevê tabuleiros de dimensão **2 × 2 até 6 × 6**. A última região da imagem, no canto inferior direito, é removida para representar o espaço vazio do quebra-cabeça.

O foco do desenvolvimento é aplicar conceitos de programação e estruturas de dados em uma aplicação gráfica, mantendo a implementação simples, organizada e compreensível.

## Tecnologias utilizadas

- **C++** — linguagem de programação.
- **Raylib** — carregamento de imagens, criação da janela e renderização gráfica.
- **STL (`std::vector`)** — armazenamento das peças, texturas e representação lógica do tabuleiro.
- **Git e GitHub** — versionamento e registro da evolução do projeto.

## Estado atual do desenvolvimento

O projeto está em desenvolvimento. Esta seção diferencia o que já foi implementado do que ainda está sendo construído.

### Implementado

- Carregamento e validação da imagem de entrada.
- Divisão da imagem em regiões conforme o valor de **N**.
- Cálculo dos limites dos recortes para imagens cujas dimensões não são divisíveis igualmente por **N**.
- Remoção do recorte inferior direito, reservado ao espaço vazio.
- Conversão dos recortes em texturas da Raylib.
- Exibição das peças em uma grade dimensionada conforme **N**.
- Representação lógica do tabuleiro por um vetor de inteiros: cada posição guarda o identificador de uma peça, enquanto **-1** representa o espaço vazio.
- Protótipo de identificação da célula selecionada pelo mouse, convertendo as coordenadas da janela em linha, coluna e índice do vetor.

### Em desenvolvimento

- Validação completa dos cliques dentro dos limites do tabuleiro.
- Movimentação de peças somente quando houver adjacência ao espaço vazio.
- Embaralhamento por movimentos válidos e verificação de conclusão do jogo.
- Apresentação de uma sequência de solução.
- Histórico de movimentos em árvore, com desfazer, refazer e preservação de ramificações.
- Exportação e importação do histórico no formato exigido pelo projeto.
- Reprodução de uma ramificação do histórico.
- Testes dos diferentes tamanhos de tabuleiro e dos casos de entrada inválida.

## Organização do repositório

```text
RachaCuca/
├── codigo/
│   ├── assets/
│   │   └── imagem_teste.png
│   └── src/
│       └── main.cpp
├── versoes/
│   ├── 2026-11-21_imagem_recortes_texturas_2x2.cpp
│   ├── 2026-11-22_recorte_e_exibicao_estatica.cpp
│   ├── 2026-11-24_antes_tabuleiro_logico.cpp
│   └── 2026-11-24_identificacao_cliques_mouse.cpp
├── .gitignore
└── README.md
```

A pasta `versoes/` mantém cópias de etapas anteriores, permitindo acompanhar a evolução da implementação. O código principal em desenvolvimento está em `codigo/src/main.cpp`.

## Próximas etapas

As próximas entregas priorizam a integração das funcionalidades essenciais: primeiro tornar o quebra-cabeça jogável, depois implementar o histórico e os recursos de persistência, e por fim realizar os testes e finalizar as instruções de compilação e execução.

> **Status:** projeto acadêmico em desenvolvimento — funcionalidades concluídas e pendentes estão identificadas separadamente para manter o progresso transparente.# RachaCuca
