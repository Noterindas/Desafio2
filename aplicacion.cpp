#include "Aplicacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

Aplicacion::Aplicacion() {
    tipoUsuario = "";
    nombreUsuario = "";
    documentoUsuario = "";
}

bool Aplicacion::iniciarSesion() {
    ifstream archivo("usuarios.txt");
    string documentoArchivo, claveArchivo, rolArchivo, nombreArchivo, antiguedadArchivo, puntuacionArchivo;
    string documentoIngresado, claveIngresada;

    if (!archivo) {
        cout << "Error al abrir el archivo de usuarios.\n";
        return false;
    }

    cout << "Iniciar sesion " <<endl;

    cout <<"\nIngrese su usuario: ";
    cin >> documentoIngresado;
    cout <<"Ingrese su clave: ";
    cin >> claveIngresada;

    while (getline(archivo, documentoArchivo, ',') &&
           getline(archivo, claveArchivo, ',') &&
           getline(archivo, rolArchivo, ',') &&
           getline(archivo, nombreArchivo, ',') &&
           getline(archivo, antiguedadArchivo, ',') &&
           getline(archivo, puntuacionArchivo)) {

        if (documentoIngresado == documentoArchivo && claveIngresada == claveArchivo) {
            tipoUsuario = rolArchivo;
            nombreUsuario = nombreArchivo;
            documentoUsuario = documentoArchivo;
            archivo.close();
            cout << "Bienvenido, " << nombreUsuario << ". Rol: " << tipoUsuario << ".\n";
            return true;
        }
    }

    archivo.close();
    cout << "Credenciales incorrectas.\n";
    return false;
}

void Aplicacion::verAlojamientos() {
    ifstream archivo("alojamientos.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo de alojamientos.\n";
        return;
    }

    cout << "\n===== Lista de alojamientos disponibles =====\n";

    string nombre, codigo, anfitrion, departamento, municipio, tipo, direccion, precio, amenidades;
    while (getline(archivo, nombre, ',') &&
           getline(archivo, codigo, ',') &&
           getline(archivo, anfitrion, ',') &&
           getline(archivo, departamento, ',') &&
           getline(archivo, municipio, ',') &&
           getline(archivo, tipo, ',') &&
           getline(archivo, direccion, ',') &&
           getline(archivo, precio, ',') &&
           getline(archivo, amenidades)) {

        cout << "Nombre: " << nombre
             << "\nCodigo: " << codigo
             << "\nAnfitrion: " << anfitrion
             << "\nDepartamento: " << departamento
             << "\nMunicipio: " << municipio
             << "\nTipo: " << tipo
             << "\nDireccion: " << direccion
             << "\nPrecio por noche: $" << precio
             << "\nAmenidades: " << amenidades
             << "\n--------------------------\n";
    }

    archivo.close();
}

