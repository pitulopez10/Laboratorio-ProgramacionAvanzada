#include "logica/controladores/AdminController.h"
#include "logica/controladores/EmpleadoController.h"
#include "logica/controladores/VentaController.h"
#include "vista/MenuPrincipal.h"

int main() {
    AdminController adminCtrl;

    EmpleadoController empleadoCtrl(adminCtrl);

    VentaController ventaCtrl;

    MenuPrincipal menuPrincipal(adminCtrl, empleadoCtrl, ventaCtrl);

    menuPrincipal.mostrar();

    return 0;
}