//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_MENUEMPLEADO_H
#define LABORATORIO3_MENUEMPLEADO_H
#include "../logica/controladores/EmpleadoController.h"
#include <string>
using namespace std;

class VentaController;
class EmpleadoController;
class AdminController;

class MenuEmpleado {
    private:
        EmpleadoController* empleadoCtrl;
        VentaController* ventaCtrl;
        AdminController* adminCtrl;

        //Funciones
        void cerrarSesion();
        
        void altaClienteRegistrado();
        void modificarClienteRegistrado();
        void registrarVenta();
        void consultarHistorialDeCompras();
        void consultarInfoDetalladaProducto();
        void emitirOrdenDeCompra();
        void cancelarOdenDeCompra();
        void registrarRecepcionDeOrden();
        void consultarCalificacionesProducto();
        void consultarStock();
        void consultarProductosBajoMinimo();
        void montoTotalFacturadoAcliente();
        void unidadesVendidasDeProducto();

    public:
        MenuEmpleado(EmpleadoController* controllerEmp,
        VentaController* controllerVenta,
        AdminController* controllerAdmin);
        void mostrar();
};



#endif //LABORATORIO3_MENUEMPLEADO_H
