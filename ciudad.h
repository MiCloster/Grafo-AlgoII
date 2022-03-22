//
// Created by milagros on 9/3/21.
//

#ifndef TPEXTRA_CIUDAD_H
#define TPEXTRA_CIUDAD_H

#include <string>
#include "lista.h"
#include "vertice.h"

using namespace std;

class Ciudad {
private:
    string nombreCiudad;
    Lista<Vertice<string> *> *lugaresTuristicos;
public:
    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO:
     *      Constructor de la clase Ciudad.
     *      Asigna nombreCiudad y crea una nueva lista de lugare turisticos.
     */
    Ciudad(string nombre);

    /*
     * PRE:
     * POST: -
     * FUNCIONAMIENTO:
     *      Devuelve el nombreCiudad.
     */
    string obtenerNombre();

    /*
     * PRE: *lugaresTuristicos  =  puntero a una direccion de memoria valida.
     * POST: -
     * FUNCIONAMIENTO:
     *      Muestra todos los lugares de la lista.
     */
    void mostrarLugares();

    /*
     * PRE: lista lugaresTuristicos = direccion de memoria valida.
     * POST: -
     * FUNCIONAMIENTO:
     *      Agrega nuevos nombre a lugaresTuristicos.
     */
    void agregarLugares(string nombre);

    /*
     * PRE: -
     * POST:
     *      Libera la memoria de la lista *lugaresTuristicos.
     * FUNCIONAMIENTO:
     *       Destructor de la clase Ciudad.
     */
    ~Ciudad();
};


#endif //TPEXTRA_CIUDAD_H
