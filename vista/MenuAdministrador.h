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

        void agregarProducto();
        void agregarProveedor();

        //FUNCIONES DE LISTAR
        void listarEmpleados();

        void listarProductos();
        void listarCategorias();
        void listarProveedores();   

    public:
        MenuAdministrador(AdminController* adminCtrl);
        void mostrar();

};



#endif //LABORATORIO3_MENUADMINISTRADOR_H
