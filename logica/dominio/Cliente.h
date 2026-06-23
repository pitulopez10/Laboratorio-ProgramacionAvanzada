#ifndef LABORATORIO3_CLIENTE_H
#define LABORATORIO3_CLIENTE_H

#include <string>
#include <vector>

#include "Venta.h"
using namespace std;

class Calificacion;
class Venta;

class Cliente {
};

class ClienteRegistrado : public Cliente {
    private:
        int rut;
        string nombreCompleto, direccion, correo, password;

        vector<Calificacion*> calificaciones;
        vector<Venta*> ventas;

    public:
        ClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo, string password);

        //GETTERS
        int getRut() const;
        string getNombreCompleto() const;
        string getDireccion() const;
        string getCorreo() const;
        string getPassword() const;
        vector<Calificacion*> getCalificaciones() const;

        vector<Venta *> getVentas() const;

        //SETTERS
        void setNombreCompleto(string nombreCompleto);
        void setDireccion(string direccion);
        void setCorreo(string correo);
        void setPassword(string password);

        //METODOS
        void agregarCalificacion(Calificacion* calificacion);
};
#endif //LABORATORIO3_CLIENTE_H
