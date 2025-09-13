# 🎮 Projeto Free Fire - Estrutura de Dados em C

Este projeto foi desenvolvido como parte da disciplina de *Estrutura de Dados* da Estácio.  
O objetivo foi criar um sistema baseado em uma simulação de *plano de fuga do Free Fire, evoluindo em três níveis de dificuldade: **Novato, Aventureiro e Mestre*.  

Cada nível traz novos desafios, aplicando conceitos de *structs, vetores, ordenação, busca binária e manipulação de dados* em linguagem C.  

---

## 🧩 Nível Novato
- *Objetivo:* Criar um sistema de cadastro de territórios usando struct e vetores.
- *Funcionalidades:*
  - Cadastro de territórios com nome e quantidade de exércitos.
  - Exibição dos territórios cadastrados.
- *Arquivo:* [MOD1desafio.c](./MOD1desafio.c)

---

## 🧩 Nível Aventureiro
- *Objetivo:* Evoluir o projeto com novas funções para manipulação de territórios.
- *Funcionalidades:*
  - Adicionar novos territórios.
  - Listar territórios cadastrados.
  - Realizar ataques entre territórios.
- *Arquivo:* [MOD2desafio.c](./MOD2desafio.c)

---

## 🧩 Nível Mestre
- *Objetivo:* Criar um sistema completo de gerenciamento da mochila com componentes.
- *Funcionalidades:*
  - Adicionar componentes à mochila (máx. 10).
  - Descartar componentes.
  - Listar componentes com formatação alinhada.
  - Organizar mochila com opções de ordenação:
    - Por *nome* (ordem alfabética).
    - Por *tipo*.
    - Por *prioridade* (1 a 5).
  - Buscar componente com *busca binária* (requer ordenação por nome).
  - Ativar a *Torre de Fuga* (encerrar programa).
- *Arquivo:* [MOD3desafio.c](./MOD3desafio.c)

---

## ⚙ Como compilar e executar

No **Windows (CMD/PowerShell)**, utilize os comandos abaixo:

```bash
# Compilar
gcc MOD1desafio.c -o MOD1desafio.exe
gcc MOD2desafio.c -o MOD2desafio.exe
gcc MOD3desafio.c -o MOD3desafio.exe

# Executar
MOD1desafio.exe
MOD2desafio.exe
MOD3desafio.exe


---

📂 Estrutura do Repositório

📦 projeto-freefire
 ┣ 📜 MOD1desafio.c
 ┣ 📜 MOD2desafio.c
 ┣ 📜 MOD3desafio.c
 ┗ 📜 README.md


---

✍ Autor: Illan Weslley Silva Lobato
📚 Estácio - Estrutura de Dados
