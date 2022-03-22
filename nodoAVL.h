//
// Created by milagros on 7/3/21.
//

#ifndef TPEXTRA_NODOAVL_H
#define TPEXTRA_NODOAVL_H
using namespace std;

template<typename T1 ,typename T2>
class NodoAVL{
private:
    T1 clave;
    T2 valor;

    int alturaDerecha;
    int alturaIzquierda;
    int factorBalanceo;

    NodoAVL<T1, T2> *izquierdo = nullptr;
    NodoAVL<T1, T2> *derecho = nullptr;
    NodoAVL<T1, T2> *padre = nullptr;

public:
    /*
     *  PRE:
     *      clave debe ser única.
     *      value direccion de memoria valido.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Asigna los atributos clave y valor a los pasados por parametro.
     */
    NodoAVL(T1 clave, T2 valor);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Cambia el atributo alturaIzquierda del nodo por la pasada por parametro.
     */
    void cambiarAlturaIzq(int nuevaAltura);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo alturaDerecha del nodo por la pasada por parametro.
    */
    void cambiarAlturaDer(int nuevaAltura);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo clave del nodo por la pasada por parametro.
    */
    void cambiarClave(T1 clave);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo valor del nodo por la pasada por parametro.
    */
    void cambiarValor(T2 valor);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo *derecho del nodo por la pasada por parametro.
    */
    void cambiarDerecho(NodoAVL<T1, T2> *derecho);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo *izquierdo del nodo por la pasada por parametro.
    *      Cambia el atributo *izquierdo del nodo por la pasada por parametro.
    */
    void cambiarIzquierdo(NodoAVL<T1, T2> *izquierdo);

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Cambia el atributo *padre del nodo por la pasada por parametro.
    */
    void cambiarPadre(NodoAVL<T1, T2> *padre);

    /*
     *  PRE:
     *      *padre = puntero a una direccion de memoria valida.
     *      *hijoNuevo = puntero a una direccion de memoria valida.
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Setea el nuevo hijo del nodo padre dependiendo si debe ser
     *      derecho o izquierdo.
     */
    void cambiarHijoNuevo(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijoNuevo);

