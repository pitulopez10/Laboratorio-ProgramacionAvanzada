//
// Created by facuw on 3/6/2026.
//

#include "Categoria.h"

//CONSTRUCTORES

Categoria::Categoria() {

}
Categoria::Categoria(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

//GETTERS

string Categoria::getNombre() {
    return this->nombre;
}
string Categoria::getDescripcion() {
    return this->descripcion;
}

//SETTERS

void Categoria::setNombre(string nombre) {
    this->nombre = nombre;
}
void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

//METODOS