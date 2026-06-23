// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_EMPLEADOCONTROLLER_H
#define LABORATORIO3_EMPLEADOCONTROLLER_H

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Empleado.h"
#include "../dominio/Cliente.h"
#include "../dominio/EstadoCompra.h"
#include "../dominio/OrdenDeCompra.h" 
#include "../dominio/Proveedor.h"
#include "../controladores/AdminController.h"
#include "../controladores/VentaController.h"
#include <string>
#include <vector>

using namespace std;

class AdminController;

class EmpleadoController {
private:
    AdminController* adminController;
    VentaController* ventaCtrl;
    vector<Venta*> venta;
    vector<Empleado*> empleados;
    vector<ClienteRegistrado*> clientes;

    vector<OrdenDeCompra*> listaOrdenes;
    vector<LineaOrden*> lineasTempOrden;

    static EmpleadoController* instancia;
    Empleado* empleadoLogeado;

public:
    EmpleadoController();
    ~EmpleadoController();

    static EmpleadoController* getInstancia();

    Empleado* iniciarSesion(string correo, string password);
    void cerrarSesion();

    //METODOS
    void altaClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo, string password);
    void modificarClienteRegistrado(ClienteRegistrado* cliente, string nombreCompleto, string direccion, string correo, string password);

    void registrarVenta(Cliente* cliente, vector<LineaDeDetalle*> lineasTemp, DTFecha fechaActual, DTHora horaActual, float total);
    void agregarLineasVenta(Venta* venta, vector<LineaDeDetalle*> lineas);
    void descontarStock(vector<LineaDeDetalle*> lineas);

    vector<Venta*> consultarHistorialDeCompras(ClienteRegistrado* cliente) const;
    Venta* seleccionarVentaDeHistorial(vector<Venta*> historial, string idBuscado);

    void registrarRecepcionDeOrden(string idOrden);//Caso de uso 18
    vector<Calificacion*> consultarCalificacionesProducto(string codigoProducto);//Caso de uso 20
    int consultarStock(string codigoProducto);//Caso de uso 21
    vector<Producto*> consultarProductosBajoMinimo();//Caso de uso 22
    float montoTotalFacturadoAcliente(int rutCliente); //Caso de uso 23
    int unidadesVendidasDeProducto(string codigoProducto); //Caso de uso 24
    Producto* consultarInfoDetalladaProducto(string codigoProducto);//Caso de uso 25


    //METODOS
    void agregarLineaTemporalOrden(Producto* producto, int cantidad);
    void limpiarLineasTemporalesOrden();
    void registrarOrdenDeCompra(Proveedor* proveedor, vector<LineaOrden*> lineasTemp, DTFecha fechaActual, DTHora horaActual);
    
    vector<LineaOrden*> getLineasTempOrden() const ;

    //METODOS AUXILIARES
    void validarRutCliente(int rut);
    void validarCorreoCliente(string correo);
    DTFecha obtenerFechaActual();
    DTHora obtenerHoraActual();    
    ClienteRegistrado* buscarCliente(int rutBuscado);

    vector<OrdenDeCompra*> listarOrdenesPendientes();
    OrdenDeCompra* buscarOrdenDeCompra(string idOrden);
    void cancelarOrdenDeCompra(string idOrden);
};

#endif //LABORATORIO3_EMPLEADOCONTROLLER_H
