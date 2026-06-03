//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_LINEADEDETALLE_H
#define LABORATORIO3_LINEADEDETALLE_H
#include <iostream>
using namespace std;


class LineaDeDetalle {

    private:
        int cantidad;
        float precioUnitario;

    public:
        LineaDeDetalle();
        LineaDeDetalle(int cantidad, float precioUnitario);

        //GETTERS
        int getCantidad() const;
        float getPrecioUnitario() const;

        //SETTERS
        void setCantidad(int cantidad);
        void setPrecioUnitario(float precioUnitario);
};



#endif //LABORATORIO3_LINEADEDETALLE_H
