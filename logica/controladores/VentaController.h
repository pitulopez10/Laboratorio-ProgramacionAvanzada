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

    ClienteRegistrado* iniciarSesion(string correo, string password);
    void cerrarSesion();

    //FUNCIONES AUXILIARES REGISTRAR VENTA
    void agregarVenta(Venta* v);
    void agregarLineaTemporal(Producto* Producto, int cantidad);
    void limpiarLineasTemporales();
    string generarIdVenta();
    float calcularTotal(vector<LineaDeDetalle*> lineas);    
    
    //FUNCIONES AUXILIARES HISTORIAL CLIENTE
    vector<Venta*> obtenerVentasCliente(ClienteRegistrado* cliente);
    static bool compararVentas(Venta* v1, Venta* v2);
    void ordenarVentasPorFecha(vector<Venta*>& ventas);

    //GETTERS
    vector<LineaDeDetalle*> getLineasTemp();

    void validarCompra(int rut, string codigoProducto);
    vector<Venta*> listarVentas();
    void consultarStock();

    void calificarProducto(int rut, string codigoProducto, int puntaje, string comentario, DTFecha fecha);  //Caso uso 19
    Producto* consultarInfoDetalladaProducto(string codigoProducto);   //Caso uso 25
};

#endif //LABORATORIO3_VENTACONTROLLER_H
