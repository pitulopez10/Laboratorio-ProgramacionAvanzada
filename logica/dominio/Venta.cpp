//
// Created by facuw on 3/6/2026.
//

#include "Venta.h"
#include <iostream>

using namespace std;

//CONSTRUCTORES
Venta :: Venta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal) {
    this-> idVenta = idVenta;
    this-> fecha = fecha;
    this-> hora = hora;
    this-> precioTotal = precioTotal;
}

//GETTERS

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
