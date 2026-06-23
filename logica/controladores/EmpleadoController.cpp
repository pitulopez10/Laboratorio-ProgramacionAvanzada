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
#include "../dominio/Calificacion.h"
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
    ClienteRegistrado* cliente = new ClienteRegistrado(rut, nombreCompleto, direccion, correo, password);

    clientes.push_back(cliente);

    VentaController::getInstancia()->agregarClienteRegistrado(cliente);
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
        p->setCantVendidas(p->getCantVendidas() + l->getCantidad());
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
    for (LineaOrden* l : this->lineasTempOrden) {
        delete l;
    }

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

//REGISTRAR RECEPCION DE ORDEN
void EmpleadoController::registrarRecepcionDeOrden(string idOrden) {
    OrdenDeCompra* orden = buscarOrdenDeCompra(idOrden);

    vector<LineaOrden*> lineas = orden->getLineasOrden();

    for (int i = 0; i < lineas.size(); i++) {
        Producto* producto = lineas[i]->getProducto();
        int cantidad = lineas[i]->getCantidad();

        producto->setEstaEnStock(producto->getEstaEnStock() + cantidad);
    }

    orden->setEstado(RECIBIDO);
}

//Caso de uso 20 consultar calificaciones de producto
vector<Calificacion*> EmpleadoController::consultarCalificacionesProducto(string codigoProducto) {
    Producto* producto = NULL;
    vector<Producto*> productos = AdminController::getInstancia()->listarProductos();

    for (int i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigoProducto) {
            producto = productos[i];
        }
    }
    if (producto == NULL) {
        throw 1;
    }

    vector<Calificacion*> calificaciones = producto->getCalificaciones();

    if (calificaciones.empty()) {
        throw 2;
    }
    return calificaciones;
}

//Caso de uso 21 consultar stock actual
int EmpleadoController::consultarStock(string codigoProducto) {
    vector<Producto*> productos = AdminController::getInstancia()->listarProductos();
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigoProducto) {
            return productos[i]->getEstaEnStock();
        }
    }
    throw 1;
}

vector<Producto*> EmpleadoController::consultarProductosBajoMinimo() {
    vector<Producto*> productos = AdminController::getInstancia()->listarProductos(); //Lista completa de productos registrados en el sistema
    vector<Producto*> productosBajoMinimo; //Vector aux para guardar solo productos que esten debajo del minimo
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i]->getEstaEnStock() < productos[i]->getStockMinimo()) {
            productosBajoMinimo.push_back(productos[i]);          //Si el stock actual es menor al mínimo, agrego el producto al vector de productos bajo mínimo
        }
    }
    if (productosBajoMinimo.empty()) {
        throw 1;        //Error si no encuentra productos bajo minimo
    }
    return productosBajoMinimo; //Lista productos que estan debajo del minimo
}

float EmpleadoController::montoTotalFacturadoAcliente(int rutCliente) {
    ClienteRegistrado* clienteEncontrado = nullptr;
    float montoTotal = 0;
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getRut() == rutCliente) {
            clienteEncontrado = clientes[i];
            break;
        }
    }
    if (clienteEncontrado == nullptr) {
        throw 1; //Cliente no encontrado
    }

    vector<Venta*> ventasCliente = VentaController::getInstancia()->obtenerVentasCliente(clienteEncontrado);

    if (ventasCliente.empty()) {
        throw 2; //Cliente sin ventas
    }

    for (int i = 0; i < ventasCliente.size(); i++) {
        montoTotal += ventasCliente[i]->getPrecioTotal();
    }
    return montoTotal;
}

int EmpleadoController::unidadesVendidasDeProducto(string codigoProducto) {
    vector<Producto*> productos = AdminController::getInstancia()->listarProductos();
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigoProducto) {
            return productos[i]->getCantVendidas();
        }
    }
    throw 1;
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
