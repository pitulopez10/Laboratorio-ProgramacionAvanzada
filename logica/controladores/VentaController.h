#ifndef LABORATORIO3_VENTACONTROLLER_H
#define LABORATORIO3_VENTACONTROLLER_H

#include <vector>
#include <string>

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Cliente.h"
using namespace std;

class ClienteRegistrado;

class VentaController {
private:
    vector<Venta*> ventas;
    vector<ClienteRegistrado*> clientesRegistrados;
    static VentaController* instancia;

    VentaController();

public:
    static VentaController* getInstancia();

    void nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);
    vector<Venta*> listarVentas();
    void consultarStock();
    void calificarProducto(int rut, string codigoProducto, int puntaje, string comentario);
    void consultarHistorialDeCompras(string rut);

    ClienteRegistrado* iniciarSesion(string correo);

};

#endif //LABORATORIO3_VENTACONTROLLER_H