void Aplicacion::reservarAlojamiento() {
    ifstream archivoAlojamientos("alojamientos.txt");
    if (!archivoAlojamientos) {
        cout << "Error al abrir el archivo de alojamientos.\n";
        return;
    }

    string municipioBuscado, fechaEntrada;
    int noches, precioMaximo;

    cin.ignore();
    cout << "Ingrese el municipio donde desea alojarse: ";
    getline(cin, municipioBuscado);
    cout << "Ingrese la fecha de entrada (DD-MM-YYYY): ";
    cin >> fechaEntrada;
    cout << "Ingrese la cantidad de noches: ";
    cin >> noches;

    cout << "Desea fijar un costo maximo por noche? (Ingrese 0 si no aplica): ";
    cin >> precioMaximo;

    cout << "\n===== Alojamientos disponibles =====\n";

    string nombre, codigo, anfitrion, departamento, municipio, tipo, direccion, precio, amenidades;
    bool hayDisponibles = false;

    while (getline(archivoAlojamientos, nombre, ',') &&
           getline(archivoAlojamientos, codigo, ',') &&
           getline(archivoAlojamientos, anfitrion, ',') &&
           getline(archivoAlojamientos, departamento, ',') &&
           getline(archivoAlojamientos, municipio, ',') &&
           getline(archivoAlojamientos, tipo, ',') &&
           getline(archivoAlojamientos, direccion, ',') &&
           getline(archivoAlojamientos, precio, ',') &&
           getline(archivoAlojamientos, amenidades)) {

        int precioInt = stoi(precio);
        if (municipio == municipioBuscado && (precioMaximo == 0 || precioInt <= precioMaximo)) {
            hayDisponibles = true;
            cout << "Codigo: " << codigo << " | Nombre: " << nombre << " | Precio: $" << precio << "\n";
        }
    }

    archivoAlojamientos.close();

    if (!hayDisponibles) {
        cout << "No hay alojamientos disponibles con los criterios ingresados.\n";
        return;
    }

    string codigoSeleccionado;
    bool codigoValido = false;

    do {
        cout << "\nIngrese el codigo del alojamiento a reservar: ";
        cin >> codigoSeleccionado;

        ifstream busqueda("alojamientos.txt");
        while (getline(busqueda, nombre, ',') &&
               getline(busqueda, codigo, ',') &&
               getline(busqueda, anfitrion, ',') &&
               getline(busqueda, departamento, ',') &&
               getline(busqueda, municipio, ',') &&
               getline(busqueda, tipo, ',') &&
               getline(busqueda, direccion, ',') &&
               getline(busqueda, precio, ',') &&
               getline(busqueda, amenidades)) {
            if (codigoSeleccionado == codigo) {
                codigoValido = true;
                break;
            }
        }
        busqueda.close();

        if (!codigoValido) {
            cout << "Codigo invalido. Ingrese un codigo de alojamiento valido.\n";
        }
    } while (!codigoValido);

    ifstream Reservas("reservaciones.txt");
    if (!Reservas) {
        cout << "Error al abrir el archivo de reservaciones.\n";
        return;
    }

    bool fechaDisponible = true;
    string codigoReserva, codigoAlojamiento, usuario, fechaEntradaGuardada, nochesGuardadas, metodoPagoGuardado, fechaPagoGuardada, montoGuardado, anotacionesGuardada;

    int diaInicioNuevo = stoi(fechaEntrada.substr(0, 2));
    int mesInicioNuevo = stoi(fechaEntrada.substr(3, 2));
    int anioInicioNuevo = stoi(fechaEntrada.substr(6, 4));
    int diaFinNuevo = diaInicioNuevo + noches;

    while (getline(Reservas, codigoReserva, ',') &&
           getline(Reservas, codigoAlojamiento, ',') &&
           getline(Reservas, usuario, ',') &&
           getline(Reservas, fechaEntradaGuardada, ',') &&
           getline(Reservas, nochesGuardadas, ',') &&
           getline(Reservas, metodoPagoGuardado, ',') &&
           getline(Reservas, fechaPagoGuardada, ',') &&
           getline(Reservas, montoGuardado, ',') &&
           getline(Reservas, anotacionesGuardada)) {

        if (codigoSeleccionado == codigoAlojamiento) {
            int diaInicioExistente = stoi(fechaEntradaGuardada.substr(0, 2));
            int mesInicioExistente = stoi(fechaEntradaGuardada.substr(3, 2));
            int anioInicioExistente = stoi(fechaEntradaGuardada.substr(6, 4));
            int diaFinExistente = diaInicioExistente + stoi(nochesGuardadas);

            if (diaFinNuevo > diaInicioExistente && diaInicioNuevo < diaFinExistente &&
                mesInicioNuevo == mesInicioExistente && anioInicioNuevo == anioInicioExistente) {
                fechaDisponible = false;
                break;
            }
        }
    }

    Reservas.close();

    if (!fechaDisponible) {
        cout << "Error: El alojamiento ya esta reservado en esas fechas.\n";
        return;
    }

    ifstream Reservas2("reservaciones.txt");
    if (!Reservas2) {
        cout << "Error al abrir el archivo de reservaciones.\n";
        return;
    }

    bool usuarioSinReservas = true;

    while (getline(Reservas2, codigoReserva, ',') &&
           getline(Reservas2, codigoAlojamiento, ',') &&
           getline(Reservas2, usuario, ',') &&
           getline(Reservas2, fechaEntradaGuardada, ',') &&
           getline(Reservas2, nochesGuardadas, ',') &&
           getline(Reservas2, metodoPagoGuardado, ',') &&
           getline(Reservas2, fechaPagoGuardada, ',') &&
           getline(Reservas2, montoGuardado, ',') &&
           getline(Reservas2, anotacionesGuardada)) {

        int diaInicioExistente = stoi(fechaEntradaGuardada.substr(0, 2));
        int mesInicioExistente = stoi(fechaEntradaGuardada.substr(3, 2));
        int anioInicioExistente = stoi(fechaEntradaGuardada.substr(6, 4));
        int diaFinExistente = diaInicioExistente + stoi(nochesGuardadas);

        if (usuario == documentoUsuario) {
            if (diaFinNuevo > diaInicioExistente && diaInicioNuevo < diaFinExistente &&
                mesInicioNuevo == mesInicioExistente && anioInicioNuevo == anioInicioExistente) {
                usuarioSinReservas = false;
            }
        }
    }
    Reservas2.close();

    if (!usuarioSinReservas) {
        cout << "Error: Usted ya tiene una reservacion activa en esas fechas.\n";
        return;
    }

    string metodoPago, fechaPago, monto, anotaciones;

    cout << "Seleccione metodo de pago (PSE / Tarjeta de Credito): ";
    cin >> metodoPago;
    cout << "Ingrese fecha del pago (DD-MM-YYYY): ";
    cin >> fechaPago;
    cout << "Ingrese monto del pago: ";
    cin >> monto;

    cin.ignore(); // Evitar problemas en `getline()`
    cout << "Ingrese anotaciones para el anfitrion: ";
    getline(cin, anotaciones);

    string nuevoCodigoReserva = "R" + to_string(time(0) % 10000);

    ofstream agregarReservas("reservaciones.txt", ios::app);
    if (!agregarReservas) {
        cout << "Error al abrir el archivo de reservaciones.\n";
        return;
    }

    agregarReservas << nuevoCodigoReserva << "," << codigoSeleccionado << "," << documentoUsuario << ","
                    << fechaEntrada << "," << noches << "," << metodoPago << "," << fechaPago << ","
                    << monto << "," << anotaciones << "\n";

    agregarReservas.close();

    cout << "Reservacion exitosa\nCodigo de reservacion: " << nuevoCodigoReserva << "\n";
}

