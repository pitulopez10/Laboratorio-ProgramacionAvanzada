//
// Created by facuw on 3/6/2026.
//

#include "AdminController.h"
AdminController* AdminController::instancia = NULL;




//CONTROLADORES E INTANCIA
AdminController::~AdminController() {

}

AdminController::AdminController() {
    administradores.push_back(new Admin("Carlos Perez", "Montevideo 234", "carlosadmin@gmail.com", "1234"));
    empleados.push_back(new Empleado("Maria Rodriguez", "18 de Julio 429", "mariaempleado@gmail.com", "1234"));
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
Admin* AdminController::iniciarSesion(string correo, string password) {
    for (int i = 0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo && administradores[i]->getPassword() == password) {
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
void AdminController::altaEmpleado(string nombreCompleto, string direccion, string correo, string password) {
    for (int i =0; i < administradores.size(); i++) {
        if (administradores[i]->getCorreo() == correo) {
            throw 1;
        }
    }

    Empleado* empleado = new Empleado(nombreCompleto, direccion, correo, password);
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

void AdminController::agregarProducto(string nombre, string codigo, string descripcion, float precioUnitario, int estaEnStock, string nombreCategoria, int stockMinimo) {
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

    Producto* producto =  new Producto(nombre, codigo, descripcion, precioUnitario, 0, 0, estaEnStock, categoria, stockMinimo);
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

    for (int i = 0; i < productos.size(); i++) {
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
            
            vector<LineaOrden*> lineas = ordenesCompra[i]->getLineasOrden(); 
            
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

void AdminController::agregarProveedor(int rut, string nombre, string telContacto, string nombreContacto) {
    for (int i =0; i < proveedores.size(); i++) {
        if (proveedores[i]->getRut() == rut) {
            throw 1;
        }
    }
    Proveedor* proveedor = new Proveedor(rut, nombre, telContacto, nombreContacto);
    proveedores.push_back(proveedor);
}

Proveedor* AdminController::buscarProveedor(int rutBuscado) {
    for(Proveedor* p : proveedores) {
        if (p->getRut() == rutBuscado) {
            return p;
        }
    }
    return nullptr;
}

void AdminController::modificarProveedor(Proveedor* proveedor, string nombre, string telContacto, string nombreContacto) {
    if(nombre != "") {
        proveedor->setNombre(nombre);
    }
    if(telContacto != "") {
        proveedor->setTelContacto(telContacto);
    }    
    if(nombreContacto != "") {
        proveedor->setNombreContacto(nombreContacto);
    }
}

void AdminController::asociarProductoProveedor(int rutProveedor, string codigoProducto, float precioCompra, int tiempoEntrega) {
    
    Proveedor* proveedor = buscarProveedor(rutProveedor);
    if (proveedor == NULL) {
        throw 1;
    }

    Producto* productoEncontrado = NULL;
    for (Producto* p : productos) {
        if (p->getCodigo() == codigoProducto) {
            productoEncontrado = p;
            break;
        }
    }
    if (productoEncontrado == NULL) {
        throw 2;
    }
    if (proveedor->abasteceProducto(codigoProducto)) {
        throw 3;
    }

    proveedor->agregarProducto(productoEncontrado, precioCompra, tiempoEntrega);
}

void AdminController::actualizarAsociacion(int rutProveedor, string codigoProducto, float precioCompra, int tiempoEntrega) {
    
    Proveedor* proveedor = buscarProveedor(rutProveedor);

    proveedor->actualizarDatosProducto(codigoProducto, precioCompra, tiempoEntrega);
}

vector<Producto*> AdminController::listarProductosNoAsociados(int rutProveedor) {
    vector<Producto*> productosNoAsociados;
    
    Proveedor* proveedor = buscarProveedor(rutProveedor);
    if (proveedor == NULL) throw 2;
    
    vector<Producto*> todosLosProductos = listarProductos(); 
    for (Producto* p : todosLosProductos) {
        
        if (!proveedor->abasteceProducto(p->getCodigo())) {
            productosNoAsociados.push_back(p);
        }
    }
    return productosNoAsociados;
}

//FUNCION AUXILIAR
Producto* AdminController::buscarProducto(string codigo) {
    for (Producto* p : productos) {
        if (p->getCodigo() == codigo) {
            return p;
        }
    }
    return nullptr;
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
    return proveedores;
}

vector<OrdenDeCompra*> AdminController::listarOrdenesCompra() {
    return ordenesCompra;
}