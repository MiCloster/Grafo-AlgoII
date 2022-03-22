//
// Created by milagros on 8/3/21.
//

#ifndef TPEXTRA_MENU_H
#define TPEXTRA_MENU_H

#include <string>
#include <fstream>
#include <iostream>

#include "lista.h"
#include "diccionario.h"
#include "ciudad.h"
#include "grafo.h"
#include <string>

const string ARCHIVO_CIUDADES = "ciudades.txt";
using namespace std;

class Menu {
private:
    Diccionario<int, Ciudad*> *diccCiudades;
    Lista<Vertice<string> *> *ciudades;
    Grafo *rutasMinimas;
public:
    /*
     * PRE:-
     * POST:-
     * FUNCIONAMIENTO:
     *         Contructor de la clase Menu.
     *         Asigna a *diccCiudades un nuevo diccionario, a *ciudadesOrdenadas una nueva lista
     *         y a *rutasMinimas un nuevo grafo.
     */
    Menu();

    /*
     * PRE:-
     * POST:-
     * FUNCIONAMIENTO:
     *         Lee el archivo ciudades.txt, por cada ciudad crea un objeto Ciudad
     *         Agrega en el diccionario el objeto ciudad junto con su clave numerica.
     */
    void cargarDatos();

    /*
     * PRE:-
     * POST:-
     * FUNCIONAMIENTO:-
     */
    void menuCiudades();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Muestra el menu de rutas.
     */
    void menuRutas();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *      Carga el grafo e inicia las matrices del mismo.
     */
    void cargarGrafo();

    /*
     * PRE:-
     * POST:
     *      Libera la memoria de la lista *ciudadesOrdenadas, del diccionario *diccCiudades
     *      y del grafo *rutasMinimas.
     * FUNCIONAMIENTO:
     *         Destructor de la clase Menu;
     */
    ~Menu();

private:
    /*
     * PRE:-
     * POST:-
     * FUNCIONAMIENTO:
     *         Imprime el primer o segundo menu segun el valor pasado por parametro.
     */
    void mostrarMenu(int numeroMenu);

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Imprime los detalles de la clave buscada.
     */
    void buscarCiudad();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Devuelve el numero de la opcion elegida.
     */
    int pedirOpcion(int minimo, int maximo, int numeroMenu);

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *        Devuelve el entero que coincide con el nombre de la ciudad elegida que esta dentro del diccionario.
     */
    int pedirNombreCiudad();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Devuelve un string.
     */
    string chequearSeguir();

    /*
     * PRE:-
     * POST:-
     * FUNCIONAMIENTO:
     *         Muestra el camino minimo segun los valores pasado por parametro.
     */
    void mostrarCaminosMinimos(int opcion, int origen, int destino);


    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Agrega una nueva ciudad al diccCiudades y a la lista ciudadesOrdenadas.
     */
    void altaCiudad();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Elimina una ciudad del diccCiudades y de la lista ciudadesOrdenadas.
     */
    void bajaCiudad();


    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     *         Devuelve un numero dentro del rango.
     */
    int chequearCiudades();



};


#endif //TPEXTRA_MENU_H
