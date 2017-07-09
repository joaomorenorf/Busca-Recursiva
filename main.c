#include <stdlib.h>
#include <stdio.h>
#include "PGM.h"
#include "pilha.h"
#include "recursiva.h"

void ChecaNumArgumentos (int argc) {
    if (argc != 2) {
        printf ("ERRO:\nNumero de argumentos invalido, espera-se 2, %d foram recebidos.\n", argc);
        exit(1);
    }
}

int main (int argc, char ** argv) {

    ChecaNumArgumentos (argc);

    PGM * imagem = LerPGM (argv[1]);

    Pilha * caminho = BuscaCaminho (imagem);

    DesalocaPGM (imagem);

    ImprimeCaminho (caminho);

    ApagaPilha (caminho);

    return 0;
}
