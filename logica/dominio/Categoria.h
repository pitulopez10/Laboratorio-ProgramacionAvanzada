//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_CATEGORIA_H
#define LABORATORIO3_CATEGORIA_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Producto;

class Categoria {
private:

    string nombre, descripcion;
    vector<Producto*> productos;

public:

    //CONSTRUCTORES

    Categoria();
    Categoria(string nombre, string descripcion);

    //GETTERS

    string getNombre();
    string getDescripcion();
    vector<Producto*> getProducto();

    //SETTERS

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setProducto(vector<Producto*> productos);

    //METODOS
};



#endif //LABORATORIO3_CATEGORIA_H
