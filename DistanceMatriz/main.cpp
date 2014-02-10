#include "TDistMat.h"
#include "TDistMat2.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

/*
    Descri��o: M�todo que limpa a tela do console, compat�vel com Windows e Linux
*/
void clearScreen()
{
#ifdef _WIN32
      system ("cls");
#else
      system ("clear");
#endif
}

/*
    Descri��o: M�todo criado para pausar temporariamente a execu��o do programa
*/
void waitToContinue()
{
    string wait;

    do
    {
        cout << endl << "Digite 'c' para continuar... ";
        cin >> wait;
        clearScreen();
    }
    while(wait != "c");
}

/*
    Descri��o: M�todo gen�rico que l� um arquivo dos dados da matriz
*/
template <class T> T* readMat(string fileName)
{
    ifstream streamFile;
    streamFile.open(fileName.c_str());

    if (!streamFile.is_open())
    {
        cout << endl << "[ Erro: Arquivo da matriz nao carregado ]" << endl;
        waitToContinue();
    }
    else
    {
        int ordem;
        streamFile >> ordem;

        if(streamFile && (ordem > 0))
        {
            int i = 0;
            int j = 0;
            string line;
            int readLength = 0;

            T *distMat = new T(ordem);

            while (getline(streamFile, line))
            {
                float dist;
                istringstream streamLine(line);

                while(streamLine >> dist)
                {
                    distMat->setDist(i, j, dist);
                    readLength++;
                    j++;
                }

                j = 0;
                i++;
            }

            streamFile.close();

            if(readLength == ((ordem * (ordem - 1)) / 2))
                return distMat;
            else
            {
                cout << endl << "[ Erro: Arquivo da matriz corrompido ]" << endl;
                delete distMat;
                waitToContinue();
            }
        }
        else
        {
            cout << endl << "[ Erro: Ordem da matriz invalida ]" << endl;
            waitToContinue();
        }
    }

    return NULL;
}

/*
    Descri��o: M�todo gen�rico que exibe na tela uma mensagem e espera uma entrada
*/
template <typename T> T getInput(string desc)
{
    T result;

    while(true)
    {
        cout << desc;
        cin >> result;

        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "[ Erro: Entrada invalida ]" << endl;
            waitToContinue();
        }
        else
            break;
    }

    return result;
}

/*
    Descri��o: M�todo gen�rico para consultar um item da matriz
*/
template <class T> void consultMat(T *distMat)
{
    clearScreen();
    cout << " -- CONSULTAR ITEM DA MATRIZ DISTANCIA -- " << endl << endl;

    int i = getInput<int>("Insira o indice i: ");
    int j = getInput<int>("Insira o indice j: ");

    cout << endl << "[" << i << "][" << j << "]: " << distMat->getDist(i, j) << endl;

    waitToContinue();
}

/*
    Descri��o: M�todo gen�rico que altera um elemento da matriz
*/
template <class T> void changeMat(T *distMat)
{
    clearScreen();
    cout << " -- ALTERAR ITEM DA MATRIZ DISTANCIA -- " << endl << endl;

    int i = getInput<int>("Insira o indice i: ");
    int j = getInput<int>("Insira o indice j: ");
    float dist = getInput<float>("Insira a distancia: ");

    if(distMat->setDist(i, j, dist))
    {
        cout << endl << "[" << i << "][" << j << "]: " << distMat->getDist(i, j) << endl;
        cout << endl << "Valor alterado!" << endl;
    }

    waitToContinue();
}

/*
    Descri��o: M�todo gen�rico que imprime a matriz
*/
template <class T> void printMat(T *p)
{
    clearScreen();
    cout << " -- IMPRESSAO DA MATRIZ DISTANCIA -- " << endl << endl;
    p->print();
    waitToContinue();
}

/*
    Descri��o: M�todo gen�rico que verifica a escolha do menu
*/
template <class T> void parseMenu(int menuOp, T *p)
{
    switch(menuOp)
    {
        case 1:
            printMat<T>(p);
            break;
        case 2:
            consultMat<T>(p);
            break;
        case 3:
            changeMat<T>(p);
            break;
        case 0:
            delete p;
            break;
        default:
            cout << endl << "[ Erro: Opcao invalida ]" << endl;
            waitToContinue();
    }
}

/*
    Descri��o: M�todo gen�rico que exibe o menu para a escolha dos TADs
*/
int showMenuTAD()
{
    int tadOp;
    bool again = true;

    do
    {
        clearScreen();

        cout << "Escolha um TAD para testar:" << endl << endl;
        cout << "[1] - TAD vetor (Parte 1)" << endl;
        cout << "[2] - TAD vetor de listas (Parte 2)" << endl;
        cout << "[0] - Sair" << endl;
        tadOp = getInput<int>("Opcao: ");

        if((tadOp == 1) || (tadOp == 2) || (tadOp == 0))
            again = false;
        else
        {
            cout << endl << "[ Erro: Opcao invalida ]" << endl;
            waitToContinue();
        }
    }
    while(again);

    return tadOp;
}

/*
    Descri��o: M�todo gen�rico que exibe o menu da matriz
*/
int showMenu()
{
    clearScreen();

    cout << " -- MATRIZ DE DISTANCIA -- " << endl << endl;
    cout << "[1] - Imprimir matriz" << endl;
    cout << "[2] - Consultar item da matriz" << endl;
    cout << "[3] - Alterar item da matriz" << endl;
    cout << "[0] - Sair" << endl;

    return getInput<int>("Opcao: ");
}

/*
    Descri��o: M�todo gen�rico que verifica se um arquivo existe tomando como base o diret�rio de execu��o
*/
bool checkFileExists(string fileName)
{
    if (ifstream(fileName.c_str()))
         return true;

    return false;
}

/*
    Descri��o: M�todo gen�rico que exibe o menu para a entrada do arquivo da matriz
*/
string showMenuFileName()
{
    string fileName;
    bool again = false;

    do
    {
        clearScreen();

        cout << "Insira o caminho do arquivo da matriz [Ex: Matrizes/matriz.txt]: ";
        cin >> fileName;

        if(checkFileExists(fileName))
            again = true;
        else
        {
            cout << endl << "[ Erro: Arquivo nao existe ]" << endl;
            waitToContinue();
        }
    }
    while(!again);

    return fileName;
}

int main()
{
    int tadOp = -1;

    do
    {
        tadOp = showMenuTAD();

        if(tadOp == 1)
        {
            string fileName = showMenuFileName();
            TDistMat *distMat = readMat<TDistMat>(fileName);

            if(distMat != NULL)
            {
                int menuOp = -1;

                do
                {
                    menuOp = showMenu();
                    parseMenu(menuOp, distMat);
                }
                while(menuOp != 0);
            }
        }
        else if(tadOp == 2)
        {
            string fileName = showMenuFileName();
            TDistMat2 *distMat2 = readMat<TDistMat2>(fileName);

            if(distMat2 != NULL)
            {
                int menuOp = -1;

                do
                {
                    menuOp = showMenu();
                    parseMenu(menuOp, distMat2);
                }
                while(menuOp != 0);
            }
        }
    }
    while(tadOp != 0);

    return 0;
}
