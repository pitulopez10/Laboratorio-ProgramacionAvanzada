//
// Created by facuw on 27/5/2026.
//

#include "DTFecha.h"
#include <iostream>
using namespace std;


//CONSTRUCTORES
DTFecha::DTFecha() {

}
DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

//GETTERS
int DTFecha::getDia() const {
    return this->dia;
}
int DTFecha::getMes() const {
    return this->mes;
}
int DTFecha::getAnio() const {
    return this->anio;
}

//SETTERS
void DTFecha::setDia(int dia) {
    this->dia = dia;
}
void DTFecha::setMes(int mes) {
    this->mes = mes;
}
void DTFecha::setAnio(int anio) {
    this->anio = anio;
}