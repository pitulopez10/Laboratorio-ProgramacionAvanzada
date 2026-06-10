//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_MENUADMINISTRADOR_H
#define LABORATORIO3_MENUADMINISTRADOR_H
#include "../logica/controladores/AdminController.h"

class MenuAdministrador {
    private:
        AdminController& adminCtrl;

        //Funciones para agregar.
        void agregarProducto();
        void agregarCategoria();
        void agregarProveedor();

        //Funciones para listar,
        void listarProductos();
        void listarCategorias();
        void listarProveedores();   

    public:
        MenuAdministrador(AdminController& adminController);
        void mostrar();

};



#endif //LABORATORIO3_MENUADMINISTRADOR_H
