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
    fila.imprime();
}

void PrintingProcess::imprimir(ostream& os) const {
    os << getId() << "  | Impressao ";
}


#endif // PRINTINGPROCESS_H_INCLUDED
