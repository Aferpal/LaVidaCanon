#pragma once
#include "./BasicTypes/Entorno.h"
#include "./BasicTypes/Lenguaje.h"
#include "./BasicTypes/Programa.h"
#include "../DataTypes/List/List.h"
#include "../DataTypes/List/ArrayList.h"

namespace lvc{

    class DataBaseConnection{
        private:

        public:
            virtual ~DataBaseConnection(){};
            
            virtual void connect() = 0;

            virtual void selectProgramas(List<Programa>*) = 0;

            virtual void insertPrograma(const Programa&) = 0;

            virtual void updatePrograma(const Programa&) = 0;

            virtual bool deletePrograma(const Programa&) = 0;


    };

}