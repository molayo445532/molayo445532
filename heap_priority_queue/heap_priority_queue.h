
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //todo
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    //todo
    for(int i=0;i<lst.getLength();i++){
        if(item<lst.getEntry(i)){
            lst.insert(i,item);
            return;
        }
    }
    lst.insert(lst.getLength(),item);

}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    //todo
    lst.remove(lst.getLength()-1);
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //todo
    return lst.getEntry(lst.getLength()-1);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
