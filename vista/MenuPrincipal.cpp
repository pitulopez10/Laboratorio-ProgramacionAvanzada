#include "MenuPrincipal.h"
#include <iostream>

#include "MenuAdministrador.h"
#include "MenuEmpleado.h"
#include "MenuCliente.h"

using namespace std;

MenuPrincipal::MenuPrincipal(AdminController* adminCtrl,EmpleadoController* empleadoCtrl,VentaController* ventaCtrl)
: menuAdmin(*adminCtrl),
  menuEmpleado(empleadoCtrl),
  menuCliente(ventaCtrl)
  //el cliente realizar compras,consultar compras, calificar productos por eso se relaciona con ventactrl
{
}

void MenuPrincipal :: mostrar() {
    int opcion;

    do {
        cout<<"\n========================\n";
        cout<<"Sistema Stock y Ventas\n";
        cout<<"\n========================\n";

        cout<<"1. Iniciar sesion como Administrador\n";
        cout<<"2. Iniciar sesion como Empleado\n";
        cout<<"3. Iniciar sesion como Cliente\n";
        cout<<"4. Salir\n";
        cout<<"Seleccione opcion:";
        cin>>opcion;

        switch (opcion) {
            case 1:{
                menuAdmin.mostrar();
                break;}
            case 2:{
                menuEmpleado.mostrar();
                break;}
            case 3:{
                menuCliente.mostrar();
                break;}
            case 4:{
                cout<<"Saliendo...\n";
                break;}
            default: cout<<"Opcion invalida\n";
        }
    }while(opcion != 4);
}
