#include "DTHora.h"

//CONSTRUCTORES
DTHora::DTHora() {

}
DTHora::DTHora(int hora, int minuto, int segundo) {
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

//GETTERS
int DTHora::getHora() const {
    return this->hora;
}
int DTHora::getMinuto() const {
    return this->minuto;
}
int DTHora::getSegundo() const {
    return this->segundo;
}

//SETTERS
void DTHora::setHora(int hora) {
    this->hora = hora;
}
void DTHora::setMinuto(int minuto) {
    this->minuto = minuto;
}
void DTHora::setSegundo(int segundo) {
    this->segundo = segundo;
}

