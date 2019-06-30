#ifndef Stack_H
#define Stack_H
#include "LinkedList.h"
#include "Node.h"
#include <cassert>
using namespace std;

template<class T>
class LinkedStack : protected LinkedList<T>
{

public:

	//Default Constructor
	LinkedStack();
	//Copy Constructor
	LinkedStack(const LinkedStack<T>& aStack);
	//destructor
	~LinkedStack();

	//see whether stack is empty
	bool isEmpty() const;
	//push
	bool push(const T &newEntry);
	//pop: return true if removal is successful
	Node<T>* pop();
	Node<T>* peek();
	void displayStack();
	int getStackSize();
};

//Default constructor
template<class T>
LinkedStack<T>::LinkedStack()
{
	typedef LinkedList<T> list;
	list::headPtr = nullptr;
	list::counter = 0;
}


//*******************************************
//				Copy Constructor
//Copy constructor copy all the data of nodes
//in the LinkedStack by using while loop
//*******************************************
template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& aStack)
{
	typedef LinkedList<T> list;
	//origChainPtr points to the topPtr
	Node<T>* origChainPtr = aStack->list::headPtr;
	//OG bag is empty
	if (origChainPtr == NULL)
		list::headPtr = NULL;
	else
	{
		//copy first node
		list::headPtr = new Node<T>();
		list::headPtr->setItem(origChainPtr->getItem());
		//point to first node in new Chain
		Node<T>* newChainPtr = list::headPtr;
		//copy remaining nodes
		while (origChainPtr != nullptr)
		{
			//Adv og chain ptr
			origChainPtr = origChainPtr->getNext();
			//Get next item from og chain
			T nextItem = origChainPtr->getItem();
			//create a new node containing the next item
			Node<T>* newNodePtr = new Node<T>(nextItem);
			//Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			//Adv ptr to new last node
			newChainPtr = newChainPtr->getNext();
		}
		//Flag end of chain
		newChainPtr->setNext(nullptr);
	}
}//end of copy constructor

 //Destructor
template<class T>
LinkedStack<T>::~LinkedStack()
{
	//pop till stack is empty
	while (!isEmpty())
		pop();
}
//****************************************************
//					isEmpty 
//	The function check if the stack is empty
//****************************************************
template<class T>
bool LinkedStack<T>::isEmpty() const
{
	typedef LinkedList<T> list;
	return list::headPtr == nullptr;
}
//*********************************************************
//						push
// The function push the node to stack with data from main
//*********************************************************
template<class T>
bool LinkedStack<T>::push(const T& newItem)
{
	typedef LinkedList<T> list;

	Node<T>* newNodePtr = new Node<T>(newItem, list::headPtr);
	list::headPtr = newNodePtr;
	newNodePtr = nullptr;
	this->setCounter(1);
	return true;
}
//****************************************************
//						pop
//	This function set the node to nullptr 
//	that the headPtr is pointing to
//****************************************************
template<class T>
Node<T>* LinkedStack<T>::pop()
{
	Node<T>* head = this->getHeadPtr();

	if (!isEmpty())
	{
		Node<T> *next = head->getNext();
		this->setHeadPtr(next);
		this->setCounter(-1);
	}
	return head;
}
//****************************************************
//				peek
//	This function get the item from the top node
//****************************************************

template<class T>
Node<T>* LinkedStack<T>::peek()
{
	return this->getHeadPtr();
}

template<class T>
void LinkedStack<T>::displayStack()
{
	this->displayList();
}

template<class T>
int LinkedStack<T>::getStackSize()
{
	return this->getCounter();
}

#endif