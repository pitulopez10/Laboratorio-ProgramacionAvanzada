//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_MENUADMINISTRADOR_H
#define LABORATORIO3_MENUADMINISTRADOR_H
#include "../logica/controladores/AdminController.h"

class MenuAdministrador {
    private:

        AdminController* adminCtrl;

        //CERRAR SESION
        void cerrarSesion();

        //FUNCIONES DE AGREGAR
        void altaEmpleado();
        void agregarCategoria();
        void modificarCategoria();
        void agregarProducto();
        void modificarProducto();
        void eliminarProducto();

        void agregarProveedor();
        void modificarProveedor();
        void registrarProveedorProducto();

        //FUNCIONES DE LISTAR
        void listarEmpleados();
        void listarCategorias();

        void listarProductos();
        void listarProveedores();

        void consultarCalificacionesProducto();
        void consultarInfoDetalladaProducto();

        void consultarStock();
        void consultarProductosBajoMinimo();
        void montoTotalFacturadoAcliente();
        void unidadesVendidasDeProducto();

    public:
        MenuAdministrador(AdminController* adminCtrl);

        void mostrar();

};



#endif //LABORATORIO3_MENUADMINISTRADOR_H
