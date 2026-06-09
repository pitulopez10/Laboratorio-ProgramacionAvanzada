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

VentaController::VentaController() {}

void VentaController::nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal) {}

vector<Venta*> VentaController::listarVentas() {
    return ventas;
}

void VentaController::consultarStock() {}
