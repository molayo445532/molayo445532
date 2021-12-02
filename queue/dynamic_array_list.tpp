#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  size=0;
  
  capacity=10;
   data=new T [capacity];
   for(int i=0;i<capacity;i++){
     data[i]=0;
   }
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  data=new T[x.size];
  size=x.size;
  //copy data
  for(int i=0; i<size; i++){
    data[i]=x.data[i];
  }
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  
 delete [] data;
  data=nullptr;
  size=0;
  
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  
  data=new T[x.size];
  //set size
  size=x.size;
  //copy data
  for(int i=0; i<size; i++){
    data[i]=x.data[i];
  }
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
  
  int tempSize=x.size;
  //swap sizes
  x.size=y.size;
  y.size=tempSize;
  ///create data pointer temp
  T* tempData=x.data;
  //swap data pointers
  x.data=y.data;
  y.data=tempData;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  if(size==0)
    return true;
  else
    return false;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  if(data[capacity]!=0){
    data[position]=item;
    size++;
  }
  else if(position<=size && position>=0){
    //increment size
    size++;
    //make ptr to hold new
    T* temp;
    //allocate memory for newbag
   temp=new T[size];
    
    //for loop to copy over data until position
    for(int i=0; i<position; i++){
      temp[i]=data[i];
    }
    //put item in position
    temp[position]=item;
    //continue loop to add rest of items
    for(int i=position; i<size-1; i++){
      temp[i+1]=data[i];
    }
    
    //delete old bag memory
    delete [] data;
    //data=nullptr;
    //set newbag ptr to bag
    data=temp;
    delete [] temp;
    
  }
 
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  if(data[capacity]!=0){
    data[position]=0;
    size--;
  }
 // if(position>size-1|| position<=0)throw std::out_of_range("position out of range");
 
   else{ //decrement size
    size--;
    //allocate mems
    T* newData=new T[size];
    
    //loop through and copy
    for(int i=0; i<position; i++){
      newData[i]=data[i];
     
    }
    //second loop omitting item position
    for(int i=position; i<size+1; i++){
      newData[i-1]=data[i];
      
    }
    //delete bag
    delete [] data;
    //data=nullptr;
    //set bag equal to newbag
    data=newData;
    delete [] newData;
    //newData=nullptr;}
}

template <typename T>
void DynamicArrayList<T>::clear()
{
 
  size=0;
  delete [] data;
  data=nullptr;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  
  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  
  data[position]=newValue;
}