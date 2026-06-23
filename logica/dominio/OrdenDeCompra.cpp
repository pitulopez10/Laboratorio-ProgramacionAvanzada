//
// Created by facuw on 27/5/2026.
//

#include "OrdenDeCompra.h"
#include "DTFecha.h"
#include "EstadoCompra.h"
#include "Producto.h"
#include "LineaOrden.h"
#include <iostream>
using namespace std;

#include "OrdenDeCompra.h"

OrdenDeCompra::OrdenDeCompra() {

}
OrdenDeCompra::OrdenDeCompra(string idOrden, DTFecha fechaEmision, Proveedor* proveedor) {
  this->idOrden = idOrden;
  this->fechaEmision = fechaEmision;
  this->proveedor = proveedor;

  //la orden se registra en estado 'pendiente'
  this->estado = PENDIENTE;
}

// GETTERS
string OrdenDeCompra::getIdOrden() const {
  return this->idOrden;
}
DTFecha OrdenDeCompra::getFechaEmision() const {
  return this->fechaEmision;
}
Proveedor* OrdenDeCompra::getProveedor() const {
  return this->proveedor;
}
EstadoCompra OrdenDeCompra::getEstado() const {
  return this->estado;
}

vector<LineaOrden*> OrdenDeCompra::getLineasOrden() {
  return this->lineasOrden;
}

// SETTERS
void OrdenDeCompra::setFechaEmision(DTFecha fechaEmision) {
  this->fechaEmision = fechaEmision;
}

void OrdenDeCompra::setEstado(EstadoCompra nuevoEstado) {
  this->estado = estado;
}

// METODOS
void OrdenDeCompra::agregarLineaOrden(LineaOrden* lineaOrden) {
    this->lineasOrden.push_back(lineaOrden);
}

