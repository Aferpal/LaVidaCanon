#include<iostream>
#include<string>
#include<sstream>
#include "./CommandEngine/CommandEngine.h"

void decode(const std::string& input, std::string* com, std::string* args){
    std::stringstream ss {input};
    ss>>*com;
    int in = input.find(' ');
    if(in != -1){
        *args = input.substr(input.find(' '), input.size()-input.find(' '));
    }
}

int main(){
    system("clear");
    lvc::CommandEngine commandEngine;

    commandEngine.insertCommand("echo", [](const std::string& params){
        std::cout<<'\t'<<params<<'\n';
    });

    commandEngine.insertCommand("clear", [](const std::string& params){
        system("clear");
    });

    commandEngine.insertCommand("exit", [](const std::string& params){
        system("clear");
        exit(0);
    });

    commandEngine.insertCommand("add", [](const std::string& params){
        std::stringstream ss{params};
        int a, b;
        ss>>a>>b;
        std::cout<<"\tLa suma es "<<a+b<<'\n';
    });

    std::string input;
    std::string com;
    std::string args;
    bool exit = false;
    while(!exit){
        com = "";
        args = "";
        std::cout<<"> ";
        getline(std::cin, input);
        decode(input, &com, &args);
        commandEngine.processCommand(com, args);
    }
    system("clear");
    return 0;
}