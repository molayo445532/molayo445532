//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
		headPtr=nullptr;
	currentSize=0;

}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	while(!isEmpty()){
		pop();
	}
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr==nullptr;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>*temp=new Node<ItemType>(newItem,headPtr);
	headPtr=temp;

	temp=nullptr;
	currentSize++;
	return true;
	
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	
	if(isEmpty()){
		throw std::logic_error("cannot peek at empty stack");
	}
	return headPtr->getItem();

}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if(!isEmpty()){
		Node<ItemType>*temp=headPtr;
		headPtr=headPtr->getNext();
		temp->setNext(nullptr);
		delete temp;
		temp=nullptr;
		currentSize--;
		return true;
		
	}
	else return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while(!isEmpty()){
		pop();
	}
	currentSize=0;
}  // end clear

