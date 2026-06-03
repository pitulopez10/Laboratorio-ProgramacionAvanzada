//
// Created by facuw on 3/6/2026.
//

#include "Proveedor.h"


//CONSTRUCTORES
Proveedor::Proveedor() {

}
Proveedor::Proveedor(int rut, int tiempoEntrega, string nombre, string telContacto, string nombreContacto) {
    this->rut = rut;
    this->tiempoEntrega = tiempoEntrega;
    this->nombre = nombre;
    this->telContacto = telContacto;
    this->nombreContacto = nombreContacto;
}

//GETTERS

int Proveedor::getRut() {
    return this->rut;
}
int Proveedor::getTiempoEntrega() {
    return this->tiempoEntrega;
}
string Proveedor::getNombre(){
    return this->nombre;
}
string Proveedor::getTelContacto() {
    return this->telContacto;
}
string Proveedor::getNombreContacto() {
    return this->nombreContacto;
}

//SETTERS

void Proveedor::setRut(int rut) {
    this->rut = rut;
}
void Proveedor::setTiempoEntrega(int tiempoEntrega) {
    this->tiempoEntrega = tiempoEntrega;
}
void Proveedor::setNombre(string nombre) {
    this->nombre = nombre;
}
void Proveedor::setTelContacto(string telContacto) {
    this->telContacto = telContacto;
}
void Proveedor::setNombreContacto(string nombreContacto) {
    this->nombreContacto = nombreContacto;
}

//METODOS