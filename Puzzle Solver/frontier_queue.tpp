#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

if(queue.size() == 0) {
    throw std::range_error("empty queue");
  }
  State<T> x=queue.front();
  queue.erase(queue.begin());
  if(queue.size() > 0) {
    queue.insert(queue.begin(),queue.back());
    queue.pop_back();
    for(int i = 0; i < queue.size() - 1; i++) {
      if(queue[i + 1].getFCost() < queue[i].getFCost()) {
        State<T> temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
      }
    }
  }
  return x;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  
  State<T> x(p,cost,heur);
  queue.push_back(x);
  for(int i = 0; i < queue.size() - 1; i++) {
    if(queue[i + 1].getFCost() < queue[i].getFCost()) {
      State<T> temp = queue[i];
      queue[i] = queue[i + 1];
      queue[i + 1] = temp;
    }
  }

}

template <typename T>
bool frontier_queue<T>::empty() {
  if(queue.size()==0)return true;
  else return false;
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for(int i = 0; i < queue.size(); i++) {
    if(queue[i].getValue() == p) {
      return true;
    }
  }
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
  for(int i = 0; i < queue.size(); i++) {
    if(queue[i].getPathCost() > cost) {
      queue[i].updatePathCost(cost);
    }
  }
}


