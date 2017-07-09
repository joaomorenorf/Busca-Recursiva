#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha * CriaPilhaVazia (void) {
    Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

Celula * CriaCelula (void) {
    Celula * celula = (Celula *)malloc(sizeof(Celula));
    celula->proximo = NULL;
    return celula;
}

int PilhaEstaVazia (Pilha * pilha) {
    if (pilha->topo == NULL) return 1;
    else return 0;
}

int BuscaCelula (Pilha * pilha, Celula * celula) {
    Celula * proximo = pilha->topo;
    while (proximo != NULL) {
        if ( ( proximo->l == celula->l ) && ( proximo->c == celula->c )) return 1;
        else proximo = proximo->proximo;
    }
    return 0;
}

void ApagaCelula (Celula * celula) {
    free (celula);
}

void ApagaPilha (Pilha * pilha) {
    Celula * proximo;
    Celula * auxiliar = pilha->topo;
    while (auxiliar != NULL) {
        proximo = auxiliar->proximo;
        ApagaCelula (auxiliar);
        auxiliar = proximo;
    }
    free(pilha);
}

void Empilha (Pilha * pilha, Celula * celula) {
    celula->proximo = pilha->topo;
    pilha->topo = celula;
}

int Desempilha (Pilha * pilha, Celula * celula) {
    Celula * proximo = pilha->topo;
    while (proximo != NULL) {
        if ( ( proximo->l == celula->l ) && ( proximo->c == celula->c )) {
            pilha->topo = proximo;
            return 1;
        }
        else
            proximo = celula->proximo;
    }
    pilha->topo = proximo;
    return 0;
}
