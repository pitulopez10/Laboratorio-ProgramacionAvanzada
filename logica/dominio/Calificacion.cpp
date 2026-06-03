//
// Created by facuw on 27/5/2026.
//

#include "Calificacion.h"
#include "DTFecha.h"
#include <iostream>
using namespace std;


//CONSTRUCTORES
Calificacion::Calificacion() {

}
Calificacion::Calificacion(string comentario, int puntaje, DTFecha fechaCalificacion) {
    this->comentario = comentario;
    this->puntaje = puntaje;
    this->fechaCalificacion = fechaCalificacion;

}

//GETTERS
string Calificacion::getComentario() const {
    return this->comentario;
}
int Calificacion::getPuntaje() const {
    return this->puntaje;
}
DTFecha Calificacion::getFechaCalificacion() const {
    return this->fechaCalificacion;
}

//SETTERS
void Calificacion::setComentario(string comentario) {
    this->comentario = comentario;
}
void Calificacion::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}
void Calificacion::setFechaCalificacion(DTFecha fechaCalificacion) {
    this->fechaCalificacion = fechaCalificacion;
}