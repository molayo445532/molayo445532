#include "ring_buffer.h"

#include <cassert>

template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
  queueLength = size;
  data.reset(new T[queueLength]);
  front = 0;
  back = queueLength-1;
  count = 0;
}


template <typename T>
bool RingBuffer<T>::enqueue_front(const T& item)
{
  
  if(count<queueLength){
   int temp[queueLength];
   temp[0]=item;
   for(int i=0;i<queueLength-1;i++){
    temp[i+1]=data[i];
   }
    for(int i=0;i<queueLength;i++){
    data[i]=temp[i];
   }
   
    back=(back+1)%queueLength;
    
    
    ++count;
    return true;
  }

  return false;
}


template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
  if(count <queueLength){
    back = (back+1) % queueLength;
    data[back] = item;
    ++count;
    return true;
  }
  
  return false;
}

template <typename T>
T RingBuffer<T>::dequeue_front()
{
  assert(count > 0);
  
  T value;
  value = data[front];
  front = (front +1) % queueLength;
  --count;
  
  return value;
}


template <typename T>
T RingBuffer<T>::dequeue_back()
{
  // TODO
  assert(count>0);
  T value;

  value=data[back];
  back=(back-1)% queueLength;
  --count;

  return value;
}


template <typename T>
long int RingBuffer<T>::getCount()
{
  return count;
}