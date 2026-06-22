#ifndef LABORATORIO3_MENUCLIENTE_H
#define LABORATORIO3_MENUCLIENTE_H

#include "../logica/controladores/VentaController.h"

#include <string>
using namespace std;

class MenuCliente {
private:
    VentaController* ventaCtrl;

public:
    MenuCliente(VentaController* controller);
    void mostrar();

    void cerrarSesion();

    void calificarProducto();

    void consultarInfoDetalladaProducto();
};
#endif
