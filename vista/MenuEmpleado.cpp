//
// Created by facuw on 3/6/2026.
//

#include "MenuEmpleado.h"
#include "../logica/dominio/DTFecha.h"
#include <string>
#include <iostream>
using namespace std;

MenuEmpleado::MenuEmpleado(EmpleadoController* empleadoCtrl) {
    this->empleadoCtrl = empleadoCtrl;
}

void MenuEmpleado::mostrar() {
    int opcion;
    bool salir = false;
    do {
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "|        MENU EMPLEADOS       |" <<endl;
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
                registrarVenta();
                break;
            }
            case 2: {
                consultarHistorialDeCompras();
                break;
            }
            case 3: {
                consultarStock();
                break;
            }
            case 4: {
                altaClienteRegistrado();
                break;
            }
            case 0: {
                cerrarSesion();
                salir = true;
                break;
            }




        }
    }while (opcion != 0);
}


//Funciones



void MenuEmpleado::cerrarSesion() {
    empleadoCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}

void::MenuEmpleado::registrarVenta() {
    string idVenta, dia, mes, anio;
    DTFecha fecha; DTHora hora;
    int horaReal, minuto, segundo;
    float precioTotal;
    cout << "Ingrese id de la venta: " << endl; getline(cin, idVenta);
    cout << "Ingrese el dia: " << endl; cin >> dia;
    cout << "Ingrese el mes: " << endl; cin >> mes;
    cout << "Ingrese el año: " << endl; cin >> anio;
    cout << "Ingrese la hora: " << endl; cin >> horaReal;
    cout << "Ingrese minuto: " << endl; cin >> minuto;
    cout << "Ingrese segundo: " << endl; cin >> segundo;
    empleadoCtrl->registrarVenta( idVenta, fecha, hora, precioTotal);
    cout << "La venta fue realizada correctamente" << endl;
    cout << "No se puede realizar la venta" << endl;

}

void::MenuEmpleado::consultarHistorialDeCompras() {
    string rut;
    cout << "Ingrese RUT: " << endl; getline(cin, rut);
    empleadoCtrl->consultarHistorialDeCompras(rut);
}

void::MenuEmpleado::consultarStock() {
    empleadoCtrl->consultarStock();
}

void::MenuEmpleado::altaClienteRegistrado() {
    string rut, nombreCompleto, direccion, correo;
    cout << "Ingrese nombre completo" << endl; getline(cin, nombreCompleto);
    cout << "Ingrese direccion " << endl; getline(cin, direccion);
    cout << "Ingrese correo " << endl; getline(cin, correo);
    empleadoCtrl->altaClienteRegistrado(rut, nombreCompleto, direccion, correo);
}