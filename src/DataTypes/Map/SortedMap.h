#pragma once

namespace lvc
{


    template<class K, class V>
    class Entry{
        private:
            K key;
            V value;
        public:

            Entry(const K& k, const V& v){
                this->key = k;
                this->value = v;
            }

            Entry(const K& k){
                this->key = k;
            }

            bool operator<(const Entry& other){
                return this->key < other.key;
            }

            bool operator>(const Entry& other){
                return this->key > other.key;
            }

            bool operator==(const Entry& other){
                return this->key == other.key;
            }

            bool operator<=(const Entry& other){
                return this->key <= other.key;
            }

            bool operator>=(const Entry& other){
                return this->key >= other.key;
            }

            K& getKey(){
                return this->key;
            }

            V& getValue(){
                return this->value;
            }

            const K& getKey()const{
                return this->key;
            }

            const V& getValue()const{
                return this->value;
            }
    };

    template<class K, class V>
    class SortedMap{
        public:

            virtual ~SortedMap(){}

            virtual V*const get(const K&) = 0;

            virtual const V* const get(const K&)const = 0;

            virtual V* const operator[](const K&) = 0;

            virtual const V* const operator[](const K&)const = 0;

            virtual void insert(const K&, const V&) = 0;

            virtual void remove(const K&) = 0;

            virtual void clear() = 0;

            virtual int size() const= 0;

            virtual bool isEmpty() const= 0;

            virtual bool contains(const K&) const= 0;

  };  
} 