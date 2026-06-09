#include "MenuCliente.h"
#include <iostream>

using namespace std;

MenuCliente :: MenuCliente(VentaController* controller) {
    this->controller = controller;
}

void MenuCliente::mostrar() {
    int opcion;
    do {
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout<<"|        MENU CLIENTES        |"<<endl;
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout<<"1. Consultar su historial de compras"<<endl;
        cout<<"2. Calificar productos comprados"<<endl;
        cout<<"0. Volver"<<endl;
        cout<<"Seleccione opcion: ";
        cin>>opcion;

        switch(opcion) {
            case 1: {
                cin.ignore();

                string rut;
                cout<<"Ingrese RUT: ";
                getline(cin, rut);

                controller->consultarHistorialDeCompras(rut);
                break;
            }
            case 2: {
                string rut;
                string codigoProducto;
                int puntaje;
                string comentario;

                cout<<"Ingrese RUT: ";
                cin>>rut;

                cout<<"Ingrese codigo del producto: ";
                cin>>codigoProducto;

                cout<<"Ingrese puntaje (1-5): ";
                cin>>puntaje;

                cin.ignore();
                cout<<"Ingrese comentario: ";
                getline(cin, comentario);

                controller->calificarProducto(rut,codigoProducto,puntaje,comentario);
                break;
            }
            case 0:
                cout<<"Volviendo...\n";
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    } while(opcion != 0);
}
