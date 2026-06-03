//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_EMPLEADOCONTROLLER_H
#define LABORATORIO3_EMPLEADOCONTROLLER_H
#include "..dominio/Empleado.h"
#include <string>
#include <vector>
using namespace std;

class AdminController;

class EmpleadoController {
    private:
        AdminController& adminController;
    public:
        EmpleadoController(AdminController& adminController);

        bool agregarEmpleado(const string& nombre, const string& apellido, int& idEmpleado);
        Empleado* buscarEmpleado(int idEmpleado) const;
};



#endif //LABORATORIO3_EMPLEADOCONTROLLER_H
