#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED

#include "ComputingProcess.h"
#include "PrintingProcess.h"
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
        void executarProximo(Fila<T>& fila);
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
            break;
        case 4: // salvar fila
            break;
        case 5: // carregar fila
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
        case 2: // executar proximo
            break;
        case 3: // executar especifico
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
    string o = "";

    cout << "\n\nEscreva a operacao desejada:" << endl;

    while (o == "") {
        cin >> o;
    }

    ComputingProcess* cp = new ComputingProcess(o);
    cp->separaOperacao();
    cp->setId(fila.getTamanho() + 1);
    fila.adicionarFila(cp);

    cout << "\nProcesso salvo com sucesso!\n\n" << endl;
    system("pause");

    imprimirOpcoes(fila);

}

template<class T>
void Gerenciador<T>::cadastrarPrintingProcess(Fila<T>& fila){
    PrintingProcess* pp = new PrintingProcess();
    pp->setId(fila.getTamanho()+1);

    fila.adicionarFila(pp);

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
        atual->execute(fila);

        fila.removerFila();
    }

    system("pause");

    imprimirOpcoes(fila);

}

#endif // GERENCIADOR_H_INCLUDED
