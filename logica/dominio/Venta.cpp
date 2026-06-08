//
// Created by facuw on 3/6/2026.
//

#include "Venta.h"
#include <vector>
#include "LineaDeDetalle.h"

using namespace std;

//CONSTRUCTORES
Venta ::Venta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal) {
    this-> idVenta = idVenta;
    this-> fecha = fecha;
    this-> hora = hora;
    this-> precioTotal = precioTotal;
}

void Venta::agregarLinea(LineaDeDetalle* linea) {
    this->lineas.push_back(linea);
}

//GETTERS

vector<LineaDeDetalle*> Venta::getLineas() {
    return this->lineas;
}

string Venta :: getIdVenta() {
    return idVenta;
}

DTFecha Venta :: getFecha() {
    return fecha;
}
  
DTHora Venta :: getHora() {
    return hora;
}
 
float Venta :: getPrecioTotal() {
    return precioTotal;
}

//SETTERS

void Venta :: setFecha(DTFecha fecha) {
    this-> fecha = fecha;
}

void Venta :: setHora(DTHora hora) {
    this-> hora = hora;
}
      
void Venta :: setPrecioTotal(float precioTotal) {
    this-> precioTotal = precioTotal;
}
