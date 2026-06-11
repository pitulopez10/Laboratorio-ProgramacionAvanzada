#include "Cliente.h"
#include "Calificacion.h"

using namespace std;

//CONSTRUCTORES
ClienteRegistrado :: ClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo) {
    this-> rut = rut;
    this-> nombreCompleto = nombreCompleto;
    this-> direccion = direccion;
    this-> correo = correo;
}

//GETTERS
int ClienteRegistrado::getRut() const{
    return rut;
}

string ClienteRegistrado::getNombreCompleto() const{
    return nombreCompleto;
}

string ClienteRegistrado::getDireccion() const{
    return direccion;
}

string ClienteRegistrado::getCorreo() const{
    return correo;
}

vector<Calificacion*> ClienteRegistrado::getCalificaciones() const{
    return calificaciones;
}

//SETTERS
void ClienteRegistrado::setNombreCompleto(string nombreCompleto) {
    this-> nombreCompleto = nombreCompleto;
}

void ClienteRegistrado::setDireccion(string direccion) {
    this-> direccion = direccion;
}
void ClienteRegistrado::setCorreo(string correo) {
    this-> correo = correo;
}

//METODOS
void ClienteRegistrado::agregarCalificacion(Calificacion* calificacion) {
    calificaciones.push_back(calificacion);
}
