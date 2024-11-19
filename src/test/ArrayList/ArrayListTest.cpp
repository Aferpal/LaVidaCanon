#include "../../DataTypes/List/ArrayList.h"
#include <iostream>


template<class T>
void printList(const lvc::ArrayList<T>& l){
    for( int i = 0; i < l.size(); i++){
        std::cout<< l.get(i) << ' ';
    }
    std::cout<<'\n';
}

int main(){
    lvc::ArrayList<int> list {2};
    list.append(10);
    list.prepend(1);
    list.insert(1, 2);
    list.append(20);
    printList<int>(list);
    list.remove(2);
    if( ! list.contains(1)){
        throw 0;
    }
    printList<int>(list);
    list.clear();
    return 0;
}