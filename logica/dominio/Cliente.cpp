#include "Cliente.h"

using namespace std;

ClienteRegistrado :: ClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo) {
    this-> rut = rut;
    this-> nombreCompleto = nombreCompleto;
    this-> direccion = direccion;
    this-> correo = correo;
}
    
int ClienteRegistrado::getRut() {
    return rut;
}

string ClienteRegistrado::getNombreCompleto() {
    return nombreCompleto;
}

string ClienteRegistrado::getDireccion() {
    return direccion;
}

string ClienteRegistrado::getCorreo() {
    return correo;
}

void ClienteRegistrado::setNombreCompleto(string nombreCompleto) {
    this-> nombreCompleto = nombreCompleto;
}

void ClienteRegistrado::setDireccion(string direccion) {
    this-> direccion = direccion;
}
void ClienteRegistrado::setCorreo(string correo) {
    this-> correo = correo;
}
