#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  itemCount=0;
  for(int i=0;i<=arraySize;i++){
    items[i]=0;
  }
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  if(itemCount==0)return true;
  else return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return arraySize;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
 if(position>(arraySize-1)){
   return false;
 }
 else if(items[position+1]==0)
 {
 items[position+1]=item;
 return true;
 itemCount++;}
 else{
   for(int i=arraySize-1;i>=position;i--){
     items[i]=items[i-1];
     
   }
   items[position-1]=item;
   return true;
   itemCount++;
 }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
if(items=nullptr){
  return false;
}
if(position<1|| position+1>arraySize){
  return false;
}
else{
items[position+1]=0;
return true;
itemCount--;
}

}

template <typename T>
void ArrayList<T>::clear() {
  items=nullptr;
  itemCount=0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {

  return items[position+1];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  items[position+1]=newValue;
}
