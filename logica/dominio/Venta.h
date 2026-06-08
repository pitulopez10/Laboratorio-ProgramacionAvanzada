//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_VENTA_H
#define LABORATORIO3_VENTA_H

#include "DTFecha.h"
#include "DTHora.h"
#include <string>
#include <vector>
#include "LineaDeDetalle.h"
using namespace std;

class Venta {
    private:
        string idVenta;
        DTFecha fecha;
        DTHora hora;
        float precioTotal;
        vector<LineaDeDetalle*> lineas;
    public:
        //CONSTRUCTORES
        Venta(string idVenta, DTFecha fecha, DTHora hora, float precioTotal);

        void agregarLinea(LineaDeDetalle* linea);

        //GETTERS
        string getIdVenta();
        DTFecha getFecha();
        DTHora getHora();
        float getPrecioTotal();
        vector<LineaDeDetalle*> getLineas();

        //SETTERS
        void setFecha(DTFecha fecha);
        void setHora(DTHora hora);
        void setPrecioTotal(float precioTotal);
};
#endif //LABORATORIO3_VENTA_H
