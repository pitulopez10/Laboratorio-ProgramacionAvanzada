//
// Created by facuw on 3/6/2026.
//
#include "VentaController.h"

#include <vector>
#include <string>

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Producto.h"
#include "../dominio/Calificacion.h"

using namespace std;
VentaController* VentaController::instancia = NULL;

VentaController::VentaController() {
    clientesRegistrados.push_back(new ClienteRegistrado(86469,"Marcos Lopez", "Herrera 748", "marcoscliente@gmail.com", "1234"));
    clienteLogeado = NULL;
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

//Verifica que haya comprado un producto
void VentaController::verificarCompra(int rut, string codigoProducto) {
    ClienteRegistrado* cliente = NULL;
    Producto* producto = NULL;

    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getRut() == rut) {
            cliente = clientesRegistrados[i];
        }
    }
    if (cliente == NULL) {
        throw 1;
    }

    ventas = cliente->getVentas();

    for (int i = 0; i < ventas.size(); i++) {
        vector<LineaDeDetalle*> lineas = ventas[i]->getLineas();
        for (int j = 0; j < lineas.size(); j++) {
            if (lineas[j]->getProducto()->getCodigo() == codigoProducto) {
                producto = lineas[j]->getProducto();
            }
        }
    }
    if (producto == NULL) {
        throw 2;
    }
}

void VentaController::calificarProducto(int rut, string codigoProducto, int puntaje, string comentario, DTFecha fecha) {
    ClienteRegistrado* cliente = NULL;
    Producto* producto = NULL;

    if (puntaje < 1 || puntaje > 5) {
        throw 3;
    }

    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getRut() == rut) {
            cliente = clientesRegistrados[i];
        }
    }

    ventas = cliente->getVentas();

    for (int j = 0; j < ventas.size(); j++) {
        lineas = ventas[j]->getLineas();
        for (int k = 0; k < lineas.size(); k++) {
            if (lineas[k]->getProducto()->getCodigo() == codigoProducto) {
                producto = lineas[k]->getProducto();
            }
        }
    }
    Calificacion* calificacion = new Calificacion(comentario, puntaje, fecha, cliente, producto);

    cliente->agregarCalificacion(calificacion);
}

void VentaController::consultarHistorialDeCompras(string rut) {

}

//INICIAR SESION
ClienteRegistrado* VentaController::iniciarSesion(string correo) {
    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getCorreo() == correo) {
            return clientesRegistrados[i];
        }
    }
            return NULL;
}

//CERRAR SESION
void VentaController::cerrarSesion() {
    clienteLogeado = NULL;
}

