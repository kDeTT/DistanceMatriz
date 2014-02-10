#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED
#include "TNo.h"

class TList
{
    private:
        TNo *first; // Primeiro elemento da lista
        TNo *last; // �ltimo elemento da lista
        TNo *it; // Utilizado na busca por um elemento

        bool searchDist(int index); // Busca por um �ndice j da matriz
        float getDist(); // Consulta a dist�ncia do n� it
        void setDist(float dist); // Atribui uma dist�ncia ao n� it
    public:
        TList(); // Construtor do TAD
        ~TList(); // Destrutor do TAD
        float getDist(int j); // Consulta a dist�ncia por um �ndice j da matriz
        void setDist(int j, float dist); // Atribui um �ndice e uma dist�ncia da matriz
        bool isEmpty(); // Verifica se a lista est� vazia
        void print(); // Imprime a matriz
};

#endif // TLIST_H_INCLUDED
