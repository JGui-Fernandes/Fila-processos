#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED

#include <iostream>
#include <fstream>

#include "ComputingProcess.h"
#include "PrintingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "Process.h"
#include "Fila.h"


template<class T>
class Gerenciador{
    public:
        void iniciar(Fila<T>& fila);
        void encerrar();

        void imprimirOpcoes(Fila<T>& fila);

        void imprimirOpcoesProcessos(Fila<T>& fila);

        void cadastrarComputingProcess(Fila<T>& fila);
        void cadastrarPrintingProcess(Fila<T>& fila);
        void cadastrarWritingProcess(Fila<T>& fila);
        void cadastrarReadingProcess(Fila<T>& fila);

        void executarProximo(Fila<T>& fila);
        void executarEspecifico(Fila<T>& fila);

        void salvarProcessos(Fila<T>& fila);
        void lerProcessos(Fila<T>& fila);
};

template<class T>
void Gerenciador<T>::iniciar(Fila<T>& fila){
    cout << "Bem-vindo!" << endl;

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::encerrar(){
    cout << "\n\nAte a proxima!\n\n" << endl;
    exit(0);
}

template<class T>
void Gerenciador<T>::imprimirOpcoes(Fila<T>& fila){
    int opcao = 0;

    while(opcao < 1 || opcao > 6){
        cout << "\n\n1) Criar processo" << endl;
        cout << "2) Executar proximo" << endl;
        cout << "3) Executar processo especifico" << endl;
        cout << "4) Salvar a fila de processos" << endl;
        cout << "5) Carregar do arquivo a fila de processos" << endl;
        cout << "6) Sair\n" << endl;
        cout << "Digite a opcao desejada: " << endl;

        cin >> opcao;

        if(opcao < 1 || opcao > 6){
            cout << "\n\nOpcao invalida!\n\n" << endl;
            system("pause");
        }

    }

    switch(opcao){
        case 1: // criar processo
            imprimirOpcoesProcessos(fila);
            break;
        case 2: // executar proximo
            executarProximo(fila);
            break;
        case 3: // executar especifico
            executarEspecifico(fila);
            break;
        case 4: // salvar fila
            salvarProcessos(fila);
            break;
        case 5: // carregar fila
            lerProcessos(fila);
            break;
        case 6: // sair
            encerrar();
            break;
    }

}

template<class T>
void Gerenciador<T>::imprimirOpcoesProcessos(Fila<T>& fila){
    int opcao = 0;

    while(opcao < 1 || opcao > 5){
        cout << "\n\n1) Processo de calculo" << endl;
        cout << "2) Processo de gravacao" << endl;
        cout << "3) Processo de leitura" << endl;
        cout << "4) Processo de impressao" << endl;
        cout << "5) Cancelar\n" << endl;
        cout << "Digite a opcao desejada: " << endl;

        cin >> opcao;

        if(opcao < 1 || opcao > 5){
            cout << "\n\nOpcao invalida!\n\n" << endl;
            system("pause");
        }

    }

    switch(opcao){
        case 1: // criar calculo
            cadastrarComputingProcess(fila);
            break;
        case 2: // criar gravacao
            cadastrarWritingProcess(fila);
            break;
        case 3: // criar leitura
            cadastrarReadingProcess(fila);
            break;
        case 4: // criar impressao
            cadastrarPrintingProcess(fila);
            break;
        case 5: // carregar fila
            imprimirOpcoes(fila);
            break;
    }
}


template<class T>
void Gerenciador<T>::cadastrarComputingProcess(Fila<T>& fila){
    string expressao = "";

    cout << "\n\nEscreva a expressao desejada:" << endl;

    while (expressao == "") {
        cin >> expressao;
    }

    ComputingProcess* cp = new ComputingProcess(expressao);
    fila.adicionarFila(cp);

    cout << "\nProcesso salvo com sucesso!\n\n" << endl;
    system("pause");

    imprimirOpcoes(fila);

}

template<class T>
void Gerenciador<T>::cadastrarPrintingProcess(Fila<T>& fila){
    PrintingProcess* pp = new PrintingProcess();

    fila.adicionarFila(pp);

    cout << "\nProcesso salvo com sucesso!\n\n" << endl;
    system("pause");

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::cadastrarWritingProcess(Fila<T>& fila){
    WritingProcess* wp = new WritingProcess();

    fila.adicionarFila(wp);

    cout << "\nProcesso salvo com sucesso!\n\n" << endl;
    system("pause");

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::cadastrarReadingProcess(Fila<T>& fila){
    ReadingProcess* rp = new ReadingProcess();

    fila.adicionarFila(rp);

    cout << "\nProcesso salvo com sucesso!\n\n" << endl;
    system("pause");

    imprimirOpcoes(fila);
}


template<class T>
void Gerenciador<T>::executarProximo(Fila<T>& fila){

    if(fila.getTamanho() == 0){
        cout << "\n\nNenhum processo cadastrado na fila!\n\n" << endl;
    }
    else{
        Process* atual = fila.getInicio()->getElemento();
        fila.removerFila();

        atual->execute(fila);
    }

    system("pause");

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::executarEspecifico(Fila<T>& fila){
    if(fila.getTamanho() < 1){
        cout << "\n\nNenhum processo cadastrado na fila!\n\n" << endl;
    }
    else{


        fila.imprime();
        Nodo<T>* atual = fila.getInicio()->getProximo();
        Nodo<T>* anterior = fila.getInicio();
        int id;
        bool encontrou = false;

        cout << "\nDigite o id do processo desejado:" << endl;
        cin >> id;

        while(atual != nullptr){
            if(atual->getElemento()->getId() == id){
                encontrou = true;
                break;
            }
            atual = atual->getProximo();
            anterior = anterior->getProximo();
        }

        if(!encontrou){
            cout << "\n\nNenhum processo com o ID correspondente!\n\n" << endl;
        }
        else{
            atual->getElemento()->execute(fila);
            anterior->setProximo(atual->getProximo());
            cout << "\n\nProcesso executado com sucesso!\n\n" << endl;
            fila.diminuiTamamho();


            delete atual;
        }
    }
    system("pause");

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::salvarProcessos(Fila<T>& fila){
    if(fila.getTamanho() < 1){
        cout << "\n\nNenhum processo cadastrado na fila!\n\n" << endl;
    }
    else{
        ofstream arquivo("process.txt");

        Nodo<T>* atual = fila.getInicio();

        if(arquivo.is_open()){
            while(atual != nullptr){
                arquivo << *(atual->getElemento()) << endl;
                atual = atual->getProximo();
            }
            cout << "\n\nProcessos salvos com sucesso!\n\n" << endl;
        }
        else{
            cout << "\n\nErro ao abrir o arquivo!\n\n" << endl;
        }
    }

    system("pause");

    imprimirOpcoes(fila);
}

template<class T>
void Gerenciador<T>::lerProcessos(Fila<T>& fila){
    ifstream arquivo("process.txt");
    string linha;
    bool vazio = true;
    string lixo, tipo, expressao, e;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            stringstream ss(linha);

            getline(ss, lixo, '|');
            getline(ss, tipo, '|');
            getline(ss, expressao, '|');

            tipo.erase(0, tipo.find_first_not_of(" "));
            tipo.erase(tipo.find_last_not_of(" ") + 1);

            for (char c : expressao) {
                if (c != ' ') e += c;
            }
            vazio = false;

            if(tipo == "Calculo") {
                ComputingProcess* cp = new ComputingProcess(e);
                fila.adicionarFila(cp);
            }
            else if(tipo == "Gravacao"){
                WritingProcess* wp = new WritingProcess();
                fila.adicionarFila(wp);
            }
            else if(tipo == "Leitura"){
                ReadingProcess* rp = new ReadingProcess();
                fila.adicionarFila(rp);
            }
            else if(tipo == "Impressao"){
                PrintingProcess* pp = new PrintingProcess();
                fila.adicionarFila(pp);
            }
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

    ofstream limpar("process.txt");
    if (limpar.is_open()) {
        limpar << "";
        limpar.close();
    } else {
        cout << "\n\nErro ao limpar o arquivo!\n\n" << endl;
    }

    system("pause");

    imprimirOpcoes(fila);
}


#endif // GERENCIADOR_H_INCLUDED
