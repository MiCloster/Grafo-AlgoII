#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

#include <iostream>
#include "nodoAVL.h"


const int FB_POSITIVO = 1;
const int FB_NEGATIVO = -1;
const int FB_NEUTRO = 0;

using namespace std;

template <typename T1, typename T2>
class Diccionario{

private:
    NodoAVL<T1 , T2> *raiz;
    int cantidadNodos;

public:
    /*
     *  PRE: -
     *
     *  POST: raiz = nullptr.
     *        cantidadNodos = 0
     *
     *  FUNCIONAMIENTO:
     *      Constructor de diccionario.
     */
    Diccionario();

    /*
     *  PRE:
     *      nodo = puntero a una direccion de memoria valida.
     *      clave = clave unica.
     *
     *  POST:
     *      Si el diccionario no esta vacio cambia el padre del nodo agregado.
     *
     *  FUNCIONAMIENTO:
     *      Inserta al diccionario un nuevo nodo con los valores pasados por parametro.
     */
    NodoAVL<T1 , T2> *agregarNodo(NodoAVL<T1 , T2> *nodo_nuevo, T1 clave, T2 valor);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO: agrega los nodos en el diccionario y chequea que este balanceado.
     */
    void alta(T1 clave, T2 valor);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Si la clave esta dentro del diccionario, devuelve un
     *      puntero nodo con la misma clave que la pasada por parametro.
     *      Caso contrario, devuelve nullptr.
     */
    NodoAVL<T1 , T2> *buscar(NodoAVL<T1 , T2> *nodo, T1 clave);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *          Si la clave esta dentro del diccionario, devuelve true.
     *          Caso contrario, devuelve false.
     */
    bool buscar(T1 clave);

    /*
     *  PRE: -
     *
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Elimina el nodo que contenga la clave pasada como parametros si
     *      se encuentra en el diccionario.
     */
    void quitarNodo(T1 clave);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve true si raiz = nullptr.
     *      Caso contrario, devuelve false.
     */
    bool vacio();

