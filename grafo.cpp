//
// Created by milagros on 9/3/21.
//

#include "grafo.h"

Grafo::Grafo(){
    raiz = new Lista<Lista<Vertice<string> *> *>;

    listaRutas = new Lista<Ruta *>();

    listaCiudades = cargarRuta();

    cantidad = listaCiudades->obtenerCantidad();
}

void Grafo::cargarGrafo() {
    Vertice<string> *verticeOrigen;
    Vertice<string> *verticeDestino;
    string nombreOrigen;
    string nombreDestino;
    for (int i = 0; i < cantidad; i++){
        nombreOrigen = listaCiudades -> buscarNodo(i+1) -> obtenerDato() -> obtenerValor();

        for (int j = 0; j<cantidad; j++){

            if (i!=j){

                nombreDestino = listaCiudades -> buscarNodo(j+1) -> obtenerDato() -> obtenerValor();
                if(listaRutas -> buscarElemento(nombreOrigen, nombreDestino)){
                    verticeOrigen = new Vertice<string>(nombreOrigen);
                    verticeDestino = new Vertice<string>(nombreDestino);
                    insertarVertice(verticeOrigen, verticeDestino);
                }
            }
        }
    }
}

void Grafo::insertarVertice(Vertice<string> *verticeOrigen, Vertice<string> *verticeDestino) {
    Lista<Vertice<string> *> *sublista = obtenerSublista(verticeOrigen);

    if(sublista == nullptr){
        sublista = new Lista<Vertice<string> *>();
        sublista -> alta(verticeOrigen);
        sublista -> alta(verticeDestino);
        raiz -> alta(sublista);
    }
    else{
        sublista -> alta(verticeDestino);
        delete verticeOrigen;
    }
}

Lista<Vertice<string> *> *Grafo::obtenerSublista(Vertice<string> * verticeOrigen){
    if (raiz -> obtenerCantidad() == 0){
        return nullptr;
    }
    Lista<Vertice<string> *> *sublista = raiz -> buscarNodo(1) -> obtenerDato();
    Nodo<Vertice<string> *> *nodo  = sublista -> buscarNodo(1);
    int i = 1;
    while ((nodo -> obtenerDato() -> obtenerValor() != verticeOrigen -> obtenerValor()) && (i <= raiz -> obtenerCantidad())){
        sublista = raiz -> buscarNodo(i)->obtenerDato();
        nodo = sublista -> buscarNodo(1);
        i++;
    }
    if (nodo -> obtenerDato() -> obtenerValor() != verticeOrigen -> obtenerValor()){
        return nullptr;
    }
    return sublista;

}

Lista<Vertice<string> *> * Grafo::cargarRuta() {
    Lista<Vertice<string> *> * ciudades = new Lista<Vertice<string> *>();
    ifstream entrada(ARCHIVO_RUTAS);
    string palabra;
    string ruta;
    string origen;
    string destino;
    int distancia;
    int velocidadMax;
    int peajes;

    if(! entrada)
        cout << "ERROR AL ABRIR EL ARCHIVO"<<endl;
    else{
        while(getline(entrada, ruta)){
            getline(entrada,origen);
            getline(entrada,destino);

            getline(entrada,palabra);
            distancia = stoi(palabra);

            getline(entrada, palabra);
            velocidadMax = stoi(palabra);

            getline(entrada,palabra);
            peajes = stoi(palabra);
            entrada.ignore(1000,'\n');

            if(! ciudades -> existe(origen)){
                ciudades -> alta(new Vertice<string>(origen));
            }
            else if(! ciudades -> existe(destino)){
                ciudades -> alta(new Vertice<string>(destino));
            }
            listaRutas -> alta(new Ruta(ruta,origen,destino,distancia,velocidadMax,peajes));
        }
    }
    return ciudades;
}

void Grafo::iniciarMatrices() {
    iniciarMatrices(&matrizDistancia, &matrizCaminoDistancia);
    iniciarMatrices(&matrizPeaje, &matrizCaminoPeaje);
    iniciarMatrices(&matrizVelocidad, &matrizCaminoVelocidad);

    actualizarMatrices(TIPO_DISTANCIA, matrizCaminoDistancia, matrizDistancia);
    actualizarMatrices(TIPO_VELOCIDAD, matrizCaminoVelocidad, matrizVelocidad);
    actualizarMatrices(TIPO_PEAJE, matrizCaminoPeaje, matrizPeaje);
}
void Grafo::iniciarMatrices(int **matrizPeso[], int **matrizCamino[]){
    *matrizCamino = new int * [cantidad];
    *matrizPeso = new int * [cantidad];

    for (int i=0; i < cantidad;i++){
        (*matrizCamino)[i] = new int [cantidad];
        (*matrizPeso)[i] = new int [cantidad];

    }
}

void Grafo::actualizarMatrices(string tipoMatriz, int **matrizCamino, int **matrizPeso) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            matrizPeso[i][j] = calcularPeso(listaCiudades -> buscarNodo(i+1) -> obtenerDato() -> obtenerValor(),
                                            listaCiudades -> buscarNodo(j+1) -> obtenerDato() ->obtenerValor(),
                                            tipoMatriz);
            matrizCamino[i][j] = j + 1;

        }
    }

    algoritmoFloydWarshall(matrizPeso, matrizCamino);

}

int Grafo::calcularPeso(string origen, string destino, string tipoMatriz){
    int peso = 0;
    if(listaRutas -> buscarElemento(origen, destino)){
        peso = listaRutas -> minimoValor(origen,destino, tipoMatriz);
    }
    else if(destino == origen)
        peso = 0;
    else
        peso = INFINITO;
    return peso;
}

