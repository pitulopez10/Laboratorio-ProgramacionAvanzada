//
// Created by facuw on 27/5/2026.
//

#include "OrdenDeCompra.h"
#include "DTFecha.h"
#include "EstadoCompra.h"
#include <iostream>
using namespace std;


//CONSTRUCTORES
OrdenDeCompra::OrdenDeCompra() {

}

OrdenDeCompra::OrdenDeCompra(DTFecha fechaEmision, EstadoCompra estado, string idOrden) {
  this->fechaEmision = fechaEmision;
  this->estado = estado;
  this->idOrden = idOrden;
}

//GETTERS
DTFecha OrdenDeCompra::getFechaEmision() const {
  return this->fechaEmision;
}
EstadoCompra OrdenDeCompra::getEstado() const {
  return this->estado;
}
string OrdenDeCompra::getIdOrden() const {
  return this->idOrden;
}
vector<LineaDeCompra*> OrdenDeCompra::getLineasCompra() {
  return lineasCompra;
}


//SETTERS
void OrdenDeCompra::setFechaEmision(DTFecha fechaEmision) {
  this->fechaEmision = fechaEmision;
}
void OrdenDeCompra::setEstado(EstadoCompra estado) {
  this->estado = estado;
}
void OrdenDeCompra::setIdOrden(string idOrden) {
  this->idOrden = idOrden;
}

//METODOS

void OrdenDeCompra::agregarLineaCompra(LineaDeCompra* lineaCompra) {
  lineasCompra.push_back(lineaCompra);
}
