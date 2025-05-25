#ifndef RESERVACIONES_H
#define RESERVACIONES_H
#include <string>
using namespace std;

class Reservaciones
{
    string fechasfuturas;
    string fechaentrada;
    int duracion;
    int codigodereservacion;
    string anotacionesensureservacion;
    int codigodealojamiento;
    int documentodelhuesped;
    string metododepago;
    int fechadepago;
    int montodepago;

public:
    Reservaciones();
};

#endif // RESERVACIONES_H
