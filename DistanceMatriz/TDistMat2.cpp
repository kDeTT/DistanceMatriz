#include "TDistMat2.h"
#include "TList.h"
#include <iostream>

using namespace std;

/*
    Descri��o: Implementa��o do m�todo construtor do TAD, recebe como par�metro a ordem da matriz e aloca
               mem�ria para um vetor [n - 1] de listas
    Autor: Igor Pires dos Santos
*/
TDistMat2::TDistMat2(int ordem)
{
    n = ordem;
    nVet = n - 1;
    mat = new TList*[nVet];
    for(int i = 0; i < nVet; i++)
        mat[i] = new TList();
}


/*
    Descri��o: Implementa��o do m�todo destrutor do TAD, desaloca as listas e em seguida o vetor que guarda estas
    Autor: Igor Pires dos Santos
*/
TDistMat2::~TDistMat2()
{
    for(int k = 0; k < n; k++)
    {
        TList *p = mat[k];
        delete p;
    }

    delete [] mat;
}

/*
    Descri��o: Implementa��o do m�todo isValidIndex do TAD
    Autor: Igor Pires dos Santos
*/
bool TDistMat2::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descri��o: Implementa��o do m�todo getDist do TAD
    Autor: Igor Pires dos Santos
*/
float TDistMat2::getDist(int i, int j)
{
    if(isValidIndex(i,j))
    {
        if(i == j)
            return 0;
        else if(i != j)
        {
            if(j > i)
                return mat[j-1]->getDistJ(i);

            return mat[i-1]->getDistJ(j);
        }
        else
            cout << "�ndice inv�lido" << endl;
    }

    return -1;
}

/*
    Descri��o: Implementa��o do m�todo setDist do TAD
    Autor: Igor Pires dos Santos
*/
void TDistMat2::setDist(int i, int j, float dist)
{
    if(isValidIndex(i,j))
    {
        if(i != j)
        {
            if(j > i)
                mat[j-1]->setDist(i,dist);
            else
                mat[i-1]->setDist(j,dist);
        }
        else
            cout << "�ndice inv�lido" << endl;

    }
}

/*
    Descri��o: Implementa��o do m�todo print do TAD
    Autor: Luis Augusto Toscano
*/
void TDistMat2::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "[" << i << "][" << j << "]: " << getDist(i, j) << endl;
        }
    }
}

