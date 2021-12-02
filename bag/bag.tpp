#include "bag.hpp"

// empty implementation                                                                                                     

template <typename T> Bag<T>::Bag() {
    size=0;
    numberOfItems=0;
}

template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { 
    return size; }

template <typename T> bool Bag<T>::isEmpty() const { 
if(getCurrentSize()==0)
{
    return true;
} 
else return false;
}

template <typename T> bool Bag<T>::add(const T& entry) { 
   if(item.size()>size){
       return false;
       }else{
           item.push_back(entry);
           size++;
           numberOfItems++;
           return true;
       }
   
    }

template <typename T> bool Bag<T>::remove(const T& entry) { 
   for(int i=0;i<item.size();i++){
       if(item.at(i)==entry){
           size--;
           numberOfItems--;
           return true;
       }

   }
   return false;
}


template <typename T> void Bag<T>::clear() {
    item.clear();
    size=0;
    numberOfItems=0;
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const { 
    return numberOfItems; }

template <typename T> bool Bag<T>::contains(const T& entry) const { 
    if(numberOfItems>1){
 return true;       
}
else return false; }

