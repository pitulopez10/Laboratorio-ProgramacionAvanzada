//
// Created by facuw on 3/6/2026.
//

#include "EmpleadoController.h"
#include "../dominio/MenuEmpleado.h"
#include <string>
#include <vector>
using namespace std;

EmpleadoController::EmpleadoController() {}

EmpleadoController::~EmpleadoController() {
    for (Empleado* e : empleados)
        delete e;
}

Empleado* EmpleadoController::buscarEmpleado(int idEmpleado) const {
    for (Empleado* e : empleados)
        if (e->getIdEmpleado() == idEmpleado)
            return e;
    return nullptr;
}


bool EmpleadoController::agregarEmpleado(const string& nombre, const string& apellido, int idEmpleado) {
    if (buscarEmpleado(idEmpleado) != nullptr)
        return false;  //El empleado ya existe
    empleados.push_back(new Empleado(nombre, apellido, idEmpleado));
    return true;
}

