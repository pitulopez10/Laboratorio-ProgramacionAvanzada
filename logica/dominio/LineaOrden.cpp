#include <iostream>
#include "LineaOrden.h"
#include "Producto.h"

//CONSTRUCTORES
LineaOrden::LineaOrden(Producto* producto, int cantidad) {
    this->producto = producto;
    this->cantidad = cantidad;
}

//GETTERS
Producto* LineaOrden::getProducto() {
    return producto;
}
int LineaOrden::getCantidad() {
    return cantidad;
}

//SETTERS
void LineaOrden::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}
    
//METODOS