#ifndef LABORATORIO3_ADMIN_H
#define LABORATORIO3_ADMIN_H

#include <string>
using namespace std;

class Admin {
    private:
        string nombreCompleto, direccion, correo, password;

    public:
        Admin(string nombreCompleto, string direccion, string correo, string password);
        ~Admin();

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