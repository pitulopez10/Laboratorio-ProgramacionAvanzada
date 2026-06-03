//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_CATEGORIA_H
#define LABORATORIO3_CATEGORIA_H
#include <string>
#include <iostream>

using namespace std;

class Categoria {
private:

    string nombre, descripcion;

public:

    //CONSTRUCTORES

    Categoria();
    Categoria(string nombre, string descripcion);

    //GETTERS

    string getNombre();
    string getDescripcion();

    //SETTERS

    void setNombre(string nombre);
    void setDescripcion(string descripcion);

    //METODOS
};



#endif //LABORATORIO3_CATEGORIA_H
