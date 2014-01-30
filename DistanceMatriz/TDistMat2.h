#ifndef TDISTMAT2_H
#define TDISTMAT2_H


class TDistMat2
{
    private:
        int n; // Ordem da matriz
        TList *mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o �ndice � v�lido
        int convertIndex(int i, int j); // Se i e j forem v�lidos, converte o i e j para o �ndice correto no vetor
    public:
        TDistMat2();
        float getDist(int i, int j); // Consulta a dist�ncia na posi��o i e j
        void setDist(int i, int j, float dist); // Atribui uma dist�ncia � posi��o i e j
        void print(); // Imprime a matriz
        virtual ~TDistMat2();

};

#endif // TDISTMAT2_H
