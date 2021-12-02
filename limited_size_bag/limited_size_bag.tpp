#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {size=0;

}
  

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  //returning pointer to array
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size >= MAXSIZE){//check if size isnt full
    return false;
  }

  data[size] = item;
  ++size;//incrementing size
  
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
   if(size == 0) return false;//check if bag is not empty

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;//decremnting size
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return (getCurrentSize()==0);
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  size=0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
   std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) ++freq;//incrementing freq if item is found
  }
  
  return freq;
};
