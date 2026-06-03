//
// Created by facuw on 27/5/2026.
//

#include "LineaDeDetalle.h"
#include <iostream>
using namespace std;

//CONSTRUCTORES
LineaDeDetalle::LineaDeDetalle() {

}
LineaDeDetalle::LineaDeDetalle(int cantidad, float precioUnitario) {
    this->cantidad = cantidad;
    this->precioUnitario = precioUnitario;
}

//GETTERS
int LineaDeDetalle::getCantidad() const {
    return this->cantidad;
}
float LineaDeDetalle::getPrecioUnitario() const {
    return this->precioUnitario;
}

//SETTERS
void LineaDeDetalle::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}
void LineaDeDetalle::setPrecioUnitario(float precioUnitario) {
    this->precioUnitario = precioUnitario;
}