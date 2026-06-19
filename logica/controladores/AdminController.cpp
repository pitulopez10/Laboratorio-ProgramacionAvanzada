//
// Created by facuw on 3/6/2026.
//

#include "AdminController.h"
AdminController* AdminController::instancia = NULL;




//CONTROLADORES E INTANCIA
AdminController::~AdminController() {

}

AdminController::AdminController() {
    administradores.push_back(new Admin("Carlos Perez", "Montevideo 234", "carlosadmin@gmail.com"));
    empleados.push_back(new Empleado("Maria Rodriguez", "18 de Julio 429", "mariaempleado@gmail.com"));
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

//INICIO DE SESION
Admin* AdminController::iniciarSesion(string correo) {
    for (int i = 0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            return administradores[i];
        }
    }
    return NULL;
}

//FUNCIONES DE AGREGAR
void AdminController::altaEmpleado(string nombreCompleto, string direccion, string correo) {
    for (int i =0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            throw 1;
        }
    }

    Empleado* empleado = new Empleado(nombreCompleto, direccion, correo);
    empleados.push_back(empleado);
}




void AdminController::agregarProducto(string codigo, string nombre, string descripcion,float precioUnitario, int cantVendidas, int estaEnStock) {

}

void AdminController::agregarCategoria(string nombre, string descripcion) {

}

void AdminController::agregarProveedor(int rut, string nombre, string telContacto, string nombreContacto, int tiempoEntrega) {

}

bool AdminController::agregarOrdenCompra(OrdenDeCompra* ordenesCompra) {

}

//FUNCIONES DE LISTAR
vector<Empleado*> AdminController::listarEmpleados() {
    return empleados;
}


vector<Producto*> AdminController::listarProductos() {

}

vector<Categoria*> AdminController::listarCategorias() {

}

vector<Proveedor*> AdminController::listarProveedores() {

}

vector<OrdenDeCompra*> AdminController::crearOrdenCompra() {

}