#ifndef LABORATORIO3_EMPLEADO_H
#define LABORATORIO3_EMPLEADO_H

#include <string>
using namespace std;

class Empleado {
    private:
        string nombreCompleto, direccion, correo, password;

    public:
        Empleado(string nombreCompleto, string direccion, string correo, string password);
        ~Empleado();

        string getNombreCompleto();
        string getDireccion();
        string getCorreo();
        string getPassword();

        void setNombreCompleto(string nombreCompleto);
        void setDireccion(string direccion);
        void setCorreo(string correo);
        void setPassword(string password);
};

#endif