//
// Created by facuw on 3/6/2026.
//

#include "EmpleadoController.h"
#include "AdminController.h"
#include <string>
#include <vector>
#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Cliente.h"
using namespace std;

EmpleadoController* EmpleadoController::instancia = NULL;


EmpleadoController::EmpleadoController() {
    this->adminController = AdminController::getInstancia();
    empleados.push_back(new Empleado("Maria Rodriguez", "18 de Julio 429", "mariaempleado@gmail.com","1234"));
}


EmpleadoController*  EmpleadoController::getInstancia() {
    if (instancia != NULL) {
        return instancia;
    }
    else {
        instancia = new EmpleadoController();
        return instancia;
    }
}
void EmpleadoController::validarRutCliente(int rut) {
    for(ClienteRegistrado* c : clientes) {
        if(c->getRut() == rut) {
            throw 1;
        }
    }
    return;
}
void EmpleadoController::validarCorreoCliente(string correo) {
    for(ClienteRegistrado* c : clientes) {
        
        if(c->getCorreo() == correo) {
            throw 2;
        }
    }
    return;
}

ClienteRegistrado* EmpleadoController::buscarCliente(int rutBuscado) {
    for(ClienteRegistrado* c : clientes) {
        if (c->getRut() == rutBuscado) {
            return c;
        }
    }
    return nullptr;
}


void EmpleadoController::altaClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo, string password) {

    ClienteRegistrado* nuevoCliente = new ClienteRegistrado(rut, nombreCompleto, direccion, correo, password);

    clientes.push_back(nuevoCliente);
}

void EmpleadoController::modificarClienteRegistrado(ClienteRegistrado* cliente, string nombreCompleto, string direccion, string correo, string password) {

    if(nombreCompleto != "") {
        cliente->setNombreCompleto(nombreCompleto);
    }
    if(direccion != "") {
        cliente->setDireccion(direccion);
    }    
    if(correo != "") {
        cliente->setCorreo(correo);
    }
    if(password != "") {
        cliente->setPassword(password);
    }
}

Producto* EmpleadoController::consultarInfoDetalladaProducto(string codigoProducto) {
    Producto* producto = NULL;
    AdminController* adminCtrl = AdminController::getInstancia();
    vector<Producto*> productos = adminCtrl->listarProductos();
    string codigoGuardado;

    for (int i = 0; i < productos.size(); i++) {
        codigoGuardado = productos[i]->getCodigo();
        if (codigoGuardado == codigoProducto) {
            return productos[i];
        }
    }
    throw 1;
}

bool EmpleadoController::registrarVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal){
    return true;
}


void EmpleadoController::consultarHistorialDeCompras(string rut) const {

}


void EmpleadoController::consultarStock() {

}


Empleado* EmpleadoController::iniciarSesion(string correo, string password) {

    vector<Empleado*> empleados = AdminController::getInstancia()->listarEmpleados();
    for (int i = 0; i < empleados.size(); i++) {
        if (empleados[i]->getCorreo() == correo && empleados[i]->getPassword() == password) {
            empleadoLogeado = empleados[i];
            return empleados[i];
        }
    }
    return NULL;
}

void EmpleadoController::cerrarSesion() {
    empleadoLogeado = NULL;
}
