# Snake Game (Terminal) 🐍

Um projeto clássico do jogo da cobrinha (Snake) desenvolvido inteiramente na linguagem C para rodar direto no terminal. 

O objetivo deste projeto é aplicar e consolidar fundamentos de Algoritmos e Programação, manipulando vetores (arrays) para o corpo da cobra, controle de fluxo e laços de repetição para o *game loop*, e utilizando a biblioteca `ncurses` para a renderização gráfica em modo texto.

## ✨ Funcionalidades (Até o momento)
- [x] Renderização da arena delimitada por bordas.
- [x] Suporte a cores nativas do terminal (cobra verde, bordas ciano).
- [x] Movimentação contínua e fluida utilizando *timeout* (sem travar a execução).
- [x] Identificação visual separada para a cabeça (`@`) e o corpo (`o`).
- [ ] Geração aleatória de comida.
- [ ] Mecânica de crescimento do corpo.
- [ ] Condições de *Game Over* (colisão com a parede e com o próprio corpo).

## 🛠️ Tecnologias Utilizadas
* **Linguagem:** C
* **Biblioteca Gráfica:** `ncurses` (com `-ltinfo`)
* **Compilador:** GCC

## 🚀 Como Compilar e Rodar

Este jogo é portável e funciona nativamente em praticamente qualquer terminal Linux ou macOS.

### 1. Instalando as dependências
Para compilar o jogo, você precisa ter o compilador `gcc` e a biblioteca de desenvolvimento do `ncurses` instalados no seu sistema. Execute o comando correspondente à sua distribuição:

**No Fedora / Red Hat / CentOS:**
    
    sudo dnf install gcc ncurses-devel

**No Ubuntu / Debian / Linux Mint:**
    
    sudo apt update && sudo apt install gcc libncurses5-dev libncursesw5-dev

**No Arch Linux / Manjaro:**
    
    sudo pacman -S gcc ncurses

### 2. Compilação
Clone este repositório, abra o terminal na pasta do projeto e rode o seguinte comando para compilar o código-fonte:

    gcc snake.c -o snake -lncurses -ltinfo

### 3. Execução
Após a compilação ser concluída sem erros, basta executar o jogo gerado:

    ./snake

## 🎮 Controles
* **Setas do Teclado (⬆️ ⬇️ ⬅️ ➡️):** Controlam a direção da cobra.
* **Q:** Sai do jogo a qualquer momento.

---
*Projeto em desenvolvimento ativo.*
