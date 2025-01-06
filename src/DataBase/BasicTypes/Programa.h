#pragma once
#include<string>

class Programa{
    private:
        std::string nombre;
        std::string directorio;
    public:
        Programa(){}

        Programa(const std::string& n, const std::string d){
            this->nombre = n;
            this->directorio = d;
        }

        const std::string& getNombre() const {
            return this->nombre;
        }

        const std::string& getDirectorio() const {
            return this->directorio;
        }

        void setNombre(const std::string& s){
            this->nombre = s;
        }

        void setDirectorio(const std::string& d){
            this->directorio = d;
        }

        bool operator==(const Programa& otro){
            return this->nombre == otro.nombre;
        }


};