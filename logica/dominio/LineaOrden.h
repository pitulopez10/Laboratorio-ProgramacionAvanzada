#ifndef LABORATORIO3_LINEAORDEN_H
#define LABORATORIO3_LINEAORDEN_H
#include <iostream>

using namespace std;

class Producto;

class LineaOrden {
private:
    Producto* producto;
    int cantidad;
public:
    LineaOrden(Producto* producto, int cantidad);

    //GETTERS
    Producto* getProducto();
    int getCantidad();

    //SETTERS
    void setCantidad(int cantidad);
    
    //METODOS

};

#endif
