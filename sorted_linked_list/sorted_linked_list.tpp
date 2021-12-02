#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{

}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  for(int i=0; i<getLength(); i++){
    if(item<getEntry(i)){
      LinkedList<T>::insert(i, item);
      return;
    }
  }
  LinkedList<T>::insert(getLength(), item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  int n=0;
  for(int i=0; i<getLength(); i++){
    if(getEntry(i)==item){
      n++;
      LinkedList<T>::remove(i);
      break;
    }
  }
  if(n==0){
    throw std::range_error("item is not in list");
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()||position<0||position>=getLength()) throw std::range_error("empty list in remove");

  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  if(isEmpty()||position<0||position>=getLength()) throw std::range_error("empty list");
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  long int pos=-1;
  for(long int i=0; i<getLength(); i++){
    if(getEntry(i)==newValue){
      pos=i;
      break;
    }
  }
  return pos;
}