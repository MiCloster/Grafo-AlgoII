//
// Created by milagros on 9/3/21.
//

#include "ciudad.h"

Ciudad::Ciudad(string nombre){
    this -> nombreCiudad = nombre;
    lugaresTuristicos = new Lista<Vertice<string> *>();
}

string Ciudad::obtenerNombre() {
    return nombreCiudad;
}

void Ciudad::agregarLugares(string nombre) {
    lugaresTuristicos -> alta(new Vertice<string>(nombre));
}

void Ciudad::mostrarLugares() {
    cout << "Lista de lugares para visitar de " << nombreCiudad<< ": " << endl;
    lugaresTuristicos -> mostrarLista();
}

Ciudad::~Ciudad() {
    delete lugaresTuristicos;
}