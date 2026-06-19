//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_MENUEMPLEADO_H
#define LABORATORIO3_MENUEMPLEADO_H
#include "../logica/controladores/EmpleadoController.h"
#include <string>
using namespace std;


class MenuEmpleado {
    private:
        EmpleadoController* empleadoCtrl;

        //Funciones
        void cerrarSesion();

        void registrarVenta();
        void consultarHistorialDeCompras();
        void consultarStock();
        void altaClienteRegistrado();

    public:
        MenuEmpleado(EmpleadoController* controllerEmp);
        void mostrar();
};



#endif //LABORATORIO3_MENUEMPLEADO_H
