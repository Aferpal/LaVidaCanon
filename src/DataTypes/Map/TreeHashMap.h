#include "./SortedMap.h"
#include "../List/ArrayList.h"
#include "../Tree/BSTree.h"

namespace lvc
{
    template<class K, class V>
    class TreeMap: public SortedMap<K, V>{
        private:
            BSTree<Entry<K, V>> data;
        public:

            virtual ~TreeMap();

            V*const get(const K&);

            const V*const get(const K&)const;

            V*const operator[](const K&);

            const V*const operator[](const K&)const;

            void insert(const K&, const V&);

            void remove(const K&);

            void clear();

            int size()const;

            bool isEmpty()const;

            bool contains(const K&)const;

    };

    template<class K, class V>
    bool TreeMap<K, V>::contains(const K& key) const {
        return this->data.contains(key);
    }

    template<class K, class V>
    bool TreeMap<K, V>::isEmpty() const {
        return this->data.isEmpty();
    }

    template<class K, class V>
    int TreeMap<K, V>::size() const {
        return this->data.size();
    }

    template<class K, class V>
    void TreeMap<K, V>::clear(){
        return this->data.clear();
    }

    template<class K, class V>
    void TreeMap<K, V>::remove(const K& key){
        return this->data.remove(key);
    }

    template<class K, class V>
    void TreeMap<K, V>::insert(const K& key, const V& value){
        return this->data.insert(Entry{key, value});
    }

    template<class K, class V>
    V*const TreeMap<K, V>::get(const K& key){
        Entry<K, V> * d = this->data.search(key);
        return d != nullptr ? &(d->getValue()) : nullptr;
    }

    template<class K, class V>
    const V*const TreeMap<K, V>::get(const K& key)const{
        const Entry<K, V> * d = this->data.search(key);
        return d != nullptr ? &(d->getValue()) : nullptr;
    }

    template<class K, class V>
    V* const TreeMap<K, V>::operator[](const K& key){
        Entry<K, V> * d = this->data.search(key);
        return d != nullptr ? &(d->getValue()) : nullptr;
    }

    template<class K, class V>
    const V*const TreeMap<K, V>::operator[](const K& key)const{
        const Entry<K, V> * d = this->data.search(key);
        return d != nullptr ? &(d->getValue()) : nullptr;
    }

    template<class K, class V>
    TreeMap<K, V>::~TreeMap(){

    }
} // namespace lvc
