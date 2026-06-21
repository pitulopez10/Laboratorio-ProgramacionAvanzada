#include "MenuCliente.h"
#include <iostream>

using namespace std;

MenuCliente :: MenuCliente(VentaController* ventaCtrl) {
    this->ventaCtrl = ventaCtrl;
}

void MenuCliente::mostrar() {
    int opcion;
    bool salir = false;
    do {
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout<<"|        MENU CLIENTES        |"<<endl;
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout<<"1. Consultar su historial de compras"<<endl;
        cout<<"2. Calificar productos comprados"<<endl;
        cout<<"0. Cerrar sesion\n";
        cout<<"Seleccione opcion: ";
        cin>>opcion;

        switch(opcion) {
            case 1: {
                cin.ignore();

                string rut;
                cout<<"Ingrese RUT: ";
                getline(cin, rut);

                ventaCtrl->consultarHistorialDeCompras(rut);
                break;
            }
            case 2: {
                calificarProducto();
                break;
            }
            case 0:
                cerrarSesion();
                salir = true;
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    } while(opcion != 0);
}

//CERRAR SESION
void MenuCliente::cerrarSesion() {
    ventaCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}

void MenuCliente::calificarProducto() {
    string codigoProducto, comentario;
    int puntaje, rut, dia, mes, anio;

    cout << "\n---CALIFICAR PRODUCTO---\n";

    cout<<"Ingrese RUT: ";
    cin>>rut;

    cout<<"Ingrese codigo del producto: ";
    cin>>codigoProducto;

    try {
        ventaCtrl->verificarCompra(rut, codigoProducto);

        cout<<"Ingrese dia: ";
        cin>>dia;

        cout<<"Ingrese mes: ";
        cin>>mes;

        cout<<"Ingrese anio: ";
        cin>>anio;
        DTFecha fecha(dia, mes, anio);

        cout<<"Ingrese puntaje (1-5): ";
        cin>>puntaje;

        cin.ignore();
        cout<<"Ingrese comentario: ";
        getline(cin, comentario);
        ventaCtrl->calificarProducto(rut,codigoProducto,puntaje,comentario, fecha);
        cout << "Calificacion agregada correctamente." << endl;
    }
    catch (int error) {
       if (error == 1) {
           cout << "No existe un cliente con ese RUT." << endl;
       }
       if (error == 2) {
            cout << "Debes comprar un producto para hacer una calificacion" << endl;
       }
       if (error == 3) {
            cout << "La calificacion ingresada debe ser entre 1-5" << endl;
       }
    }
}