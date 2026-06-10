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
        EmpleadoController* controllerEmp;

    public:
        MenuEmpleado(EmpleadoController* controllerEmp);
        void mostrar();
};



#endif //LABORATORIO3_MENUEMPLEADO_H
