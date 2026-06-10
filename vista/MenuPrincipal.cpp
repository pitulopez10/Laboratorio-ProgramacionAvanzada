#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuEmpleado.h"
#include "MenuCliente.h"

#include <iostream>

using namespace std;

MenuPrincipal::MenuPrincipal(AdminController& adminController,
                             EmpleadoController& empleadoController,
                             VentaController& ventaController)
    : adminController(adminController),
      empleadoController(empleadoController),
      ventaController(ventaController) {
}

void MenuPrincipal::mostrar() {
    int opcion;

    do {
        cout << "\n============================\n";
        cout << " Sistema Stock y Ventas\n";
        cout << "============================\n";
        cout << "1. Iniciar sesion como Administrador\n";
        cout << "2. Iniciar sesion como Empleado\n";
        cout << "3. Iniciar sesion como Cliente\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                MenuAdministrador menuAdministrador(adminController);
                menuAdministrador.mostrar();
                break;
            }
            case 2: {
                MenuEmpleado menuEmpleado(&empleadoController);
                menuEmpleado.mostrar();
                break;
            }
            case 3: {
                MenuCliente menuCliente(&ventaController);
                menuCliente.mostrar();
                break;
            }
            case 0:
                cout << "Hasta luego.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 0);
}