#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuEmpleado.h"
#include "MenuCliente.h"

#include <iostream>

using namespace std;

MenuPrincipal::MenuPrincipal(AdminController* adminCtrl,
                             EmpleadoController* empleadoCtrl,
                             VentaController* ventaCtrl) {
    this->adminCtrl = adminCtrl;
    this->empleadoCtrl = empleadoCtrl;
    this->ventaCtrl = ventaCtrl;
}

void MenuPrincipal::mostrar() {
    int opcion;

    AdminController* adminCtrl = AdminController::getInstancia();
    EmpleadoController* empleadoCtrl = EmpleadoController::getInstancia();
    VentaController* ventaCtrl = VentaController::getInstancia();

    do {
        cout << "\n============================\n";
        cout << " Sistema Stock y Ventas\n";
        cout << "     INICIAR SESION\n";
        cout << "============================\n";
        cout << "1. Ingresar correo" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string correo;
                cout << "Ingrese el correo: ";
                cin >> correo;
                if (adminCtrl->iniciarSesion(correo) != NULL) {
                    MenuAdministrador menuAdministrador(adminCtrl);
                    menuAdministrador.mostrar();
                    break;
                }
                else if (empleadoCtrl->iniciarSesion(correo) != NULL) {
                    MenuEmpleado menuEmpleado(empleadoCtrl);
                    menuEmpleado.mostrar();
                    break;
                }
                else if (ventaCtrl->iniciarSesion(correo) != NULL) {
                    MenuCliente menuCliente(ventaCtrl);
                    menuCliente.mostrar();
                    break;
                }
                else {
                    cout << "Correo no encontrado" << endl;
                }
            }
            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (opcion != 0);
}