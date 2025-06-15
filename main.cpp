#include <iostream>

#include "Gerenciador.h"

using namespace std;

int main()
{
    Fila<Process*> fila;

    Gerenciador<Process*> gerenciador;

    gerenciador.iniciar(fila);

    return 0;
}
