//
// Created by facuw on 3/6/2026.
//

#include "Categoria.h"

#include <vector>

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

vector<Producto*> Categoria::getProducto(){
    return this->productos;
}

//SETTERS

void Categoria::setNombre(string nombre) {
    this->nombre = nombre;
}
void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}
void Categoria::setProducto(vector<Producto*> productos) {
    this->productos = productos;
}

//METODOS