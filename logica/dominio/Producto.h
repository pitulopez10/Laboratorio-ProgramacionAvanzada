//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_PRODUCTO_H
#define LABORATORIO3_PRODUCTO_H
#include <string>
#include <iostream>

#include "Calificacion.h"
#include "Categoria.h"

using namespace std;


class Producto {
private:

    string nombre, codigo, descripcion;
    float precioUnitario, puntajePromedio;
    int cantVendidas, estaEnStock, stockMinimo;
    Categoria* categoria;   //MUCHOS productos tienen UNA categoría.
    vector<Calificacion*> calificaciones;

public:

    //CONSTRUCTORES

    Producto();
    Producto(string nombre, string codigo, string descripcion, float precioUnitario, float puntajePromedio, int cantVendidas, int estaEnStock, Categoria* categoria, int stockMinimo);

    //GETTERS

    string getNombre();
    string getCodigo();
    string getDescripcion();
    float getPrecioUnitario();
    float getPuntajePromedio();
    int getCantVendidas();
    int getEstaEnStock();
    Categoria* getCategoria();
    int getStockMinimo();
    vector<Calificacion*> getCalificaciones();

    //SETTERS

    void setNombre(string nombre);
    void setCodigo(string codigo);
    void setDescripcion(string descripcion);
    void setPrecioUnitario(float precioUnitario);
    void setPuntajePromedio(float puntajePromedio);
    void setCantVendidas(int cantVendidas);
    void setEstaEnStock(int estaEnStock);
    void setCategoria(Categoria* categoria);
    void setStockMinimo(int stockMinimo);
    void setCalificaciones(vector<Calificacion*> calificaciones);

    //METODOS
    void agregarCalificacion(Calificacion* calificacion);
    
};



#endif //LABORATORIO3_PRODUCTO_H
