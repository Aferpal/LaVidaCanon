#pragma once
#include<string>

class Entorno{
    private:
        std::string nombre;
        std::string comando;
    public:
        Entorno(const std::string& n, const std::string c){
            this->nombre = n;
            this->comando = c;
        }

        const std::string& getNombre(){
            return this->nombre;
        }

        const std::string& getComando(){
            return this->comando;
        }

        void setNombre(const std::string& s){
            this->nombre = s;
        }

        void setComando(const std::string& c){
            this->comando = c;
        }

};