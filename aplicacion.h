#ifndef APLICACION_H
#define APLICACION_H
#include <string>

using namespace std;

class Aplicacion {
private:
    string tipoUsuario;
    string nombreUsuario;
    string documentoUsuario;

public:
    Aplicacion();
    bool iniciarSesion();
    void mostrarMenu();
    void verAlojamientos();
    void reservarAlojamiento();
    void anularReservacion();
    void consultarReservaciones();
    void actualizarHistorico();
};

#endif
