//
// Created by facuw on 3/6/2026.
//

#include "MenuEmpleado.h"
#include "../logica/dominio/DTFecha.h"
#include <string>
#include <iostream>
using namespace std;

MenuEmpleado::MenuEmpleado(EmpleadoController* controllerEmp) {
    this->controllerEmp = controllerEmp;
}

void MenuEmpleado::mostrar() {
    int opcion;
    do {
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "|        MENU EMPLEADOS       |";
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "1. Registrar una venta" << endl;
        cout << "2. Consultar historial de compras de un cliente registrado" << endl;
        cout << "3. Consultar stock" << endl;
        cout << "4. Dar de alta a cliente registrado" << endl;
        cout << "0. Volver" << endl;
        cout << "Elegir opcion: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string producto, cantidad;
                cout << "Ingrese producto: " << endl; getline(cin, producto);
                cout << "Ingrese cantidad: " << endl; getline(cin, cantidad);
                cout << "La venta fue realizada correctamente" << endl;
                cout << "No se puede realizar la venta" << endl;

                break;
            }
            case 2: {
                string rut;
                cout << "Ingrese RUT: " << endl; getline(cin, rut);
                controllerEmp->consultarHistorialDeCompras(rut);
                break;
            }
            case 3: {
                controllerEmp->consultarStock();
                break;
            }
            case 4: {
                string rut, nombreCompleto, direccion, correo;
                cout << "Ingrese nombre completo" << endl; getline(cin, nombreCompleto);
                cout << "Ingrese direccion " << endl; getline(cin, direccion);
                cout << "Ingrese correo " << endl; getline(cin, correo);
                controllerEmp->altaClienteRegistrado(rut, nombreCompleto, direccion, correo);
                break;
            }
        }
    }while (opcion != 0);
}





