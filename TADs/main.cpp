#include "Lista.cpp"

#include <iostream>

using namespace std;

int main() {

    ListaInt lista = crearListaInt();

    agregar(lista, 4);
    agregar(lista, 2);
    agregar(lista, 8);
    agregar(lista, 2);

    imprimir(lista);
    imprimir(lista);
    imprimir(lista);

    return 0;
}