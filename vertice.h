#ifndef TP_3_ALGORITMOS_2_VERTICE_H
#define TP_3_ALGORITMOS_2_VERTICE_H

template <typename T1>
class Vertice{
private:
    T1 valor;
    int peso;
    string ruta;


public:
    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Constructor de la clase Vertice.
     *      Asigna al atributo valor el pasado por parametro.
     */
    Vertice(T1 valor);

    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Constructor de vertice que asigna el atributo valor, ruta y peso.
     */
    Vertice(T1 valor, int peso, string ruta);


    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Retorna el valor del atributo valor.
     */
    T1 obtenerValor();

    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Retorna el valor del atributo peso.
     */
    int obtenerPeso();

    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Retorna el valor del atributo ruta.
     */
    string obtenerRuta();

    /*
     *  PRE: -
     *  POST: -
     *  FUNCIONAMIENTO:
     *      Destructor por default de vertice.
     */
    ~Vertice() = default;
};

template <typename T1>
Vertice<T1>::Vertice(T1 valor){
    this -> valor = valor;
}

template <typename T1>
Vertice<T1>::Vertice(T1 valor, int peso, string ruta)
{
    this -> valor = valor;
    this -> peso = peso;
    this -> ruta = ruta;
}

template <typename T1>
T1 Vertice<T1>::obtenerValor()
{
    return valor;
};

template <typename T1>
int Vertice<T1>::obtenerPeso()
{
    return peso;
};

template <typename T1>
string Vertice<T1>::obtenerRuta()
{
    return ruta;
};


#endif //TP_3_ALGORITMOS_2_VERTICE_H