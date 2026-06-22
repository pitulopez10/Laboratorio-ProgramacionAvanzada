//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_LINEADECOMPRA_H
#define LABORATORIO3_LINEADECOMPRA_H
#include "Producto.h"

class LineaDeCompra {
    private:
        float precioCompra;
        Producto* producto;
    public:
        //CONSTRUCTORES
        LineaDeCompra(float precioCompra, Producto* producto);

        //GETTERS
        float getPrecioCompra();
        Producto* getProducto();

        //SETTERS
        void setPrecioCompra(float precioCompra);
        void setProducto(Producto* producto);
};

#endif //LABORATORIO3_LINEADECOMPRA_H
