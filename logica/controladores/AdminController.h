//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_ADMINCONTROLLER_H
#define LABORATORIO3_ADMINCONTROLLER_H
#include <vector>
#include <iostream>
#include <string>
#include "../dominio/Producto.h"
#include "../dominio/Categoria.h"
#include "../dominio/Proveedor.h"

using namespace std;


class AdminController {
private:
    vector<Producto*> produtos;
    vector<Categoria*> categorias;
    vector<Proveedor*> proveedores;
public:
    AdminController();
    ~AdminController();

    void agregarProducto(string codigo, string nombre, string descripcion,
            float precioUnitario, int cantVendidas, int estaEnStock);

    void agregarCategoria(string codigo, string descripcion);

    void agregarProveedor(int rut, string nombre, string telContacto,
            string nombreContacto, int tiempoEntrega);

    vector<Producto*> listarProductos();
    vector<Categoria*> listarCategorias();
    vector<Proveedor*> listarProveedores();

};



#endif //LABORATORIO3_ADMINCONTROLLER_H
