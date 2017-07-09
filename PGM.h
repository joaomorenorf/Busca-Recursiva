#ifndef PGM_INCLUDED
#define PGM_INCLUDED

typedef struct {
    int c;                          // número de colunas na imagem
    int l;                          // número de linhas na imagem
    unsigned char maximo;           // valor máximo para cada pixelconvolucao
    unsigned char **imagem;         // variável para armazenar os pixels da imagem (matriz)
} PGM;

typedef struct {
    int **e;
} TipoKernel;

PGM *LerPGM(char* entrada);

/*--------------------------------------------------------------------------------
Protótipo: PGM *LerPGM(char* entrada)
Função: Lê o arquivo de entrada e armazena ele na estrutura de dados
Entrada: Vetor endereço do arquivo
Saida: Tipo abstrato de dados do tiopo imagem PGM
--------------------------------------------------------------------------------*/

void DesalocaPGM (PGM * imagem);

/*--------------------------------------------------------------------------------
Protótipo: PGM *LerPGM(char* entrada)
Função: Lê o arquivo de entrada e armazena ele na estrutura de dados
Entrada: Vetor endereço do arquivo
Saida: Tipo abstrato de dados do tiopo imagem PGM
--------------------------------------------------------------------------------*/

#endif // PGM_INCLUDED
