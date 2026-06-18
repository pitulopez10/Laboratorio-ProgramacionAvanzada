//
// Created by facuw on 3/6/2026.
//
#include "VentaController.h"

#include <vector>
#include <string>

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"

using namespace std;
VentaController* VentaController::instancia = NULL;

VentaController::VentaController() {}

VentaController* VentaController::getInstancia() {
    if (instancia != NULL) {
        return instancia;
    }
    else {
        instancia = new VentaController();
        return instancia;
    }

}

void VentaController::nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal) {}

vector<Venta*> VentaController::listarVentas() {
    return ventas;
}

void VentaController::consultarStock() {}

void VentaController::calificarProducto(string rut, string codigoProducto, int puntaje, string comentario) {}

void VentaController::consultarHistorialDeCompras(string rut) {

}