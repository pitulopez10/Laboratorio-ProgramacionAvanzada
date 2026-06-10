#ifndef LABORATORIO3_MENUPRINCIPAL_H
#define LABORATORIO3_MENUPRINCIPAL_H
#include "../logica/controladores/EmpleadoController.h"
#include "../logica/controladores/AdminController.h"
#include "../logica/controladores/VentaController.h"

#include <string>
using namespace std;

class MenuPrincipal {
    private:
    AdminController& adminController;
    EmpleadoController& empleadoController;
    VentaController& ventaController;
    public:
    MenuPrincipal(AdminController& adminController,
           EmpleadoController& empleadoController,
           VentaController& ventaController);
        void mostrar();
};

#endif