void Aplicacion::anularReservacion() {
    ifstream archivoReservas("reservaciones.txt");
    ofstream archivoTemp("temp.txt"); // Archivo temporal

    if (!archivoReservas || !archivoTemp) {
        cout << "Error al abrir los archivos.\n";
        return;
    }

    string codigoReserva, codigoAlojamiento, usuario, fechaEntrada, noches, metodoPago, fechaPago, monto, anotaciones;
    string codigoIngresado;
    bool reservacionEncontrada = false;

    cout << "Ingrese el codigo de la reservacion a anular: ";
    cin >> codigoIngresado;

    while (getline(archivoReservas, codigoReserva, ',') &&
           getline(archivoReservas, codigoAlojamiento, ',') &&
           getline(archivoReservas, usuario, ',') &&
           getline(archivoReservas, fechaEntrada, ',') &&
           getline(archivoReservas, noches, ',') &&
           getline(archivoReservas, metodoPago, ',') &&
           getline(archivoReservas, fechaPago, ',') &&
           getline(archivoReservas, monto, ',') &&
           getline(archivoReservas, anotaciones)) {

        if (codigoReserva == codigoIngresado && (usuario == documentoUsuario || tipoUsuario == "Anfitrion")) {
            reservacionEncontrada = true;
            cout << "Reservacion " << codigoReserva << " anulada con exito.\n";
        } else {
            archivoTemp << codigoReserva << "," << codigoAlojamiento << "," << usuario << ","
                        << fechaEntrada << "," << noches << "," << metodoPago << "," << fechaPago << ","
                        << monto << "," << anotaciones << "\n";
        }
    }

    archivoReservas.close();
    archivoTemp.close();

    if (!reservacionEncontrada) {
        cout << "No se encontro ninguna reservacion con el codigo ingresado o no tiene permiso para anularla.\n";
        remove("temp.txt");
    } else {
        remove("reservaciones.txt");
        rename("temp.txt", "reservaciones.txt");
    }
}

