#include "alojamientos.h"

Alojamientos::Alojamientos()
{
}

Alojamientos::Alojamientos(string nombre)
{
    this->nombre = nombre;
}

Alojamientos::Alojamientos(string nombre, string tipo)
{
    this->nombre = nombre;
    this->tipo = tipo;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
    this->direccion = direccion;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
    this->direccion = direccion;
    this->precio = precio;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
    this->direccion = direccion;
    this->precio = precio;
    this->anfitrion = anfitrion;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion, string codigoidentificador)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
    this->direccion = direccion;
    this->precio = precio;
    this->anfitrion = anfitrion;
    this->codigoidentificador = codigoidentificador;
}

Alojamientos::Alojamientos(string nombre, string tipo, string departamento, string municipio, string direccion, int precio, string anfitrion, string codigoidentificador, string amenidades)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->departamento = departamento;
    this->municipio = municipio;
    this->direccion = direccion;
    this->precio = precio;
    this->anfitrion = anfitrion;
    this->codigoidentificador = codigoidentificador;
    this->amenidades = amenidades;
}

string Alojamientos::mostrarinformacion()
{
    return "Nombre: "+ nombre + "\nTipo: "+ tipo + "\nDepartamento: "+ departamento + "\nMunicipio: "+ municipio +
           "\nDireccion: "+ direccion + "\nAnfitrion: "+ anfitrion + "\nCodigo identificador"+ codigoidentificador + "\nAmenidades: "+ amenidades + "\nPrecio: "+ to_string(precio);
}