void Grafo::algoritmoFloydWarshall(int **matrizPesos, int **matrizCamino) {
    for (int k = 0; k < cantidad; k++){
        for (int i = 0; i < cantidad; i++){
            for (int j = 0; j < cantidad; j++){

                if ( i != k && j!=k) {
                    if (matrizPesos[k][j] + matrizPesos[i][k] < matrizPesos[i][j]) {
                        //cout << matrizPesos[i][j]<<endl;
                        matrizPesos[i][j] = matrizPesos[k][j] + matrizPesos[i][k];
                        matrizCamino[i][j] = matrizCamino[k][k];
                    }
                }
            }

        }
    }
}


void Grafo::obtenerCaminoMinimo(int origen, int destino, int **matrizCamino, int **matrizPeso,
                                Lista<Vertice<int> *> *lista, string tipo) {

    string ruta;
    if (matrizCamino[origen-1][destino-1] == destino){
        ruta = obtenerRuta(convertirEnCadena(origen), convertirEnCadena(destino),
                           tipo,  matrizPeso[origen - 1][destino - 1]);

        lista -> alta(new Vertice<int>(origen, matrizPeso[origen-1][destino-1], ruta));
    }

    else{
        obtenerCaminoMinimo( origen,matrizCamino[origen - 1][destino - 1], matrizCamino, matrizPeso, lista, tipo);
        obtenerCaminoMinimo( matrizCamino[origen - 1][destino - 1], destino, matrizCamino, matrizPeso, lista, tipo);
    }

}

Lista<Vertice<int> *> *Grafo::obtenerCaminoMinimo(int origen, int destino, string tipo) {

    int **matrizCamino= tipoCamino(tipo);
    int **matrizPeso = tipoPeso(tipo);

    Lista<Vertice<int> *> *lista = new Lista<Vertice<int> *>();

    obtenerCaminoMinimo( origen,destino, matrizCamino, matrizPeso, lista, tipo);

    string ruta = obtenerRuta(convertirEnCadena(origen), convertirEnCadena(destino), tipo,
                              matrizPeso[origen - 1][destino - 1]);

    lista -> alta(new Vertice<int>(destino, matrizPeso[origen - 1][destino - 1], ruta));

    return lista;
}

string Grafo::convertirEnCadena(int valor)
{
    return listaCiudades -> buscarNodo(valor) -> obtenerDato() -> obtenerValor();
}

int **Grafo::tipoCamino(string tipo)
{
    if (tipo == TIPO_DISTANCIA){
        return matrizCaminoDistancia;
    }
    else if (tipo == TIPO_VELOCIDAD){
        return matrizCaminoVelocidad;
    }
    else {
        return matrizCaminoPeaje;
    }
}

int **Grafo::tipoPeso(string tipo)
{
    if (tipo == TIPO_DISTANCIA){
        return matrizDistancia;
    }
    else if (tipo == TIPO_VELOCIDAD){
        return matrizVelocidad;
    }
    else {
        return matrizPeaje;
    }
}

void Grafo::imprimirCiudades()
{
    listaCiudades -> mostrarLista();
}

void Grafo::mostrarCamino(Lista<Vertice<int>*> *lista)
{
    int numeroCiudad, peso;
    string ruta;
    cout << "De ";
    for (int i = 0; i < lista -> obtenerCantidad() - 1; i ++){
        numeroCiudad= lista->buscarNodo(i + 1) -> obtenerDato() -> obtenerValor();
        peso = lista -> buscarNodo(i + 1) -> obtenerDato() -> obtenerPeso();
        ruta = lista -> buscarNodo(i + 1) -> obtenerDato() -> obtenerRuta();

        cout<<listaCiudades -> buscarNodo(numeroCiudad) -> obtenerDato() -> obtenerValor();
        if(peso < INFINITO && peso != 0)
            cout << ", con un peso de " << peso << ", por la ruta " << ruta;

        cout <<" a ";

    }
    numeroCiudad = lista -> buscarNodo(lista -> obtenerCantidad()) -> obtenerDato() -> obtenerValor();
    cout << listaCiudades -> buscarNodo(numeroCiudad) -> obtenerDato() -> obtenerValor();
    if(peso == INFINITO)
        cout << " no existen caminos posibles." << endl;
    else if(peso == 0)
        cout << " son el mismo origen y destino" << endl;
}

string Grafo::obtenerRuta(string origen, string destino, string tipo, int valor)
{
    string ruta = "";

    if(listaRutas -> buscarElemento(origen, destino, tipo, valor) != nullptr)
        ruta = listaRutas -> buscarElemento(origen, destino, tipo, valor) -> obtenerDato() -> obtenerRuta();

    return ruta;
}


int Grafo::obtenerCantidad() {
    return cantidad;
}

Grafo::~Grafo(){
    for (int i = 0; i < cantidad;i ++){
        delete [] matrizDistancia[i];
        delete [] matrizCaminoDistancia[i];

        delete [] matrizPeaje[i];
        delete [] matrizCaminoPeaje[i];

        delete [] matrizVelocidad[i];
        delete [] matrizCaminoVelocidad[i];
    }

    delete [] matrizDistancia;
    delete [] matrizCaminoDistancia;

    delete [] matrizPeaje;
    delete [] matrizCaminoPeaje;

    delete [] matrizVelocidad;
    delete [] matrizCaminoVelocidad;

    if (raiz!= nullptr) {
        delete raiz;
    }

    delete listaRutas;
    delete listaCiudades;

}