    /*
     *  PRE:
     *      *nodo : puntero a una direccion de memoria valida con un puntero *padre
     *          a una direccion de memoria valida.
     *
     *  POST:
     *      No elimina de memoria el valor a donde apunta *derecho e/o *izquierdo.
     *
     *  FUNCIONAMIENTO:
     *      Cambia el atributo *derecho e *izquierdo a nullptr.
     */
    void quitarPadre(NodoAVL<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo alturaIzquierda.
     */
    int obtenerAlturaDer();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo alturaDerecha.
     */
    int obtenerAlturaIzq();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo clave.
     */
    T1 obtenerClave();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo valor.
     */
    T2 obtenerValor();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo *derecho.
     */
    NodoAVL<T1, T2> *obtenerDerecho();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo *izquierdo.
     */
    NodoAVL<T1, T2> *obtenerIzquierdo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo *padre.
     */
    NodoAVL<T1, T2> *obtenerPadre();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve true si el nodo tiene solo un hijo izquierdo.
     *      *izquierdo != nullptr y *derecho = nulllptr
     *      Caso contrario, devuelve false.
     */
    bool hijoIzquierdoUnico();

    /*
      *  PRE: -
      *
      *  POST: -
      *
      *  FUNCIONAMIENTO:
      *      Devuelve true si el nodo tiene solo un hijo derecho.
      *      *derecho != nullptr y *izquierdo = nulllptr
      *      Caso contrario, devuelve false.
      */
    bool hijoDerechoUnico();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve true si el nodo tiene los dos hijos.
     *      *izquierdo != nullptr y *derecho != nulllptr
     *      Caso contrario, devuelve false.
     */
    bool dosHijos();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve true si el nodo no tiene hijos.
     *      *izquierdo = nullptr y *derecho = nulllptr
     *      Caso contrario, devuelve false.
     */
    bool esHoja();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Si el nodo es distinto de nullptr, se llama recursivamente para
     *      recorre los nodos que le siguen hasta llegar al último, asigando los atributos
     *      alturaIzquierda y alturaDerecha.
     */
    int calcularAltura(NodoAVL<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *        Le resta el atributo alturaIzquierda a al atributo alturaDerecha
     *        y el resultado se lo asigana al atributo factorBalanceo.
     *
     */
    void calcularFactorBalanceo(NodoAVL<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el atributo factorBalanceo.
     */
    int obtenerFB();

    /*
     *  PRE:
     *      valor = puntero a una direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria del puntero valor
     *
     *  FUNCIONAMIENTO:
     *      Destructor de NodoAVL.
     */
    ~NodoAVL();

};


template<typename T1, typename T2>
NodoAVL<T1, T2>::NodoAVL(T1 clave, T2 valor)
{
    this -> clave = clave;
    this -> valor = valor;
    this -> alturaIzquierda = 0;
    this -> alturaDerecha = 0;
    this -> factorBalanceo = 0;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarAlturaIzq(int nuevaAltura)
{
    this -> alturaIzquierda = nuevaAltura;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarAlturaDer(int nuevaAltura)
{
    this -> alturaDerecha = nuevaAltura;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarClave(T1 clave)
{
    this -> clave = clave;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarValor(T2 valor)
{
    this -> valor = valor;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarIzquierdo(NodoAVL<T1, T2> *izquierdo )
{
    this -> izquierdo = izquierdo;
}
template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarDerecho(NodoAVL<T1, T2> *derecho )
{
    this -> derecho = derecho;
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarPadre(NodoAVL<T1, T2> *padre )
{
    this -> padre = padre;
}

template<typename T1, typename T2>
int NodoAVL<T1, T2>::obtenerAlturaDer()
{
    return  alturaDerecha;
}

template<typename T1, typename T2>
int NodoAVL<T1, T2>::obtenerAlturaIzq()
{
    return  alturaIzquierda;
}

template<typename T1, typename T2>
NodoAVL<T1, T2>  *NodoAVL<T1, T2>::obtenerIzquierdo()
{
    return izquierdo;
}

template<typename T1, typename T2>
NodoAVL<T1, T2> *NodoAVL<T1, T2>::obtenerDerecho()
{
    return derecho;
}

template<typename T1, typename T2>
NodoAVL<T1, T2> *NodoAVL<T1, T2>::obtenerPadre()
{
    return  padre;
}

template<typename T1, typename T2>
T1 NodoAVL<T1, T2>::obtenerClave()
{
    return  clave;
}

template<typename T1, typename T2>
T2 NodoAVL<T1, T2>::obtenerValor()
{
    return  valor;
}

template<typename T1, typename T2>
bool NodoAVL<T1, T2>::hijoIzquierdoUnico()
{
    return ((izquierdo != nullptr) && (derecho == nullptr));
}

template<typename T1, typename T2>
bool NodoAVL<T1, T2>::hijoDerechoUnico()
{
    return ((izquierdo == nullptr) && (derecho != nullptr));
}

template<typename T1, typename T2>
bool NodoAVL<T1, T2>::esHoja()
{
    return ((izquierdo == nullptr) && (derecho == nullptr));

}
template<typename T1, typename T2>
bool NodoAVL<T1, T2>::dosHijos()
{
    return ((izquierdo != nullptr) && (derecho != nullptr));

}

template <typename T1, typename T2>
void NodoAVL<T1, T2>::quitarPadre(NodoAVL<T1, T2> *nodo)
{
    if (nodo == nodo -> obtenerPadre() -> obtenerDerecho()){
        nodo -> obtenerPadre() -> cambiarDerecho(nullptr);
    }
    else{
        nodo -> obtenerPadre() -> cambiarIzquierdo(nullptr);
    }
}
template <typename T1, typename T2>
void NodoAVL<T1, T2>::cambiarHijoNuevo(NodoAVL<T1, T2> *padre, NodoAVL<T1, T2> *hijoNuevo)
{

    if (padre -> hijoDerechoUnico()){
        padre -> cambiarDerecho(hijoNuevo);
    }
    else if (padre->hijoIzquierdoUnico()){
        padre -> cambiarIzquierdo(hijoNuevo);
    }
    else if (! padre -> esHoja()){
        if (padre -> obtenerDerecho() == hijoNuevo -> obtenerPadre()){
            padre -> cambiarDerecho(hijoNuevo);
        }
        else{
            padre -> cambiarIzquierdo(hijoNuevo);
        }
    }
}

template<typename T1, typename T2>
int NodoAVL<T1, T2>::calcularAltura(NodoAVL<T1, T2> *nodo)
{
    if(nodo == nullptr)
        return 0;
    else{
        nodo -> cambiarAlturaDer(calcularAltura(nodo->obtenerDerecho()));
        nodo -> cambiarAlturaIzq(calcularAltura(nodo->obtenerIzquierdo()));

        if(nodo -> obtenerAlturaIzq() > nodo -> obtenerAlturaDer())
            return (nodo -> obtenerAlturaIzq() + 1);
        else
            return (nodo->obtenerAlturaDer() + 1);
    }
}

template<typename T1, typename T2>
void NodoAVL<T1, T2>:: calcularFactorBalanceo(NodoAVL<T1, T2> * nodo)
{
    factorBalanceo = nodo -> obtenerAlturaDer() - nodo -> obtenerAlturaIzq();
}

template<typename T1, typename T2>
int NodoAVL<T1, T2>::obtenerFB()
{
    return factorBalanceo;
}

template<typename T1, typename T2>
NodoAVL<T1, T2>::~NodoAVL<T1, T2>() {
    delete valor;
}

#endif //TPEXTRA_NODOAVL_H
