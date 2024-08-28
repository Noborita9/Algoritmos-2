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
    if (l->sig == NULL) {
        NodoListaInt* ultimo = l;
        l = l->sig;
        delete ultimo;
        return;
    }
    borrarMaximo(l->sig);       
}

// PRE: -
// POS: borra una ocurrencia del mayor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMaximo(ListaOrdInt& l) {
    if (l->ppio == NULL) return;
    borrarMaximo(l->ppio);
    l->largo--;
}

bool borrar(NodoListaInt*& l, int e) {
    if (l == NULL) return false;
    if (l->dato == e) {
        NodoListaInt* aux = l;
        l = l->sig;
        delete aux;
        return true;
    }
    if (l->sig == NULL) return false;
    if (l->sig->dato == e) {
        NodoListaInt* aux = l->sig;
        l->sig  = l->sig->sig;
        delete aux;
        return true;
    }
    return borrar(l->sig, e);
}

// PRE: -
// POS: borra una ocurrencia del primer elemento que sea igual a e
//        Si no encuentra no tiene efecto
void borrar(ListaOrdInt& l, int e) {
    if (borrar(l->ppio, e)) l->largo--;
}

// PRE: !esVacia()
// POS: retorna el menor elemento
int minimo(ListaOrdInt l) {
    return l->ppio->dato;
}

// PRE: !esVacia()
// POS: retorna el mayor elemento     
int maximo(ListaOrdInt l) {
    NodoListaInt* aux = l->ppio;
    while (aux->sig != NULL) {
        aux = aux->sig;
    }
    return aux->dato;
}

bool existe(NodoListaInt*& l, int e) {
    if (l == NULL) return false;
    if (l->dato == e) return true;
    return existe(l->sig, e);
}

// PRE: -
// POS: retorna true sii existe al menos un elemento que sea igual a e
bool existe(ListaOrdInt l, int e) {
    return existe(l->ppio, e);
}

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaOrdInt l) {
    return !l->ppio;
}

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaOrdInt l) {
    return l->largo;
}

NodoListaInt* clon(NodoListaInt* l) {
    if (l == NULL) return NULL;
    NodoListaInt* nuevo = new NodoListaInt;
    nuevo->dato = l->dato;
    nuevo->sig = clon(l->sig);
    return nuevo;
}

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaOrdInt clon(ListaOrdInt l) {
    ListaOrdInt copia = new _cabezalListaOrdInt;
    copia->largo = l->largo;
    copia->ppio = clon(l->ppio);
    return copia;
}

void vaciar(NodoListaInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaOrdInt& l) {
    vaciar(l->ppio);
    delete l;
    l = NULL;
}

void imprimir(NodoListaInt*& nodo) {
    if (nodo == NULL) {
        cout << endl;
        return;
    }
    cout << nodo->dato << " ";
    imprimir(nodo->sig);
}

void imprimir(ListaOrdInt l) {
    imprimir(l->ppio);
}

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