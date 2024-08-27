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

struct _cabezalListaOrdInt
{
    NodoListaInt* ppio;
    unsigned int largo;
};

typedef struct _cabezalListaOrdInt* ListaOrdInt;

// PRE: -
// POS: retorna una nueva lista vacia
ListaOrdInt crearListaOrdInt() {
    ListaOrdInt lista = new _cabezalListaOrdInt;
    lista->ppio = NULL;
    lista->largo = 0;
    return lista;
};

void agregar(NodoListaInt*& principioLista, int e) {
    if (principioLista == NULL) {
        principioLista = new NodoListaInt(e);
    }
    else if (e <= principioLista->dato) {
        NodoListaInt *nuevo = new NodoListaInt(e);
        nuevo->sig = principioLista;
        principioLista = nuevo;
    }
    else {
        agregar(principioLista->sig, e);
    }
}

// PRE: -
// POS: agrega el elemento e en la lista ordenada de menor a mayor
void agregar(ListaOrdInt& l, int e) {
    agregar(l->ppio, e);
    l->largo++;
};

// PRE: -
// POS: borra una ocurrencia del menor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMinimo(ListaOrdInt& l) {
    if (l->ppio == NULL) return;
    NodoListaInt* aux = l->ppio;
    l->ppio = l->ppio->sig;
    l->largo--;
    delete aux;
}

void borrarMaximo(NodoListaInt*& l) {
    if (l == NULL) return;
    if (l->sig = NULL) {
        NodoListaInt* ultimo = l;
        l = NULL;
        delete ultimo;
    }
    borrarMaximo(l->sig);       
}

// PRE: -
// POS: borra una ocurrencia del mayor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMaximo(ListaOrdInt& l) {
    NodoListaInt* principio = l->ppio;
    borrarMaximo(l->ppio);
    l->ppio = principio;
    l->largo--;
    delete principio;
}

// PRE: -
// POS: borra una ocurrencia del primer elemento que sea igual a e
//        Si no encuentra no tiene efecto
void borrar(ListaOrdInt& l, int e);

// PRE: !esVacia()
// POS: retorna el menor elemento
int minimo(ListaOrdInt l);

// PRE: !esVacia()
// POS: retorna el mayor elemento     
int maximo(ListaOrdInt l);

// PRE: -
// POS: retorna true sii existe al menos un elemento que sea igual a e
bool existe(ListaOrdInt l, int e);

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaOrdInt l);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaOrdInt l);

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaOrdInt clon(ListaOrdInt l);

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaOrdInt& l);

void imprimir(NodoListaInt*& nodo) {
    if (nodo == NULL) {
        cout << endl;
        delete nodo;
        return;
    }
    cout << nodo->dato << " ";
    imprimir(nodo->sig);
}

void imprimir(ListaOrdInt l) {
    NodoListaInt* principio = l->ppio;
    imprimir(l->ppio);
    l->ppio = principio;
}
