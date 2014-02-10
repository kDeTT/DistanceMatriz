#ifndef TNO_H_INCLUDED
#define TNO_H_INCLUDED

class TNo
{
    private:
        int index; // Guarda o �ndice j da matriz
        float info; // Guarda a dist�ncia
        TNo *next; // Guarda o pr�ximo n�
    public:
        TNo(int j); // Construtor do TAD
        ~TNo(); // Destrutor do TAD
        int getIndex(); // Consulta o �ndice armazenado
        float getInfo(); // Consulta a dist�ncia armazenada
        void setInfo(float val); // Altera a dist�ncia armazenada
        TNo* getNext(); // Consulta o pr�ximo n�
        void setNext(TNo *p); // Altera o pr�ximo n�
};

#endif // TNO_H_INCLUDED
