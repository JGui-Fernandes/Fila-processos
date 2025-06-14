#include <iostream>

#include "Fila.h"
#include "Process.h"
#include "Gerenciador.h"

using namespace std;

int main()
{
    Fila<Process*> fila;

    Gerenciador<Process*> gerenciador;

    gerenciador.iniciar(fila);

    return 0;
}
