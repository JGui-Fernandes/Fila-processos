#ifndef PRINTINGPROCESS_H_INCLUDED
#define PRINTINGPROCESS_H_INCLUDED

#include "Process.h"

class PrintingProcess: public Process{

    public:
        PrintingProcess();

        void execute(Fila<Process*>& fila);

        void imprimir(ostream& os) const;
};

PrintingProcess::PrintingProcess(){

}

void PrintingProcess::execute(Fila<Process*>& fila){
    Nodo<Process*>* atual = fila.getInicio();
    cout << "ID | TIPO" << endl;
    while(atual != nullptr){
        cout << *(atual->getElemento()) << endl;
        atual = atual->getProximo();
    }
}

void PrintingProcess::imprimir(ostream& os) const {
    os << getId() << " | Impressao ";
}


#endif // PRINTINGPROCESS_H_INCLUDED
