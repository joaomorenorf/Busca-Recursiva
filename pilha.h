#ifndef PILHA_INCLUDED
#define PILHA_INCLUDED

typedef struct C{
    int l;              // Linha de um ponto do caminho até a primeira célula de valor 0
    int c;              // Coluna de um ponto do caminho até a primeira célula de valor 0
    struct C * proximo; // Ponteiro para a próxima célula da pilha
} Celula;

typedef struct {
    Celula * topo;      // Armazena somente a célula no topo da pilha
} Pilha;

Pilha * CriaPilhaVazia (void);
/*--------------------------------------------------------------------------------
Protótipo: Pilha * CriaPilhaVazia (void)
Função: Aloca uma Pilha e passa o endereço de memória
Entrada: Nenhuma
Saida: Ponteiro para Pilha
--------------------------------------------------------------------------------*/

Celula * CriaCelula (void);

/*--------------------------------------------------------------------------------
Protótipo: Celula * CriaCelula (void)
Função: Criar Celula para Pilha
Entrada: Nenhuma
Saida: Ponteiro para celula
--------------------------------------------------------------------------------*/

int PilhaEstaVazia (Pilha * pilha);

/*--------------------------------------------------------------------------------
Protótipo: int PilhaEstaVazia (Pilha * pilha)
Função: Checa se a Pilha está vazia
Entrada: Pilha
Saida: 0 se não 1 se sim
--------------------------------------------------------------------------------*/

int BuscaCelula (Pilha * pilha, Celula * celula);

/*--------------------------------------------------------------------------------
Protótipo: int BuscaCelula (Pilha * pilha, Celula * celula)
Função: Buscar se determinada Celula está na Pilha
Entrada: A Pilha a ser percorrida e a celula a ser buscada
Saida: 0 se não 1 se sim
--------------------------------------------------------------------------------*/

void ApagaCelula (Celula * celula);

/*--------------------------------------------------------------------------------
Protótipo: void ApagaCelula (Celula * celula)
Função: Apaga celula
Entrada: Endereço da Celula a ser apagada
Saida: Nenhuma
--------------------------------------------------------------------------------*/

void ApagaPilha (Pilha * pilha);

/*--------------------------------------------------------------------------------
Protótipo: void ApagaPilha (Pilha * pilha)
Função: Apaga a pilha
Entrada: Endereço da Pilha a ser apagada
Saida: Nenhuma
--------------------------------------------------------------------------------*/

void Empilha (Pilha * pilha, Celula * celula);

/*--------------------------------------------------------------------------------
Protótipo: void Empilha (Pilha * pilha, Celula * celula)
Função: Empilha Celula no topo da Pilha
Entrada: Pilha na qual será empilhada e a Celula que será empilhada
Saida: nenhuma
--------------------------------------------------------------------------------*/

int Desempilha (Pilha * pilha, Celula * celula);

/*--------------------------------------------------------------------------------
Protótipo: int Desempilha (Pilha * pilha, Celula * celula)
Função: Desempilha elementos atéencontrar a Celula
Entrada: Pilha que será trabalhada e a Celula que será buscada
Saida: 1 se encontrar 0 se não
--------------------------------------------------------------------------------*/

#endif
