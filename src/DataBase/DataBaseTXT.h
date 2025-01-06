#pragma once
#include "./DataBaseConnection.h"
#include <fstream>
#include <sstream>
namespace lvc
{
    class DataBaseTXT : public DataBaseConnection{
        private:
            std::string root;
            std::ifstream f;
        public:

            DataBaseTXT(const std::string&);

            void connect();

            void selectProgramas(List<Programa>*);

            void insertPrograma(const Programa&);

            void updatePrograma(const Programa&);

            void deletePrograma(const Programa&);

            ~DataBaseTXT(){
                if(this->f.is_open()){
                    this->f.close();
                }
            }

    };

    DataBaseTXT::DataBaseTXT(const std::string& r): root{r}{

    }

    void DataBaseTXT::connect(){
        this->f = std::ifstream(this->root+"/programas.txt");

        if( !this->f.is_open()){
            throw 0;
        }

    }

    void DataBaseTXT::selectProgramas(List<Programa>* list){
        this->f.close();
        std::string finalroot = this->root + "/programas.txt";
        this->f = std::ifstream(finalroot);
        
        if( list == nullptr){
            return;
        }

        if( this->f ){
            std::string line;
            Programa p;
            while(this->f >> line){
                p.setNombre(line.substr(0, line.find(';')));
                p.setDirectorio(line.substr(line.find(';')+1, line.length()-line.find(';')-1));
                (list)->append(p);
            }
        }
    }

    void DataBaseTXT::insertPrograma(const Programa& p){
        List<Programa>* list = new ArrayList<Programa>;
        this->selectProgramas(list);
        if( list->contains(p)){
            return;
        }
        list->append(p);
        std::ofstream w{this->root+"/programas.txt"};
        if( w ){
            for( int i = 0; i<list->size(); i++){
                w << list->get(i).getNombre() << ';' << list->get(i).getDirectorio() << '\n';
            }
        }
        delete list;
        w.close();
    };

    void DataBaseTXT::updatePrograma(const Programa& p){
        List<Programa>* list = new ArrayList<Programa>;
        this->selectProgramas(list);
        list->remove(p);
        list->append(p);
        std::ofstream w{this->root+"/programas.txt"};
        if( w ){
            for( int i = 0; i<list->size(); i++){
                w << list->get(i).getNombre() << ';' << list->get(i).getDirectorio() << '\n';
            }
        }
        delete list;
        w.close();
    };

    void DataBaseTXT::deletePrograma(const Programa& p){
        List<Programa>* list = new ArrayList<Programa>;
        this->selectProgramas(list);
        if( !list->contains(p) ){
            return;
        }
        list->remove(p);
        std::ofstream w{this->root+"/programas.txt"};
        if( w ){
            for( int i = 0; i<list->size(); i++){
                w << list->get(i).getNombre() << ';' << list->get(i).getDirectorio() << '\n';
            }
        }
        delete list;
        w.close();
    };
} // namespace lvc

