#ifndef LABORATORIO3_MENUPRINCIPAL_H
#define LABORATORIO3_MENUPRINCIPAL_H
#include "../logica/controladores/EmpleadoController.h"
#include "../logica/controladores/AdminController.h"
#include "../logica/controladores/VentaController.h"

#include <string>
using namespace std;

class MenuPrincipal {
    private:
    AdminController* adminCtrl;
    EmpleadoController* empleadoCtrl;
    VentaController* ventaCtrl;
    public:
        MenuPrincipal(AdminController* adminCtrl,
                  EmpleadoController* empleadoCtrl,
                  VentaController* ventaCtrl);
        void mostrar();
};

#endif


