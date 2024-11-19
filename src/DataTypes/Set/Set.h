#pragma once
#include "../List/List.h"
namespace lvc{
    template<class T>
    class Set{
        private:

        public:
            virtual ~Set(){};
            virtual void insert(T) = 0;
            virtual void remove(T) = 0;
            virtual bool contains(T) = 0;
            virtual bool isEmpty() = 0;
            virtual int size() = 0;
    };
}
