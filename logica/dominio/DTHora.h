#ifndef LABORATORIO3_DTHORA_H
#define LABORATORIO3_DTHORA_H


class DTHora {
    private:
        int hora;
        int minuto;
        int segundo;

public:
        DTHora();
        DTHora(int hora, int minuto, int segundo);

        //GETTERS
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        //SETTERS
        void setHora(int hora);
        void setMinuto(int minuto);
        void setSegundo(int segundo);
};

#endif
