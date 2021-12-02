#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  size=0;
  items=new T[size];
  }
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag &x){

}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] items;//deallocating memory
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  //returning pointer to array
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{

  
  
    items[size]=item;
    size++;//incrementing size

  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
    if(size == 0) return false;//cannot remove from empty bag

  std::size_t temp = 0;
  for(std::size_t i = 0; i < size; i++){//incrementing to find item we want to remove
    if(items[i] == item) break;
    temp=temp+1;
  }

  size=size-1;//decrementing size afte removal
  for(std::size_t i = temp; i < size; ++i){
    items[i] = items[i+1];//shifting array to the left
  }

  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if(size==0) return true;

  else return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
return(getFrequencyOf(item)!=0);
}

template<typename T>
void DynamicBag<T>::clear(){
 size=0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
    std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(items[i] == item) ++freq;//checking for item and icrementing local variable if found
  }
  
  return freq;
}
