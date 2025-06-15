#ifndef WRITINGPROCESS_H_INCLUDED
#define WRITINGPROCESS_H_INCLUDED

#include <iostream>
#include <fstream>

#include "Process.h"

class WritingProcess: public Process{

    public:
        WritingProcess();
        void execute(Fila<Process*>& fila);

        void imprimir(ostream& os) const override;

    private:

};
WritingProcess::WritingProcess(){

}

void WritingProcess::execute(Fila<Process*>& fila){
    ofstream arquivo("computation.txt", ios::app);

    string expressao = "";

    cout << "\n\nDigite a expressao que deseja armazenar:" << endl;

    while(expressao == ""){
        getline(cin, expressao);
    }

    if(arquivo.is_open()){
        arquivo << expressao << endl;
        arquivo.close();
        cout << "\n\nSalvo no arquivo com sucesso!\n\n" << endl;
    } else{
        cout << "\n\nErro ao abrir o arquivo!\n\n" << endl;
    }
}

void WritingProcess::imprimir(ostream& os) const {
    os << getId() << " | Gravacao";
}
#endif // WRITINGPROCESS_H_INCLUDED
