#ifndef LABORATORIO3_ORDENDECOMPRA_H
#define LABORATORIO3_ORDENDECOMPRA_H
#include "DTFecha.h"
#include "EstadoCompra.h"
#include "LineaOrden.h"
#include "Proveedor.h"
#include <iostream>
#include <vector>

using namespace std;

class OrdenDeCompra {
    private:
        string idOrden;
        DTFecha fechaEmision;
        EstadoCompra estado;
        Proveedor* proveedor;
        vector<LineaOrden*> lineasOrden;

    public:
        OrdenDeCompra();
        OrdenDeCompra(string idOrden, DTFecha fechaActual, Proveedor* proveedor);

        // GETTERS
        string getIdOrden() const;
        DTFecha getFechaEmision() const;
        Proveedor* getProveedor() const;
        EstadoCompra getEstado() const;
        vector<LineaOrden*> getLineasOrden();

        // SETTERS
        void setFechaEmision(DTFecha fechaEmision);
        void setEstado(EstadoCompra nuevoEstado);

        // METODOS
        void agregarLineaOrden(LineaOrden* lineaOrden);
};

#endif
