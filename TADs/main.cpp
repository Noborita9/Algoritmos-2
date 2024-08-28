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

    //borrarMinimo(listaOrdenada);
    //borrarMinimo(listaOrdenada);

    //borrarMaximo(listaOrdenada);

    // borrar(listaOrdenada, 10);

    // cout << "Primier elemento: " << minimo(listaOrdenada) << endl;
    // cout << "Último elemento: " << maximo(listaOrdenada) << endl;

    // imprimir(listaOrdenada);
 
    // cout << "Largo: " << listaOrdenada->largo << endl;

    cout << "Existe el elemento? " << existe(listaOrdenada, 15) << endl;

    ListaOrdInt ordenadaDos = crearListaOrdInt();

    agregar(ordenadaDos, 11);

    cout << "Esta vacia? " << esVacia(ordenadaDos) << endl;

    cout << "Cantidad de elementos: " << cantidadElementos(listaOrdenada) << endl;


    return 0;
}