    /*
     *  PRE: *nodo = puntero a una direccion de memoria valida.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Imprime los nodos del árbol ordenadamente llamandose recursivamente.
     */
    void recorridoInOrden(NodoAVL<T1,T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO: -
     */
    void recorridoInOrden();

    /*
     *  PRE: *nodo = puntero a una direccion de memoria valida.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Imprime el arbol por niveles.
     */
    void recorridoAncho(NodoAVL<T1,T2> *nodo, int cont);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO: -
     */
    void recorridoAncho();

    /*
     *  PRE: -
     *
     *  POST: devuelve la cantidad de niveles, es decir la altura de la raiz.
     *
     *  FUNCIONAMIENTO:
     *
     */
    int cantidadNiveles();


    /*
     *  PRE: -
     *
     *  POST: devuelve la cantidad de nodos.
     *
     *  FUNCIONAMIENTO: -
     */
    int obtenerCantidad();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Imprime los datos que le corresponden a la clave ingresada.
     */
    void imprimir(int clave);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Destructor de la clase.
     */
    ~Diccionario();

private:
    /*
    *  PRE:
    *      *nodo = puntero a una direccion de memoria valida.
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Retorna el predecesor del nodo.
    */
    NodoAVL<T1 , T2> *obtenerPredecesor(NodoAVL<T1 , T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria ocupada por la raiz.
     *      Cambia raiz a nullptr si es hoja.
     *
     *  FUNCIONAMIENTO:
     *      Elimina la raiz del diccionario.
     */
    void quitarRaiz();

    /*
     *  PRE:
     *      *nodo = puntero a una direccion de memoria valida.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Según el tipo de nodo, llama a la funcion que le corresponde.
     *      Despues de que se elimina el nodo, chequea el balance del arbol.
     */
    void quitarNodo( NodoAVL<T1 , T2> *nodo);
    /*
   *  PRE:
   *      *padre de nodo debe ser un puntero a una direccion de memoria valida.
   *
   *  POST:
   *      Libera la memoria ocupada por *nodo.
   *
   *  FUNCIONAMIENTO:
   *      Elimina el nodo pasado como parametro.
   *      Coloca en nullptr al atributo *izquierdo o *derecho del padre del nodo
   *      dependiendo de si este es hijo izquierdo o derecho respectivamente.
   */
    void quitarHoja(NodoAVL<T1 , T2> *nodo);

    /*
     *  PRE:
     *      *padre de nodo debe ser un puntero a una direccion de memoria valida.
     *      *derecho de nodo debe ser un puntero a una direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  FUNCIONAMIENTO:
     *      Conecta al nodo padre de nodo con su nodo hijo derecho.
     */
    void quitarNodoConHijoDerecho(NodoAVL<T1 , T2> *nodo);

    /*
     *  PRE:
     *      *padre de nodo debe ser un puntero a una direccion de memoria valida.
     *      *izquierdo de nodo debe ser un puntero a una direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  FUNCIONAMIENTO:
     *      Elimina el nodo pasado como parametro.
     *      Conecta al nodo padre de nodo con su nodo hijo izquierdo.
     */
    void quitarNodoConHijoIzquierdo(NodoAVL<T1 , T2> *nodo);

    /*
     *  PRE:
     *      *padre de nodo debe ser un puntero a una direccion de memoria valida.
     *      *izquierdo de nodo debe ser un puntero a una direccion de memoria valida.
     *      *derecho de nodo debe ser un puntero a una direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  FUNCIONAMIENTO:
     *      Elimina el nodo pasado como parametro.
     *      Conecta al nodo padre con el nodo sucesor.
     */
    void quitarNodoConDosHijos(NodoAVL<T1 , T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria de los nodos del diccionario.
     *      Raiz = nullptr.
     *
     *  FUNCIONAMIENTO:
     *      Elimina todos los nodos del diccionario.
     */
    void limpiar();

    /*
     *  PRE: *nodo = puntero a una direccion de memoria valida.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Compara los factores de balanceo de los nodos llamandose recursivamente
     *      hasta recorrer todos los nodos.
     *      Si se encuentra desbalanceado, llama a la funcion balancear.
     */
    void chequearBalance(NodoAVL<T1, T2> *nodo);

    /*
     *  PRE: *padre = puntero a una direccion de memoria valida.
     *       *hijo = puntero a una direccion de memoria valida.
     *
     *  POST: balancea el arbolAVL
     *
     *  FUNCIONAMIENTO:
     *      Chequea si el arbol esta desbalanceado hacia la izquierda o derecha.
     *      Si lo esta llama a la funcion que le corresponde.
     */
    void balancear(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo);


    /*
     *  PRE: *padre = puntero a una direccion de memoria valida.
     *       *hijo = puntero a una direccion de memoria valida.
     *       Factor de balanceo de *padre e *hijo < 0
     *
     *  POST: balancea el arbolAVL
     *
     *  FUNCIONAMIENTO:
     *      Realiza una rotacion simple derecha.
     *      Si *padre = raiz, *hijo pasa a convertirse en la raiz y se asigna *padre a *derecho del *hijo.
     *      Si *padre != raiz, se une al *hijo con el padre de *padre y *padre pasa a ser el *derecho de *hijo.
     *      Si *hijo tiene izquierdo != nullptr y derecho != nullptr, asigna a *derecho al *padre,
     *      y al *derecho de *hijo se asigna *padre.
     */
    void rotacionSD(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo);

    /*
     *  PRE: *padre = puntero a una direccion de memoria valida.
     *       *hijo = puntero a una direccion de memoria valida.
     *       Factor de balanceo de *padre e *hijo > 0
     *
     *  POST: balancea el arbolAVL
     *
     *  FUNCIONAMIENTO:
     *      Realiza una rotacion simple izquierda.
     *      Si *padre = raiz, *hijo pasa a convertirse en la raiz y se asigna al *padre a *izquierdo del *hijo.
     *      Si *padre != raiz, se une al *hijo con el padre de *padre y *padre pasa a ser el *izquierdo de *hijo.
     *      Si *hijo tiene izquierdo != nullptr y derecho != nullptr, asigna a *izquierda al *padre,
     *      y al *izquierdo de *hijo se asigna *padre.
     */
    void rotacionSI(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo);

    /*
     *  PRE: *padre = puntero a una direccion de memoria valida.
     *       *hijo = puntero a una direccion de memoria valida.
     *       Factor de balanceo de *padre > 0
     *       Factor de balanceo de *hijo < 0
     *
     *  POST: balancea el arbolAVL
     *
     *  FUNCIONAMIENTO:
     *      Primero realiza una rotacion simple derecha y luego una rotacion simple izquierda.
     */
    void rotacionDDI(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo);

    /*
     *  PRE: *padre = puntero a una direccion de memoria valida.
     *       *hijo = puntero a una direccion de memoria valida.
     *       Factor de balanceo de *padre < 0
     *       Factor de balanceo de *hijo > 0
     *
     *  POST: balancea el arbolAVL
     *
     *  FUNCIONAMIENTO:
     *      Primero realiza una rotacion simple izquierda y luego una rotacion simple derecha.
     */
    void rotacionDID(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo);

    /*
       *  PRE: -
       *
       *  POST: -
       *
       *  FUNCIONAMIENTO:
       *      Actualiza la altura y el factor de balanceo del arbol.
   */
    void actualizarFactorBalanceo(NodoAVL<T1,T2> *nodo);



};


template<typename T1, typename T2>
Diccionario<T1, T2>::Diccionario(){
    raiz = nullptr;
    cantidadNodos = 0;

}

template<typename T1, typename T2>
NodoAVL<T1 , T2> *Diccionario<T1, T2>::agregarNodo(NodoAVL<T1 , T2> *nodo, T1 clave, T2 valor)
{
    if (nodo == nullptr){
        nodo = new NodoAVL<T1 , T2>(clave,valor);
        return nodo;
    }
    else if (nodo->obtenerClave() > clave){
        nodo -> cambiarIzquierdo(agregarNodo(nodo -> obtenerIzquierdo(), clave, valor));
        nodo -> obtenerIzquierdo() -> cambiarPadre(nodo);
    }
    else {
        nodo -> cambiarDerecho(agregarNodo(nodo -> obtenerDerecho(), clave, valor));
        nodo -> obtenerDerecho() -> cambiarPadre(nodo);
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::alta(T1 clave, T2 valor)
{
    raiz = agregarNodo(raiz, clave, valor);
    chequearBalance(raiz);
    cantidadNodos++;
}


template<typename T1, typename T2>
NodoAVL<T1 , T2> *Diccionario<T1, T2>::buscar(NodoAVL<T1 , T2> *nodo, T1 clave)
{
    if (nodo == nullptr || clave == nodo -> obtenerClave()){
        return nodo;
    }
    else if (nodo->obtenerClave() > clave){
        return buscar(nodo -> obtenerIzquierdo(), clave);
    }
    return buscar(nodo -> obtenerDerecho(), clave);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::buscar(T1 clave)
{
    NodoAVL<T1 , T2> *encontrado = buscar(raiz, clave);
    return (encontrado != nullptr);
}


template<typename T1, typename T2>
NodoAVL<T1 , T2> *Diccionario<T1, T2>::obtenerPredecesor(NodoAVL<T1 , T2> *nodo)
{
    if (nodo -> obtenerDerecho() != nullptr){
        return obtenerPredecesor(nodo -> obtenerDerecho());
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarRaiz()
{
    if (raiz -> dosHijos()){
        quitarNodoConDosHijos(raiz);
    }
    else{
        NodoAVL< T1 , T2> *aux = raiz;
        if (raiz -> esHoja()){
            raiz = nullptr;
        }
        else if (raiz -> hijoDerechoUnico()){
            raiz = raiz -> obtenerDerecho();
        }
        else if (raiz -> hijoIzquierdoUnico()){
            raiz = raiz -> obtenerIzquierdo();
        }
        delete aux;
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHoja(NodoAVL<T1 , T2> *nodo)
{
    NodoAVL<T1, T2> *padre = nodo -> obtenerPadre();
    if (nodo == padre -> obtenerIzquierdo()){
        padre -> cambiarIzquierdo(nullptr);
    }
    else{
        padre -> cambiarDerecho(nullptr);
    }

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConHijoDerecho(NodoAVL<T1 , T2> *nodo)
{
    NodoAVL<T1, T2> *padre = nodo -> obtenerPadre();
    NodoAVL<T1, T2> *hijoDerecho = nodo -> obtenerDerecho();

    padre -> cambiarHijoNuevo(nodo -> obtenerPadre(), nodo -> obtenerDerecho());
    hijoDerecho -> cambiarPadre(nodo -> obtenerPadre());
    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConHijoIzquierdo(NodoAVL<T1 , T2> *nodo){
    NodoAVL<T1, T2> *padre = nodo -> obtenerPadre();
    NodoAVL<T1, T2> *hijoIzquierdo = nodo -> obtenerDerecho();
    padre -> cambiarHijoNuevo(nodo->obtenerPadre(), nodo->obtenerIzquierdo());
    hijoIzquierdo -> obtenerIzquierdo() -> cambiarPadre(nodo->obtenerPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConDosHijos(NodoAVL<T1 , T2> *nodo)
{
    NodoAVL<T1 , T2> *nodoPredecesor = obtenerPredecesor(nodo -> obtenerIzquierdo());
    T2 auxValor = nodo -> obtenerValor();
    T1 auxClave = nodo -> obtenerClave();

    nodo -> cambiarValor(nodoPredecesor -> obtenerValor());
    nodo -> cambiarClave(nodoPredecesor -> obtenerClave());

    if (!nodoPredecesor -> esHoja()){
        NodoAVL<T1 , T2> *padreNodoPredecesor = nodoPredecesor -> obtenerPadre();
        NodoAVL<T1 , T2> *hijoNodoPredecesor = nodoPredecesor -> obtenerIzquierdo();
        hijoNodoPredecesor -> quitarPadre(hijoNodoPredecesor);

        if (padreNodoPredecesor -> obtenerIzquierdo() == nodoPredecesor){
            padreNodoPredecesor -> cambiarIzquierdo(hijoNodoPredecesor);
        }
        else{
            padreNodoPredecesor -> cambiarDerecho(hijoNodoPredecesor);
        }
        hijoNodoPredecesor -> cambiarPadre(padreNodoPredecesor);
    }

    else{
        nodoPredecesor -> quitarPadre(nodoPredecesor);
    }
    nodoPredecesor -> cambiarValor(auxValor);
    nodoPredecesor -> cambiarClave(auxClave);

    delete nodoPredecesor;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(NodoAVL<T1 , T2> *nodo)
{
    if (nodo == raiz){
        quitarRaiz();
    }
    else if (nodo -> esHoja()) {
        quitarHoja(nodo);
    }

    else if (nodo -> hijoDerechoUnico()){
        quitarNodoConHijoDerecho(nodo);
    }

    else if (nodo -> hijoIzquierdoUnico()){
        quitarNodoConHijoIzquierdo(nodo);
    }

    else{
        quitarNodoConDosHijos(nodo);
    }
    chequearBalance(raiz);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(T1 clave)
{
    NodoAVL<T1, T2> *nodo = buscar(raiz, clave);
    quitarNodo(nodo);
    cantidadNodos--;
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::vacio()
{
    return (raiz == nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::limpiar()
{
    while (!vacio()){
        quitarRaiz();
    }
}



template<typename T1, typename T2>
void Diccionario<T1,T2>::chequearBalance(NodoAVL<T1, T2> *nodo)
{
    if(nodo != nullptr){
        NodoAVL<T1, T2>* padre = nodo;
        NodoAVL<T1, T2>* hijo;
        actualizarFactorBalanceo(nodo);
        chequearBalance(nodo -> obtenerIzquierdo());
        chequearBalance(nodo -> obtenerDerecho());
        actualizarFactorBalanceo(nodo);
        if(nodo->obtenerFB() < FB_NEGATIVO){
            hijo = padre -> obtenerIzquierdo();
            balancear(padre,hijo);
        }
        else if(nodo -> obtenerFB() > FB_POSITIVO){
            hijo = padre -> obtenerDerecho();
            balancear(padre,hijo);
        }
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::balancear(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo)
{
    if (padre -> obtenerFB() < FB_NEGATIVO && hijo -> obtenerFB() <= FB_NEUTRO) {
        rotacionSD(padre,hijo);
    }
    else if (padre -> obtenerFB() > FB_POSITIVO && hijo -> obtenerFB() >= FB_NEUTRO) {
        rotacionSI(padre,hijo);
    }
    else if (padre -> obtenerFB() < FB_NEGATIVO && hijo -> obtenerFB() > FB_NEUTRO) {
        rotacionDID(padre,hijo);
    }
    else if (padre -> obtenerFB() > FB_POSITIVO && hijo -> obtenerFB() < FB_NEUTRO) {
        rotacionDDI(padre,hijo);
    }
    actualizarFactorBalanceo(raiz);
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::rotacionSD(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo)
{
    if(padre == raiz) {
        raiz = hijo;
        padre -> cambiarPadre(hijo);
        hijo -> cambiarPadre(nullptr);
        padre -> cambiarIzquierdo(nullptr);
        hijo -> cambiarDerecho(padre);
    }
    else{
        NodoAVL<T1, T2> *abuelo = padre -> obtenerPadre();
        if(abuelo -> obtenerClave() < hijo -> obtenerClave())
            abuelo -> cambiarDerecho(hijo);
        else
            abuelo->cambiarIzquierdo(hijo);

        hijo->cambiarPadre(abuelo);
        padre->cambiarPadre(hijo);

        if(hijo -> hijoIzquierdoUnico())
            padre -> cambiarIzquierdo(nullptr);
        else
            padre -> cambiarIzquierdo(hijo -> obtenerDerecho());

        hijo->cambiarDerecho(padre);
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::rotacionSI(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo)
{
    if(padre == raiz) {
        raiz = hijo;
        padre -> cambiarPadre(hijo);
        hijo -> cambiarPadre(nullptr);
        padre -> cambiarDerecho(hijo->obtenerIzquierdo());
        hijo -> cambiarIzquierdo(padre);
    }
    else{
        NodoAVL<T1, T2> *abuelo = padre -> obtenerPadre();
        if(abuelo -> obtenerClave() < hijo -> obtenerClave())
            abuelo -> cambiarDerecho(hijo);
        else
            abuelo -> cambiarIzquierdo(hijo);

        hijo -> cambiarPadre(abuelo);

        if(hijo -> hijoDerechoUnico())
            padre -> cambiarDerecho(nullptr);
        else
            padre -> cambiarDerecho(hijo -> obtenerIzquierdo());

        hijo -> cambiarIzquierdo(padre);
        padre -> cambiarPadre(hijo);
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::rotacionDDI(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo)
{
    NodoAVL<T1, T2> *nieto = hijo -> obtenerIzquierdo();
    if (padre == raiz) {
        raiz -> cambiarDerecho(nieto);
        hijo -> cambiarPadre(nieto);
        nieto -> cambiarDerecho(hijo);
        hijo -> cambiarPadre(nieto);
        hijo -> cambiarIzquierdo(nullptr);
        rotacionSI(raiz, nieto);
    }
    else {
        padre -> cambiarDerecho(nieto);
        nieto -> cambiarPadre(padre);
        nieto -> cambiarDerecho(hijo);
        hijo -> cambiarPadre(nieto);
        hijo -> cambiarIzquierdo(nullptr);

        rotacionSI(padre,nieto);
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::rotacionDID(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijo)
{
    NodoAVL<T1, T2> *nieto = hijo -> obtenerDerecho();
    if (padre == raiz) {
        raiz -> cambiarIzquierdo(nieto);
        hijo -> cambiarPadre(nieto);
        nieto -> cambiarIzquierdo(hijo);
        hijo -> cambiarPadre(nieto);
        hijo -> cambiarDerecho(nullptr);

        rotacionSD(raiz,nieto);
    }
    else{
        padre -> cambiarIzquierdo(nieto);
        nieto -> cambiarPadre(padre);
        nieto -> cambiarIzquierdo(hijo);
        hijo -> cambiarPadre(nieto);
        hijo -> cambiarDerecho(nullptr);

        rotacionSD(padre, nieto);
    }
}


template<typename T1, typename T2>
void Diccionario<T1,T2>::recorridoInOrden(NodoAVL<T1, T2> *nodo)
{
    if(nodo != nullptr){
        recorridoInOrden(nodo -> obtenerIzquierdo());
        cout << nodo -> obtenerValor() -> obtenerNombre() << endl;
        recorridoInOrden(nodo -> obtenerDerecho());
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::recorridoInOrden()
{
    recorridoInOrden(raiz);
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::recorridoAncho(NodoAVL<T1, T2> *nodo, int cont)
{
    if(nodo != nullptr){
        if(cont == 0)
            cout << nodo -> obtenerValor() -> obtenerNombre() << "     ";

        recorridoAncho(nodo -> obtenerIzquierdo(), cont - 1);
        recorridoAncho(nodo -> obtenerDerecho(), cont - 1);
    }
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::recorridoAncho()
{
    for(int i = 0; i <= cantidadNiveles(); i ++){
        recorridoAncho(raiz, i);
        cout<<endl;
    }

}

template<typename T1, typename T2>
int Diccionario<T1,T2>::cantidadNiveles()
{
    if(raiz -> obtenerAlturaIzq() > raiz -> obtenerAlturaDer())
        return raiz -> obtenerAlturaIzq();
    else
        return raiz -> obtenerAlturaDer();

}

template<typename T1, typename T2>
int Diccionario<T1,T2>::obtenerCantidad()
{
    return cantidadNodos;
}

template<typename T1, typename T2>
void Diccionario<T1,T2>::imprimir(int clave)
{
    NodoAVL<T1, T2> *encontrado = buscar(raiz, clave);
    encontrado -> obtenerValor() -> mostrarLugares();
}



template<typename T1, typename T2>
void Diccionario<T1,T2>::actualizarFactorBalanceo(NodoAVL<T1, T2> *nodo)
{
    nodo -> calcularAltura(nodo);
    nodo -> calcularFactorBalanceo(nodo);
}

template<typename T1, typename T2>
Diccionario<T1, T2>::~Diccionario()
{
    limpiar();
};

#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H