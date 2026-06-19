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
using namespace std;

EmpleadoController* EmpleadoController::instancia = NULL;


EmpleadoController::EmpleadoController() {
    this->adminController = AdminController::getInstancia();
    empleados.push_back(new Empleado("Maria Rodriguez", "18 de Julio 429", "mariaempleado@gmail.com"));
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


bool EmpleadoController::registrarVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal){
    return true;
}


void EmpleadoController::consultarHistorialDeCompras(string rut) const {

}


void EmpleadoController::consultarStock() {

}

void EmpleadoController::altaClienteRegistrado(string rut, string nombreCompleto, string direccion, string correo) {

}

Empleado* EmpleadoController::iniciarSesion(string correo) {

    vector<Empleado*> empleados = AdminController::getInstancia()->listarEmpleados();
    for (int i = 0; i < empleados.size(); i++) {
        if (empleados[i]->getCorreo() == correo) {
            empleadoLogeado = empleados[i];
            return empleados[i];
        }
    }
    return NULL;
}

void EmpleadoController::cerrarSesion() {
    empleadoLogeado = NULL;
}
