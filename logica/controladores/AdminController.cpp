//
// Created by facuw on 3/6/2026.
//

#include "AdminController.h"
AdminController* AdminController::instancia = NULL;


AdminController::AdminController() {
    administradores.push_back(new Admin("Carlos Perez", "Montevideo 234", "carlosadmin@gmail.com"));
}

AdminController::~AdminController() {

}

AdminController*  AdminController::getInstancia() {
    if (instancia != NULL) {
        return instancia;
    }
    else {
        instancia = new AdminController();
        return instancia;
    }
}

Admin* AdminController::iniciarSesion(string correo) {
    for (int i = 0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            return administradores[i];
        }
    }
    return NULL;
}

void AdminController::agregarProducto(string codigo, string nombre, string descripcion,float precioUnitario, int cantVendidas, int estaEnStock) {

}

void AdminController::agregarCategoria(string nombre, string descripcion) {

}

void AdminController::agregarProveedor(int rut, string nombre, string telContacto, string nombreContacto, int tiempoEntrega) {

}

bool AdminController::agregarOrdenCompra(OrdenDeCompra* ordenesCompra) {

}

vector<Producto*> AdminController::listarProductos() {

}

vector<Categoria*> AdminController::listarCategorias() {

}

vector<Proveedor*> AdminController::listarProveedores() {

}

vector<OrdenDeCompra*> AdminController::crearOrdenCompra() {

}