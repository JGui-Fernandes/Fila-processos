#ifndef READINGPROCESS_H_INCLUDED
#define READINGPROCESS_H_INCLUDED

#include <iostream>
#include <fstream>

#include "Process.h"
#include "ComputingProcess.h"

class ReadingProcess: public Process{

    public:
        ReadingProcess();

        void execute(Fila<Process*>& fila);
        void imprimir(ostream& os) const override;

};

ReadingProcess::ReadingProcess(){

}

void ReadingProcess::execute(Fila<Process*>& fila){
    ifstream arquivo("computation.txt");
    string linha;
    bool vazio = true;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            ComputingProcess* cp = new ComputingProcess(linha);

            fila.adicionarFila(cp);
            vazio = false;
        }

        if(vazio){
            cout << "\n\nNenhuma expressao disponivel para leitura!\n\n" << endl;
        } else{
            cout << "\n\nLeitura feita com sucesso!\n\n" << endl;
        }
        arquivo.close();
    } else {
        cout << "\n\nErro ao abrir o arquivo!\n\n" << endl;
    }

    ofstream limpar("computation.txt");
    if (limpar.is_open()) {
        limpar << "";
        limpar.close();
    } else {
        cout << "\n\nErro ao abrir o arquivo!\n\n" << endl;
    }
}

void ReadingProcess::imprimir(ostream& os) const {
    os << getId() << "  | Leitura";
}

#endif // READINGPROCESS_H_INCLUDED
