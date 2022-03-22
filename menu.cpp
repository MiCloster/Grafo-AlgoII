//
// Created by milagros on 9/3/21.
//

#include "menu.h"


enum opciones1 {
    PRIMER_MENU = 0,
    BUSCAR_CIUDAD = 1,
    AGREGAR_CIUDAD = 2,
    ELIMINAR_CIUDAD = 3,
    ORDEN_CIUDAD = 4,
    ANCHO_CIUDAD = 5,
    SALIR = 6
};

enum opciones2 {
    SEGUNDO_MENU = -1,
    DISTANCIA_MINIMA = 1,
    TIEMPO_MINIMO = 2,
    PEAJE_MINIMO = 3
};

Menu::Menu(){
    diccCiudades = new Diccionario<int, Ciudad *>();
    ciudades = new Lista<Vertice<string> *>();
    rutasMinimas = new Grafo();
}

void Menu::cargarDatos() {
    Ciudad *nuevaCiudad;
    ifstream archivo(ARCHIVO_CIUDADES);
    string palabra;
    string ciudad;
    if (! archivo){
        cout << "ERROR AL ABRIR EL ARCHIVO"<<endl;
    }
    else {
        while (getline(archivo, ciudad)) {
            nuevaCiudad = new Ciudad(ciudad);
            ciudades -> alta(new Vertice<string>(ciudad));
            while(getline(archivo, palabra) && palabra != ""){
                nuevaCiudad -> agregarLugares(palabra);
            }
            diccCiudades -> alta(ciudades -> posicionDato(ciudad), nuevaCiudad);
        }
    }
    archivo.close();
}

void Menu::mostrarMenu(int numeroMenu) {
    if(numeroMenu == PRIMER_MENU) {
        cout << "\nMENÚ DE CIUDADES Y SUS LUGARES TURISTICOS:";
        cout << "\n1.Buscar ciudad.";
        cout << "\n2.Agregar nueva ciudad.";
        cout << "\n3.Eliminar ciudad.";
        cout << "\n4.Mostrar ciudades ordenadas.";
        cout << "\n5.Mostrar ciudades por niveles.";
        cout << "\n6.Salir.";
    }
    else{
        cout << "\nMENÚ DE CAMINOS MINIMOS:";
        cout << "\n1.Distancia minima" << endl;
        cout << "\n2.Tiempo minimo" << endl;
        cout << "\n3.Peaje minimo" << endl;
    }

    cout << "\nOPCIÓN: ";
}

string Menu::chequearSeguir() {
    string seguir;
    cout << "\n¿QUIERE SEGUIR? S/N: ";
    cin >> seguir;
    while(seguir != "S" && seguir != "N"){
        cout << "¿QUIERE SEGUIR? S/N: ";
        cin >> seguir;
    }
    cin.ignore();
    return seguir;
}

int Menu::pedirOpcion(int minimo, int maximo, int numeroMenu) {
    int opc;
    cin >> opc;
    while(opc > maximo || opc < minimo){
        cout << "INGRESO OPCION FUERA DE RANGO." << endl;
        mostrarMenu(numeroMenu);
        cin >> opc;
    }
    cin.ignore();
    return opc;
}


void Menu::altaCiudad()
{
    int posicion = diccCiudades -> obtenerCantidad() + 1;
    string nombre, lugar;
    string seguir = "S";
    int i = 0;

    cout << "NOMBRE DE CIUDAD: ";
    getline(cin, nombre);

    Ciudad *nueva = new Ciudad(nombre);
    ciudades -> alta(new Vertice<string>(nombre));

    while(seguir == "S"){
        cout << "NOMBRE DE LUGARES TURISTICOS: ";
        getline(cin, lugar);
        nueva -> agregarLugares(lugar);
        seguir = chequearSeguir();
        i ++;
    }
    diccCiudades -> alta(posicion,nueva);
}

void Menu::bajaCiudad()
{
    int numero = pedirNombreCiudad();
    diccCiudades -> quitarNodo(numero);
}

void Menu::buscarCiudad()
{
    int claveBuscar = pedirNombreCiudad();
    diccCiudades -> imprimir(claveBuscar);
}

