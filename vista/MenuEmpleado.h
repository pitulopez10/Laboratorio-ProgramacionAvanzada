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
        EmpleadoController* controller;

    public:
        MenuEmpleado(EmpleadoController* controller);

        //GETTERS
        string getNombre();
        string getApellido();
        int getIdEmpleado();

        //SETTERS
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setIdEmpleado(int idEmpleado);

        //METODOS
        void MenuEmpleado::MenuEmp();
};



#endif //LABORATORIO3_MENUEMPLEADO_H
