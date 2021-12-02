#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  headptr=nullptr; 
  size=0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  
  size=x.size;
  
  Node<T>* original=x.headptr;

  if(original==nullptr){
    headptr=nullptr;
  }
  else{
    headptr=new Node<T>();
    headptr->setItem(original->getItem());
    Node<T>* chain = headptr; 
    original=original->getNext(); 
    while(original!=nullptr){
      T nextItem=original->getItem();
      Node<T>* newNode = new Node<T>(nextItem);
      chain->setNext(newNode);
      chain=chain->getNext();
      original=original->getNext();
    }
    chain->setNext(nullptr);
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  Node<T>* temp=x.headptr;
  x.headptr=y.headptr;
  y.headptr=temp;
  int sizex=x.size;
  x.size=y.size;
  y.size=sizex;

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
 
  clear();
  
  size=x.size;
 
  Node<T>* original=x.headptr;
  
  if(original==nullptr){
    headptr=nullptr;
  }
  else{
    
    headptr=new Node<T>();
  
    headptr->setItem(original->getItem());
    
    Node<T>* chain = headptr; 
    original=original->getNext(); 
    while(original!=nullptr){
      
      T nextItem=original->getItem();
      
      Node<T>* newNode = new Node<T>(nextItem);
     
      chain->setNext(newNode);
      
      chain=chain->getNext();
      original=original->getNext();
    }
    
    chain->setNext(nullptr);
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  
  return size==0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{

  if(position>=0 && position<=size+1){
   
    Node<T>* newNode=new Node<T>;
    if(position==0){
     
      newNode->setNext(headptr);;
      
      newNode->setItem(item);
     
      headptr=newNode;
    }
    else{
     
      newNode->setNext(getNodePosition(position));
      
      getNodePosition(position-1)->setNext(newNode);
      
      newNode->setItem(item);
    }
    
    size++;
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  
  if(position>=0 && position<=size-1){
    
    Node<T>* holder=nullptr;
    
    if(position==0){
      
      holder=headptr;
      
      headptr=headptr->getNext(); 
    }
    else{
      
      Node<T>* previous=getNodePosition(position-1);
      
      holder=previous->getNext();
      
      previous->setNext(holder->getNext());

    }
    holder->setNext(nullptr);
    delete holder;
    holder=nullptr;
    size--;
    return true;
  }
  else{
    return false;
    }
  
}

template <typename T>
void LinkedList<T>::clear()
{

  Node<T>* nodeToDeletePtr=headptr;
 
  while(headptr!=nullptr){
    headptr=headptr->getNext();
  
    nodeToDeletePtr->setNext(nullptr);
   
    delete nodeToDeletePtr;
  
    nodeToDeletePtr=headptr;
  }
  
  size=0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  
  Node<T>* holder = getNodePosition(position);
  
  return holder->getItem();
  
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  
  Node<T>* holder=getNodePosition(position);
  holder->setItem(newValue);

}


template <typename T>
Node<T>* LinkedList<T>::getNodePosition(int i) const{
  
  Node<T>* ptr = headptr;
  
  for(int k=0; k<i; k++){
    ptr=ptr->getNext();
  }
  
  return ptr;
}