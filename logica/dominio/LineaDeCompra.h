//
// Created by facuw on 3/6/2026.
//

#ifndef LABORATORIO3_LINEADECOMPRA_H
#define LABORATORIO3_LINEADECOMPRA_H

class Producto;

class LineaDeCompra {
    private:
        int cantidad;
        float precioCompra;
        Producto* producto;
        //nuevo
        int tiempoEntrega;
    public:
        //CONSTRUCTORES
        LineaDeCompra(float precioCompra, Producto* producto, int tiempoEntrega);

        //GETTERS
        int getCantidad();
        float getPrecioCompra();
        Producto* getProducto();
        int getTiempoEntrega();

        //SETTERS
        void setCantidad(int cantidad);
        void setPrecioCompra(float precioCompra);
        void setProducto(Producto* producto);
        void setTiempoEntrega(int tiempoEntrega);
};

#endif //LABORATORIO3_LINEADECOMPRA_H
