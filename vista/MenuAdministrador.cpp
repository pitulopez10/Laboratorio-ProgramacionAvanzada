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

MenuAdministrador::MenuAdministrador(AdminController* adminCtrl) {
    this->adminCtrl = adminCtrl;
}
//MENU DEL ADMIN
void MenuAdministrador::mostrar() {
    int opcion;
    bool salir = false;

    do {
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout<<"|      MENU ADMINISTRADOR     |"<<endl;
        cout<<"=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!="<<endl;
        cout << "1. Alta empleado\n";
        cout << "2. Listar empleados\n";
        cout << "3. Agregar categoria\n";
        cout << "4. Listar categorias\n";
        cout << "5. Modificar categoria\n";
        cout << "6. Agregar Producto\n";
        cout << "7. Modificar Producto\n";
        cout << "0. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                altaEmpleado();
                break;
            case 2:
                listarEmpleados();
                break;
            case 3:
                agregarCategoria();
                break;
            case 4:
                listarCategorias();
                break;
            case 5:
                modificarCategoria();
                break;
            case 6:
                agregarProducto();
                break;
            case 7:
                modificarProducto();
                break;
            case 0:
                cerrarSesion();
                salir = true;
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    }while(opcion != 0);
}

//CERRAR SESION
void MenuAdministrador::cerrarSesion() {
    adminCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}


//FUNCIONES DE AGREGAR
void MenuAdministrador::altaEmpleado() {
    string nombreCompleto, direccion, correo;

    cout << "\n---ALTA-EMPLEADO---\n";

    cout << "Ingrese nombre completo: "<< endl;
    cin.ignore();
    getline(cin, nombreCompleto);

    cout << "Ingrese direccion: "<< endl;
    getline(cin,direccion);

    cout << "Ingrese correo: "<< endl;
    getline(cin,correo);

    try {
        adminCtrl->altaEmpleado(nombreCompleto,direccion,correo);
        cout << "Empledo agregado correctamente." << endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "Ya existe un empleado con ese correo.";
        }
    }
}

void MenuAdministrador::agregarCategoria() {
    string nombre, descripcion;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n---AGREGAR CATEGORIA---\n";

    cout << "Ingrese nombre: "<< endl;
    getline(cin, nombre);

    cout << "Ingrese descripcion: "<< endl;
    getline(cin, descripcion);

    try {
        adminCtrl->agregarCategoria(nombre, descripcion);
        cout << "\nCategoria agregado correctamente\n";
    }catch (int error) {
        if (error == 1) {
            cout << "Ya existe una categoria con ese nombre." << endl;
        }
    }
}

void MenuAdministrador::modificarCategoria() {
    string nombreActual, nuevoNombre, nuevaDescripcion;

    cout << "\n---MODIFICAR CATEGORIA---\n";

    cin.ignore();

    cout << "Ingrese nombre actual: "<< endl;
    getline(cin, nombreActual);

    cout << "Ingrese nuevo nombre: ";
    getline(cin, nuevoNombre);

    cout << "Ingrese nueva descripcion: ";
    getline(cin, nuevaDescripcion);

    try {
        adminCtrl->modificarCategoria(nombreActual,nuevoNombre,nuevaDescripcion);
        cout << "\nCategoria modificada correctamente\n";
    }
    catch (int error) {
        if (error == 1) {
            cout << "La categoria no existe." << endl;
        }
        if (error == 2) {
            cout << "Ya existe una categoria con ese nombre" << endl;
        }
    }
}

