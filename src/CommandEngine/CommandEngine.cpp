#include "./CommandEngine.h"

using namespace lvc;

void CommandEngine::insertCommand(const std::string& s, const std::function<void(const std::string&)>& f){
    this->commands.insert(s, f);
}

void CommandEngine::processCommand(const std::string& command, const std::string& params){
    const std::function<void(const std::string&)>* f = this->commands.get(command);
    if( f != nullptr ){
        (*f)(params);
    }else{
        
    }
}