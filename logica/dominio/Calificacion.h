//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_CALIFICACION_H
#define LABORATORIO3_CALIFICACION_H
#include "DTFecha.h"
#include <string>
using namespace std;

class ClienteRegistrado;
class Producto;

class Calificacion {
    private:
        string comentario;
        int puntaje;
        DTFecha fechaCalificacion;

        ClienteRegistrado* cliente;
        Producto* producto;

    public:
        Calificacion();
        Calificacion(string comentario, int puntaje, DTFecha fechaCalificacion, ClienteRegistrado* cliente, Producto* producto);

        //GETTERS
        string getComentario() const;
        int getPuntaje() const;
        DTFecha getFechaCalificacion() const;
        ClienteRegistrado* getCliente() const;
        Producto* getProducto() const;

        //SETTERS
        void setComentario(string comentario);
        void setPuntaje(int puntaje);
        void setFechaCalificacion(DTFecha fechaCalificacion);
};



#endif //LABORATORIO3_CALIFICACION_H
