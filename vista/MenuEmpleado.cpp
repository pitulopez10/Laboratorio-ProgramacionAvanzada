//
// Created by facuw on 3/6/2026.
//

#include "MenuEmpleado.h"
#include "../logica/dominio/DTFecha.h"
#include "../logica/controladores/EmpleadoController.h"
#include "../logica/controladores/VentaController.h"
#include "../logica/controladores/AdminController.h"
#include "../logica/dominio/LineaDeCompra.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

MenuEmpleado::MenuEmpleado(EmpleadoController* empleadoCtrl, VentaController* ventaCtrl, AdminController* adminCtrl) {
    this->empleadoCtrl = empleadoCtrl;
    this->ventaCtrl = ventaCtrl;
    this->adminCtrl = adminCtrl;
}

void MenuEmpleado::mostrar() {
    int opcion;

    do {
        cout << "\n=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;
        cout << "|        MENU EMPLEADOS       |" << endl;
        cout << "=!!=!!=!!=!!=!!=!!=!!=!!=!!=!!=" << endl;

        cout << "1. Gestion de clientes" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Ordenes de compra" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. Informacion de producto" << endl;
        cout << "0. Cerrar sesion" << endl;
        cout << "Elegir opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int opcionClientes;

                do {
                    cout << "\n--- GESTION DE CLIENTES ---\n";
                    cout << "1. Alta cliente registrado" << endl;
                    cout << "2. Modificar cliente registrado" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionClientes;
                    cin.ignore();

                    switch (opcionClientes) {
                        case 1:
                            altaClienteRegistrado();
                            break;
                        case 2:
                            modificarClienteRegistrado();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionClientes != 0);

                break;
            }

            case 2: {
                int opcionVentas;

                do {
                    cout << "\n--- VENTAS ---\n";
                    cout << "1. Registrar venta" << endl;
                    cout << "2. Consultar historial de compras" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionVentas;
                    cin.ignore();

                    switch (opcionVentas) {
                        case 1:
                            registrarVenta();
                            break;
                        case 2:
                            consultarHistorialDeCompras();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionVentas != 0);

                break;
            }

            case 3: {
                int opcionOrdenes;

                do {
                    cout << "\n--- ORDENES DE COMPRA ---\n";
                    cout << "1. Emitir orden de compra" << endl;
                    cout << "2. Cancelar orden de compra" << endl;
                    cout << "3. Registrar recepcion de orden" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionOrdenes;
                    cin.ignore();

                    switch (opcionOrdenes) {
                        case 1:
                            emitirOrdenDeCompra();
                            break;
                        case 2:
                            cancelarOdenDeCompra();
                            break;
                        case 3:
                            registrarRecepcionDeOrden();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionOrdenes != 0);

                break;
            }

            case 4: {
                int opcionReportes;
                do {
                    cout << "\n--- REPORTES ---\n";
                    cout << "1. Consultar stock actual" << endl;
                    cout << "2. Consultar productos bajo minimo" << endl;
                    cout << "3. Monto total facturado a cliente" << endl;
                    cout << "4. Unidades vendidas de producto" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionReportes;
                    cin.ignore();

                    switch (opcionReportes) {
                        case 1:
                            consultarStock();
                            break;
                        case 2:
                            consultarProductosBajoMinimo();
                            break;
                        case 3:
                            montoTotalFacturadoAcliente();
                            break;
                        case 4:
                            unidadesVendidasDeProducto();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionReportes != 0);

                break;
            }

            case 5: {
                int opcionInfo;

                do {
                    cout << "\n--- INFORMACION DE PRODUCTO ---\n";
                    cout << "1. Consultar informacion detallada de producto" << endl;
                    cout << "0. Volver" << endl;
                    cout << "Elegir opcion: ";
                    cin >> opcionInfo;
                    cin.ignore();

                    switch (opcionInfo) {
                        case 1:
                            consultarInfoDetalladaProducto();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }

                } while (opcionInfo != 0);

                break;
            }

            case 0:
                cerrarSesion();
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
        }

    } while (opcion != 0);
}


//FUNCIONES: GESTION DE CLIENTES

void MenuEmpleado::altaClienteRegistrado() {
    string nombreCompleto, direccion, correo, password;
    int rut;
        cout << "\n======================================\n";
        cout << "====== REGISTRAR NUEVO CLIENTE =======";
        cout << "\n======================================\n";
    while(true) {
        cout << "Ingrese RUT: "<< endl; cin >> rut;
        cin.ignore();

        try {
            empleadoCtrl->validarRutCliente(rut);
        }
        catch (int error) {
            cout << "--- --- Ya existe un cliente con ese RUT, ingrese los datos nuevamente --- ---\n";
            continue;
        }
        break;
    }
        cout << "Ingrese nombre completo: "<< endl; getline(cin, nombreCompleto);
        cout << "Ingrese dirección: "<< endl; getline(cin, direccion);
    while(true) {
        cout << "Ingrese correo electrónico: " << endl; getline(cin, correo);

    try {
        empleadoCtrl->validarCorreoCliente(correo);
        break;
    }
    catch (int error) {
        cout << "--- --- Ya existe un cliente con ese correo, ingrese el correo nuevamente --- ---\n";
    }
}
    cout << "Ingrese contraseña: "<< endl; getline(cin, password);

    cout << "\n--------------------------------------\n";
    cout << "==== RESUMEN DE DATOS DEL CLIENTE ====";
    cout << "\n--------------------------------------\n";

    cout << "RUT:" << rut << endl;
    cout << "Nombre completo:" << nombreCompleto << endl;
    cout << "Dirección:" << direccion << endl;
    cout << "Correo electrónico:" << correo << endl;
    cout << "Contraseña:" << password << endl;
    
    string confirmacion;
    while (true) { 
        cout << "\n¿Desea confirmar el alta de este cliente?(si/no)\n";
        cin >> confirmacion;  
        cin.ignore();
       
    if(confirmacion == "si") {
        empleadoCtrl->altaClienteRegistrado(rut, nombreCompleto, direccion, correo, password);
        
        cout << "\n------------------------------------------\n";
        cout << "==== CLIENTE REGISTRADO CORRECTAMENTE ====";
        cout << "\n------------------------------------------\n\n";
        cout << "Enter para continuar";
        cin.get();
        return;
    } 
    if (confirmacion == "no") {
        cout << "\n == == Alta de cliente cancelada == ==\n\n";
        cout << "Enter para continuar";
        cin.get();
        return;
    } else {
        cout << "Opcion inválida, Intente de nuevo\n";
    }
    }
}

void MenuEmpleado::modificarClienteRegistrado() {
    string nombreCompleto, direccion, correo, password;
    int rut;
    cout << "\n===========================================\n";
    cout << "====== MODIFICAR CLIENTE REGISTRADO =======";
    cout << "\n===========================================\n";

    cout << "Ingrese RUT de cliente a modificar:";
    cin >> rut;
    cin.ignore();
    ClienteRegistrado* cliente = empleadoCtrl->buscarCliente(rut);
    if(!cliente) {
        cout << "\n--- --- No existe un cliente con ese RUT --- ---\n\n";
        cout << "Presione Enter para continuar";
        cin.get();
    } else {
        cout << "\n------------------------------------\n";
        cout << "==== DATOS ACTUALES DEL CLIENTE ====";
        cout << "\n------------------------------------\n";

        cout << "RUT:" << cliente->getRut() << endl;
        cout << "Nombre completo:" << cliente->getNombreCompleto() << endl;
        cout << "Dirección:" << cliente->getDireccion() << endl;
        cout << "Correo electrónico:" << cliente->getCorreo() << endl;
        cout << "Contraseña:" << cliente->getPassword() << endl;

        cout << "\n=== === MODIFICAR CLIENTE === ===\n";
        cout << "\n(Deje el campo vacío y presione Enter para mantener el valor actual)\n";
        cout << "Ingrese nuevo nombre completo: "<< endl; getline(cin, nombreCompleto);
        cout << "Ingrese nueva dirección: "<< endl; getline(cin, direccion);
        while (true) {
            cout << "Ingrese nuevo correo: "<< endl; getline(cin, correo);
            try {
                empleadoCtrl->validarCorreoCliente(correo);
            }
            catch (int error) {
                cout << "--- --- Ya existe un cliente con ese correo, ingrese los datos nuevamente --- ---\n";
                continue;
            }
            break;
        }
        cout << "Ingrese nueva contraseña: "<< endl; getline(cin, password);

        string confirmacion;
        while (true) { 
            cout << "\n¿Desea confirmar la modificación de este cliente?(si/no)\n";
            cin >> confirmacion;  
            cin.ignore();
       
        if(confirmacion == "si") {
            empleadoCtrl->modificarClienteRegistrado(cliente, nombreCompleto, direccion, correo, password);
        
            cout << "\n------------------------------------------\n";
            cout << "==== CLIENTE MODIFICADO CORRECTAMENTE ====";
            cout << "\n------------------------------------------\n\n";
            cout << "Enter para continuar";
            cin.get();

            return;
        } 
        if (confirmacion == "no") {
            cout << "\n == == Modificación cancelada == ==\n\n";
            cout << "Enter para continuar";
            cin.get();
            return;
        } else {
            cout << "Opcion invalida, Intente de nuevo\n";
        }
    }
    }
}
//FUNCIONES: VENTAS
void MenuEmpleado::registrarVenta() {
    
    cout << "\n====================================\n";
    cout << "====== REGISTRAR NUEVA VENTA =======";
    cout << "\n====================================\n";

    string opcion, codigo;
    int rut, cantidad;
    Cliente* cliente = nullptr;
    ventaCtrl->limpiarLineasTemporales();
    while(true) {
        cout << "\n¿Desea realizar la venta a un cliente ocacional o registrado?(ocacional/registrado)\n";
        getline(cin, opcion); 

        if(opcion == "registrado") {
        cout << "Ingrese RUT de cliente registrado:";
        cin >> rut;
        cin.ignore();

        cliente = empleadoCtrl->buscarCliente(rut);
            
        if(!cliente) {
            cout << "\n--- --- No existe un cliente con ese RUT --- ---\n\n";   
            cout << "Enter para continuar";
            cin.get();
            continue;
        }
        }
        while (true) {
            cout << "\n=== Agregar nueva linea de detalle ===\n\n";

            cout << "Ingrese código del producto:\n"; getline(cin, codigo);
            cout << "Ingrese cantidad:\n";
            cin >> cantidad;
            cin.ignore();

            Producto* producto = adminCtrl->buscarProducto(codigo);
            if(!producto) {
                cout << "\n--- --- No existe un producto registrado con ese código --- ---\n\n";
                cout << "Enter para continuar";
                cin.get();
                continue;
            } 
            if (producto) {
                //consultar stock actual
                int stockActual = producto->getEstaEnStock(); 
                float precioUnitario = producto->getPrecioUnitario();
                cout << "Stock disponible: " << stockActual << endl;
                cout << "Precio unitario actual: " << precioUnitario << endl;
                    
                try {
                    ventaCtrl->agregarLineaTemporal(producto, cantidad);
                    cout << "\n--- Linea agregada correctamente ---\n";
                }
                catch (int error) {
                    cout << "Stock insuficiente. La venta no puede registrarse\n";
                    cout << "Enter para continuar";
                    cin.get();
                    continue;
                    }
                }
                cout << "\n¿Desea seguir agregando líneas de detalle?(si/no)\n";
                cin >> opcion;
                cin.ignore();
                if(opcion == "si") {
                    continue;
                }
                else if(opcion == "no") {
                    break;   
                } else {
                    cout << "Opcion invalida, Intente de nuevo\n";
                }
        }
        cout << "\n-----------------------------\n";
        cout << "==== RESUMEN DE LA VENTA ====";
        cout << "\n-----------------------------\n";    

        vector<LineaDeDetalle*> lineasTemp = ventaCtrl->getLineasTemp();
        float total = ventaCtrl->calcularTotal(lineasTemp);
        DTFecha fechaActual = empleadoCtrl->obtenerFechaActual();
        DTHora horaActual = empleadoCtrl->obtenerHoraActual();
        cout << "Cantidad de lineas: " << lineasTemp.size() << endl;
        cout << "Total calculado: $" << total << endl;
        cout << "\nFecha:" << fechaActual.getDia() << "/" << fechaActual.getMes() << "/" << fechaActual.getAnio() << endl;
        cout << "\nHora:" << horaActual.getHora() << ":" << horaActual.getMinuto() << ":" << horaActual.getSegundo() << endl;

        string confirmacion;
        while (true) { 
            cout << "\n¿Desea confirmar la venta?(si/no)\n";
            cin >> confirmacion;  
            cin.ignore();
            if(confirmacion == "si") {
                try {
                    empleadoCtrl->registrarVenta(cliente, lineasTemp, fechaActual, horaActual, total);
                    ventaCtrl->limpiarLineasTemporales();
                    cout << "\n----------------------------------------\n";
                    cout << "==== VENTA REGISTRADA CORRECTAMENTE ====";
                    cout << "\n----------------------------------------\n\n";
                    cout << "Enter para continuar";
                    cin.get();
                }    
                catch(int error) {
                    if(error == 1) {
                        cout << "Debe agregar al menos una linea de detalle\n";
                    }
                }    
                return;
            } 
            else if(confirmacion == "no") {
                ventaCtrl->limpiarLineasTemporales();
                cout << "\n == == Venta cancelada == ==\n\n";
                cout << "Enter para continuar";
                cin.get();
                return;
            } else {
                cout << "Opcion invalida, Intente de nuevo\n";
            }
        }
}
}

void MenuEmpleado::consultarHistorialDeCompras() {
    cout << "\n=============================================\n";
    cout << "====== CONSULTAR HISTORIAL DE COMPRAS =======";
    cout << "\n=============================================\n";

    int rut;
    cout << "Ingrese RUT de cliente:";
    cin >> rut;
    cin.ignore();
    ClienteRegistrado* cliente = empleadoCtrl->buscarCliente(rut);

    if(!cliente) {
        cout << "\n--- --- No existe un cliente con ese RUT --- ---\n\n";
        cout << "Presione Enter para continuar";
        cin.get();
        return;
    } 
    try {
        vector<Venta*> historial = empleadoCtrl->consultarHistorialDeCompras(cliente);
        
        cout << "\n------------------------------\n";
        cout << "==== RESUMEN DE HISTORIAL ====";
        cout << "\n------------------------------\n"; 
        
        for(Venta* v : historial) {
            cout << "ID de venta: " << v->getIdVenta() << endl;
            cout << "Fecha: " << v->getFecha().getDia() << "/" << v->getFecha().getMes() << "/" << v->getFecha().getAnio() << endl;

            cout << "Hora: " << v->getHora().getHora() << ":" << v->getHora().getMinuto() << endl;
            cout << "Cantidad de lineas: " << v->getLineas().size() << endl;
            cout << "Monto total: $" << v->getPrecioTotal() << endl << endl;
        }
        string idBuscado;
        cout << "\nIngrese ID de la venta para ver el detalle completo: ";
        cin>>idBuscado;
        cin.ignore();
        try {
            Venta * venta = empleadoCtrl->seleccionarVentaDeHistorial(historial,idBuscado);
            cout << "\n==== DETALLE DE LA VENTA ===\n";
            for(LineaDeDetalle* linea : venta->getLineas()) {
                cout << "\nProducto: " << linea->getProducto()->getNombre() << endl;
                cout << "Cantidad: " << linea->getCantidad() << endl;
                cout << "Precio unitario aplicado: $" << linea->getPrecioUnitario() << endl;
            }
                cout << "Enter para continuar";
                cin.get();
        } 
        catch(int error) {
            if(error == 1) {
                cout<<"\n--- ID de venta no encontrado ---\n";
                cout << "Enter para continuar";
                cin.get();
            }
        }
    } catch (int error) {
        if (error == 1) {
            cout << "\n--- Este cliente no tiene compras registradas en el historial ---\n\n";
            cout << "Enter para continuar";
            cin.get();
        }
    }

}

//CONSULTAR INFO DETALLADA PRODUCTO
void MenuEmpleado::consultarInfoDetalladaProducto() {
    string nombre, codigoProducto, descripcion;
    int cantVendidas, estaEnStock;
    float precioUnitario, puntajePromedio;
    Categoria* categoria;

    cout << "\n---CONSULTAR INFO DETALLADA PRODUCTO---\n";

    cout<<"Ingrese codigo del producto: ";
    cin >> codigoProducto;

    try {
        Producto* producto = empleadoCtrl->consultarInfoDetalladaProducto(codigoProducto);

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
void MenuEmpleado::emitirOrdenDeCompra() { 
    int rutProveedor;
    cout << "\n=====================================\n";
    cout << "====== EMITIR ORDEN DE COMPRA =======";
    cout << "\n======================================\n";
    
    vector<Proveedor*> proveedores = adminCtrl->listarProveedores();
    for (Proveedor* p : proveedores) {
        cout << "RUT: " << p->getRut() << endl; 
        cout << "Nombre: " << p->getNombre() << endl;
    }
    
    cout << "\nIngrese el RUT del proveedor a seleccionar: ";
    cin >> rutProveedor;
    cin.ignore();
    
    Proveedor* proveedor = adminCtrl->buscarProveedor(rutProveedor);
    if(!proveedor) {
        cout << "\n--- No existe un proveedor registrado con ese RUT ---\n\n";
        cout << "Enter para continuar";
        cin.get();
        return; 
    }
    
    empleadoCtrl->limpiarLineasTemporalesOrden();
    string opcion;

    do {
        string codigoProducto;
        int cantidad;

        cout << "\n=== Agregar nueva linea de orden ===\n";
        cout << "Ingrese el codigo del producto: ";
        getline(cin, codigoProducto);

        Producto* producto = adminCtrl->buscarProducto(codigoProducto);
        if(!producto) {
            cout << "--- El producto no existe en el sistema ---\n";
            cout << "Enter para continuar";
            cin.get();
            continue;
        }
        
        LineaDeCompra* info = proveedor->buscarLineaDeCompra(codigoProducto);

        if(!info) {
            cout << "--- Este proveedor no puede abastecer este producto ---\n";
            cout << "Enter para continuar";
            cin.get();
        } else {
            cout << "Precio de compra vigente: $" << info->getPrecioCompra() << endl;
            cout << "Tiempo de entrega estimado: " << info->getTiempoEntrega() << " dias\n";

            cout << "Ingrese cantidad: ";
            cin >> cantidad;
            cin.ignore();

            if(cantidad <= 0) {
                cout << "Cantidad inválida.\n";
            } else {
                empleadoCtrl->agregarLineaTemporalOrden(producto, cantidad);
                cout << "--- Linea agregada correctamente ---\n";
            }
        }
        cout << "\n¿Desea seguir agregando líneas de detalle? (si/no): ";
        cin >> opcion;
        cin.ignore();

    } while(opcion == "si");
    
    vector<LineaOrden*> lineasTemp = empleadoCtrl->getLineasTempOrden();

    cout << "\n===== RESUMEN DE LA ORDEN =====\n";
    cout << "Proveedor: " << proveedor->getNombre() <<endl;
    
    DTFecha fechaActual = empleadoCtrl->obtenerFechaActual(); 
    DTHora horaActual = empleadoCtrl->obtenerHoraActual();
    
    cout << "Cantidad de lineas: " << lineasTemp.size() << endl;
    cout << "Fecha: " << fechaActual.getDia() << "/" << fechaActual.getMes() << "/" << fechaActual.getAnio() << endl;
    cout << "\nDetalle de productos:\n";
    
    for(LineaOrden* linea : lineasTemp) {
        cout << "Producto: " << linea->getProducto()->getNombre() << endl;
        cout << "Cantidad: " << linea->getCantidad() << endl;
    }

    cout << "\n¿Desea confirmar la orden? (si/no): ";
    cin >> opcion;
    cin.ignore();

    if(opcion == "si") {
        try {
            empleadoCtrl->registrarOrdenDeCompra(proveedor, lineasTemp, fechaActual, horaActual);
            empleadoCtrl->limpiarLineasTemporalesOrden();
            
            cout << "\n--- La orden ha sido registrada con estado 'PENDIENTE' ---\n";
        } 
        catch(int error) {
            if(error == 1) {
                cout << "Debe agregar al menos una linea a la orden de compra\n";
            }
        }
    } else {
        empleadoCtrl->limpiarLineasTemporalesOrden();
        cout << "\n--- Orden de compra cancelada ---\n";
        cout << "Enter para continuar";
        cin.get();
    }
}

void MenuEmpleado::cancelarOdenDeCompra() {
    cout << "\n=====================================\n";
    cout << "====== CANCELAR ORDEN DE COMPRA =====";
    cout << "\n=====================================\n";
    vector<OrdenDeCompra*> pendientes;

    try {
        pendientes = empleadoCtrl->listarOrdenesPendientes();
    } catch (int error) {
        if (error == 1) {
            cout << "\n--- No hay ordenes de compra en estado PENDIENTE ---\n";
            cout << "Enter para continuar";
            cin.get(); 
            return;
        }
    }

    cout << "\n=== Ordenes en estado pendientes ===\n";
    for (OrdenDeCompra* orden : pendientes) {
        DTFecha fecha = orden->getFechaEmision();
        cout << "- ID: " << orden->getIdOrden() << endl;
        cout << "  Proveedor: " << orden->getProveedor()->getNombre() << endl;
        cout << "  Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;
        cout << "  Cantidad de lineas: " << orden->getLineasOrden().size() << endl;
    }

    string idSeleccionado;
    cout << "\nIngrese el ID de la orden que desea cancelar: ";
    cin >> idSeleccionado;
    cin.ignore();
    
    OrdenDeCompra* ordenSeleccionada;
    try {
        ordenSeleccionada = empleadoCtrl->buscarOrdenDeCompra(idSeleccionado);
    } catch (int error){
        if(error == 2) {
            cout << "\n--- Error: El ID ingresado no es valido o no esta pendiente ---\n";
            cout << "Enter para continuar";
            cin.get();
            return;
        }
    }
    cout << "\n==== DETALLE DE LA ORDEN SELECCIONADA ===\n\n";
    cout << "ID: " << ordenSeleccionada->getIdOrden() << endl;
    cout << "Proveedor: " << ordenSeleccionada->getProveedor()->getNombre() << endl;
    cout << "Productos solicitados:\n";
    
    vector<LineaOrden*> lineas = ordenSeleccionada->getLineasOrden();
    for (LineaOrden* linea : lineas) {
        cout << " Nombre: " << linea->getProducto()->getNombre() << endl;
        cout << " Cantidad: " << linea->getCantidad() << endl;
    }

    string confirmacion;
    cout << "\nConfirmar cancelacion de esta orden(si/no): ";
    cin >> confirmacion;
    cin.ignore();

    if (confirmacion == "si") {
        empleadoCtrl->cancelarOrdenDeCompra(idSeleccionado);
        cout << "\n=== La orden ha pasado al estado 'CANCELADA' ===\n";
        cout << "--- AVISO: Una orden cancelada no generara movimiento de stock ---\n";
    } else {
        cout << "\n--- Operacion cancelada ---\n";
    }
    
    cout << "\nEnter para continuar";
    cin.get();
}


void MenuEmpleado::registrarRecepcionDeOrden() {
    string idOrden;
    cout << "\n--- REGISTRAR RECEPCION DE COMPRA ---\n";
    cout << "Ingrese el ID de la compra: ";
    cin >> idOrden;
    try {
        empleadoCtrl->registrarRecepcionDeOrden(idOrden);
        cout << "Recepcion registrada correctamente.";
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe una orden de compra con ese ID" << endl;
        } else if (error == 2) {
            cout << "La orden ya fue recibida o no esta pendiente." << endl;
        }
    }
}



void MenuEmpleado::consultarStock() {
    string codigoProducto;
    int stock;
    cout << "\n--- CONSULTAR STOCK ---\n";
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoProducto;
    try {
        stock = EmpleadoController::getInstancia()->consultarStock(codigoProducto);
        cout << "\nStock actual del producto: " << stock << endl;
    }
    catch (int error) {
        if (error == 1) {
            cout << "No existe un producto con ese codigo.";
        }
    }
}

void MenuEmpleado::consultarProductosBajoMinimo() {
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

void MenuEmpleado::montoTotalFacturadoAcliente() {
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

void MenuEmpleado::unidadesVendidasDeProducto() {
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

void MenuEmpleado::cerrarSesion() {
    empleadoCtrl->cerrarSesion();
    cout << "Sesion cerrada correctamente." << endl;
}
