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

    do {
        cout << "\n=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "|        MENU EMPLEADOS       |" << endl;
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;

        cout << "1. Gestion de clientes" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Ordenes de compra" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. Informacion de producto" << endl;
        cout << "0. Cerrar sesion" << endl;
        cout << "Elegir opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int opcionClientes;

                do {
                    cout << "\n--- GESTION DE CLIENTES ---\n";
                    cout << "1. Alta cliente registrado" << endl;
                    cout << "2. Modificar cliente registrado" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionClientes;
                    cin.ignore();

                    switch (opcionClientes) {
                        case 1:
                            altaClienteRegistrado();
                            break;
                        case 2:
                            modificarClienteRegistrado();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionClientes != 0);

                break;
            }

            case 2: {
                int opcionVentas;

                do {
                    cout << "\n--- VENTAS ---\n";
                    cout << "1. Registrar venta" << endl;
                    cout << "2. Consultar historial de compras" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionVentas;
                    cin.ignore();

                    switch (opcionVentas) {
                        case 1:
                            registrarVenta();
                            break;
                        case 2:
                            consultarHistorialDeCompras();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionVentas != 0);

                break;
            }

            case 3: {
                int opcionOrdenes;

                do {
                    cout << "\n--- ORDENES DE COMPRA ---\n";
                    cout << "1. Emitir orden de compra" << endl;
                    cout << "2. Cancelar orden de compra" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionOrdenes;
                    cin.ignore();

                    switch (opcionOrdenes) {
                        case 1:
                            emitirOrdenDeCompra();
                            break;
                        case 2:
                            cancelarOdenDeCompra();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionOrdenes != 0);

                break;
            }

            case 4: {
                int opcionReportes;

                do {
                    cout << "\n--- REPORTES ---\n";
                    cout << "1. Consultar stock" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionReportes;
                    cin.ignore();

                    switch (opcionReportes) {
                        case 1:
                            consultarStock();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionReportes != 0);

                break;
            }

            case 5: {
                int opcionInfo;

                do {
                    cout << "\n--- INFORMACION DE PRODUCTO ---\n";
                    cout << "1. Consultar informacion detallada de producto" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionInfo;
                    cin.ignore();

                    switch (opcionInfo) {
                        case 1:
                            consultarInfoDetalladaProducto();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionInfo != 0);

                break;
            }

            case 0:
                cerrarSesion();
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
        }

    } while (opcion != 0);
}


//Funciones

void MenuEmpleado::altaClienteRegistrado() {
    string nombreCompleto, direccion, correo, password;
    int rut;
        cout << "\n======================================\n";
        cout << "====== REGISTRAR NUEVO CLIENTE =======";
        cout << "\n======================================\n";
    while(true) {
        cout << "Ingrese RUT: "<< endl; cin >> rut;
        cin.ignore();

        try {
            empleadoCtrl->validarRutCliente(rut);
        }
        catch (int error) {
            cout << "--- --- Ya existe un cliente con ese RUT, ingrese los datos nuevamente --- ---\n";
            continue;
        }
        break;
    }
        cout << "Ingrese nombre completo: "<< endl; getline(cin, nombreCompleto);
        cout << "Ingrese dirección: "<< endl; getline(cin, direccion);
    while(true) {
        cout << "Ingrese correo electrónico: ";
        getline(cin, correo);

    try {
        empleadoCtrl->validarCorreoCliente(correo);
        break;
    }
    catch (int error) {
        cout << "--- --- Ya existe un cliente con ese correo, ingrese el correo nuevamente --- ---\n";
    }
}
    cout << "Ingrese contraseña: "<< endl; getline(cin, password);

    cout << "\n--------------------------------------\n";
    cout << "==== RESUMEN DE DATOS DEL CLIENTE ====";
    cout << "\n--------------------------------------\n";

    cout << "RUT:" << rut << endl;
    cout << "Nombre completo:" << nombreCompleto << endl;
    cout << "Dirección:" << direccion << endl;
    cout << "Correo electrónico:" << correo << endl;
    cout << "Contraseña:" << password << endl;
    
    string confirmacion;
    while (true) { 
        cout << "\n¿Desea confirmar el alta de este cliente?(si/no)\n";
        cin >> confirmacion;  
        cin.ignore();
       
    if(confirmacion == "si") {
        empleadoCtrl->altaClienteRegistrado(rut, nombreCompleto, direccion, correo, password);
        
        cout << "\n------------------------------------------\n";
        cout << "==== CLIENTE REGISTRADO CORRECTAMENTE ====";
        cout << "\n------------------------------------------\n\n";
        return;
    } 
    if (confirmacion == "no") {
        cout << "\n == == Alta de cliente cancelada == ==\n\n";
        return;
    } else {
        cout << "Opcion inválida, Intente de nuevo\n";
    }
    }
}

void MenuEmpleado::modificarClienteRegistrado() {
    string nombreCompleto, direccion, correo, password;
    int rut;
    cout << "\n===========================================\n";
    cout << "====== MODIFICAR CLIENTE REGISTRADO =======";
    cout << "\n===========================================\n";

    cout << "Ingrese RUT de cliente a modificar:";
    cin >> rut;
    cin.ignore();
    ClienteRegistrado* cliente = empleadoCtrl->buscarCliente(rut);
    if(!cliente) {
        cout << "\n--- --- No existe un cliente con ese RUT --- ---\n\n";
    } else {
        cout << "\n------------------------------------\n";
        cout << "==== DATOS ACTUALES DEL CLIENTE ====";
        cout << "\n------------------------------------\n";

        cout << "RUT:" << cliente->getRut() << endl;
        cout << "Nombre completo:" << cliente->getNombreCompleto() << endl;
        cout << "Dirección:" << cliente->getDireccion() << endl;
        cout << "Correo electrónico:" << cliente->getCorreo() << endl;
        cout << "Contraseña:" << cliente->getPassword() << endl;

        cout << "\n=== === MODIFICAR CLIENTE === ===\n";
        cout << "\n(Deje el campo vacío y presione Enter para mantener el valor actual)\n";
        cout << "Ingrese nuevo nombre completo: "<< endl; getline(cin, nombreCompleto);
        cout << "Ingrese nueva dirección: "<< endl; getline(cin, direccion);
        while (true) {
            cout << "Ingrese nuevo correo: "<< endl; getline(cin, correo);
            try {
                empleadoCtrl->validarCorreoCliente(correo);
            }
            catch (int error) {
                cout << "--- --- Ya existe un cliente con ese correo, ingrese los datos nuevamente --- ---\n";
                continue;
            }
            break;
        }
        cout << "Ingrese nueva contraseña: "<< endl; getline(cin, password);

        string confirmacion;
        while (true) { 
            cout << "\n¿Desea confirmar la modificación de este cliente?(si/no)\n";
            cin >> confirmacion;  
            cin.ignore();
       
        if(confirmacion == "si") {
            empleadoCtrl->modificarClienteRegistrado(cliente, nombreCompleto, direccion, correo, password);
        
            cout << "\n------------------------------------------\n";
            cout << "==== CLIENTE MODIFICADO CORRECTAMENTE ====";
            cout << "\n------------------------------------------\n\n";

            return;
        } 
        if (confirmacion == "no") {
            cout << "\n == == Modificación cancelada == ==\n\n";
            return;
        } else {
            cout << "Opcion invalida, Intente de nuevo\n";
        }
    }
    }
}

//CONSULTAR INFO DETALLADA PRODUCTO
void MenuEmpleado::consultarInfoDetalladaProducto() {
    string nombre, codigoProducto, descripcion;
    int cantVendidas, estaEnStock;
    float precioUnitario, puntajePromedio;
    Categoria* categoria;

    cout << "\n---CONSULTAR INFO DETALLADA PRODUCTO---\n";

    cout<<"Ingrese codigo del producto: ";
    cin >> codigoProducto;

    try {
        Producto* producto = empleadoCtrl->consultarInfoDetalladaProducto(codigoProducto);

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

void MenuEmpleado::registrarVenta() { }
void MenuEmpleado::consultarHistorialDeCompras() { }
void MenuEmpleado::emitirOrdenDeCompra() { }
void MenuEmpleado::cancelarOdenDeCompra() { }


void::MenuEmpleado::consultarStock() {
    empleadoCtrl->consultarStock();
}

void MenuEmpleado::cerrarSesion() {
    empleadoCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}
