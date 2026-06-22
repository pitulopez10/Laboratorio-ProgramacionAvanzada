#ifndef LABORATORIO3_VENTACONTROLLER_H
#define LABORATORIO3_VENTACONTROLLER_H

#include <vector>
#include <string>

#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Cliente.h"
#include "../dominio/Categoria.h"
using namespace std;

class ClienteRegistrado;

class VentaController {
private:
    vector<Venta*> ventas;
    vector<ClienteRegistrado*> clientesRegistrados;
    vector<LineaDeDetalle*> lineas;
    vector<Categoria*> categorias;
    static VentaController* instancia;

    VentaController();

public:
    static VentaController* getInstancia();
    Venta* clienteLogeado;

    ClienteRegistrado* iniciarSesion(string correo);
    void cerrarSesion();

    void nuevaVenta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);
    vector<Venta*> listarVentas();
    void consultarStock();

    void consultarHistorialDeCompras(int rut, string codigoProducto);
    void calificarProducto(int rut, string codigoProducto, int puntaje, string comentario, DTFecha fecha);  //Caso uso 19
    Producto* consultarInfoDetalladaProducto(string codigoProducto);   //Caso uso 25

};

#endif //LABORATORIO3_VENTACONTROLLER_H
