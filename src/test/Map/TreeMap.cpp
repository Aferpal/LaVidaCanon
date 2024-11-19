#include "../../DataTypes/Map/TreeHashMap.h"
#include <iostream>

template<class K, class V>
void printDictionary(const lvc::TreeMap<K, V>& l){
    printNode(l.m_Root);
    std::cout<<'\n';
}

int main(){
    lvc::TreeMap<std::string, int> dictionary;
    if(!dictionary.isEmpty()){
        throw 0;
    }
    dictionary.insert("Hola", 0);
    dictionary.insert("Adios", 2);
    dictionary.get("Hola");
    std::cout<<*dictionary.get("Hola")<<'\n';
    (*dictionary["Hola"])++;
    std::cout<<*dictionary.get("Hola")<<'\n';
    if(dictionary.contains("PATATA")){
        std::cout<<"Contiene PATATA"<<'\n';
    }else{
        std::cout<<"No contiene PATATA"<<'\n';
    }

    if(dictionary.contains("Adios")){
        std::cout<<"Contiene Adios"<<'\n';
    }else{
        std::cout<<"No contiene Adios"<<'\n';
    }
    dictionary.clear();
    if(!dictionary.isEmpty()){
        throw 0;
    }
    dictionary.insert("Adios", 0);
    dictionary.insert("Adios", 10);
    std::cout<<*(dictionary["Adios"])<<'\n';
    return 0;
}