//
// Created by milagros on 9/3/21.
//

#ifndef TPEXTRA_RUTA_H
#define TPEXTRA_RUTA_H

#include <string>
#include <iostream>
using namespace std;

class Ruta {
private:
    string ruta;
    string origen;
    string destino;
    int distancia;
    int tiempo;
    int peaje;

public:

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *         Constructor de la clase Ruta.
     *         Asigna los atributos a los pasados por parametro.
     */
    Ruta(string ruta, string origen, string destino, int distancia, int velocidad, int peaje);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *         Devuelve el atributo ruta.
     */
    string obtenerRuta();

    /*
    * PRE: -
    * POST: -
    * FUNCIONAMIENTO:
    *         Devuelve el atributo distancia.
    */
    int obtenerDistancia();

    /*
    * PRE: -
    * POST: -
    * FUNCIONAMIENTO:
    *         Devuelve el atributo tiempo.
    */
    int obtenerTiempo();

    /*
    * PRE: -
    * POST: -
    * FUNCIONAMIENTO:
    *         Devuelve el atributo peaje.
    */
    int obtenerPeaje();

    /*
    * PRE: -
    * POST: -
    * FUNCIONAMIENTO:
    *         Devuelve true si los valores pasados por parametro estan conectados.
    *         Caso contrario, devuelve false.
    */
    bool chequearConexion(string origenNuevo, string destinoNuevo);

    /*
    * PRE: -
    * POST: -
    * FUNCIONAMIENTO:
    *        Destructor por defecto de la clase Ruta.
    */
    ~Ruta() = default;
};


#endif //TPEXTRA_RUTA_H
