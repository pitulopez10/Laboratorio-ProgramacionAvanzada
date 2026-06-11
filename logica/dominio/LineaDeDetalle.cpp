//
// Created by facuw on 27/5/2026.
//

#include "LineaDeDetalle.h"
#include "Producto.h"

using namespace std;

//CONSTRUCTORES
LineaDeDetalle::LineaDeDetalle() {

}
LineaDeDetalle::LineaDeDetalle(int cantidad, float precioUnitario, Producto* producto) {
    this->cantidad = cantidad;
    this->precioUnitario = precioUnitario;
    this->producto = producto;
}

//GETTERS
int LineaDeDetalle::getCantidad() const {
    return this->cantidad;
}
float LineaDeDetalle::getPrecioUnitario() const {
    return this->precioUnitario;
}
Producto* LineaDeDetalle::getProducto() const {
    return this->producto;
}


//SETTERS
void LineaDeDetalle::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}
void LineaDeDetalle::setPrecioUnitario(float precioUnitario) {
    this->precioUnitario = precioUnitario;
}
