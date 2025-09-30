#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_FILA 5

typedef struct {
    int id;
    char tipo[2]; // 'I', 'O', 'T', 'L', etc.
} Peca;

Peca fila[TAM_FILA];
int inicio = 0, fim = 0, total = 0;
int contadorID = 1;

// Gera uma peça aleatória
Peca gerarPeca() {
    Peca nova;
    char tipos[4][2] = {"I", "O", "T", "L"};
    int indice = rand() % 4;
    strcpy(nova.tipo, tipos[indice]);
    nova.id = contadorID++;
    return nova;
}

// Insere uma peça na fila (enqueue)
void inserirPeca() {
    if (total == TAM_FILA) {
        printf("⚠️ Fila cheia! Não é possível inserir nova peça.\n");
        return;
    }
    fila[fim] = gerarPeca();
    fim = (fim + 1) % TAM_FILA;
    total++;
}

// Remove uma peça da fila (dequeue)
void jogarPeca() {
