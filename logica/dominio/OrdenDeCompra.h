//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_ORDENDECOMPRA_H
#define LABORATORIO3_ORDENDECOMPRA_H
#include "DTFecha.h"
#include "EstadoCompra.h"
#include <iostream>
#include <vector>

#include "LineaDeCompra.h"
using namespace std;


class OrdenDeCompra  {
    private:
        DTFecha fechaEmision;
        EstadoCompra estado;
        string idOrden;
        vector<LineaDeCompra*> lineasCompra;

    public:
        OrdenDeCompra();
        OrdenDeCompra(DTFecha fechaEmision, EstadoCompra estado, string idOrden);

        //GETTERS
        DTFecha getFechaEmision() const;
        EstadoCompra getEstado() const;
        string getIdOrden() const;

        //SETTERS
        void setFechaEmision(DTFecha fechaEmision);
        void setEstado(EstadoCompra estado);
        void setIdOrden(string idOrden);
};



#endif //LABORATORIO3_ORDENDECOMPRA_H
