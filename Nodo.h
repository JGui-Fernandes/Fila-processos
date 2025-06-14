#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template<class T>
class Nodo{

    public:
        Nodo();
        Nodo(T novoElemento);
        Nodo(T novoElemento, Nodo* novoAnterior, Nodo* novoProximo);

        void setElemento(T novoElemento);
        T getElemento();

        void setAnterior(Nodo* novoAnterior);
        Nodo<T>* getAnterior();

        void setProximo(Nodo* novoProximo);
        Nodo<T>* getProximo();

    private:
        T elemento;
        Nodo<T>* anterior;
        Nodo<T>* proximo;
};

template<class T>
Nodo<T>::Nodo(){
    anterior = nullptr;
    proximo = nullptr;
}

template<class T>
Nodo<T>::Nodo(T novoElemento){
    elemento = novoElemento;
    anterior = nullptr;
    proximo = nullptr;
}

template<class T>
Nodo<T>::Nodo(T novoElemento, Nodo<T>* novoAnterior, Nodo<T>* novoProximo){
    elemento = novoElemento;
    anterior = novoAnterior;
    proximo = novoProximo;
}

template<class T>
void Nodo<T>::setElemento(T novoElemento){
    elemento = novoElemento;
}


template<class T>
T Nodo<T>::getElemento(){
    return elemento;
}

template<class T>
void Nodo<T>::setAnterior(Nodo<T>* novoAnterior){
    anterior = novoAnterior;
}

template<class T>
Nodo<T>* Nodo<T>::getAnterior(){
    return anterior;
}

template<class T>
void Nodo<T>::setProximo(Nodo<T>* novoProximo){
    proximo = novoProximo;
}

template<class T>
Nodo<T>* Nodo<T>::getProximo(){
    return proximo;
}

#endif // NODO_H_INCLUDED
