#pragma once
namespace lvc{
    template<class T>
    class List{
        public:
            virtual ~List(){}


        //insertion methods
            virtual void insert(int,T) = 0;

            virtual void append(T) = 0;

            virtual void prepend(T) = 0;

            virtual void set(int, T) = 0;


        //remove methods
            virtual void remove(T) = 0;


        //read methods
            virtual T& get(int) = 0;

            virtual const T& get(int) const = 0;

            virtual T& operator[](int) = 0;

            virtual const T& operator[](int) const = 0;


        //other methods
            virtual bool isEmpty() const = 0;

            virtual bool contains(const T&) = 0;

            virtual int size() const = 0;
            
        //clear methods
            virtual void clear() = 0;
    };
}