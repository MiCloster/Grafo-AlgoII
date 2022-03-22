//
// Created by milagros on 7/3/21.
//

#ifndef TPEXTRA_LISTA_H
#define TPEXTRA_LISTA_H

#include "nodo.h"
#include <iostream>



using namespace std;

const string TIPO_VELOCIDAD = "velocidad";
const string TIPO_DISTANCIA = "distancia";
const string TIPO_PEAJE = "peaje";

template<typename Dato>
class Lista {
private:
    Nodo<Dato> *primero;
    int cantidad;

public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Constructor de la clase Lista.
     *      Iguala primero a nullptr y cantidad a 0.
     */
    Lista();

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *          Cambia el valor de siguiente al hasta entonces ultimo elemento con el valor del
     *          nuevo ultimo elemento.
     *          Agrega al final de la lista el elemento .
     */
    void alta(Dato elementoNuevo);

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Devuelve la cantidad de elementos que contiene la lista.
     */
    int obtenerCantidad();

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Si se encuentra en la lista,la primera coincidencia tipo nodo.
     *      Caso contrario, devuelve nullptr.
     *      Si en la lista hay mas de una coincidencia devuelve la primera.
     * */
    Nodo<Dato> *buscarElemento(string origen, string destino);

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Si se encuentra en la lista,la primera coincidencia tipo nodo.
     *      Caso contrario, devuelve nullptr.
     *      Si en la lista hay mas de una coincidencia devuelve la primera.
     * */
    Nodo<Dato> *buscarElemento(string origen, string destino, string tipo, int valor);

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Devuelve el valor que coincida con el tipo pasado por parametro.
     * */
    int obtenerValorTipo(Nodo<Dato> *nodo, string tipo);

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Busca el minimo valor del nodo segun el tipo pasado por parametro
     *      y lo devuelve.
     * */
    int minimoValor(string origen, string destino, string tipo);

    /*
     * PRE: 0 < posicion < cantidad.
     * POST: -
     * FUNCIONAMIENTO:
     *        Elimina el elemento de la posicion pasada por parametro
     *        y apunta el anterior del eliminado al siguiente de la lista.
     */
    void baja(int posicion);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *      Devuelve true si la cantidad de elementos es igual a 0.
     *      Caso contrario, devuelve false.
     *
     */
    bool listaVacia();

    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO:
     *      Muestra la informacion de los elementos  de la lista con su respectiva posicion.
     */
    void mostrarLista();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Devuelve el nodo que se encuentra en la posicion pasada por parametro.
     */
    Nodo<Dato> *buscarNodo(int posicion);

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Devuelve la posicion en la que se encuentra el nodo que coincide con
     *      el valor pasado por parametros.
     *      Caso contrario, devuelve 0.
     */
    int posicionDato(string buscar);

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Devuelve true si elemento buscado existe dentro de la lista.
     *      Caso contrario, devuelve false.
     */
    bool existe(string nombre);

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Destructor de la clase Listas.
     *      Da de baja todos los elementos hasta que la lista este vacia.
     */
    ~Lista();
};


template<typename Dato>
Lista<Dato>::Lista()
{
    primero = nullptr;
    cantidad = 0;
}

template<typename Dato>
int Lista<Dato>::obtenerCantidad()
{
    return cantidad;
}

template<typename Dato>
bool Lista<Dato>::listaVacia()
{
    return cantidad == 0;
}


template<typename Dato>
void Lista<Dato>::alta(Dato elementoNuevo)
{
    Nodo<Dato> *nuevoNodo = new Nodo<Dato>(elementoNuevo);
    if (cantidad == 0)
        primero = nuevoNodo;
    else
        buscarNodo(cantidad) -> asignarSiguiente(nuevoNodo);

    cantidad ++;
}

template<typename Dato>
int Lista<Dato>::obtenerValorTipo(Nodo<Dato> *nodo, string tipo)
{
    if(tipo == TIPO_VELOCIDAD)
        return nodo -> obtenerDato() -> obtenerTiempo();
    else if(tipo == TIPO_DISTANCIA)
        return nodo -> obtenerDato() -> obtenerDistancia();
    else
        return nodo -> obtenerDato() -> obtenerPeaje();
}


template<typename Dato>
Nodo<Dato> *Lista<Dato>::buscarElemento(string origen, string destino)
{
    Nodo<Dato> *actual = primero;

    while (actual != nullptr && actual -> obtenerDato() -> chequearConexion(origen, destino) == false) {
        actual = actual -> obtenerSiguiente();
    }
    if(! actual)
        return nullptr;

    return actual;
}

template<typename Dato>
Nodo<Dato> *Lista<Dato>::buscarElemento(string origen, string destino, string tipo, int valor)
{
    Nodo<Dato> *actual = primero;
    bool encontrado = false;

    while (actual != nullptr && encontrado == false) {
        if((actual -> obtenerDato() -> chequearConexion(origen, destino)) && valor == obtenerValorTipo(actual, tipo)){
            encontrado = true;
        }
        else
            actual = actual -> obtenerSiguiente();
    }
    if(actual != nullptr)
        return actual;

    return nullptr;

}

template<typename Dato>
int Lista<Dato>::minimoValor(string origen, string destino, string tipo)
{
    Nodo<Dato> *actual = primero;
    int valorMinimo = obtenerValorTipo(buscarElemento(origen,destino), tipo);
    while (actual != nullptr) {
        if (actual -> obtenerDato() -> chequearConexion(origen, destino) && valorMinimo > obtenerValorTipo(actual, tipo)) {
            valorMinimo = obtenerValorTipo(actual, tipo);
        }
        actual = actual->obtenerSiguiente();
    }

    return valorMinimo;
}

template<typename Dato>
bool Lista<Dato>::existe(string nombre)
{
    Nodo<Dato> *actual = primero;
    while (actual != nullptr && actual -> obtenerDato() -> obtenerValor() != nombre) {
        actual = actual -> obtenerSiguiente();
    }
    if(!actual)
        return false;
    return true;
}
template<typename Dato>
void Lista<Dato>::baja(int posicion)
{
    Nodo<Dato> *nodoAux = buscarNodo(posicion);

    if (posicion == 1) {
        primero = nodoAux -> obtenerSiguiente();

    } else {
        Nodo<Dato> *nodoAnterior = buscarNodo(posicion - 1);

        nodoAnterior -> asignarSiguiente(nodoAux->obtenerSiguiente());
    }

    cantidad--;

    delete nodoAux;
}

template<typename Dato>
void Lista<Dato>::mostrarLista()
{
    if (cantidad == 0) {
        cout << "\nLa lista esta vacia\n" << endl;
    } else {
        for (int i = 1; i <= cantidad; i ++) {
            cout << endl << i << "-" << buscarNodo(i) -> obtenerDato() -> obtenerValor() << endl;
        }
    }
}

template<typename Dato>
Nodo<Dato> *Lista<Dato>::buscarNodo(int posicion) {
    if (listaVacia() || posicion > cantidad) {
        return nullptr;
    }
    Nodo<Dato> *buscado = primero;

    for (int i = 1; i < posicion; i ++) {
        buscado = buscado -> obtenerSiguiente();
    }
    return buscado;
}

template<typename Dato>
int Lista<Dato>::posicionDato(string buscar) {
    for (int i = 1; i <= cantidad; i ++) {
        string elemento = buscarNodo(i) -> obtenerDato() -> obtenerValor();
        if (buscar == elemento)
            return i;
    }
    return 0;
}

template<typename Dato>
Lista<Dato>::~Lista() {
    while (!listaVacia()) {
        baja(1);
    }
}


#endif //TPEXTRA_LISTA_H
