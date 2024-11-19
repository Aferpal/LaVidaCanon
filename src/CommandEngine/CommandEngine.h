#pragma once
#include "../DataTypes/Map/TreeHashMap.h"
#include <string>
#include<functional>
namespace lvc
{
    
    class CommandEngine{
        private:
            TreeMap<std::string, std::function<void(const std::string&)>> commands;
        public:
            void insertCommand(const std::string& s, const std::function<void(const std::string&)>& f);
            void processCommand(const std::string& command, const std::string& params);
    };

} // namespace lvc