int Menu::pedirNombreCiudad()
{
    string nombre;
    cout << "CIUDADES: " << endl;
    diccCiudades -> recorridoInOrden();
    cout << "\nIngrese nombre de la ciudad: ";
    getline(cin, nombre);
    while (! diccCiudades -> buscar( ciudades -> posicionDato(nombre))){
        cout << "INGRESO UNA CIUDAD NO VÁLIDA. REEINGRESE: ";
        getline(cin, nombre);
    }
    return ciudades -> posicionDato(nombre);
}

void Menu::menuCiudades()
{
    bool continuar = true;
    do {
        mostrarMenu(PRIMER_MENU);
        int opcion = pedirOpcion(BUSCAR_CIUDAD, SALIR, PRIMER_MENU);

        switch (opcion) {
            case BUSCAR_CIUDAD:
                buscarCiudad();
                break;
            case AGREGAR_CIUDAD:
                altaCiudad();
                break;
            case ELIMINAR_CIUDAD:
                bajaCiudad();
                break;
            case ORDEN_CIUDAD: {
                cout << "\nRECORRIDO IN ORDEN:" << endl;
                diccCiudades->recorridoInOrden();
                break;
            }
            case ANCHO_CIUDAD: {
                cout << "\nRECORRIDO EN ANCHO:" << endl;
                diccCiudades->recorridoAncho();
                break;
            }
            case SALIR:
                continuar = false;
        }
    } while (continuar);
}

int Menu::chequearCiudades() {
    int numeroCiudad;
    int cantidad = rutasMinimas->obtenerCantidad();
    cin >> numeroCiudad;
    while (numeroCiudad > cantidad || numeroCiudad <= 0){

        cout << "\nINGRESO UNA CIUDAD NO VALIDA." << endl;
        rutasMinimas -> imprimirCiudades();
        cout << "REINGRESE: ";
        cin >> numeroCiudad;
    }
    return  numeroCiudad;
}

void Menu::mostrarCaminosMinimos(int opcion, int origen, int destino)
{
    switch (opcion) {
        case DISTANCIA_MINIMA:{
            cout << "CAMINO DE MINIMA DISTANCIA" << endl;
            Lista<Vertice<int> *> *distancia = rutasMinimas -> obtenerCaminoMinimo(origen, destino, TIPO_DISTANCIA);
            rutasMinimas -> mostrarCamino(distancia);
            delete distancia;
            break;
        }
        case TIEMPO_MINIMO:{
            cout << "\nCAMINO DE MENOR TIEMPO" << endl;
            Lista<Vertice<int> *> *tiempo = rutasMinimas -> obtenerCaminoMinimo(origen, destino, TIPO_VELOCIDAD);;
            rutasMinimas -> mostrarCamino(tiempo);
            delete tiempo;
            break;
        }
        case PEAJE_MINIMO:{
            cout << "\nCAMINO DE PEAJES BARATOS" << endl;
            Lista<Vertice<int> *> *peaje = rutasMinimas -> obtenerCaminoMinimo(origen, destino, TIPO_PEAJE);
            rutasMinimas -> mostrarCamino(peaje);
            delete peaje;
            break;
        }

    }

}

void Menu::cargarGrafo() {
    rutasMinimas->cargarGrafo();
    rutasMinimas->iniciarMatrices();
}

void Menu::menuRutas()
{
    int destino, origen;

    string seguir = "S";

    while (seguir == "S") {
        cout << "\nMENÚ DE RUTAS:" << endl;
        rutasMinimas -> imprimirCiudades();
        cout << "\nIngrese numero de ciudad origen: ";
        origen = chequearCiudades();

        rutasMinimas -> imprimirCiudades();
        cout << "\nIngrese numero de ciudad destino: ";
        destino = chequearCiudades();

        mostrarMenu(SEGUNDO_MENU);
        int opcion = pedirOpcion(DISTANCIA_MINIMA, PEAJE_MINIMO, SEGUNDO_MENU);
        mostrarCaminosMinimos(opcion,origen, destino);
        seguir = chequearSeguir();
    }
}

Menu::~Menu() {
    delete diccCiudades;
    delete rutasMinimas;
    delete ciudades;
}