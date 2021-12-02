#include "deque.hpp"
#include "abstract_list.hpp"

template <typename T,typename L>
Deque<T,L>::Deque()
{
}

template <typename T,typename L>
Deque<T,L>::~Deque()
{
    linked_list.clear();
}

template <typename T,typename L>
Deque<T,L>::Deque(const Deque<T,L>& x)
{
}
template <typename T,typename L>
Deque<T,L>& Deque<T,L>::operator=(const Deque<T,L>& x)
{
 
  return  linked_list.operator=(x);
}

template <typename T,typename L>
bool Deque<T,L>::isEmpty() const noexcept{

    return linked_list.isEmpty();

}

/** Add item to the front of the deque
* may throw std::bad_alloc
*/
template <typename T,typename L>
void Deque<T,L>::pushFront(const T & item){

linked_list.insert(linked_list.getLength(),item);
}

/** Remove the item at the front of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T,typename L>
void Deque<T,L>::popFront(){
if(linked_list.getLength()==0){
    throw std::runtime_error("deque is empty");
}
else{
    linked_list.remove(linked_list.getLength()-1);
}
}

/** Returns the item at the front of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T,typename L>
T Deque<T,L>:: front() const{
if(linked_list.getLength()==0){
    throw std::runtime_error("deque is empty");
}
return linked_list.getEntry(linked_list.getLength()-1);
}

/** Add item to the back of the deque
* may throw std::bad_alloc
*/
template <typename T,typename L>
void Deque<T,L>::pushBack(const T & item){
    linked_list.insert(0,item);
}

/** Remove the item at the back of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T,typename L>
void Deque<T,L>::popBack(){
if(linked_list.getLength()==0){
    throw std::runtime_error("deque is empty");
}
else linked_list.remove(0);
}


/** Returns the item at the back of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T,typename L>
T Deque<T,L>:: back() const{
if(linked_list.getLength()==0){
    throw std::runtime_error("deque is empty");
}
    return linked_list.getEntry(0);

}
