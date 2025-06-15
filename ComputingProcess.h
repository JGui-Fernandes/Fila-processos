#ifndef COMPUTINGPROCESS_H_INCLUDED
#define COMPUTINGPROCESS_H_INCLUDED

#include <sstream>

#include "Process.h"

using namespace std;

class ComputingProcess: public Process{

    public:
        ComputingProcess();
        ComputingProcess(string novaOperacao);

        void execute(Fila<Process*>& fila);
        void separaOperacao();

        void setOperacao(string novaOperacao);
        string getOperacao();

        void setX(float novoX);
        float getX();

        void setOperador(char novoOperador);
        char getOperador();

        void setY(float novoY);
        float getY();

        float getResultado()const;

        void imprimir(ostream& os) const override;

    private:
        string operacao;
        char operador;
        float x;
        float y;

};

ComputingProcess::ComputingProcess(){

}

ComputingProcess::ComputingProcess(string novaOperacao){
    operacao = novaOperacao;
}

void ComputingProcess::execute(Fila<Process*>& fila){
    cout << *this << " = " << getResultado() << endl;
}

float ComputingProcess::getResultado() const{
    float resultado = 0;
    if(operador == '+'){
        resultado = x+y;
    }
    else if(operador == '-'){
        resultado = x-y;
    }
    else if(operador == '*'){
        resultado = x*y;
    }
    else if(operador == '/'){
        resultado = x/y;
    }
    return resultado;
}

void ComputingProcess::separaOperacao(){
    stringstream ss(operacao);

    ss >> x >> operador >> y;
}

void ComputingProcess::setOperacao(string novaOperacao){
    operacao = novaOperacao;
}

string ComputingProcess::getOperacao(){
    return operacao;
}

void ComputingProcess::setX(float novoX){
    x = novoX;
}

float ComputingProcess::getX(){
    return x;
}

void ComputingProcess::setOperador(char novoOperador){
    operador = novoOperador;
}

char ComputingProcess::getOperador(){
    return operador;
}

void ComputingProcess::setY(float novoY){
    y = novoY;
}

float ComputingProcess::getY(){
    return y;
}

void ComputingProcess::imprimir(ostream& os) const {
    os << getId() << "  | Calculo   | " << x << " " << operador << " " << y;
}

#endif // COMPUTINGPROCESS_H_INCLUDED
