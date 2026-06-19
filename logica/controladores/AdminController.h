//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_ADMINCONTROLLER_H
#define LABORATORIO3_ADMINCONTROLLER_H
#include <vector>
#include <string>
#include "../dominio/Producto.h"
#include "../dominio/Categoria.h"
#include "../dominio/Proveedor.h"
#include "../dominio/OrdenDeCompra.h"
#include "../dominio/Admin.h"

using namespace std;

class OrdenDeCompra;

class AdminController {
private:
    vector<Producto*> productos;
    vector<Categoria*> categorias;
    vector<Proveedor*> proveedores;
    vector<OrdenDeCompra*> ordenesCompra;
    vector<Admin*> administradores;

    static AdminController* instancia;

public:
    AdminController();
    ~AdminController();
    static AdminController* getInstancia();

    Admin* iniciarSesion(string correo);

    void agregarProducto(string codigo, string nombre, string descripcion,
            float precioUnitario, int cantVendidas, int estaEnStock);

    void agregarCategoria(string codigo, string descripcion);

    void agregarProveedor(int rut, string nombre, string telContacto,
            string nombreContacto, int tiempoEntrega);

    bool agregarOrdenCompra(OrdenDeCompra* ordenesCompra);

    vector<Producto*> listarProductos();
    vector<Categoria*> listarCategorias();
    vector<Proveedor*> listarProveedores();
    vector<OrdenDeCompra*> crearOrdenCompra();
};



#endif //LABORATORIO3_ADMINCONTROLLER_H
