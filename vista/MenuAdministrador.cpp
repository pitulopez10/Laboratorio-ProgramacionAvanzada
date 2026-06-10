//
// Created by facuw on 3/6/2026.
//

#include "../vista/MenuAdministrador.h"
#include <limits>
#include <vector>
#include "string"
#include "iostream"

using namespace std;

#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(AdminController& adminController) : adminCtrl(adminCtrl) {

}

void MenuAdministrador::mostrar() {
    int opcion;

    do {
        cout << "\n===== MENU ADMINISTRADOR =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Agregar categoria\n";
        cout << "3. Agregar proveedor\n";
        cout << "4. Listar productos\n";
        cout << "5. Listar categorias\n";
        cout << "6. Listar proveedores\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                agregarCategoria();
                break;
            case 3:
                agregarProveedor();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                listarCategorias();
                break;
            case 6:
                listarProveedores();
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    }while(opcion != 0);
}

//Funciones para agregar.
void MenuAdministrador::agregarProducto() {
    string codigo, nombre, descripcion;
    float precioUnitario;
    int cantVendidas, estaEnStock;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n---AGREGAR PRODUCTO---\n";

    cout << "Codigo: "<< endl;
    getline(cin, codigo);

    cout << "Nombre: "<< endl;
    getline(cin, nombre);

    cout << "Descripcion: "<< endl;
    getline(cin, descripcion);

    cout << "Precio Unitario: "<< endl;
    cin >> precioUnitario;

    cout << "Cantidad de Vendidas: "<< endl;
    cin >> cantVendidas;

    cout << "Cantidad en Stock: " << endl;
    cin >> estaEnStock;

    adminCtrl.agregarProducto(codigo, nombre, descripcion, precioUnitario, cantVendidas, estaEnStock);
    cout << "\n---Producto agregado correctamente---\n";
}

void MenuAdministrador::agregarCategoria() {
    string nombre, descripcion;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n---AGREGAR CATEGORIA---\n";

    cout << "Nombre: "<< endl;
    getline(cin, nombre);

    cout << "Descripcion: "<< endl;
    getline(cin, descripcion);

    adminCtrl.agregarCategoria(nombre, descripcion);
    cout << "\n---Categoria agregado correctamente---\n";
}

void MenuAdministrador::agregarProveedor() {
    int rut, tiempoEntrega;
    string nombre, telContacto, nombreContacto;

    cout << "\n---AGREGAR PROVEEDOR---\n";

    cout << "Rut: "<< endl;
    cin >> rut;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: "<< endl;
    getline(cin, nombre);

    cout << "Telefono de Contacto: "<< endl;
    getline(cin, telContacto);

    cout << "Nombre de Contacto: "<< endl;
    getline(cin, nombreContacto);

    cout << "Tiempo de entrega: "<< endl;
    cin >> tiempoEntrega;

    adminCtrl.agregarProveedor(rut, nombre, telContacto, nombreContacto, tiempoEntrega);
    cout << "\n---Proveedor agregado correctamente---\n";
}

//Funciones para listar,
void MenuAdministrador::listarProductos() {
    vector<Producto*> productos = adminCtrl.listarProductos();

    cout << "\n--- LISTA DE PRODUCTOS ---\n";

    if (productos.empty()) {
        cout << "No hay productos cargados.\n";
        return;
    }

    for (int i = 0; i < productos.size(); i++) {
        cout << "Codigo: " << productos[i]->getCodigo() << endl;
        cout << "Nombre: " << productos[i]->getNombre() << endl;
        cout << "Descripcion: " << productos[i]->getDescripcion() << endl;
        cout << "Precio unitario: " << productos[i]->getPrecioUnitario() << endl;
        cout << "Cantidad vendidas: " << productos[i]->getCantVendidas() << endl;
        cout << "Stock: " << productos[i]->getEstaEnStock() << endl;
        cout << "-----------------------------\n";
    }
}

void MenuAdministrador::listarCategorias() {
    vector<Categoria*> categorias = adminCtrl.listarCategorias();

    cout << "\n--- LISTA DE CATEGORIAS ---\n";

    if (categorias.empty()) {
        cout << "No hay categorias cargadas.\n";
        return;
    }

    for (int i = 0; i < categorias.size(); i++) {
        cout << "Nombre: " << categorias[i]->getNombre() << endl;
        cout << "Descripcion: " << categorias[i]->getDescripcion() << endl;
        cout << "-----------------------------\n";
    }
}

void MenuAdministrador::listarProveedores() {
    vector<Proveedor*> proveedores = adminCtrl.listarProveedores();

    cout << "\n--- LISTA DE PROVEEDORES ---\n";

    if (proveedores.empty()) {
        cout << "No hay proveedores cargados.\n";
        return;
    }

    for (int i = 0; i < proveedores.size(); i++) {
        cout << "RUT: " << proveedores[i]->getRut() << endl;
        cout << "Nombre: " << proveedores[i]->getNombre() << endl;
        cout << "Telefono contacto: " << proveedores[i]->getTelContacto() << endl;
        cout << "Nombre contacto: " << proveedores[i]->getNombreContacto() << endl;
        cout << "Tiempo entrega: " << proveedores[i]->getTiempoEntrega() << endl;
        cout << "-----------------------------\n";
    }
}