#include<iostream>
#include<string>
#include<sstream>

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
        if(com.compare("echo") == 0){
            std::cout<<'\t'<<args<<'\n';
        }else if(com.compare("exit") == 0){
            exit = true;
        }else if(com.compare("") == 0){

        }else if(com.compare("clear") == 0){
            system("clear");
        }else{
            std::cout<<"\tCommand "<<com<<" not found. Use --help\n";
        }
    }
    system("clear");
    return 0;
}