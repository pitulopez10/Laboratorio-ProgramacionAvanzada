//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_LINEADECOMPRA_H
#define LABORATORIO3_LINEADECOMPRA_H

class LineaDeCompra {
    private:
        float precioCompra;
    public:
        //CONSTRUCTORES
        LineaDeCompra(float precioCompra);

        //GETTERS
        float getPrecioCompra();

        //SETTERS
        void setPrecioCompra(float precioCompra);
};

#endif //LABORATORIO3_LINEADECOMPRA_H
