//
// Created by facuw on 3/6/2026.
//

#include "EmpleadoController.h"
#include "AdminController.h"
#include "VentaController.h"
#include <string>
#include <vector>
#include <ctime>
#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Cliente.h"
#include "../dominio/EstadoCompra.h"
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


//REGISTRAR VENTA

void EmpleadoController::registrarVenta(Cliente* cliente, vector<LineaDeDetalle*> lineasTemp, DTFecha fechaActual, DTHora horaActual, float total) {    
    if(lineasTemp.empty()) { throw 1; }
    string idVenta = VentaController::getInstancia()->generarIdVenta();
    
    Venta* nuevaVenta = new Venta(idVenta, fechaActual, horaActual, total, cliente);

    agregarLineasVenta(nuevaVenta, lineasTemp);

    descontarStock(lineasTemp);

    VentaController::getInstancia()->agregarVenta(nuevaVenta);
}
//Cuando el usuario confirma el registro de la nueva venta
void EmpleadoController::agregarLineasVenta(Venta* venta, vector<LineaDeDetalle*> lineas) {
    for(LineaDeDetalle* l : lineas)
    {
        venta->agregarLinea(l);
    }
}

void EmpleadoController::descontarStock(vector<LineaDeDetalle*> lineas) {
    for(LineaDeDetalle* l : lineas)
    {
        Producto* p = l->getProducto();
        p->setEstaEnStock(p->getEstaEnStock() - l->getCantidad());
    }
}

DTFecha EmpleadoController::obtenerFechaActual() {
    time_t ahora = time(nullptr);
    tm* tiempo = localtime(&ahora);
    //convierte el valor time_t en una estructura tm con la fecha organizadas

    return DTFecha(tiempo->tm_mday, tiempo->tm_mon + 1/*(0-11)*/, tiempo->tm_year + 1900);
}

DTHora EmpleadoController::obtenerHoraActual()
{
    time_t ahora = time(nullptr);
    tm* tiempo = localtime(&ahora);

    return DTHora(tiempo->tm_hour, tiempo->tm_min, tiempo->tm_sec);
}

//CONSULTAR HISTORIAL

vector<Venta*> EmpleadoController::consultarHistorialDeCompras(ClienteRegistrado* cliente) const {

    vector<Venta*> ventasCliente = VentaController::getInstancia()->obtenerVentasCliente(cliente);

    if (ventasCliente.empty()) {
        throw 1;
    } 
    VentaController::getInstancia()->ordenarVentasPorFecha(ventasCliente);

    return ventasCliente;

}

Venta* EmpleadoController::seleccionarVentaDeHistorial(vector<Venta*> historial, string idBuscado) {
    for(Venta* v : historial) {
        if(v->getIdVenta() == idBuscado) {
            return v;
        }
    }
    throw 1;
}

vector<LineaOrden*> EmpleadoController::getLineasTempOrden() const {
    return lineasTempOrden; 
}

//EMITIR ORDEN DE COMPRA
void EmpleadoController::agregarLineaTemporalOrden(Producto* producto, int cantidad) {
    LineaOrden* linea = new LineaOrden(producto, cantidad);

    this->lineasTempOrden.push_back(linea); 
}

void EmpleadoController::limpiarLineasTemporalesOrden() {
    //liberar memoria
    for (LineaOrden* l : this->lineasTempOrden) {
        delete l;
    }
    //limpiar
    this->lineasTempOrden.clear();
}

void EmpleadoController::registrarOrdenDeCompra(Proveedor* proveedor, vector<LineaOrden*> lineasTemp, DTFecha fechaActual, DTHora horaActual) {
    
    if (lineasTemp.empty()) {
        throw 1; 
    }
    string idGenerado = "OC-" + to_string(this->listaOrdenes.size() + 1);
    OrdenDeCompra* nuevaOrden = new OrdenDeCompra(idGenerado, fechaActual, proveedor);

    for (LineaOrden* linea : lineasTemp) {
        nuevaOrden->agregarLineaOrden(linea);
    }
    this->listaOrdenes.push_back(nuevaOrden);
}

//CANCELAR ORDEN DE COMPRA

vector<OrdenDeCompra*> EmpleadoController::listarOrdenesPendientes() {
    vector<OrdenDeCompra*> pendientes;

    for (OrdenDeCompra* orden : this->listaOrdenes) {
        if (orden->getEstado() == PENDIENTE) {
            pendientes.push_back(orden);
        }
    }   
    if (pendientes.empty()) {
        throw 1; 
    }
    return pendientes;
}

OrdenDeCompra* EmpleadoController::buscarOrdenDeCompra(string idOrden) {
    for (OrdenDeCompra* orden : this->listaOrdenes) {
        if (orden->getIdOrden() == idOrden) {
            if (orden->getEstado() != PENDIENTE) {
                throw 2; 
            }
            return orden;
        }
    }
    throw 2; 
}

void EmpleadoController::cancelarOrdenDeCompra(string idOrden) {
    OrdenDeCompra* orden = buscarOrdenDeCompra(idOrden);
    
    orden->setEstado(CANCELADO);
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
