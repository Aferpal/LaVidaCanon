#pragma once
#include "./List.h"

namespace lvc{
    template<class T>
    class ArrayList: public List<T>{
        private: 

            T* m_Data;

            int m_Size;

            int m_Capacity;

            constexpr static int DEFAULT_CAPACITY = 8;

            constexpr static int RESIZE_FACTOR = 8;

        public:

            ArrayList(int);

            ArrayList();

            virtual ~ArrayList();

            void resize();

            void ensureCapacity();

        //insertion methods
            virtual void insert(int,T);

            virtual void append(T);

            virtual void prepend(T);

            virtual void set(int, T);


        //remove methods
            virtual void remove(int);


        //read methods
            virtual T& get(int);

            virtual const T& get(int) const;

            virtual T& operator[](int);

            virtual const T& operator[](int) const;


        //other methods
            virtual bool isEmpty() const;

            virtual bool contains(const T&);

            virtual int size() const;
            
        //clear methods
            virtual void clear();
    };

    template<class T>
    ArrayList<T>::ArrayList(int size) {
        if(size < 0){
            size = DEFAULT_CAPACITY;
        }
        this->m_Data = new T[size];
        this->m_Size = 0;
        this->m_Capacity = size;
    }

    template<class T>
    ArrayList<T>::ArrayList() {
        this->m_Data = new T[DEFAULT_CAPACITY];
        this->m_Size = 0;
        this->m_Capacity = DEFAULT_CAPACITY;
    }

    template<class T>
    void ArrayList<T>::resize(){
        T* old_data = this->m_Data;
        this->m_Data = new T[RESIZE_FACTOR*this->m_Capacity];
        for( int i = 0; i < this->m_Size; i++){
            *( this->m_Data + i ) = *( old_data + i );
        }
        this->m_Capacity *= RESIZE_FACTOR;

        if(old_data != nullptr){
            delete[] old_data;
        }
    }

    template<class T>
    void ArrayList<T>::ensureCapacity(){
        if(this->m_Capacity == this->m_Size){
            this->resize();
        }
    }

    template<class T>
    void ArrayList<T>::append(T element){
        this->ensureCapacity();
        *( this->m_Data + this->m_Size ) = element;
        this->m_Size++;
    } 

    template<class T>
    void ArrayList<T>::insert(int pos, T element){

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        this->ensureCapacity();

        T aux;
        
        for( int i = pos; i <= this->m_Size; i++ ){
            aux = * ( this->m_Data + i);
            *( this->m_Data + i ) = element;
            element = aux; 
        }
        
        this->m_Size++;

    } 

    template<class T>
    void ArrayList<T>::prepend(T element){
        if(this->isEmpty()){
            append(element);
        }else{
            insert(0, element);
        }
    } 

    template<class T>
    void ArrayList<T>::set(int pos, T element){
        
        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        *( this->m_Data + pos ) = element;
    }   

    template<class T>
    void ArrayList<T>::remove(int pos){

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }
        
        for( int i = pos; i < this->m_Size-1; i++ ){
            *( this->m_Data + i ) = * ( this->m_Data + i + 1 );
        }
        
        this->m_Size--;

    }   

    template<class T>
    T& ArrayList<T>::get(int pos){

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        return *( this->m_Data + pos);

    }

    template<class T>
    const T& ArrayList<T>::get(int pos) const {

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        return *( this->m_Data + pos);

    }

    template<class T>
    T& ArrayList<T>::operator[](int pos){

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        return *( this->m_Data + pos);

    }

    template<class T>
    const T& ArrayList<T>::operator[](int pos) const {

        if( pos < 0 || pos > this->m_Size){
            throw 0;
        }

        return *( this->m_Data + pos);

    }

    template<class T>
    bool ArrayList<T>::isEmpty() const{

        return this->m_Size == 0;
    
    }

    template<class T>
    int ArrayList<T>::size() const{
        
        return this->m_Size;

    }

    template<class T>
    bool ArrayList<T>::contains(const T& element){

        bool found = false;
        
        for( int i = 0; i < this->m_Size && !found; i++ ){
        
            found = element == *( this->m_Data + i);
        
        }

        return found;

    }

    template<class T>
    void ArrayList<T>::clear(){

        this->m_Size = 0;

    }

    template<class T>
    ArrayList<T>::~ArrayList(){
        
        if(this->m_Data != nullptr){
            delete[] m_Data;
        }

        this->m_Size = 0;
        
        this->m_Capacity = 0;

    }
}