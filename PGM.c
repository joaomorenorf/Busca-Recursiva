#include <stdio.h>
#include <stdlib.h>
#include "PGM.h"
#include <string.h>


PGM *LerPGM (char* entrada) {
    // Abrir o arquivo
    FILE *imagem;
    imagem=fopen(entrada, "r");
    if (!imagem) {
        printf("Erro na abertura do arquivo.\n");
        exit (1);
    }
    char *c;
    c=(char *)malloc(3*sizeof(char));
    fscanf(imagem, "%s", c);
    c[2] = '\0';
    if (strcmp(c, "P2") != 0){
        printf("\nO Arquivo nao e PGM.\n");
    }
    free(c);

    // Iniciar PGM_Entrada
    PGM *PGM_Entrada = (PGM *) malloc (sizeof(PGM));
    fscanf (imagem, "%d", &PGM_Entrada->c);
    fscanf (imagem, "%d", &PGM_Entrada->l);
    fscanf (imagem, "%hhu", &PGM_Entrada->maximo);
    unsigned char **MatrizEntrada=(unsigned char **)malloc((PGM_Entrada->l)*sizeof(char *));
    int ii;
    for (ii=0; ii < PGM_Entrada->l; ii++) {
        MatrizEntrada[ii]=(unsigned char *)malloc((PGM_Entrada->c)*sizeof(char));
    }
    PGM_Entrada->imagem=MatrizEntrada;

    // Copiar imagem em PGM_Entrada.imagem
    int jj;
    for(ii=0; ii < PGM_Entrada->l; ii++) {
        for (jj=0; jj < PGM_Entrada->c; jj++) {
            if (fscanf(imagem,"%hhu", &PGM_Entrada->imagem[ii][jj]) != 1) {
                printf("\nErro ao copiar a imagem.\n");
                exit (2);
            }
        }
    }
    fclose (imagem);
    return PGM_Entrada;
}

void DesalocaPGM (PGM * imagem) {
    int ii;
    for (ii=0; ii < imagem->l; ii++) {
        free(imagem->imagem[ii]);
    }
    free(imagem->imagem);
    free(imagem);
}
