#include "TList.h"
#include "TNo.h"

TList::TList(int linha) {
    first = NULL;
    it = NULL;
    i = linha;
}

TList::~TList() {
    TNo* p = first;
    while(p != NULL)
    {
        TNo* t = p->consultaProx();
        delete p;
        p = t;
    }
}

float TList::getDist()
{
    return it->getInfo();
}

void TList::setDist(float val){
    it->setInfo(val);
}

void TList::start() {
    it = first;
}

void TList::next(){
    if(!isEnd()){
        it = it->getNext();
    } else {
        cout << "N�o h� mais valores nesta linha" << endl;
    }
}

bool TList::isEnd(){
    if(it->getNext() == NULL)
        return true;
    return false;
}

void TList::InsertLast(float val){
    TNo *p = new TNo();
    p->setInfo(val);

    TNo aux = first;

    if(aux == NULL){
        first = p;
    } else{

        while(aux->getNext() != NULL)
            aux = aux->getNext();

        aux->setNext(p);
    }
}


