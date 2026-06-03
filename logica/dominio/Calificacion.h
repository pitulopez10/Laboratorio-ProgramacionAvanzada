//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_CALIFICACION_H
#define LABORATORIO3_CALIFICACION_H
#include "DTFecha.h"
#include <iostream>
using namespace std;


class Calificacion {
    private:
        string comentario;
        int puntaje;
        DTFecha fechaCalificacion;

    public:
        Calificacion();
        Calificacion(string comentario, int puntaje, DTFecha fechaCalificacion);

        //GETTERS
        string getComentario() const;
        int getPuntaje() const;
        DTFecha getFechaCalificacion() const;

        //SETTERS
        void setComentario(string comentario);
        void setPuntaje(int puntaje);
        void setFechaCalificacion(DTFecha fechaCalificacion);
};



#endif //LABORATORIO3_CALIFICACION_H
