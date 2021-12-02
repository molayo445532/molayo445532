#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

<<<<<<< HEAD
#include <cstdlib>
#include "abstract_bag.hpp"
template<typename T> class Bag: public AbstractBag<T>
{
=======
#include "abstract_bag.hpp"

template<typename T> class Bag{
>>>>>>> dccaa28eb4fb4c2af901b00b5ba94c8601ac01de
public:

  Bag();
  
  ~Bag();

  std::size_t getCurrentSize() const;

  bool isEmpty() const;

  bool add(const T& entry);

  bool remove(const T& entry);

  void clear();

  std::size_t getFrequencyOf(const T& entry) const;

  bool contains(const T& entry) const;

  static const std::size_t MAXSIZE = 100;
  
private:
  // implementation using fixed automatic storage
  std::size_t size;
  
  T data[MAXSIZE];
};

#include "bag_simple.tpp"

#endif