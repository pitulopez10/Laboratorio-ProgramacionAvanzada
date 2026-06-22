//
// Created by facuw on 3/6/2026.
//

#include "LineaDeCompra.h"
//CONSTRUCTORES
LineaDeCompra :: LineaDeCompra(float precioCompra, Producto* producto) {
    this-> precioCompra = precioCompra;
    this->producto = producto;
}

//GETTERS
float LineaDeCompra :: getPrecioCompra() {
    return precioCompra;
}

Producto* LineaDeCompra::getProducto() {
    return producto;
}

//SETTERS
void LineaDeCompra :: setPrecioCompra(float precioCompra) {
    this-> precioCompra = precioCompra;
}

void LineaDeCompra :: setProducto(Producto* producto) {
    this-> producto = producto;
}
