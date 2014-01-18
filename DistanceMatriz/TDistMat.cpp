#include "TDistMat.h"
#include <iostream>

using namespace std;

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
    Autor: Luis Augusto Toscano
*/
bool TDistMat::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descri��o: Implementa��o do m�todo convertIndex do TAD
    Autor: Luis Augusto Toscano
*/
int TDistMat::convertIndex(int i, int j)
{
    if(isValidIndex(i, j))
        return (i + n * j);

    return -1;
}

/*
    Descri��o: Implementa��o do m�todo getDist do TAD
    Autor: Luis Augusto Toscano
*/
float TDistMat::getDist(int i, int j)
{
    int index = convertIndex(i, j);

    if((index != -1) && (i == j))
        return 0;
    else if((index != -1) && (i != j))
    {
        if(j > i)
            index = convertIndex(j, i);

         return mat[index];
    }
    else
        cout << "�ndice inv�lido" << endl;

    return -1;
}

/*
    Descri��o: Implementa��o do m�todo setDist do TAD
    Autor: Luis Augusto Toscano
*/
void TDistMat::setDist(int i, int j, float dist)
{
    int index = convertIndex(i, j);

    if(index != -1)
    {
        if(i != j)
        {
            if((i != j) && (i < j))
                index = convertIndex(j, i);

            mat[index] = dist;
        }
    }
    else
        cout << "�ndice inv�lido" << endl;
}

/*
    Descri��o: Implementa��o do m�todo print do TAD
    Autor: Luis Augusto Toscano
*/
void TDistMat::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "[" << i << "][" << j << "]: " << getDist(i, j) << endl;
        }
    }
}

