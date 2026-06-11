//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_LINEADEDETALLE_H
#define LABORATORIO3_LINEADEDETALLE_H
using namespace std;

class Producto;

class LineaDeDetalle {

    private:
        int cantidad;
        float precioUnitario;
        Producto* producto;

    public:
        LineaDeDetalle();
        LineaDeDetalle(int cantidad, float precioUnitario, Producto* producto);

        //GETTERS
        int getCantidad() const;
        float getPrecioUnitario() const;
        Producto* getProducto() const;

        //SETTERS
        void setCantidad(int cantidad);
        void setPrecioUnitario(float precioUnitario);
};



#endif //LABORATORIO3_LINEADEDETALLE_H