void MenuAdministrador::agregarProducto() {

    string nombre, codigo, descripcion, nombreCategoria;
    float precioUnitario;
    int estaEnStock;

    cout << "\n---AGREGAR PRODUCTO---\n";

    cin.ignore();
    cout << "Nombre del producto: ";
    getline(cin, nombre);

    cout << "Codigo del producto: ";
    getline(cin, codigo);

    cout << "Descripcion del producto: ";
    getline(cin, descripcion);

    cout << "Precio unitario: ";
    cin >> precioUnitario;

    cout << "Stock inicial: ";
    cin >> estaEnStock;
    cin.ignore();

    cout << "Nombre de la categoria: ";
    getline(cin, nombreCategoria);

    try {
        adminCtrl->agregarProducto(nombre,codigo,descripcion,precioUnitario,estaEnStock,nombreCategoria);
        cout << "Producto agregado correctamente." << endl;
    }
    catch(int error) {
        if(error == 1) {
            cout << "Ya existe un producto con ese codigo." << endl;
        }
        else if(error == 2) {
            cout << "El precio no puede ser negativo." << endl;
        }
        else if(error == 3) {
            cout << "El stock no puede ser negativo." << endl;
        }
        else if(error == 4) {
            cout << "La categoria ingresada no existe." << endl;
        }
    }
}

void MenuAdministrador::modificarProducto() {
    string codigo, nuevoNombre, nuevaDescripcion, nuevaCategoria;
    float nuevoPrecioUnitario;
    int nuevoStock;

    cout << "\n---MODIFICAR PRODUCTO---\n";
    cin.ignore();

    cout << "Ingrese codigo del producto a modificar: " << endl;
    getline(cin, codigo);

    cout << "Ingrese nuevo nombre: " << endl;
    getline(cin, nuevoNombre);

    cout << "Ingrese nueva descripcion: " << endl;
    getline(cin, nuevaDescripcion);

    cout << "Ingrese nuevo precio unitario: " << endl;
    cin >> nuevoPrecioUnitario;

    cout << "Ingrese nuevo stock: " << endl;
    cin >> nuevoStock;

    cout << "Ingrese nueva categoria: " << endl;
    getline(cin, nuevaCategoria);

    try {
        adminCtrl->modificarProducto(codigo, nuevoNombre, nuevaDescripcion, nuevoPrecioUnitario, nuevoStock, nuevaCategoria);
        cout << "Producto modificado correctamente." << endl;
    }
    catch(int error) {
        if(error == 1) {
            cout << "No existe un producto con ese codigo." << endl;
        }
        else if(error == 2) {
            cout << "El precio no puede ser negativo." << endl;
        }
        else if(error == 3) {
            cout << "El stock no puede ser negativo." << endl;
        }
        else if(error == 4) {
            cout << "La categoria ingresada no existe." << endl;
        }
    }
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

    adminCtrl->agregarProveedor(rut, nombre, telContacto, nombreContacto, tiempoEntrega);
    cout << "\n---Proveedor agregado correctamente---\n";
}

//FUNCIONES DE LISTAR
void MenuAdministrador::listarEmpleados() {
    vector<Empleado*> empleados = adminCtrl->listarEmpleados();

    if (empleados.size() == 0) {
        cout << "No hay empleados registrados. " << endl;
        return;
    }

    cout << "\n---LISTA DE EMPLEADOS---\n";

    for (int i = 0; i < empleados.size(); i++) {
        cout << "Empleado #" << i+1 << endl;
        cout << "Nombre completo: " << empleados[i]->getNombreCompleto() << endl;
        cout << "Descripcion: " << empleados[i]->getDireccion() << endl;
        cout << "Correo: " << empleados[i]->getCorreo() << endl;
        cout << "------------------------" << endl;
    }
}

void MenuAdministrador::listarCategorias() {
    vector<Categoria*> categorias = adminCtrl->listarCategorias();

    cout << "\n--- LISTA DE CATEGORIAS ---\n";

    if (categorias.size() == 0) {
        cout << "No hay categorias registradas. " << endl;
        return;
    }

    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categoria #" << i+1 << endl;
        cout << "Nombre: " << categorias[i]->getNombre() << endl;
        cout << "Descripcion: " << categorias[i]->getDescripcion() << endl;
        cout << "-----------------------------\n";
    }
}

void MenuAdministrador::listarProductos() {
    vector<Producto*> productos = adminCtrl->listarProductos();

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



void MenuAdministrador::listarProveedores() {
    vector<Proveedor*> proveedores = adminCtrl->listarProveedores();

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