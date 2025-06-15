#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#ifndef FILA_H
#define FILA_H
#include "Nodo.h"

using namespace std;
template <class T>
class Fila
{
    public:
        Fila();

        void adicionarFila(T novo);
        void removerFila();
        void imprime();

        int getTamanho();
        void diminuiTamamho();

        Nodo<T>* getInicio();

    private:
        Nodo<T> *inicio;
        Nodo<T> *fim;
        int size;
};
template <class T>
Fila<T>::Fila(){
   inicio = nullptr;
   fim = nullptr;
   size = 0;
}

template <class T>
void Fila<T>::adicionarFila(T n){
    Nodo<T> *novo = new Nodo<T>(n);
     if(inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{

        fim->setProximo(novo);
        fim = novo;
    }

    size++;
}
template <class T>
void Fila<T>::imprime(){
    if(size < 1){
        cout << "\n\nNenhum processo cadastrado na fila!\n\n" << endl;
    }
    else{
        Nodo<T>* atual = inicio;
        cout << "\n\nID | TIPO" << endl;
        while(atual != nullptr){
            cout << *(atual->getElemento()) << endl;
            atual = atual->getProximo();
        }
    }
}

template<class T>
void Fila<T>::removerFila(){
    Nodo<T>* atual = inicio;

    inicio = inicio->getProximo();

    delete atual;

    size--;
}

template<class T>
int Fila<T>::getTamanho(){
    return size;
}

template<class T>
Nodo<T>* Fila<T>::getInicio(){
    return inicio;
}

template<class T>
void Fila<T>::diminuiTamamho(){
    size--;
}

#endif // FILA_H


#endif // FILA_H_INCLUDED
