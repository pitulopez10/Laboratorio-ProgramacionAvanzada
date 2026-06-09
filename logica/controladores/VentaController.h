#ifndef LABORATORIO3_VENTACONTROLLER_H
#define LABORATORIO3_VENTACONTROLLER_H

#include <vector>
#include <string>

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"

using namespace std;

class VentaController {
private:
    vector<Venta*> ventas;

public:
    VentaController();

    void nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);
    vector<Venta*> listarVentas();
    void consultarStock();
    void calificarProducto(int rut, string codigoProducto, int puntaje, string comentario);
};

#endif //LABORATORIO3_VENTACONTROLLER_H
