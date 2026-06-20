//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_ADMINCONTROLLER_H
#define LABORATORIO3_ADMINCONTROLLER_H
#include <vector>
#include <string>
#include "../dominio/Empleado.h"
#include "../dominio/Producto.h"
#include "../dominio/Categoria.h"
#include "../dominio/Proveedor.h"
#include "../dominio/OrdenDeCompra.h"
#include "../dominio/Admin.h"

using namespace std;

class OrdenDeCompra;

class AdminController {
private:
    vector<Empleado*> empleados;
    vector<Producto*> productos;
    vector<Categoria*> categorias;
    vector<Proveedor*> proveedores;
    vector<OrdenDeCompra*> ordenesCompra;
    vector<Admin*> administradores;

    static AdminController* instancia;
    Admin* adminLogeado;

public:
    //CONTROLADORES E INSTANCIA
    AdminController();
    ~AdminController();
    static AdminController* getInstancia();

    //INICIO DE SESION
    Admin* iniciarSesion(string correo);

    //CIERRE DE SESION
    void cerrarSesion();

    //FUNCIONES DE AGREGAR
    void altaEmpleado(string nombreCompleto, string direccion, string correo);
    void agregarCategoria(string nombre, string descripcion);
    void modificarCategoria(string nombreActual, string nuevoNuombre, string nuevaDescripcion);
    void agregarProducto(string nombre, string codigo, string descripcion, float precioUnitario, int estaEnStock, string nombreCategoria);


    void agregarProveedor(int rut, string nombre, string telContacto,
                          string nombreContacto, int tiempoEntrega);

    bool agregarOrdenCompra(OrdenDeCompra* ordenesCompra);

    //FUNCIONES DE LISTAR
    vector<Empleado*> listarEmpleados();
    vector<Categoria*> listarCategorias();

    vector<Producto*> listarProductos();
    vector<Proveedor*> listarProveedores();
    vector<OrdenDeCompra*> crearOrdenCompra();
};



#endif //LABORATORIO3_ADMINCONTROLLER_H