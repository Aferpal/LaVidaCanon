#include "./ArrayList.h"
#include<string>
#include<iostream>

lvc::List<std::string>* split(const std::string& str, const std::string& delimiter){
    lvc::List<std::string>* res = new lvc::ArrayList<std::string>;
    int lastSearch = 0;
    while(str.length() > lastSearch){
        int p = str.find(delimiter, lastSearch);
        if( p == std::string::npos){
            p = str.size() - lastSearch;
        }else{
            p = p-lastSearch;
        }
        res->append(str.substr(lastSearch, p));
        
        lastSearch += res->get(res->size()-1).length() + delimiter.size();

        if(res->get(res->size()-1).size() == 0){
            res->remove("");
        }
    }
    return res;
}