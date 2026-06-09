#ifndef LABORATORIO3_MENUCLIENTE_H
#define LABORATORIO3_MENUCLIENTE_H

#include "../logica/controladores/VentaController.h"

#include <string>
using namespace std;

class MenuCliente {
private:
    VentaController* controller;

public:
    MenuCliente(VentaController* controller);
    void mostrar();
};
#endif
