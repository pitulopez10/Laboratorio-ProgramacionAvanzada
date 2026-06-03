//
// Created by facuw on 3/6/2026.
//

#include "Producto.h"

//CONSTRUCTORES

Producto::Producto() {

}
Producto::Producto(string nombre, string codigo, string descripcion, float precioUnitario, float puntajePromedio, int cantVendidas, int estaEnStock, Categoria* categoria) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precioUnitario = precioUnitario;
    this->puntajePromedio = puntajePromedio;
    this->cantVendidas = cantVendidas;
    this->estaEnStock = estaEnStock;
    this->categoria = categoria;
}

//GETTERS

string Producto::getNombre() {
    return this->nombre;
}
string Producto::getCodigo() {
    return this->codigo;
}
string Producto::getDescripcion() {
    return this->descripcion;
}
float Producto::getPrecioUnitario() {
    return this->precioUnitario;
}
float Producto::getPuntajePromedio() {
    return this->puntajePromedio;
}
int Producto::getCantVendidas() {
    return this->cantVendidas;
}
int Producto::getEstaEnStock() {
    return this->estaEnStock;
}
Categoria* Producto::getCategoria() {
    return this->categoria;
}

//SETTERS

void Producto::setNombre(string nombre) {
    this->nombre = nombre;
}
void Producto::setCodigo(string codigo) {
    this->codigo = codigo;
}
void Producto::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}
void Producto::setPrecioUnitario(float precioUnitario) {
    this->precioUnitario = precioUnitario;
}
void Producto::setPuntajePromedio(float puntajePromedio) {
    this->puntajePromedio = puntajePromedio;
}
void Producto::setCantVendidas(int cantVendidas) {
    this->cantVendidas = cantVendidas;
}
void Producto::setEstaEnStock(int estaEnStock) {
    this->estaEnStock = estaEnStock;
}

void Producto::setCategoria(Categoria *categoria) {
    this->categoria = categoria;
}

//METODOS
