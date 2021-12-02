#include "Database.hpp"

template <typename T>
Database<T>::Database() {
    // TODO
}

template <typename T>
bool Database<T>::isEmpty() {
    // TODO
    return lst.isEmpty();
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() {
    // TODO
    return lst.getLength();
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, const T& item) {
    // TODO
    if(key1.insert(key1,lst.getLength())&&key2.insert(key2,lst.getLength())){
        lst.insert(lst.getLength,item);
        return true;
    }
    else return false;
}

template <typename T>
bool Database<T>::remove(std::string key) {
    // TODO
    T item=0;
    bool b=key1.retrieve(key,item);
    if(b==false){
        b=key2.retrieve(key,item);
    }
    lst.remove(item);
    return b;
}

template <typename T>
void Database<T>::clear() {
    // TODO
    lst.clear();
    key1.destroy();
    key2.destroy();
}

template <typename T>
T Database<T>::getValue(std::string key) {
    // TODO
     T item=0;
    bool b=key1.retrieve(key,item);
    if(b==false){
        b=key2.retrieve(key,item);
    }
    lst.getEntry(item);
}

template <typename T>
bool Database<T>::contains(std::string key) {
    // TODO
     T item=0;
    bool b=key1.retrieve(key,item);
    if(b==false){
        b=key2.retrieve(key,item);
    }
    for(int i=0;i<lst.getLength();i++){
        if(lst.getEntry==item){
            return true;
        }
    }
    return false;
}

template <typename T>
std::vector<T> Database<T>::getAllEntries(int keyIndex) {
    // TODO    
    std::vector<T> entries;
}