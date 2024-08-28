#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>

struct NodoListaInt {
	int dato;
	NodoListaInt *sig;
	NodoListaInt() : dato(0), sig(NULL) {}
	NodoListaInt(int d) : dato(d), sig(NULL) {}
};

struct _cabezalListaInt
{
    NodoListaInt* ppio;
    unsigned int largo;
};

typedef struct _cabezalListaInt* ListaInt;

// PRE: -
// POS: retorna una nueva lista vacia
ListaInt crearListaInt() {
    ListaInt lista = new _cabezalListaInt;
    lista->largo = 0;
    lista->ppio = NULL;
    return lista;
}

// PRE: -
// POS: agrega el elemento e en la lista
void agregar(ListaInt& l, int e) {
    NodoListaInt* nuevo = new NodoListaInt;
    nuevo->dato = e;
    nuevo->sig = l->ppio;
    l->ppio = nuevo;
}

// PRE: -
// POS: borra una ocurrencia del menor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMinimo(ListaInt& l);

// PRE: -
// POS: borra una ocurrencia del mayor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMaximo(ListaInt& l);

// PRE: -
// POS: borra una ocurrencia del primer elemento que sea igual a e
//        Si no encuentra no tiene efecto
void borrar(ListaInt& l, int e);

// PRE: !esVacia()
// POS: retorna el menor elemento
int minimo(ListaInt l);

// PRE: !esVacia()
// POS: retorna el mayor elemento     
int maximo(ListaInt l);

// PRE: -
// POS: retorna true sii existe al menos un elemento que sea igual a e
bool existe(ListaInt l, int e);

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaInt l);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaInt l);

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaInt clon(ListaInt l);

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaInt& l);

void imprimir(NodoListaInt*& nodo) {
    if (nodo == NULL) {
        cout << endl;
        return;
    }
    cout << nodo->dato << " ";
    imprimir(nodo->sig);
}

void imprimir(ListaInt l) {
    imprimir(l->ppio);
}


