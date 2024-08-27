#include "ListaOrdenada.cpp"
#include <iostream>

using namespace std;

int main() {

    ListaOrdInt listaOrdenada = crearListaOrdInt();

    agregar(listaOrdenada, 2);
    agregar(listaOrdenada, 5);
    agregar(listaOrdenada, 3);
    agregar(listaOrdenada, 1);
    agregar(listaOrdenada, 9);
    agregar(listaOrdenada, 6);

    imprimir(listaOrdenada);

    cout << "Largo: " << listaOrdenada->largo << endl;

    borrarMinimo(listaOrdenada);
    borrarMinimo(listaOrdenada);

    imprimir(listaOrdenada);

    cout << "Largo: " << listaOrdenada->largo << endl;

    return 0;
}