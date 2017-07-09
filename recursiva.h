#ifndef RECURSIVA_INCLUDED
#define RECURSIVA_INCLUDED

#include "PGM.h"
#include "pilha.h"

typedef struct {
    int c;      //colunas
    int l;      //linhas
} TipoCoord;

void ImprimeCaminho (Pilha * caminho);

/*--------------------------------------------------------------------------------
Protótipo: void ImprimeCaminho (Pilha * caminho)
Função: Imprime o caminho percorrido
Entrada: Pilha que armazena o caminho
Saida: É impresso no prompt o caminho percorrido da forma: (1,0), (2,0), ... (7,8).
--------------------------------------------------------------------------------*/

Pilha * BuscaCaminho (PGM * imagem);

/*--------------------------------------------------------------------------------
Protótipo: Pilha * BuscaCaminho (PGM * imagem)
Função: Busca o caminho até o pixel de valor 0
Entrada: imagem
Saida: Ponteiro para Pilha do caminho
--------------------------------------------------------------------------------*/

#endif
