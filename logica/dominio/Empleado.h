#ifndef LABORATORIO3_EMPLEADO_H
#define LABORATORIO3_EMPLEADO_H

#include <string>
using namespace std;

class Empleado {
    private:
        string nombreCompleto, direccion, correo;

    public:
        Empleado(string nombreCompleto, string direccion, string correo);
        ~Empleado();

        string getNombreCompleto();
        string getDireccion();
        string getCorreo();

        void setNombreCompleto(string nombreCompleto);
        void setDireccion(string direccion);
        void setCorreo(string correo);
};

#endif