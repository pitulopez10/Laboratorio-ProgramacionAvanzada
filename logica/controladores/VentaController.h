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
    vector<LineaDeDetalle*> lineas;
    static VentaController* instancia;

    VentaController();

public:
    static VentaController* getInstancia();
    Venta* clienteLogeado;

    void cerrarSesion();

    void nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);
    vector<Venta*> listarVentas();
    void consultarStock();

    void verificarCompra(int rut, string codigoProducto);
    void calificarProducto(int rut, string codigoProducto, int puntaje, string comentario, DTFecha fecha);
    void consultarHistorialDeCompras(string rut);

    ClienteRegistrado* iniciarSesion(string correo);

};

#endif //LABORATORIO3_VENTACONTROLLER_H
