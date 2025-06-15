#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template<class T>
class Nodo{

    public:
        Nodo();
        Nodo(T novoElemento);
        Nodo(T novoElemento, Nodo* novoProximo);

        void setElemento(T novoElemento);
        T getElemento();

        void setProximo(Nodo* novoProximo);
        Nodo<T>* getProximo();

    private:
        T elemento;
        Nodo<T>* proximo;
};

template<class T>
Nodo<T>::Nodo(){
    proximo = nullptr;
}

template<class T>
Nodo<T>::Nodo(T novoElemento){
    elemento = novoElemento;
    proximo = nullptr;
}

template<class T>
Nodo<T>::Nodo(T novoElemento, Nodo<T>* novoProximo){
    elemento = novoElemento;
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
void Nodo<T>::setProximo(Nodo<T>* novoProximo){
    proximo = novoProximo;
}

template<class T>
Nodo<T>* Nodo<T>::getProximo(){
    return proximo;
}

#endif // NODO_H_INCLUDED
