#include "logica/controladores/AdminController.h"
#include "logica/controladores/EmpleadoController.h"
#include "logica/controladores/VentaController.h"
#include "vista/MenuPrincipal.h"

int main() {
    AdminController* adminCtrl = AdminController::getInstancia();
    EmpleadoController* empleadoCtrl = EmpleadoController::getInstancia();
    VentaController* ventaCtrl = VentaController::getInstancia();

    MenuPrincipal menu(adminCtrl, empleadoCtrl, ventaCtrl);
    menu.mostrar();

    return 0;
}