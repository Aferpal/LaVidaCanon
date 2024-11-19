#include "../../DataTypes/Tree/BSTree.h"
#include <iostream>

template<class T>
void printNode(const lvc::Node<T>* const n ){
    if( n != nullptr){
        printNode(n->left);
        std::cout<<n->data<<' ';
        printNode(n->right);
    }   
    
}

template<class T>
void printtree(const lvc::BSTree<T>& l){
    printNode(l.m_Root);
    std::cout<<'\n';
}

int main(){
    lvc::BSTree<int> tree{};
    tree.insert(10);
    tree.insert(1);
    tree.insert(2);
    tree.insert(20);
    printtree<int>(tree);
    tree.remove(2);
    if( ! tree.contains(1)){
        throw 0;
    }
    printtree<int>(tree);
    tree.clear();
    return 0;
}