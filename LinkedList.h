#ifndef LinkedList_H
#define LinkedList_H

template<class T>
class LinkedList
{
protected:
	Node<T>* headPtr;
	int counter;

public:
	// default constructor
	LinkedList();
	LinkedList(T&);
	~LinkedList();
	void displayList();
	void addFirst(T&);
	bool addAtPos(T&, int);
	void removeFirst();
	bool removeAtPos(int);
	bool removeTarget(T&);
	int findPos(T&);
	void clearList();

	// for child class access
	int getCounter();
	Node<T> *getHeadPtr();
	void setCounter(int);
	void setHeadPtr(Node<T>*);

};

// default constructor
template<class T>
LinkedList<T>::LinkedList()
{
	headPtr = nullptr;
	// setHeadPtr(nullptr);
	counter = 0;
}

// constructor
template<class T>
LinkedList<T>::LinkedList(T& item)
{
	Node<T> *newNode = new Node<T>(item);
	headPtr = newNode;
	counter++;
}

// destructor
template<class T>
LinkedList<T>::~LinkedList()
{
	clearList();
}

//****************************************
//			displayList
// print out all the node values
//****************************************
template<class T>
void LinkedList<T>::displayList()
{
	int index = counter;
	Node<T> *current = headPtr;
	while (index > 0 && current != nullptr) {
		std::cout << current->getItem() << " "; //std::endl;
		current = current->getNext();
		index--;
	}
}

//****************************************
//			addFirst
//	The function add new node to first pos
//****************************************

template<class T>
void LinkedList<T>::addFirst(T& item)
{
	Node<T> *newNode = new Node<T>(item);
	if (headPtr != nullptr)
	{
		Node<T> *oldHead = headPtr;
		newNode->setNext(oldHead);
	}
	headPtr = newNode;

	counter++;
}
//****************************************
//			addAtPos
//	The function add node to any position
//****************************************
template <class T>
bool LinkedList<T>::addAtPos(T& item, int pos)
{
	bool isAdded = false;
	if (headPtr == nullptr || pos == 1) {
		// if pos = 1 or no node in the list
		// let addFirst method handles the case
		addFirst(item);
		isAdded = true;
	}
	// if the position is invalid || zero || negative
	// it will return -1
	else if (pos > 0) {
		int index = 1;
		Node<T> *prev = nullptr;
		Node<T> *current = headPtr;
		while (index <= pos && current != nullptr)
		{
			if (index == pos - 1) {
				Node<T> *newNode;
				newNode = new Node<T>(item);
				prev = current;
				current = current->getNext();
				prev->setNext(newNode);
				// insert new node between previous and current node
				newNode->setNext(current);
				isAdded = true;
				counter++;
				break;
			}
			index++;
			prev = current;
			current = current->getNext();
		}
		// add node to the tail if pos is greater than counter
		if (current == nullptr && pos > index)
		{
			Node<T> *newNode;
			newNode = new Node<T>(item);
			prev->setNext(newNode);
			counter++;
		}
	}
	return isAdded;
}
//****************************************
//			getCounter
// get the total number of node
//****************************************
template <class T>
int LinkedList<T>::getCounter()
{
	return counter;
}

//****************************************
//			findPos
// find the first appearing item value
//****************************************
template <class T>
int LinkedList<T>::findPos(T& item)
{
	int pos = -1;
	int index = 1;
	Node<T> *current = headPtr;
	while (current != nullptr && index <= counter)
	{
		if (current->getItem() == item) {
			pos = index;
			break;
		}
		index++;
		current = current->getNext();
	}
	return pos;
}
//****************************************
//			removeFirst
//	The function Remove the first node
//****************************************
template <class T>
void LinkedList<T>::removeFirst()
{
	if (headPtr != nullptr) {
		Node<T> *oldHead = headPtr;
		headPtr = headPtr->getNext();
		delete oldHead;
		counter--;
	}
}

//****************************************
//			removeAtPos
//	the function Remove a node anywhere
//****************************************

template <class T>
bool LinkedList<T>::removeAtPos(int pos)
{
	bool isRemoved = false;
	if (pos == 1)
	{
		removeFirst();
	}
	else if (headPtr != nullptr && pos > 0 && pos <= counter)
	{
		Node<T> *prev = nullptr;
		Node<T> *current = headPtr;
		int index = 1;
		while (current != nullptr && index <= counter)
		{
			if (index == pos)
			{
				Node<T> *nexNode = current->getNext();
				prev->setNext(nexNode);
				delete current;
				isRemoved = true;
				counter--;
				break;
			}
			prev = current;
			current = current->getNext();
			index++;
		}
	}
	return isRemoved;
}
//****************************************************
//				removeTarget
// remeove a certain node that contains target value
//****************************************************
template<class T>

bool LinkedList<T>::removeTarget(T& item)
{
	bool isRemoved = false;
	if (headPtr != nullptr)
	{
		Node<T> prev = nullptr;
		Node<T> *current = headPtr;
		int index = 1;
		while (index <= counter && current != nullptr)
		{
			if (current->getItem() == item)
			{
				Node<T> *nexNode = current->getNext();
				prev->setNext(nexNode);
				delete current;
				isRemoved = true;
				counter--;
				break;
			}
			prev = current;
			current = current->getNext();
			index++;
		}
	}
	return isRemoved;
}
//****************************************************
//				clearList
//		The function empty out the listF
//****************************************************
template <class T>
void LinkedList<T>::clearList()
{
	Node<T> *current = headPtr;
	while (counter > 0 && current != nullptr)
	{
		Node<T> *prev = current;
		current = current->getNext();
		delete prev;
		prev = nullptr;
		--counter;
	}
	counter = 0;
	headPtr = nullptr;
}

//****************************************************
//				getHeadPtr
//		The function returns headPtr address
//****************************************************
template <class T>
Node<T>* LinkedList<T>::getHeadPtr()
{
	return headPtr;
}


//****************************************************
//				setCounter
//		The function increments or decrements counter
//    arguments: negative 1 or positive 1
//****************************************************
template <class T>
void LinkedList<T>::setCounter(int num)
{
	counter += num;
}

//****************************************************
//				setHeadPtr
//		The function sets headPtr
//****************************************************
template <class T>
void LinkedList<T>::setHeadPtr(Node<T>* newHead)
{
	// std::cout << newHead << std::endl;
	headPtr = newHead;
	// if (newHead == nullptr) {
	//   headPtr = nullptr;
	// }
	// else {
	//   Node<T> *newNode= new Node<T>(newHead);
	//   headPtr = newNode;
	// }
}

#endif