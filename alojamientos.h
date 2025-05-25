#ifndef ALOJAMIENTOS_H
#define ALOJAMIENTOS_H
#include <string>
using namespace std;


class Alojamientos
{
    string nombre;
    string codigoidentificador;
    string tipo;
    string anfitrion;
    string departamento;
    string municipio;
    string direccion;
    int precio;
    string amenidades;



public:
    Alojamientos();
    Alojamientos(string nombre);
    Alojamientos(string nombre, string tipo);
    Alojamientos(string nombre, string tipo, string departamento);
    Alojamientos(string nombre, string tipo, string departamento, string municipio);
    Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion);
    Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio);
    Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion);
    Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion, string codigoidentificador);
    Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion, string codigoidentificador, string amenidades);
    string mostrarinformacion();

};

#endif // ALOJAMIENTOS_H
