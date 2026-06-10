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

//EmpleadoController::EmpleadoController() {}

EmpleadoController::EmpleadoController(AdminController& adminController): adminController(adminController) {

}

bool EmpleadoController::registrarVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal){

}


void EmpleadoController::consultarHistorialDeCompras(string rut) const {

}


void EmpleadoController::consultarStock() {

}

void altaClienteRegistrado(string rut, string nombreCompleto, string direccion, string correo) {

}
