#pragma once
#include "../CommandEngine/CommandEngine.h"
#include "../DataBase/DataBaseTXT.h"
#include <iostream>
#include <iomanip>


namespace lvc
{
    class App{
        private:
            CommandEngine cmEngine;
            DataBaseConnection* db;
            bool _exit;
            static void echo(const std::string&);

            static void clear(const std::string&);

            void initializeCommands();

            void safeExit();

            void processCommand(const std::string&);
        public:
            App(DataBaseConnection*);

            void start();
    };

    App::App(DataBaseConnection* _db){
        this->db = _db;
        this->_exit = false;
        initializeCommands();
        clear("");
        this->start();
    }

    void App::initializeCommands(){

        this->cmEngine.insertCommand("echo", echo);

        this->cmEngine.insertCommand("clear", clear);

        this->cmEngine.insertCommand("select", [this](const std::string& params){
            lvc::List<Programa>* list = new lvc::ArrayList<Programa>;
            db->selectProgramas(list);
            std::cout<<"\n"<<std::setw(64)<<std::setfill('-')<<"\n";
            std::cout<<"|  Nombre          |    Directorio                            |\n";
            std::cout<<std::setw(64)<<std::setfill('-')<<'\n';
            for( int i = 0; i <list->size(); i++){
                Programa& p = list->get(i);
                std::cout<<"|  "<<std::setfill(' ')<<std::setw(16)<<std::left<<p.getNombre()<<"|    "<<std::setw(38)<<p.getDirectorio()<<"|\n";
            }
            std::cout<<std::setw(64)<<std::setfill('-')<<std::right<<'\n'<<std::endl;
            std::cout<<"\n";
            delete list;
        });

        this->cmEngine.insertCommand("exit", [this](const std::string& params){
            clear("");
            safeExit();
        });
    }

    void App::start(){

        std::string input;
        while(!_exit){
            std::cout<<"> ";
            getline(std::cin, input);
            this->processCommand(input);
        }


    }

    void App::safeExit(){
        delete this->db;
        _exit=true;
    }

    void App::echo(const std::string& params){
        std::cout<<'\t'<<params<<'\n';
    }

    void App::clear(const std::string& params){
        system("clear");
    }

    void App::processCommand(const std::string& input){
        std::stringstream ss {input};
        std::string com, args;
        ss>>com;
        int in = input.find(' ');
        if(in != -1){
            args = input.substr(input.find(' '), input.size()-input.find(' '));
        }
        this->cmEngine.processCommand(com, args);
    }
} // namespace lvc
