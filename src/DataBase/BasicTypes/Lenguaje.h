#pragma once 
#include <string>

class Lenguaje{
    private: 
        std::string nombre;
    public: 
        Lenguaje(const std::string& s){
            this->nombre = s;
        }   

        Lenguaje(const Lenguaje& otro){
            this->nombre = otro.nombre;
        }   

        const std::string& getNombre(){
            return this->nombre;
        }

        void setNombre(const std::string& s){
            this->nombre = s;
        }

};