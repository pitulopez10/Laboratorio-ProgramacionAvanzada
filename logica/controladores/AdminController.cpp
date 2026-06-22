//
// Created by facuw on 3/6/2026.
//

#include "AdminController.h"
AdminController* AdminController::instancia = NULL;




//CONTROLADORES E INTANCIA
AdminController::~AdminController() {

}

AdminController::AdminController() {
    administradores.push_back(new Admin("Carlos Perez", "Montevideo 234", "carlosadmin@gmail.com"));
    empleados.push_back(new Empleado("Maria Rodriguez", "18 de Julio 429", "mariaempleado@gmail.com"));
    adminLogeado = NULL;
}

AdminController*  AdminController::getInstancia() {
    if (instancia != NULL) {
        return instancia;
    }
    else {
        instancia = new AdminController();
        return instancia;
    }
}

//INICIO DE SESION
Admin* AdminController::iniciarSesion(string correo) {
    for (int i = 0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            adminLogeado = administradores[i];
            return administradores[i];
        }
    }
    return NULL;
}

//CIERRE DE SESION
void AdminController::cerrarSesion() {
    adminLogeado = NULL;
}

//FUNCIONES DE AGREGAR
void AdminController::altaEmpleado(string nombreCompleto, string direccion, string correo) {
    for (int i =0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            throw 1;
        }
    }

    Empleado* empleado = new Empleado(nombreCompleto, direccion, correo);
    empleados.push_back(empleado);
}

void AdminController::agregarCategoria(string nombre, string descripcion) {
    for (int i =0; i < categorias.size(); i++) {
        if (categorias[i]->getNombre() == descripcion) {
            throw 1;
        }
    }

    Categoria* categoria = new Categoria(nombre, descripcion);
    categorias.push_back(categoria);
}

void AdminController::modificarCategoria(string nombreActual, string nuevoNuombre, string nuevaDescripcion) {
    Categoria* categoria = NULL;

    for (int i =0; i < categorias.size(); i++) {
        if (categorias[i]->getNombre() == nombreActual) {
            categoria = categorias[i];
        }
    }
    if (categoria == NULL) {
        throw 1;
    }

    for (int i =0; i < categorias.size(); i++) {
        if (categorias[i]->getNombre() == nuevoNuombre && categorias[i] != categoria) {
            throw 2;
        }
    }
    categoria->setNombre(nuevoNuombre);
    categoria->setDescripcion(nuevaDescripcion);
}

void AdminController::agregarProducto(string nombre, string codigo, string descripcion, float precioUnitario, int estaEnStock, string nombreCategoria) {
    for (int i =0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigo) {
            throw 1;
        }
    }
    if (precioUnitario < 0) {
        throw 2;
    }
    if (estaEnStock < 0) {
        throw 3;
    }
    Categoria* categoria = NULL;
    for (int i =0; i < categorias.size(); i++) {
        if (categorias[i]->getNombre() == nombreCategoria) {
            categoria = categorias[i];
        }
    }
    if (categoria == NULL) {
        throw 4;
    }

    Producto* producto =  new Producto(nombre, codigo, descripcion, precioUnitario, 0, 0, estaEnStock, categoria);
    productos.push_back(producto);
}

void AdminController::modificarProducto(string codigo, string nuevoNombre, string nuevaDescripcion, float nuevoPrecioUnitario, int nuevoStock, string nuevaCategoria) {
    Producto* producto = NULL;
    for (int i =0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigo) {
            producto = productos[i];
        }
    }

    if (producto == NULL) {
        throw 1;
    }
    if (nuevoPrecioUnitario < 0) {
        throw 2;
    }
    if (nuevoStock < 0) {
        throw 3;
    }
    Categoria* categoria = NULL;

    for (int i =0; i < categorias.size(); i++) {
        if (categorias[i]->getNombre() == nuevaCategoria) {
            categoria = categorias[i];
        }
    }
    if (categoria == NULL) {
        throw 4;
    }
    producto->setNombre(nuevoNombre);
    producto->setDescripcion(nuevaDescripcion);
    producto->setPrecioUnitario(nuevoPrecioUnitario);
    producto->setEstaEnStock(nuevoStock);
    producto->setCategoria(categoria);
}

void AdminController::eliminarProducto(string codigo) {

    Producto* producto = NULL;

    for (int i =0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigo) {
            producto = productos[i];
        }
    }

    if (producto == NULL) {
        throw 1;
    }
    if (producto->getCantVendidas() > 0) {
        throw 2;
    }
    for(int i = 0; i < ordenesCompra.size(); i++) {
        if(ordenesCompra[i]->getEstado() == PENDIENTE) {
            vector<LineaDeCompra*> lineas = ordenesCompra[i]->getLineasCompra();
            for(int j = 0; j < lineas.size(); j++) {
                if(lineas[j]->getProducto()->getCodigo() == codigo) {
                    throw 3;
                }
            }
        }
    }

    for(int i = 0; i < productos.size(); i++) {
        if(productos[i] == producto) {
            productos.erase(productos.begin() + i);
            delete producto;
            return;
        }
    }
}


void AdminController::agregarProveedor(int rut, string nombre, string telContacto, string nombreContacto, int tiempoEntrega) {

}

bool AdminController::agregarOrdenCompra(OrdenDeCompra* ordenesCompra) {

}

//FUNCIONES DE LISTAR
vector<Empleado*> AdminController::listarEmpleados() {
    return empleados;
}

vector<Categoria*> AdminController::listarCategorias() {
    return categorias;
}


vector<Producto*> AdminController::listarProductos() {
    return productos;
}



vector<Proveedor*> AdminController::listarProveedores() {

}

vector<OrdenDeCompra*> AdminController::crearOrdenCompra() {

}