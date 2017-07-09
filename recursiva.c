#include <stdio.h>
#include <stdlib.h>
#include "PGM.h"
#include "pilha.h"
#include "recursiva.h"


void ImprimeCaminho (Pilha * caminho) {
    Pilha * ordemCerta = CriaPilhaVazia ();
    Celula * proximo;
    Celula * auxiliar = caminho->topo;
    while (auxiliar != NULL) {
        proximo = auxiliar->proximo;
        Empilha(ordemCerta, auxiliar);
        auxiliar = proximo;
    }
    printf ("\n");
    proximo = ordemCerta->topo;
    printf ("(%d,%d)", proximo->l, proximo->c);
    proximo = proximo->proximo;
    while (proximo != NULL) {
        printf (", (%d,%d)", proximo->l, proximo->c);
        proximo = proximo->proximo;
    }
    printf (".\n");
    ApagaPilha(ordemCerta);
    caminho->topo = NULL;
}

static void ChecagemIndividual (Celula * coord, PGM * imagem, Pilha * caminho, int orientacao[]) {
    if (BuscaCelula(caminho, coord) != 1) {
        if (imagem->imagem[coord->l][coord->c] < orientacao[0]) {
            orientacao[0] = imagem->imagem[coord->l][coord->c];
            orientacao[1] = coord->l;
            orientacao[2] = coord->c;
        }
    }
}

static void SalvaOriTeste (Celula * teste, int * orientacao) {
    teste->l = orientacao[1];
    teste->c = orientacao[2];
}

static int BuscaRecursiva (PGM * imagem, Pilha * caminho) {
        int orientacao[3] = {256, -1, -1};
        Celula * teste = CriaCelula ();

        teste->c = caminho->topo->c + 1;
        teste->l = caminho->topo->l;
        if (teste->c < (imagem->c - 1) )         //direito
            ChecagemIndividual (teste, imagem, caminho, orientacao);

        teste->c--;
        teste->l++;
        if (caminho->topo->l < (imagem->l - 1) ) //inferior
            ChecagemIndividual (teste, imagem, caminho, orientacao);

        teste->c--;
        teste->l--;
        if (caminho->topo->c > 0 )               //esquerdo
            ChecagemIndividual (teste, imagem, caminho, orientacao);

        teste->c++;
        teste->l--;
        if (caminho->topo->l > 0 )               //superior
            ChecagemIndividual (teste, imagem, caminho, orientacao);


        if (orientacao[0] == 256) {
            free (teste);
            return -1;
        }

        SalvaOriTeste (teste, orientacao);

        Empilha (caminho, teste);

        if (orientacao[0] ==  0 )
            return  1;

        return BuscaRecursiva ( imagem, caminho);
}

Pilha * BuscaCaminho (PGM * imagem) {
    Pilha * caminho = CriaPilhaVazia ();
    Celula * coord = CriaCelula ();
    coord->l = 0;
    coord->c = 0;
    Empilha (caminho, coord);


    int sucesso = BuscaRecursiva (imagem, caminho);

    if (sucesso == -1)
        printf ("O algoritmo nao foi capaz de encontrar um pixel zero.\nO caminho percorrido por ele foi:\n");

    return caminho;
}
