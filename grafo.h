//
// Created by milagros on 9/3/21.
//

#ifndef TPEXTRA_GRAFO_H
#define TPEXTRA_GRAFO_H


#include "lista.h"
#include "vertice.h"
#include "ruta.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const string ARCHIVO_RUTAS = "rutas.txt";
const int INFINITO = 1000;

class Grafo{
private:
    Lista<Lista<Vertice<string> *> *> *raiz;

    Lista<Vertice<string> *> *listaCiudades;

    Lista<Ruta *> *listaRutas;


    int cantidad;

    int **matrizDistancia= nullptr;
    int **matrizVelocidad= nullptr;
    int **matrizPeaje= nullptr;

    int **matrizCaminoDistancia = nullptr;
    int **matrizCaminoVelocidad = nullptr;
    int **matrizCaminoPeaje= nullptr;

public:
    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Constructor de la clase Grafo.
     *      Asigna a los atributos ListaCiudades, ListaRutas, y raiz a una nueva lista.
     */
    Grafo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Asigna las ciudades de la lista, estableciendo su conexion.
     *      Si las ciudades son adyacentes llama a la funcion insertarVertice.
     */
    void cargarGrafo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Imprime todas las ciudades dentro de listaCiudades.
     */
    void imprimirCiudades();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *     Muestra el camino minimo para ir de un vertice a otro con el peso y nombre de la arista.
     */
    void mostrarCamino(Lista<Vertice<int>*> *lista);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Calcula el camino minimo de origen a destino segun el tipoMatriz pasado por parametro.
     *      Retorna la lista con el camino minimo.
     */
    Lista<Vertice<int> *> *obtenerCaminoMinimo(int origen, int destino, string tipoMatriz);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO: -
     *
     */
    void iniciarMatrices();

    /*
    *  PRE: -
    *
    *  POST: -
    *
    *  FUNCIONAMIENTO:
    *      Devuelve la cantidad de vertices.
    *
    */
    int obtenerCantidad();

    /*
    *  PRE: -
    *
    *  POST:
     *      Libera la memoria de todas las  matrices y listas.
    *
    *  FUNCIONAMIENTO:
    *      Destructor de la clase Grafo.
    *
    */
    ~Grafo();

private:

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Se llama a si misma recursivamente.
     */
    void obtenerCaminoMinimo(int origen, int destino, int **matrizCamino, int ** matrizPeso,
                             Lista<Vertice<int> *> *lista, string tipo);


    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve la matrizCamino según el tipo pasado por parametro.
     */
    int **tipoCamino(string tipo);
    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve la matrizPeso segun el tipo pasado por parametro.
     */
    int **tipoPeso(string tipo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Lee el archivo de texto ARCHIVO_RUTAS.
     *      Carga la informacion de las rutas en listaRutas y devuelve una lista solo con las ciudades.
     */
    Lista<Vertice<string> *> *cargarRuta();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Agrega *verticeOrigen y *verticeDestino si la sublista se encuentra vacia,
     *      Caso contrario, solo agrega *verticeDestino a la sublista de verticeOrigen.
     */
    void insertarVertice(Vertice<string> *verticeOrigen, Vertice<string> *verticeDestino);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve una lista, si el *verticeOrigen se encuentra en ella.
     *      Caso contrario, devuelve nullptr.
     */
    Lista<Vertice<string> *> *obtenerSublista(Vertice<string> *verticeOrigen);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Inicializa las matrices, reservando la memoria segun la cantidad de vertices, es decir el largo del grafo.
     */
    void iniciarMatrices(int **matrizPeso[], int **matrizCamino[]);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el peso para ir de origen a destino.
     *      Si origen = destino, devuelve 0.
     *      Si no es posible ir de origen a destino, devuelve INFINITO.
     */
    int calcularPeso(string origen, string destino, string tipoMatriz);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Actualiza las matrices peso y camino con los pesos minimos.
     */
    void actualizarMatrices(string tipoMatriz, int **matrizCamino, int **matrizPeso);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Aplica en las matrices el algoritmo Floy-Warshall, que consiste en comparar
     *      todos los posibles caminos entre cada par de vertices.
     */
    void algoritmoFloydWarshall(int **matrizPesos, int **matrizCamino);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el string que se encuentra en la posicion pasada por parametro.
     */
    string convertirEnCadena(int valor);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  FUNCIONAMIENTO:
     *      Devuelve el nombre de la ruta que le corresponde a los valores pasados por parametro.
     */
    string obtenerRuta(string origen, string destino, string tipo, int valor);
};

#endif //TPEXTRA_GRAFO_H
