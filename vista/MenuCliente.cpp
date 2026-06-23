#include "MenuCliente.h"
#include <iostream>

#include "../logica/dominio/Producto.h"


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
        cout<<"1. Calificar productos comprados"<<endl;
        cout<<"2. Consultar informacion detallada de producto" << endl;
        cout<<"0. Cerrar sesion\n";
        cout<<"Seleccione opcion: ";
        cin>>opcion;

        switch(opcion) {
            case 1: {
                calificarProducto();
                break;
            }
            case 2: {
                consultarInfoDetalladaProducto();
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

//CALIFICAR PRODUCTO
void MenuCliente::calificarProducto() {
    string codigoProducto, comentario;
    int puntaje, rut, dia, mes, anio;

    cout << "\n---CALIFICAR PRODUCTO---\n";

    cout<<"Ingrese RUT: ";
    cin>>rut;

    cout<<"Ingrese codigo del producto: ";
    cin >> codigoProducto;

    try {
        ventaCtrl->validarCompra(rut, codigoProducto);

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

//CONSULTAR INFO DETALLADA PRODUCTO
void MenuCliente::consultarInfoDetalladaProducto() {
    string nombre, codigoProducto, descripcion;
    int cantVendidas, estaEnStock;
    float precioUnitario, puntajePromedio;
    Categoria* categoria;

    cout << "\n---CONSULTAR INFO DETALLADA PRODUCTO---\n";

    cout<<"Ingrese codigo del producto: ";
    cin >> codigoProducto;

    try {
        Producto* producto = ventaCtrl->consultarInfoDetalladaProducto(codigoProducto);

        cout<<"Nombre: "<< producto->getNombre()<<endl;
        cout<<"Codigo: "<< producto->getCodigo()<<endl;
        cout<<"Descripcion: "<< producto->getDescripcion()<<endl;
        cout<<"Precio unitario: "<< producto->getPrecioUnitario()<<endl;
        cout<<"Puntaje promedio: "<< producto->getPuntajePromedio()<<endl;
        cout<<"Cantidad de vendidas: "<< producto->getCantVendidas()<<endl;
        cout<<"Esta en stock: "<< producto->getEstaEnStock()<<endl;
        cout<<"Categoria: " << producto->getCategoria()->getNombre()<<endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo." << endl;
        }
    }
}