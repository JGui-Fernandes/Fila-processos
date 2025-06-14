#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include "Fila.h"

using namespace std;

class Process{

    public:
        Process();

        virtual void execute(Fila<Process*>& fila){}

        int getId() const;

        void setId(int novoId);

        virtual void imprimir(ostream& os) const {
            os << "Processo base: ID " << id;
        }

        friend ostream& operator<<(ostream& os, const Process& p);

    protected:
        int id;
};

Process::Process(){
}

int Process::getId() const{
    return id;
}

void Process::setId(int novoId){
    id = novoId;
}

ostream& operator<<(ostream& os, const Process& p) {
    p.imprimir(os);
    return os;
}

#endif // PROCESS_H_INCLUDED
