//
// Created by facuw on 3/6/2026.
//

#include "MenuEmpleado.h"
#include "../logica/dominio/DTFecha.h"
#include <string>
#include <iostream>
using namespace std;

MenuEmpleado::MenuEmpleado(EmpleadoController* controlador) {
    this->controlador = controlador;
}

MenuEmpleado::MenuEmpleado(string nombre, string apellido, int idEmpleado) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->idEmpleado = idEmpleado;
}

void MenuEmpleado::MenuEmp() {
    int opcion;
    do {
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "|        MENU EMPLEADOS       |";
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "1. Agregar Empleado" << endl;
        cout << "2. Modificar Empleado" << endl;
        cout << "3. Listar Empleados" << endl;
        cout << "0. Volver" << endl;
        cout << "Elegir opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            string nombre, apellido, idEmpleado;
            cout << "Ingrese nombre del empleado: " << endl; getline(cin, nombre);
            cout << "Ingrese apellido del empleado: " << endl; getline(cin, apellido);
            cout << "Ingrese el id del empleado:" << endl; cin >> idEmpleado;
            if (ctrl.agregarEmpleado(nombre, apellido, idEmpleado)) {
                cout << "El empleado fue agregado correctamente" << endl;
            }
            else
                cout << "El empleado ya existe" << endl;
        }
    }while (opcion != 0);
}

//GETTERS
string MenuEmpleado::getNombre() {
    return this->nombre;
}

string MenuEmpleado::getApellido() {
    return this->apellido;
}


int MenuEmpleado::getIdEmpleado() {
    return this->idEmpleado;
}

//SETTERS
void MenuEmpleado::setNombre(string nombre) {
    this->nombre = nombre;
}

void MenuEmpleado::setApellido(string apellido) {
    this->apellido = apellido;
}

void MenuEmpleado::setIdEmpleado(int idEmpleado) {
    this->idEmpleado = idEmpleado;
}


