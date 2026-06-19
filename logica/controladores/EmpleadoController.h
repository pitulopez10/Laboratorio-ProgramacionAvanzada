//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_EMPLEADOCONTROLLER_H
#define LABORATORIO3_EMPLEADOCONTROLLER_H
#include "../dominio/Venta.h"
#include "../dominio/DTFecha.h"
#include "../dominio/DTHora.h"
#include "../dominio/Empleado.h"
#include <string>
#include <vector>

using namespace std;

class AdminController;

class EmpleadoController {
private:
    AdminController* adminController;
    vector<Venta*> venta;
    vector<Empleado*> empleados;
    
    static EmpleadoController* instancia;

public:
    EmpleadoController();
    ~EmpleadoController();

    static EmpleadoController* getInstancia();

        bool registrarVenta(string idVenta,DTFecha fecha,DTHora hora, float precioTotal);
        void consultarHistorialDeCompras(string rut) const;
        void consultarStock();
        void altaClienteRegistrado(string rut, string nombreCompleto, string direccion, string correo);

        Empleado* iniciarSesion(string correo);
};



#endif //LABORATORIO3_EMPLEADOCONTROLLER_H
