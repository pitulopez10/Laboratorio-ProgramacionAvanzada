#ifndef LABORATORIO3_CLIENTE_H
#define LABORATORIO3_CLIENTE_H

#include <string>
using namespace std;

class Cliente {
};

class ClienteRegistrado : public Cliente {
    private:
        int rut;
        string nombreCompleto, direccion, correo;
    public:
        ClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo);

        //GETTERS
        int getRut();
        string getNombreCompleto();
        string getDireccion();
        string getCorreo();

        //SETTERS
        void setNombreCompleto(string nombreCompleto);
        void setDireccion(string direccion);
        void setCorreo(string correo);
};
#endif //LABORATORIO3_CLIENTE_H
