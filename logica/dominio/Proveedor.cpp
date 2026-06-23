//
// Created by facuw on 3/6/2026.
//

#include "Proveedor.h"
#include "Producto.h"
#include "LineaDeCompra.h"
#include <vector>

//CONSTRUCTORES
Proveedor::Proveedor() {

}
Proveedor::Proveedor(int rut, string nombre, string telContacto, string nombreContacto) {
    this->rut = rut;
    this->nombre = nombre;
    this->telContacto = telContacto;
    this->nombreContacto = nombreContacto;
}

//GETTERS

int Proveedor::getRut() {
    return this->rut;
}
string Proveedor::getNombre(){
    return this->nombre;
}
string Proveedor::getTelContacto() {
    return this->telContacto;
}
string Proveedor::getNombreContacto() {
    return this->nombreContacto;
}
vector<LineaDeCompra*> Proveedor::getLineasAsociadas() {
    return this->lineasAsociadas;
}


//SETTERS

void Proveedor::setRut(int rut) {
    this->rut = rut;
}
void Proveedor::setNombre(string nombre) {
    this->nombre = nombre;
}
void Proveedor::setTelContacto(string telContacto) {
    this->telContacto = telContacto;
}
void Proveedor::setNombreContacto(string nombreContacto) {
    this->nombreContacto = nombreContacto;
}

//METODOS
bool Proveedor::abasteceProducto(string codigoProducto) {
    for (LineaDeCompra* linea : lineasAsociadas) {
        if (linea->getProducto()->getCodigo() == codigoProducto) {
            return true;
        }
    }
    return false;
}

void Proveedor::agregarProducto(Producto* p, float precioCompra, int tiempoEntrega) {
    LineaDeCompra* nuevaLinea = new LineaDeCompra(precioCompra, p, tiempoEntrega); 
    
    lineasAsociadas.push_back(nuevaLinea);
}
void Proveedor::actualizarDatosProducto(string codigoProducto, float nuevoPrecio, int nuevoTiempo) {
    
    for (LineaDeCompra* linea : lineasAsociadas) {
        
        if (linea->getProducto()->getCodigo() == codigoProducto) {
            
            linea->setPrecioCompra(nuevoPrecio);
            linea->setTiempoEntrega(nuevoTiempo);
            
            return;
        }
    }
}
