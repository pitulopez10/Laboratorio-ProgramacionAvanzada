//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_PROVEEDOR_H
#define LABORATORIO3_PROVEEDOR_H
#include <string>
#include <iostream>

using namespace std;

class Proveedor {

private:

    int rut, tiempoEntrega;
    string nombre, telContacto, nombreContacto;

public:

    //CONSTRUCTORES
    Proveedor();
    Proveedor(int rut, string nombre, string telContacto, string nombreContacto, int tiempoEntrega);

    //GETTERS

    int getRut();
    int getTiempoEntrega();
    string getNombre();
    string getTelContacto();
    string getNombreContacto();

    //SETTERS

    void setRut(int rut);
    void setTiempoEntrega(int tiempoEntrega);
    void setNombre(string nombre);
    void setTelContacto(string telContacto);
    void setNombreContacto(string nombreContacto);

    //METODOS
};



#endif //LABORATORIO3_PROVEEDOR_H
