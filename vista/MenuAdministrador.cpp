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
#include "../logica/dominio/Calificacion.h"
#include "../logica/controladores/EmpleadoController.h"
#include "../logica/controladores/VentaController.h"

MenuAdministrador::MenuAdministrador(AdminController* adminCtrl) {
    this->adminCtrl = adminCtrl;
}
//MENU DEL ADMIN
void MenuAdministrador::mostrar() {
    int opcion;
    bool salir = false;
    do {
    cout << "\n========== MENU ADMINISTRADOR ==========\n";
    cout << "1. Gestion de empleados\n";
    cout << "2. Gestion de categorias\n";
    cout << "3. Gestion de productos\n";
    cout << "4. Gestion de proveedores\n";
    cout << "5. Calificaciones\n";
    cout << "6. Informacion de producto\n";
    cout << "7. Stock\n";
    cout << "8. Reportes\n";
    cout << "0. Cerrar sesion\n";
    cout << "Elegir opcion: ";
    cin >> opcion;
    switch(opcion) {
        case 1: {
            int opEmpleado;
            do {
                cin.ignore();
                cout << "\n--- GESTION DE EMPLEADOS ---\n";
                cout << "1. Alta empleado\n";
                cout << "2. Listar empleados\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opEmpleado;
                switch(opEmpleado) {
                    case 1:
                        altaEmpleado();
                        break;
                    case 2:
                        listarEmpleados();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opEmpleado != 0);
            break;
        }
        case 2: {
            int opCategoria;
            do {
                cin.ignore();
                cout << "\n--- GESTION DE CATEGORIAS ---\n";
                cout << "1. Agregar categoria\n";
                cout << "2. Modificar categoria\n";
                cout << "3. Listar categorias\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opCategoria;
                switch(opCategoria) {
                    case 1:
                        agregarCategoria();
                        break;
                    case 2:
                        modificarCategoria();
                        break;
                    case 3:
                        listarCategorias();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opCategoria != 0);
            break;
        }
        case 3: {
            int opProducto;
            do {
                cin.ignore();
                cout << "\n--- GESTION DE PRODUCTOS ---\n";
                cout << "1. Agregar producto\n";
                cout << "2. Modificar producto\n";
                cout << "3. Eliminar producto\n";
                cout << "4. Listar productos\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opProducto;
                switch(opProducto) {
                    case 1:
                        agregarProducto();
                        break;
                    case 2:
                        modificarProducto();
                        break;
                    case 3:
                        eliminarProducto();
                        break;
                    case 4:
                        listarProductos();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opProducto != 0);
            break;
        }
        case 4: {
            int opProveedor;
            do {
                cin.ignore();
                cout << "\n--- GESTION DE PROVEEDORES ---\n";
                cout << "1. Agregar proveedor\n";
                cout << "2. Listar proveedores\n";
                cout << "3. Modificar proveedor\n";
                cout << "4. Registrar combinacion proveedor-producto\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opProveedor;
                switch(opProveedor) {
                    case 1:
                        agregarProveedor();
                        break;
                    case 2:
                        listarProveedores();
                        break;
                    case 3:
                        modificarProveedor();
                        break;
                    case 4: 
                        registrarProveedorProducto();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opProveedor != 0);
            break;
        }
        case 5: {
            int opCalificacion;
            do {
                cin.ignore();
                cout << "\n--- CALIFICACIONES ---\n";
                cout << "1. Consultar calificaciones de producto\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opCalificacion;
                switch(opCalificacion) {
                    case 1:
                        consultarCalificacionesProducto();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opCalificacion != 0);
            break;
        }
        case 6: {
            int opInfoPro;
            do {
                cin.ignore();
                cout << "\n--- INFO DETALLADA DE PRODUCTO ---\n";
                cout << "1. Consultar informacion detallada de producto\n";
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opInfoPro;
                switch(opInfoPro) {
                    case 1:
                        consultarInfoDetalladaProducto();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opInfoPro != 0);
            break;
        }
        case 7: {
            int opStock;
            do {
                cin.ignore();
                cout << "\n--- STOCK ---\n";
                cout << "1. Consultar stock actual" << endl;
                cout << "2. Consultar productos bajo minimo" << endl;
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opStock;
                switch(opStock) {
                    case 1:
                        consultarStock();
                        break;
                    case 2:
                        consultarProductosBajoMinimo();
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opStock != 0);
            break;
        }
        case 8: {
            int opStock;
            do {
                cin.ignore();
                cout << "\n--- REPORTES ---\n";
                cout << "1. Monto total facturado a cliente" << endl;
                cout << "2. Unidades vendidas de producto" << endl;
                cout << "0. Volver\n";
                cout << "Elegir opcion: ";
                cin >> opStock;
                switch(opStock) {
                    case 1:
                        montoTotalFacturadoAcliente();
                        break;
                    case 2:
                        unidadesVendidasDeProducto();
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opStock != 0);
            break;
        }
        case 0:
            cerrarSesion();
            salir = true;
            break;
        default:
            cout << "Opcion invalida." << endl;
    }

} while(salir == false);
}

//CERRAR SESION
void MenuAdministrador::cerrarSesion() {
    adminCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}

//FUNCIONES DE AGREGAR Y MODIFICAR
void MenuAdministrador::altaEmpleado() {
    string nombreCompleto, direccion, correo, password;

    cout << "\n---ALTA-EMPLEADO---\n";

    cout << "Ingrese nombre completo: "<< endl;
    cin.ignore();
    getline(cin, nombreCompleto);

    cout << "Ingrese direccion: "<< endl;
    getline(cin,direccion);

    cout << "Ingrese correo (..empleado@gmail.com): "<< endl;
    getline(cin,correo);

    cout << "Ingrese contrasenia: "<< endl;
    getline(cin,password);

    try {
        adminCtrl->altaEmpleado(nombreCompleto,direccion,correo,password);
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
    int estaEnStock, stockMinimo;

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

    cout << "Stock minimo: ";
    cin >> stockMinimo;
    cin.ignore();

    try {
        adminCtrl->agregarProducto(nombre,codigo,descripcion,precioUnitario,estaEnStock, stockMinimo,nombreCategoria);
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
    int nuevoStock, nuevoStockMinimo;

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
    cin.ignore();

    cout << "Ingrese nuevo stock minimo: " << endl;
    cin >> nuevoStockMinimo;
    cin.ignore();

    cout << "Ingrese nueva categoria: " << endl;
    getline(cin, nuevaCategoria);

    try {
        adminCtrl->modificarProducto(codigo, nuevoNombre, nuevaDescripcion, nuevoPrecioUnitario, nuevoStock, nuevoStockMinimo, nuevaCategoria);
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


void MenuAdministrador::eliminarProducto() {
    string codigo;

    cout << "\n---MODIFICAR PRODUCTO---\n";
    cin.ignore();

    cout << "Ingrese codigo del producto a eliminar: " << endl;
    getline(cin, codigo);

    try {
        adminCtrl->eliminarProducto(codigo);
        cout << "Producto eliminado correctamente." << endl;
    }catch(int error) {
        if(error == 1) {
            cout << "No existe un producto con ese codigo." << endl;
        }
        else if(error == 2) {
            cout << "No se puede eliminar un producto con ventas registradas." << endl;
        }
        else if(error == 3) {
            cout << "No se puede eliminar un prodcto con orden de compra pendiente." << endl;
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

    try {
        adminCtrl->agregarProveedor(rut,nombre,telContacto,nombreContacto);
        cout << "\nProveedor agregado correctamente.\n";
    }
    catch(int error) {
        if(error == 1) {
            cout << "Ya existe un proveedor con ese RUT." << endl;
        }
    }
}

void MenuAdministrador::modificarProveedor() {
    int rutBuscado;
    string nuevoNombre, nuevoTelContacto, nuevoNombreContacto;

    cout << "\n=== MODIFICAR PROVEEDOR ===\n";
    vector<Proveedor*> proveedores = adminCtrl->listarProveedores();
    for (Proveedor* p : proveedores) {
        cout << "RUT: " << p->getRut() << endl; 
        cout << "Nombre: " << p->getNombre() << endl;
    }

    cout << "\nIngrese el RUT del proveedor a modificar: ";
    cin >> rutBuscado;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Proveedor* proveedor = adminCtrl->buscarProveedor(rutBuscado);
    if (!proveedor) {
        cout << "\n---- No existe ningun proveedor registrado con ese RUT ----\n";
    } else {
        cout << "\n------------------------------------\n";
        cout << "==== DATOS ACTUALES DEL PROVEEDOR ====";
        cout << "\n------------------------------------\n";
        cout << "RUT: " << proveedor->getRut() << endl;
        cout << "Nombre de empresa: " << proveedor->getNombre() << endl;
        cout << "Teléfono de contacto: " << proveedor->getTelContacto() << endl;
        cout << "Contacto Comercial: " << proveedor->getNombreContacto() << endl;

        cout << "\n=== === MODIFICAR PROVEEDOR === ===\n";
        cout << "(Deje el campo vacio y presione Enter para mantener el valor actual)\n\n";

        cout << "Ingrese nuevo nombre: ";
        getline(cin, nuevoNombre);

        cout << "Ingrese nuevo telefono: ";
        getline(cin, nuevoTelContacto);

        cout << "Ingrese nuevo contacto: ";
        getline(cin, nuevoNombreContacto);
        string confirmacion;
        cout << "\n¿Desea confirmar la modificacion de datos? (si/no): ";
        cin >> confirmacion;
        cin.ignore();

        if (confirmacion == "si") {
            adminCtrl->modificarProveedor(proveedor, nuevoNombre, nuevoTelContacto, nuevoNombreContacto);
            cout << "\n---- Proveedor modificado correctamente ----\n";
        } else {
            cout << "\n---- Modificacion cancelada ----\n";
        }
    }
}
void MenuAdministrador::registrarProveedorProducto() {
    int rutProveedor, tiempoEntrega;
    string codigoProducto, confirmacion;
    float precioCompra; 

    cout << "\n=== REGISTRAR ASOCIACION PRODUCTO-PROVEEDOR ===\n";

    vector<Proveedor*> proveedores = adminCtrl->listarProveedores();
    for (Proveedor* p : proveedores) {
        cout << "RUT: " << p->getRut() << endl;
        cout << "Nombre: " << p->getNombre() << endl <<endl;
    }
    
    cout << "\nIngrese el RUT del proveedor: ";
    cin >> rutProveedor;
    try {
        vector<Producto*> productos = adminCtrl->listarProductosNoAsociados(rutProveedor);
        cout << "\n--- PRODUCTOS DISPONIBLES ---\n"; 
        for (Producto* p : productos) {
            cout << "Codigo: " << p->getCodigo() << endl;
            cout << "Nombre: " << p->getNombre() << endl;
        }
    }
    catch (int error) {
        if(error == 1) { 
            cout << "\n--- El proveedor no existe ---\n";
        }
        cin.ignore();
        cout << "Enter para continuar";
        cin.get();
        return;
    }
    cout << "\nIngrese el Codigo del producto deseado: ";
    cin >> codigoProducto;
    cout << "Ingrese el precio de compra pactado:";
    cin >> precioCompra;
    cout << "Ingrese el tiempo de entrega estimado (dias): ";
    cin >> tiempoEntrega;

    cout << "\n=== RESUMEN DE ASOCIACION ===\n";
    cout << "Proveedor RUT: " << rutProveedor << endl;
    cout << "Producto Codigo: " << codigoProducto << endl;
    cout << "Precio pactado: $" << precioCompra << endl;
    cout << "Tiempo de entrega: " << tiempoEntrega << " dias" << endl;

    cout << "\n¿Desea confirmar esta asociacion? (si/no): ";
    cin >> confirmacion;

    if (confirmacion == "si") {
        try {
            adminCtrl->asociarProductoProveedor(rutProveedor, codigoProducto, precioCompra, tiempoEntrega);
            cout << "\n==== Asociacion registrada correctamente ====\n";

        } catch (int error) {
            
            if (error == 3) { 
                string actualizar;
                cout << "\nEste proveedor ya abastece este producto\n";
                cout << "¿Desea actualizar el precio y el tiempo de entrega con los nuevos datos? (si/no): ";
                cin >> actualizar;

                if (actualizar == "si") {
                    adminCtrl->actualizarAsociacion(rutProveedor, codigoProducto, precioCompra, tiempoEntrega);
                    cout << "\n---- Datos de la asociacion actualizados correctamente ----\n";
                } else {
                    cout << "\n---- Actualizacion cancelada ----\n";
                }
            } 
            else if (error == 2) {
                cout << "\nEl producto ingresado no existe en el sistema.\n";
                cin.ignore();
                cout << "Enter para continuar";
                cin.get();
            }
        }
    } else {
        cout << "\n---- Operacion cancelada ----\n";
        cin.ignore();
        cout << "Enter para continuar";
        cin.get();
    }
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
        cout << "Precio unitario ($): " << productos[i]->getPrecioUnitario() << endl;
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
        cout << "-----------------------------\n";
    }
}

void MenuAdministrador::consultarCalificacionesProducto() {
    string codigoProducto;
    cout << "\n--- CONSULTAR CALIFICACIONES DE PRODUCTO ---\n";
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoProducto;
    try {
        vector<Calificacion*> calificaciones = EmpleadoController::getInstancia()->consultarCalificacionesProducto(codigoProducto);
        cout << "\n--- CALIFICACIONES ---\n";

        for (int i = 0; i < calificaciones.size(); i++) {
            cout << "Puntaje: " << calificaciones[i]->getPuntaje() << endl;
            cout << "Comentario: " << calificaciones[i]->getComentario() << endl;
        }

    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo.";
        } else if (error == 2) {
            cout << "El producto no tiene calificaciones.";
        }
    }
}

//CONSULTAR INFO DETALLADA PRODUCTO
void MenuAdministrador::consultarInfoDetalladaProducto() {
    string nombre, codigoProducto, descripcion;
    int cantVendidas, estaEnStock;
    float precioUnitario, puntajePromedio;
    Categoria* categoria;

    cout << "\n---CONSULTAR INFO DETALLADA PRODUCTO---\n";

    cout<<"Ingrese codigo del producto: ";
    cin >> codigoProducto;

    try {
        Producto* producto = VentaController::getInstancia()->consultarInfoDetalladaProducto(codigoProducto);

        cout<<"Nombre: "<< producto->getNombre()<<endl;
        cout<<"Codigo: "<< producto->getCodigo()<<endl;
        cout<<"Descripcion: "<< producto->getDescripcion()<<endl;
        cout<<"Precio unitario: "<< producto->getPrecioUnitario()<<endl;
        cout<<"Puntaje promedio: "<< producto->getPuntajePromedio()<<endl;
        cout<<"Cantidad de vendidas: "<< producto->getCantVendidas()<<endl;
        cout<<"Esta en stock: "<< producto->getEstaEnStock()<<endl;
        cout<<"Categoria: " << producto->getCategoria()->getNombre()<<endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo." << endl;
        }
    }
}

void MenuAdministrador::consultarStock() {
    string codigoProducto;
    int stock;
    cout << "\n--- CONSULTAR STOCK ---\n";
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoProducto;
    try {
        stock = EmpleadoController::getInstancia()->consultarStock(codigoProducto);
        cout << "Stock actual del producto: " << stock << endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo.";
        }
    }
}

void MenuAdministrador::consultarProductosBajoMinimo() {
    try {
        vector<Producto*> productos = EmpleadoController::getInstancia()->consultarProductosBajoMinimo();
        cout << "\n--- PRODUCTOS DEBAJO DEL STOCK MINIMO ---\n";
        for (int i = 0; i < productos.size(); i++) {
            cout << "Nombre: " << productos[i]->getNombre() << endl;
            cout << "Codigo: " << productos[i]->getCodigo() << endl;
            cout << "Stock actual: " << productos[i]->getEstaEnStock() << endl;
            cout << "Stock minimo: " << productos[i]->getStockMinimo() << endl;
            cout << "-----------------------------\n";
        }
    }
    catch (int error) {
        if (error == 1) {
            cout << "No hay productos debajo del stock minimo.";
        }
    }
}

void MenuAdministrador::montoTotalFacturadoAcliente() {
    int rutCliente;
    cout << "\n--- MONTO TOTAL FACTURADO A CLIENTE ---\n";
    cout << "Ingrese el RUT del cliente: ";
    cin >> rutCliente;

    try {
        float montoTotal = EmpleadoController::getInstancia()->montoTotalFacturadoAcliente(rutCliente);

        cout << "Monto total facturado al cliente: $" << montoTotal << endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un cliente registrado con ese RUT.";
        } else if (error == 2) {
            cout << "El cliente no tiene ventas registradas.";
        }
    }
}

void MenuAdministrador::unidadesVendidasDeProducto() {
    string codigoProducto;
    cout << "\n--- UNIDADES VENDIDAS DE PRODUCTO ---\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese el codigo del producto: ";
    getline(cin, codigoProducto);
    try {
        int unidadesVendidas = EmpleadoController::getInstancia()->unidadesVendidasDeProducto(codigoProducto);
        cout << "Unidades vendidas: " << unidadesVendidas << endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo.";
        }
    }
}