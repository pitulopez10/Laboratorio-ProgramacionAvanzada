//
// Created by facuw on 3/6/2026.
//

#include "LineaDeCompra.h"
#include "Producto.h"
//CONSTRUCTORES
LineaDeCompra :: LineaDeCompra(float precioCompra, Producto* producto, int tiempoEntrega) {
    this-> precioCompra = precioCompra;
    this->producto = producto;
    this->tiempoEntrega = tiempoEntrega;
}

//GETTERS
float LineaDeCompra :: getPrecioCompra() {
    return precioCompra;
}

Producto* LineaDeCompra::getProducto() {
    return producto;
}

int LineaDeCompra :: getTiempoEntrega() {
    return tiempoEntrega;
}

//SETTERS
void LineaDeCompra :: setPrecioCompra(float precioCompra) {
    this-> precioCompra = precioCompra;
}

void LineaDeCompra :: setProducto(Producto* producto) {
    this-> producto = producto;
}

void LineaDeCompra :: setTiempoEntrega(int tiempoEntrega) {
    this-> tiempoEntrega = tiempoEntrega;
}