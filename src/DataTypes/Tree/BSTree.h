#pragma once
#include "./Tree.h"

namespace lvc{

    template<class E>
    class Node{
        public:
            E data;
            Node<E>* right;
            Node<E>* left;
            Node(E data){
                this->data = data;
                this->right = nullptr;
                this->left = nullptr;
            }
            static int height(Node<E>* n){
                if( n == nullptr){
                    return 0;
                }
                int l = height(n->left);
                int r = height(n->right);
                return l > r ? l+1 : r+1;
            }
    };

    template<class T>
    class BSTree : public Tree<T> {
        
        private:

            

            int m_Size;

            //const Node<T>** findPositionWhereToInsert(const T&);

        public:
            Node<T>* m_Root;

            BSTree();

            virtual ~BSTree();



            //insert methods
            virtual void insert(const T&);


            //remove methods
            virtual void remove(const T&);

            virtual void clear();


            //read methods
            virtual bool contains(const T&) const;

            virtual T * const search(const T&);

            virtual const T * const search(const T&) const;


            //size related methods
            virtual bool isEmpty() const;

            virtual int size() const;
            
            virtual int height() const;
    };

    template<class T>
    BSTree<T>::BSTree(){

        this->m_Root = nullptr;
        this->m_Size = 0;

    }

    template<class T>
    bool BSTree<T>::isEmpty()const{

        return (this->m_Size == 0 
            || this->m_Root == nullptr);

    }

    template<class T>
    int BSTree<T>::size()const{

        return this->m_Size;

    }


    template<class T>
    int BSTree<T>::height()const{

        return Node<T>::height(this->m_Root);

    }



    template<class T>
    void BSTree<T>::insert(const T& element){

        Node<T>** pos = &this->m_Root;

        bool found = false;

        while(*pos != nullptr && !found){

            if( (*pos)->data == element ){

                (*pos)->data = element;
                found = true;

            }else if( (*pos)->data < element){

                pos = &((*pos)->right);

            }else{

                pos = &((*pos)->left);

            }
        }

        if(*pos == nullptr){
            *pos = new Node<T>{element};
        }

        this->m_Size++;
    }


    template<class T>
    T *const BSTree<T>::search(const T& element){
        Node<T>** pos = &this->m_Root;
        bool found = false;
        while(*pos != nullptr && !found){

            if( (*pos)->data == element ){

                (*pos)->data = element;
                found = true;

            }else if( (*pos)->data < element){

                pos = &((*pos)->right);

            }else{

                pos = &((*pos)->left);

            }
        }

        return found ? &((*pos)->data) : nullptr;

    }

    template<class T>
    const T *const BSTree<T>::search(const T& element)const{
        Node<T>*const* pos = &(this->m_Root);
        bool found = false;
        while(*pos != nullptr && !found){

            if( (*pos)->data == element ){

                (*pos)->data = element;
                found = true;

            }else if( (*pos)->data < element){

                pos = &((*pos)->right);

            }else{

                pos = &((*pos)->left);

            }
        }

        return found ? &((*pos)->data) : nullptr;

    }

    template<class T>
    bool BSTree<T>::contains(const T& element)const{

        return this->search(element) != nullptr;

    }
    


    template<class T>
    void deleteNode(Node<T>** n){
        if( *n != nullptr ){
            if( (*n)->right == nullptr){
                *n = (*n)->left;
            }else if( (*n)->left == nullptr){
                *n = (*n)->right;
            }else{

                Node<T>** min = n;
                while((*min)->left != nullptr){
                   min = &((*min)->left);
                }
                (*min)->left = (*n)->left;
                (*min)->right = (*n)->right;
                *n = *min;
                *min = nullptr;

            }
        }
    }

    template<class T>
    void BSTree<T>::remove(const T& element){
        
        Node<T>** pos = &(this->m_Root);
        bool found = false;
        while(*pos != nullptr && !found){

            if( (*pos)->data == element ){

                (*pos)->data = element;
                found = true;

            }else if( (*pos)->data < element){

                pos = &((*pos)->right);

            }else{

                pos = &((*pos)->left);

            }
        }
        if(found){
            deleteNode(pos);
            this->m_Size--;
        }

    }

    template<class T>
    void clearR(Node<T>* node){
        if(node != nullptr){
            clearR(node->right);
            clearR(node->left);
            delete node;
        }
    }

    template<class T>
    void BSTree<T>::clear(){
        clearR(this->m_Root);
        this->m_Root = nullptr;
        this->m_Size = 0;
    }

    template<class T>
    BSTree<T>::~BSTree(){
        clear();
        this->m_Size = 0;
    }





    


}