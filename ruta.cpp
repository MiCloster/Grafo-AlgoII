//
// Created by milagros on 9/3/21.
//

#include "ruta.h"

Ruta::Ruta(string ruta, string origen, string destino, int distancia, int velocidad, int peaje)
{
    this -> ruta = ruta;
    this -> origen = origen;
    this -> destino = destino;
    this -> distancia= distancia;
    this -> tiempo = (distancia / velocidad);
    this -> peaje = peaje;
}

string Ruta::obtenerRuta()
{
    return ruta;
}

int Ruta::obtenerDistancia()
{
    return distancia;
}

int Ruta::obtenerTiempo()
{
    return tiempo;
}

int Ruta::obtenerPeaje()
{
    return peaje;
}

bool Ruta::chequearConexion(string origenNuevo, string destinoNuevo)
{
    if(origen == origenNuevo && destino == destinoNuevo) {
        return true;
    }
    else if(destino == origenNuevo && origen == destinoNuevo){
        return true;
    }
    return false;
}