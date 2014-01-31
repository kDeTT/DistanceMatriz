#include "TDistMat.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

/*
    Descri��o: M�todo que l� o arquivo que cont�m a matriz
    Autor: Luis Augusto Toscano
*/
TDistMat* readMatriz(string fileName)
{
    ifstream streamFile;
    streamFile.open(fileName.c_str());

    if (!streamFile.is_open())
        cout << "Erro ao carregar o arquivo da matriz!" << endl;
    else
    {
        int i = 1;
        int j = 0;
        int cont = 0;

        string line;
        getline(streamFile, line);
        istringstream streamLine(line);

        float ordem;
        streamLine >> ordem;

        if(!isnan(ordem) && (ordem > 0))
        {
            TDistMat *distMat = new TDistMat(ordem);

            while (getline(streamFile, line))
            {
                float dist;
                istringstream streamLine(line);

                while(streamLine >> dist)
                {
                    cout << "Valor lido: " << dist << endl;
                    cont++;
                    distMat->setDist(i, j, dist);
                    j++;
                }

                j = 0;
                i++;
            }
            cout << "Itens lidos: " << cont << endl;
            streamFile.close();
            return distMat;
        }
        else
            cout << "[ Erro: Ordem da matriz invalida ]" << endl;
    }

    return NULL;
}

void consultItem(TDistMat *p)
{
    int i = 0;
    int j = 0;

    cout << " -- CONSULTAR ITEM DA MATRIZ DISTANCIA -- " << endl;

    while(i != -1 && j != -1)
    {
        cout << endl << "Insira i: ";
        cin >> i;
        cout << "Insira j: ";
        cin >> j;

        if(i != -1 && j != -1)
            cout << endl << "[" << i << "][" << j << "]: " << p->getDist(i, j) << endl;
    }

    cout << endl << " -- FIM DA CONSULTA -- ";
}

int main()
{
    TDistMat *distMat = readMatriz("Matrizes/teste1.txt");

//    if(distMat != NULL)
//        distMat->print();

    //consultItem(distMat);

    return 0;
}
