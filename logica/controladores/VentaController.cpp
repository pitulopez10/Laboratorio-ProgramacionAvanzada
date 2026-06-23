//
// Created by facuw on 3/6/2026.
//
#include "VentaController.h"
#include "AdminController.h"
#include "EmpleadoController.h"

#include <vector>
#include <string>
#include <algorithm>

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

//GETTERS

vector<LineaDeDetalle*> VentaController::getLineasTemp() {
    return lineas;
}


//REGISTRAR VENTA
//Agrega lineas temporales a un vector hasta que el usuario confirme la venta
void VentaController::agregarLineaTemporal(Producto* producto,int cantidad) {
    
    if(producto->getEstaEnStock() < cantidad)
    {
        throw 1;
    }    
    LineaDeDetalle* linea = new LineaDeDetalle(cantidad, producto->getPrecioUnitario(), producto);

    lineas.push_back(linea);
}
//Si el usuario cancela la confirmacion de registrarVenta
void VentaController::limpiarLineasTemporales() {
    lineas.clear();
}

string VentaController::generarIdVenta() {
    return "V" + to_string(ventas.size() + 1);
}

float VentaController::calcularTotal(vector<LineaDeDetalle*> lineas) {
    float total = 0;
    for(LineaDeDetalle* l : lineas)
    {
        total += l->getCantidad() * l->getPrecioUnitario();
    }
    return total;
}

void VentaController::agregarVenta(Venta* v) {
    ventas.push_back(v);
    ClienteRegistrado* clienteRegistrado = dynamic_cast<ClienteRegistrado*>(v->getCliente());
    if (clienteRegistrado != nullptr) {
        clienteRegistrado->agregarVenta(v);
    }
}

void VentaController::agregarClienteRegistrado(ClienteRegistrado* cliente) {
    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getRut() == cliente->getRut() || clientesRegistrados[i]->getCorreo() == cliente->getCorreo()) {
                return;
        }
    }
    clientesRegistrados.push_back(cliente);
}

//CONSULTAR HISTORIAL CLIENTE

vector<Venta*> VentaController::obtenerVentasCliente(ClienteRegistrado* cliente)
{
    vector<Venta*> resultado;

    for(Venta* v : ventas)
    {
        if(v->getCliente() == cliente)
        {
            resultado.push_back(v);
        }
    }

    return resultado;
}

//Ordenar ventas

bool VentaController::compararVentas(Venta* v1, Venta* v2) {
    DTFecha f1 = v1->getFecha();
    DTFecha f2 = v2->getFecha();

    if(f1.getAnio() != f2.getAnio())
        return f1.getAnio() > f2.getAnio();

    if(f1.getMes() != f2.getMes())
        return f1.getMes() > f2.getMes();

    if(f1.getDia() != f2.getDia())
        return f1.getDia() > f2.getDia();

    DTHora h1 = v1->getHora();
    DTHora h2 = v2->getHora();

    if(h1.getHora() != h2.getHora())
        return h1.getHora() > h2.getHora();

    if(h1.getMinuto() != h2.getMinuto())
        return h1.getMinuto() > h2.getMinuto();

    return h1.getSegundo() > h2.getSegundo();
}

void VentaController::ordenarVentasPorFecha(vector<Venta*>& ventas)
{
    sort(ventas.begin(), ventas.end(), compararVentas);
}

vector<Venta*> VentaController::listarVentas() {
    return ventas;
}

//Verifica que haya comprado un producto
void VentaController::validarCompra(int rut, string codigoProducto) {
    ClienteRegistrado* cliente = nullptr;
    Producto* producto = nullptr;

    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getRut() == rut) {
            cliente = clientesRegistrados[i];
            break;
        }
    }

    if (cliente == nullptr) {
        throw 1; //Cliente no encontrado
    }

    vector<Venta*> ventasCliente = cliente->getVentas();

    for (int i = 0; i < ventasCliente.size(); i++) {
        vector<LineaDeDetalle*> lineasVenta = ventasCliente[i]->getLineas();

        for (int j = 0; j < lineasVenta.size(); j++) {
            if (lineasVenta[j]->getProducto()->getCodigo() == codigoProducto) {
                producto = lineasVenta[j]->getProducto();
                break;
            }
        }
    }

    if (producto == nullptr) {
        throw 2; //Producto no comprado
    }
}

//Caso uso 19 calificar producto
void VentaController::calificarProducto(int rut, string codigoProducto, int puntaje, string comentario, DTFecha fecha) {
    ClienteRegistrado* cliente = nullptr;
    Producto* producto = nullptr;

    if (puntaje < 1 || puntaje > 5) {
        throw 3; // puntaje inválido
    }
    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getRut() == rut) {
            cliente = clientesRegistrados[i];
            break;
        }
    }
    if (cliente == nullptr) {
        throw 1; //Cliente no encontrado
    }

    vector<Venta*> ventasCliente = cliente->getVentas();

    for (int i = 0; i < ventasCliente.size(); i++) {
        vector<LineaDeDetalle*> lineasVenta = ventasCliente[i]->getLineas();
        for (int j = 0; j < lineasVenta.size(); j++) {
            if (lineasVenta[j]->getProducto()->getCodigo() == codigoProducto) {
                producto = lineasVenta[j]->getProducto();
                break;
            }
        }
    }
    if (producto == nullptr) {
        throw 2; //Producto no comprado
    }

    Calificacion* calificacion = new Calificacion(comentario, puntaje, fecha, cliente, producto);

    cliente->agregarCalificacion(calificacion);
    producto->agregarCalificacion(calificacion);
}

//Caso de uso 25 consultar info de un producto
Producto* VentaController::consultarInfoDetalladaProducto(string codigoProducto) {
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


//INICIAR SESION
ClienteRegistrado* VentaController::iniciarSesion(string correo, string password) {
    for (int i = 0; i < clientesRegistrados.size(); i++) {
        if (clientesRegistrados[i]->getCorreo() == correo && clientesRegistrados[i]->getPassword() == password) {
            return clientesRegistrados[i];
        }
    }
    return NULL;
}

//CERRAR SESION
void VentaController::cerrarSesion() {
    clienteLogeado = NULL;
}


