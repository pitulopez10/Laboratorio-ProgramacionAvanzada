//
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
#include "../controladores/AdminController.h"
#include <string>
#include <vector>

using namespace std;

class AdminController;

class EmpleadoController {
private:
    AdminController* adminController;
    vector<Venta*> venta;
    vector<Empleado*> empleados;
    vector<ClienteRegistrado*> clientes;

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

    bool registrarVenta(string idVenta,DTFecha fecha,DTHora hora, float precioTotal);
    void consultarHistorialDeCompras(string rut) const;
    Producto* consultarInfoDetalladaProducto(string codigoProducto);
    void consultarStock();


    //METODOS AUXILIARES
    void validarRutCliente(int rut);
    void validarCorreoCliente(string correo);
    
    ClienteRegistrado* buscarCliente(int rutBuscado);
};



#endif //LABORATORIO3_EMPLEADOCONTROLLER_H
