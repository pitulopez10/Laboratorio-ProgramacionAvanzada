//
// Created by facuw on 19/6/2026.
//
//
// Created by facuw on 19/6/2026.
//

#include "Empleado.h"
#include <iostream>
using namespace std;


Empleado::Empleado(string nombreCompleto, string direccion, string correo, string password) {
    this->nombreCompleto = nombreCompleto;
    this->direccion = direccion;
    this->correo = correo;
    this->password = password;
}

Empleado::~Empleado() {

}

//GETTERS
string Empleado::getNombreCompleto(){
    return this->nombreCompleto;
}
string Empleado::getDireccion(){
    return this->direccion;
}
string Empleado::getCorreo() {
    return this->correo;
}
string Empleado::getPassword() {
    return password;
}

//SETTERS
void Empleado::setNombreCompleto(string nombreCompleto) {
    this->nombreCompleto = nombreCompleto;
}
void Empleado::setDireccion(string direccion) {
    this->direccion = direccion;
}
void Empleado::setCorreo(string correo) {
    this->correo = correo;
}
void Empleado::setPassword(string password) {
    this->password = password;
}

//METODOS

