#pragma once

namespace lvc
{
    template<class T>
    class Tree{
        public:

            virtual ~Tree(){}


            //insert methods
            virtual void insert(const T&) = 0;


            //remove methods
            virtual void remove(const T&) = 0;

            virtual void clear() = 0;


            //read methods
            virtual bool contains(const T&) const = 0;

            virtual T *const search(const T&) = 0;

            virtual const T *const search(const T&) const = 0;


            //size related methods
            virtual bool isEmpty() const= 0;

            virtual int size() const= 0;
            
            virtual int height() const= 0;

    };  
} 
