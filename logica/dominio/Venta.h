//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_VENTA_H
#define LABORATORIO3_VENTA_H

#include "DTFecha.h"
#include "DTHora.h"

#include <string>
using namespace std;

class Venta {
    private:
        string idVenta;
        DTFecha fecha;
        DTHora hora;
        float precioTotal;
    public:
        Venta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);
        string getIdVenta();
        DTFecha getFecha();
        DTHora getHora();
        float getPrecioTotal();

        void setFecha(DTFecha fecha);
        void setHora(DTHora hora);
        void setPrecioTotal(float precioTotal);
};
#endif //LABORATORIO3_VENTA_H
