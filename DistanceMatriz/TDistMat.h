#ifndef TDISTMAT_H_INCLUDED
#define TDISTMAT_H_INCLUDED

/*
    Descri��o: TAD que representa a matriz de dist�ncias atrav�s de um vetor
    Autor: Luis Augusto Toscano
*/
class TDistMat
{
    private:
        int n; // Ordem da matriz
        int nVet; // Quantidade de elementos do vetor
        float *mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o �ndice � v�lido
        int convertIndex(int i, int j); // Se i e j forem v�lidos, converte o i e j para o �ndice correto no vetor
    public:
        TDistMat(int ordem); // Construtor do TAD altera��o !
        float getDist(int i, int j); // Consulta a dist�ncia na posi��o i e j
        void setDist(int i, int j, float dist); // Atribui uma dist�ncia � posi��o i e j
        void print(); // Imprime a matriz
        ~TDistMat(); // Destrutor do TAD
};

#endif // TDISTMAT_H_INCLUDED
