//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_PROVEEDOR_H
#define LABORATORIO3_PROVEEDOR_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Producto;
class LineaDeCompra;

class Proveedor {

private:

    int rut;
    string nombre, telContacto, nombreContacto;
    //proveedor abastece productos
    vector<LineaDeCompra*> lineasAsociadas;
public:

    //CONSTRUCTORES
    Proveedor();
    Proveedor(int rut, string nombre, string telContacto, string nombreContacto);

    //GETTERS

    int getRut();
    string getNombre();
    string getTelContacto();
    string getNombreContacto();
    vector<LineaDeCompra*> getLineasAsociadas();

    //SETTERS

    void setRut(int rut);
    void setNombre(string nombre);
    void setTelContacto(string telContacto);
    void setNombreContacto(string nombreContacto);

    //METODOS
    bool abasteceProducto(string codigoProducto); 
    void agregarProducto(Producto* p, float precioCompra, int tiempoEntrega);
    void actualizarDatosProducto(string codigoProducto, float nuevoPrecio, int nuevoTiempo);

};



#endif //LABORATORIO3_PROVEEDOR_H
