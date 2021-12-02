#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include <cstdlib>
#include <vector>
template<typename T> class Bag{
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
private:
std::size_t size;
int numberOfItems;
std::vector<T> item;
};

#include "bag.tpp"

#endif
