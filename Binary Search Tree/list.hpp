#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"

template <typename T>
class List: public AbstractList<T>
{
public:
  
  // default constructor
  List();
  
  // copy constructor
  List(const List& x);
    
  // destructor
  ~List();
  
  // copy assignment
  List& operator=(const List& x);
  
  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;

  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:

  int size;
  //pointer to first node
  Node<T>* headptr;
  //helper function to get node at position
  Node<T>* getNodePosition(int i) const;
  
};

#include "list.tpp"

#endif
