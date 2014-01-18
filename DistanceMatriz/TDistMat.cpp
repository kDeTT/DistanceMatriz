#include "TDistMat.h"

/*
    Descri��o: Implementa��o do TAD TDistMat
*/

/*
    Descri��o: Implementa��o do construtor do TAD, recebe como par�metro a ordem da matriz e aloca
               mem�ria para um vetor [n x n]
    Autor: Luis Augusto Toscano
*/
TDistMat::TDistMat(int ordem)
{
    n = ordem;
    mat = new float[n * n];
}

/*
    Descri��o: Implementa��o do destrutor do TAD, desaloca o vetor que guarda a matriz
    Autor: Luis Augusto Toscano
*/
TDistMat::~TDistMat()
{
    delete [] mat;
}

/*
    Descri��o: Implementa��o do m�todo isValidIndex do TAD
    Autor:
*/
bool TDistMat::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descri��o: Implementa��o do m�todo convertIndex do TAD
    Autor:
*/
int TDistMat::convertIndex(int i, int j)
{
    //TODO
}

/*
    Descri��o: Implementa��o do m�todo getDist do TAD
    Autor:
*/
float TDistMat::getDist(int i, int j)
{
    //TODO
}

/*
    Descri��o: Implementa��o do m�todo setDist do TAD
    Autor:
*/
void TDistMat::setDist(int i, int j, float dist)
{
    //TODO
}

/*
    Descri��o: Implementa��o do m�todo print do TAD
    Autor:
*/
void TDistMat::print()
{
    //TODO
}
