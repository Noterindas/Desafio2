#include <iostream>
#include <alojamientos.h>
#include <anfitriones.h>
#include <huespedes.h>
#include <reservaciones.h>
#include <string>
using namespace std;

int main()
{
    Alojamientos lugar(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion, string codigoidentificador, string amenidades);
    cout << "******************** Lugar ********************" << endl;\
    string nombre, tipo, departamento, municipio, direccion, anfitrion, codigoidentificador, amenidades, precio;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Tipo: ";
    cin >> tipo;
    cout << "Departamento: ";
    cin >> departamento;
    cout << "Municipio: ";
    cin >> municipio;
    cout << "Direccion: ";
    cin >> direccion;
    cout << "Anfitrion: ";
    cin >> anfitrion;
    cout << "Codigo identificador: ";
    cin >> codigoidentificador;
    cout << "Amenidades: ";
    cin >> amenidades;
    cout << "Precio: ";
    cin >> precio;

    cout << endl;

    return 0;
}
