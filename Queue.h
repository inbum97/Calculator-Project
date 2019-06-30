#ifndef LINKEDQUEUE_
#define LINKEDQUEUE_

template<class ItemType>
class LinkedQueue : protected LinkedList<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has
	// two external pointers, a head pointer for the front of the queue 
	// and a tail pointer for the back of the queue.
	Node<ItemType>* backPtr;
public:
	LinkedQueue();
	~LinkedQueue();
	bool isEmpty();
	bool enqueue(const ItemType& newEntry);
	ItemType dequeue();
	Node<ItemType> *peekFront();
	Node<ItemType> *peekRear();
	int getQueueSize();
	void emptyQueue();
	void displayQueue();
};

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() {
	this->setHeadPtr(nullptr);
	backPtr = nullptr;
}
// end destructor 
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	this->clearList();
}

//****************************************************
//					isEmpty 
//	The function check if the stack is empty
//****************************************************
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty()
{
	bool status = true;
	int count = this->getCounter();
	if (count > 0)
	{
		status = false;
	}
	return status;
}

//*********************************************************
//						enqueue
// The function enqueue the node to queue with data from main
//*********************************************************
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry) {
	Node<ItemType> *headPtr = this->getHeadPtr();
	Node<ItemType> *newQue = new Node<ItemType>(newEntry, nullptr);
	int count = this->getCounter();
	if (headPtr == nullptr && count == 0)
	{
		this->setHeadPtr(newQue);
	}
	else
	{
		backPtr->setNext(newQue);
	}
	backPtr = newQue;
	this->setCounter(1);
	return true;
}

//*********************************************************
//						dequeue
// The function dequeue the node to dequeue with data from main
//*********************************************************
template<class ItemType>
ItemType LinkedQueue<ItemType>::dequeue()
{
	ItemType returnItem;
	if (this->getHeadPtr() != backPtr && backPtr != nullptr)
	{
		returnItem = this->getHeadPtr()->getItem();
		Node<ItemType> *temp = this->getHeadPtr()->getNext();
		this->removeFirst();
		this->setHeadPtr(temp);
		this->setCounter(-1);
	}
	else if (this->getHeadPtr() == backPtr)
	{
		this->setHeadPtr(nullptr);
		backPtr = nullptr;
		this->setCounter(-1);
	}
	return returnItem;
}

//****************************************************
//				peekFront
//	This function returns the headPtr address
//****************************************************
template<class ItemType>
Node<ItemType>* LinkedQueue<ItemType>::peekFront()
{
	return this->getHeadPtr();
}

//****************************************************
//				peekRear
//	This function returns the backPtr address
//****************************************************
template<class ItemType>
Node<ItemType>* LinkedQueue<ItemType>::peekRear()
{
	return backPtr;
}

//****************************************************
//				getQueueSize
//	This function returns size of queue
//****************************************************
template<class ItemType>
int LinkedQueue<ItemType>::getQueueSize()
{
	return this->getCounter();
}
//****************************************************
//				EmptyQueue
//	This function empty Queue
//****************************************************
template<class ItemType>
void LinkedQueue<ItemType>::emptyQueue()
{
	this->clearList();
	backPtr = nullptr;
}

template<class ItemType>
void LinkedQueue<ItemType>::displayQueue()
{
	this->displayList();
}
#endif