void Aplicacion::consultarReservaciones() {
    ifstream archivoReservas("reservaciones.txt");

    if (!archivoReservas) {
        cout << "Error al abrir el archivo de reservaciones.\n";
        return;
    }

    string fechaInicio, fechaFin;
    cout << "Ingrese la fecha de inicio (DD-MM-YYYY): ";
    cin >> fechaInicio;
    cout << "Ingrese la fecha de fin (DD-MM-YYYY): ";
    cin >> fechaFin;

    cout << "\n===== Reservaciones Activas =====\n";

    string codigoReserva, codigoAlojamiento, usuario, fechaEntrada, noches, metodoPago, fechaPago, monto, anotaciones;
    bool encontrado = false;

    int diaInicio = stoi(fechaInicio.substr(0, 2));
    int mesInicio = stoi(fechaInicio.substr(3, 2));
    int anioInicio = stoi(fechaInicio.substr(6, 4));

    int diaFin = stoi(fechaFin.substr(0, 2));
    int mesFin = stoi(fechaFin.substr(3, 2));
    int anioFin = stoi(fechaFin.substr(6, 4));

    while (getline(archivoReservas, codigoReserva, ',') &&
           getline(archivoReservas, codigoAlojamiento, ',') &&
           getline(archivoReservas, usuario, ',') &&
           getline(archivoReservas, fechaEntrada, ',') &&
           getline(archivoReservas, noches, ',') &&
           getline(archivoReservas, metodoPago, ',') &&
           getline(archivoReservas, fechaPago, ',') &&
           getline(archivoReservas, monto, ',') &&
           getline(archivoReservas, anotaciones)) {

        int diaInicioExistente = stoi(fechaEntrada.substr(0, 2));
        int mesInicioExistente = stoi(fechaEntrada.substr(3, 2));
        int anioInicioExistente = stoi(fechaEntrada.substr(6, 4));

        if ((anioInicioExistente > anioInicio || (anioInicioExistente == anioInicio && mesInicioExistente > mesInicio) ||
             (anioInicioExistente == anioInicio && mesInicioExistente == mesInicio && diaInicioExistente >= diaInicio)) &&
            (anioInicioExistente < anioFin || (anioInicioExistente == anioFin && mesInicioExistente < mesFin) ||
             (anioInicioExistente == anioFin && mesInicioExistente == mesFin && diaInicioExistente <= diaFin))) {

            cout << "Codigo de Reservacion: " << codigoReserva
                 << "\nCodigo de Alojamiento: " << codigoAlojamiento
                 << "\nFecha de Entrada: " << fechaEntrada
                 << "\nDuracion: " << noches << " noches"
                 << "\nMetodo de Pago: " << metodoPago
                 << "\nFecha del Pago: " << fechaPago
                 << "\nMonto: $" << monto
                 << "\nAnotaciones: " << anotaciones << "\n--------------------------\n";
            encontrado = true;
        }
    }

    archivoReservas.close();

    if (!encontrado) {
        cout << "No hay reservaciones dentro de ese rango de fechas.\n";
    }
}

