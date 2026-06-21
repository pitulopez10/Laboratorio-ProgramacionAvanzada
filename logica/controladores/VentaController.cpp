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

VentaController::VentaController() {
    clientesRegistrados.push_back(new ClienteRegistrado(86469,"Marcos Lopez", "Herrera 748", "marcoscliente@gmail.com", "1234"));
}

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

void VentaController::calificarProducto(int rut, string codigoProducto, int puntaje, string comentario) {}

void VentaController::consultarHistorialDeCompras(string rut) {

}

ClienteRegistrado* VentaController::iniciarSesion(string correo) {
    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getCorreo() == correo) {
            return clientesRegistrados[i];
        }
    }
            return NULL;
}
