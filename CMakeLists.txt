cmake_minimum_required(VERSION 4.2)
project(Laboratorio3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio3 main.cpp
        logica/dominio/OrdenDeCompra.cpp
        logica/dominio/OrdenDeCompra.h
        logica/dominio/LineaDeDetalle.cpp
        logica/dominio/LineaDeDetalle.h
        logica/dominio/Calificacion.cpp
        logica/dominio/Calificacion.h
        logica/dominio/DTFecha.cpp
        logica/dominio/DTFecha.h
        logica/dominio/EstadoCompra.cpp
        logica/dominio/EstadoCompra.h
        vista/MenuEmpleado.cpp
        vista/MenuEmpleado.h
        vista/MenuPrincipal.cpp
        vista/MenuPrincipal.h
        vista/MenuAdministrador.cpp
        vista/MenuAdministrador.h
        vista/MenuCliente.cpp
        vista/MenuCliente.h
        logica/controladores/AdminController.cpp
        logica/controladores/AdminController.h
        logica/controladores/VentaController.cpp
        logica/controladores/VentaController.h
        logica/controladores/EmpleadoController.cpp
        logica/controladores/EmpleadoController.h
        logica/dominio/Proveedor.cpp
        logica/dominio/Proveedor.h
        logica/dominio/Producto.cpp
        logica/dominio/Producto.h
        logica/dominio/Categoria.cpp
        logica/dominio/Categoria.h
        logica/dominio/Cliente.cpp
        logica/dominio/Cliente.h
        logica/dominio/Venta.cpp
        logica/dominio/Venta.h
        logica/dominio/LineaDeCompra.cpp
        logica/dominio/LineaDeCompra.h)
