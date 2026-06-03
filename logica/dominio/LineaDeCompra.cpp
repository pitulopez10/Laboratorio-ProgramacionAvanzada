//
// Created by facuw on 3/6/2026.
//

#include "LineaDeCompra.h"
//CONSTRUCTORES
LineaDeCompra :: LineaDeCompra(float precioCompra) {
    this-> precioCompra = precioCompra;
}

//GETTERS
float LineaDeCompra :: getPrecioCompra() {
    return precioCompra;
}

//SETTERS
void LineaDeCompra :: setPrecioCompra(float precioCompra) {
    this-> precioCompra = precioCompra;
}
