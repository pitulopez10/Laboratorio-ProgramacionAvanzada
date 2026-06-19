#ifndef LABORATORIO3_ADMIN_H
#define LABORATORIO3_ADMIN_H

#include <string>
using namespace std;

class Admin {
    private:
        string nombreCompleto, direccion, correo;

    public:
        Admin(string nombreCompleto, string direccion, string correo);
        ~Admin();

        string getNombreCompleto();
        string getDireccion();
        string getCorreo();

        void setNombreCompleto(string nombreCompleto);
        void setDireccion(string direccion);
        void setCorreo(string correo);
};

#endif