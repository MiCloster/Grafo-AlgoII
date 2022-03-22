//
// Created by milagros on 7/3/21.
//

#ifndef TP2_NODO_H
#define TP2_NODO_H

template<typename Dato>
class Nodo {
private:
    Dato elemento;

    Nodo<Dato> *siguiente;

    //Metodos
public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Constructor de la clase Nodo.
     *      Asigna el atributo elemento al pasado por parametros y a *siguiente lo iguala a nullptr.
     */
    Nodo(Dato elementoNuevo);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *       Devuelve el contenido del nodo.
     */
    Dato obtenerDato();


    /*
    * PRE: *siguientenodo = puntero de una direccion de memoria valida.
     * POST: -
     * FUNCIONAMIENTO:
     *         Asigna a siguiente por el valor pasado por parametro.
     */
    void asignarSiguiente(Nodo<Dato> *siguienteNodo);


    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *      Devuelve el atributo *siguiente.
     */
    Nodo<Dato> *obtenerSiguiente();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Destructor del nodo.
     */
    ~Nodo();
};

template<typename Dato>
Nodo<Dato>::Nodo(Dato elementoNuevo) {
    elemento = elementoNuevo;
    siguiente = nullptr;
}

template<typename Dato>
Dato Nodo<Dato>::obtenerDato() {
    return elemento;
}

template<typename Dato>
Nodo<Dato> *Nodo<Dato>::obtenerSiguiente() {
    return siguiente;
}

template<typename Dato>
void Nodo<Dato>::asignarSiguiente(Nodo<Dato> *siguienteNodo) {
    siguiente = siguienteNodo;
}


template<typename Dato>
Nodo<Dato>::~Nodo<Dato>() {
    delete elemento;
}
#endif //TP2_NODO_H