void Aplicacion::actualizarHistorico() {
    ifstream archivoReservas("reservaciones.txt");
    ofstream archivoHistorico("historico.txt", ios::app);
    ofstream archivoNuevo("nuevo_reservaciones.txt");

    if (!archivoReservas || !archivoHistorico || !archivoNuevo) {
        cout << "Error al abrir archivos.\n";
        return;
    }

    string fechaCorte;
    cout << "Ingrese la fecha de corte (DD-MM-YYYY): ";
    cin >> fechaCorte;

    int diaCorte = stoi(fechaCorte.substr(0, 2));
    int mesCorte = stoi(fechaCorte.substr(3, 2));
    int anioCorte = stoi(fechaCorte.substr(6, 4));

    string codigoReserva, codigoAlojamiento, usuario, fechaEntrada, noches, metodoPago, fechaPago, monto, anotaciones;
    while (getline(archivoReservas, codigoReserva, ',') &&
           getline(archivoReservas, codigoAlojamiento, ',') &&
           getline(archivoReservas, usuario, ',') &&
           getline(archivoReservas, fechaEntrada, ',') &&
           getline(archivoReservas, noches, ',') &&
           getline(archivoReservas, metodoPago, ',') &&
           getline(archivoReservas, fechaPago, ',') &&
           getline(archivoReservas, monto, ',') &&
           getline(archivoReservas, anotaciones)) {

        int diaEntrada = stoi(fechaEntrada.substr(0, 2));
        int mesEntrada = stoi(fechaEntrada.substr(3, 2));
        int anioEntrada = stoi(fechaEntrada.substr(6, 4));

        if (anioEntrada < anioCorte || (anioEntrada == anioCorte && mesEntrada < mesCorte) ||
            (anioEntrada == anioCorte && mesEntrada == mesCorte && diaEntrada < diaCorte)) {
            archivoHistorico << codigoReserva << "," << codigoAlojamiento << "," << usuario << ","
                             << fechaEntrada << "," << noches << "," << metodoPago << ","
                             << fechaPago << "," << monto << "," << anotaciones << "\n";
        } else {
            archivoNuevo << codigoReserva << "," << codigoAlojamiento << "," << usuario << ","
                         << fechaEntrada << "," << noches << "," << metodoPago << ","
                         << fechaPago << "," << monto << "," << anotaciones << "\n";
        }
    }

    archivoReservas.close();
    archivoHistorico.close();
    archivoNuevo.close();

    remove("reservaciones.txt");
    rename("nuevo_reservaciones.txt", "reservaciones.txt");

    cout << "Historico actualizado correctamente.\n";
}

void Aplicacion::mostrarMenu() {
    if (!iniciarSesion()) {
        cout << "No se pudo iniciar sesión.\n";
        return;
    }

    int opcion;
    do {
        cout << "\n===== UdeAStay =====\n";

        if (tipoUsuario == "Huesped") {
            cout << "1. Ver alojamientos\n";
            cout << "2. Reservar alojamiento\n";
            cout << "3. Anular reservacion\n";
            cout << "0. Salir\n";
        } else if (tipoUsuario == "Anfitrion") {
            cout << "1. Anular reservacion\n";
            cout << "2. Consultar reservaciones\n";
            cout << "3. Actualizar historico\n";
            cout << "0. Salir\n";
        }

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            if (tipoUsuario == "Huesped") {
                cout << "Mostrando alojamientos...\n";
                verAlojamientos();
            } else {
                cout << "Anulando reservación...\n";
                anularReservacion();
            }
            break;
        case 2:
            if (tipoUsuario == "Huesped") {
                cout << "Reservar alojamiento...\n";
                reservarAlojamiento();
            } else {
                cout << "Consultando reservaciones...\n";
                consultarReservaciones();
            }
            break;
        case 3:
            if (tipoUsuario == "Huesped") {
                cout << "Anulando reservación...\n";
                anularReservacion();
            } else if (tipoUsuario == "Anfitrion") {
                cout << "Actualizando historico...\n";
                actualizarHistorico();
            } else {
                cout << "Opción no valida.\n";
            }
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no valida.\n";
        }

    } while (opcion != 0);
}

