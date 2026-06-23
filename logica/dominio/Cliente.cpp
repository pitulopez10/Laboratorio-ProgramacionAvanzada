#include "Cliente.h"
#include "Calificacion.h"
#include "Venta.h"
using namespace std;

//CONSTRUCTORES
ClienteRegistrado :: ClienteRegistrado(int rut, string nombreCompleto, string direccion, string correo, string password) {
    this-> rut = rut;
    this-> nombreCompleto = nombreCompleto;
    this-> direccion = direccion;
    this-> correo = correo;
    this-> password = password;
}

//GETTERS
int ClienteRegistrado::getRut() const{
    return rut;
}

string ClienteRegistrado::getNombreCompleto() const{
    return nombreCompleto;
}

string ClienteRegistrado::getDireccion() const{
    return direccion;
}

string ClienteRegistrado::getCorreo() const{
    return correo;
}

string ClienteRegistrado::getPassword() const {
    return password;
}

vector<Calificacion*> ClienteRegistrado::getCalificaciones() const{
    return calificaciones;
}

vector<Venta*> ClienteRegistrado::getVentas() const {
    return ventas;
}

//SETTERS
void ClienteRegistrado::setNombreCompleto(string nombreCompleto) {
    this-> nombreCompleto = nombreCompleto;
}

void ClienteRegistrado::setDireccion(string direccion) {
    this-> direccion = direccion;
}
void ClienteRegistrado::setCorreo(string correo) {
    this-> correo = correo;
}

void ClienteRegistrado::setPassword(string password) {
    this-> password = password;
}

//METODOS
void ClienteRegistrado::agregarCalificacion(Calificacion* calificacion) {
    calificaciones.push_back(calificacion);
}

void ClienteRegistrado::agregarVenta(Venta* venta) {
    ventas.push_back(venta);
}