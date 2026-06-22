//
// Created by facuw on 19/6/2026.
//

#include "Admin.h"
#include <iostream>
using namespace std;


Admin::Admin(string nombreCompleto, string direccion, string correo, string password) {
    this->nombreCompleto = nombreCompleto;
    this->direccion = direccion;
    this->correo = correo;
    this->password = password;
}

Admin::~Admin() {

}

//GETTERS
string Admin::getNombreCompleto(){
    return this->nombreCompleto;
}
string Admin::getDireccion(){
    return this->direccion;
}
string Admin::getCorreo() {
    return this->correo;
}
string Admin::getPassword() {
    return this->password;
}

//SETTERS
void Admin::setNombreCompleto(string nombreCompleto) {
    this->nombreCompleto = nombreCompleto;
}
void Admin::setDireccion(string direccion) {
    this->direccion = direccion;
}
void Admin::setCorreo(string correo) {
    this->correo = correo;
}
void Admin::setPassword(string password) {
    this->password = password;
}
//METODOS

