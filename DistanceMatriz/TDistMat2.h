#ifndef TDISTMAT2_H
#define TDISTMAT2_H
#include "TList.h"


class TDistMat2
{
    private:
        int n; // Ordem da matriz
        int nVet; // Quantidade de linhas do vetor
        TList **mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o �ndice � v�lido
    public:
        TDistMat2(int ordem);
        float getDist(int i, int j); // Consulta a dist�ncia na posi��o i e j
        void setDist(int i, int j, float dist); // Atribui uma dist�ncia � posi��o i e j
        void print(); // Imprime a matriz
        virtual ~TDistMat2();

};

#endif // TDISTMAT2_H
