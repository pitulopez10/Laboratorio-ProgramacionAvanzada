//
// Created by facuw on 27/5/2026.
//

#ifndef LABORATORIO3_DTFECHA_H
#define LABORATORIO3_DTFECHA_H
#include <iostream>
using namespace std;


class DTFecha {
    private:
        int dia;
        int mes;
        int anio;

public:
        DTFecha();
        DTFecha(int dia, int mes, int anio);

        //GETTERS
        int getDia() const;
        int getMes() const;
        int getAnio() const;

        //SETTERS
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
};



#endif //LABORATORIO3_DTFECHA_H
