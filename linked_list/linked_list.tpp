#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  headPtr = new Node<T>(); //initializing variables
  itemCount = 0;}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T>* current = headPtr;
  Node<T>* next = nullptr;

  while(current != NULL) {//checking if headPtr is not already empty
    next = current->getNext();
    delete current;
    current = next;}
  
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{

  itemCount = x.itemCount;
  Node<T>* origChainPtr = x.headPtr;
  if(origChainPtr == nullptr) {//checking if list is empty
    headPtr = nullptr;
  } 
  else 
  {
    headPtr = new Node<T>();
    headPtr->setItem(origChainPtr->getItem());//setting items to each other
    Node<T>* newChainPtr = headPtr;
    origChainPtr = origChainPtr->getNext();//setiing equal next pointers
    while (origChainPtr != nullptr)
    {
      T nextItem = origChainPtr->getItem();
      Node<T>* newheadPtr = new Node<T>(nextItem);
      newChainPtr->setNext(newheadPtr);
      newChainPtr = newChainPtr->getNext();
      origChainPtr = origChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
  }
  
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  
  std::swap(x.itemCount,y.itemCount); //using build in swap function
  std::swap(x.headPtr,y.headPtr);
  
 
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  
  LinkedList<T> l(x);
  std::swap(l.headPtr, headPtr);
  return *this;}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(itemCount == 0) {
    return true;
  } 
  else {
    return false;
  }
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{

  return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if((itemCount<position-1) || position <= 0) { //checking if position input is valid
    return false;
  } 
  else {//if not copy item to a temp pointer
    Node<T>* newheadPtr = new Node<T>();
    newheadPtr->setItem(item); 
    if(position == 1) { 
      newheadPtr->setNext(headPtr); 
      
      
      headPtr = newheadPtr;
      itemCount++;
      return true;
    } else {
      Node<T>* temp = headPtr;
      for(int i = 1; i < position - 1; i++) { //traversing list
        temp = temp->getNext();
      }
      newheadPtr->setNext(temp->getNext());
      temp->setNext(newheadPtr);
      
      itemCount++;//incrementing count after successful add
      return  true;
    }
  }
}



template <typename T>
bool LinkedList<T>::remove(std::size_t position) {
  Node<T>* current = headPtr;
  Node<T>* removeNode = nullptr;

  if(position < 1 || position - 1> itemCount) {//checking input validity
    return false;
  }

  int count = 0;
  while(++count < position - 1) {//traversing through list
    current = current->getNext();
  }
  removeNode = current->getNext();

  current->setNext(removeNode->getNext());

  removeNode->setNext(nullptr);
  delete removeNode;
  removeNode = nullptr;

  itemCount--;

  return true;
}



template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* nodeToDeletePtr = headPtr;
  while(headPtr != nullptr) { 
    headPtr = headPtr->getNext();
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = headPtr;
  }
  itemCount = 0;
  
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  
  Node<T>* temp = headPtr;
  int itemCounting = 0;
  while(++itemCounting < position) { 
    temp = temp->getNext();
  }
  
  return temp->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  Node<T>* temp = headPtr;
  for(int i = 1; i < position; i++) { 
    temp = temp->getNext();
  }
  temp->setItem(newValue);
  
}
