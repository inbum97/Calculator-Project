#ifndef NODE_
#define NODE_

template <class T>
class Node
{
private:
	// A data item
	T item;
	// Pointer to next node
	Node<T>* next;
public:
	Node();
	Node(const T&);
	Node(const T& anItem, Node<T>* nextNodePtr);
	~Node();
	void setItem(const T& anItem);
	void setNext(Node<T>* nextNodePtr);
	T getItem() const;
	Node<T>* getNext() const;
};

template<class T>
Node<T> Node<T>::*next = new Node<T>;

// Constructor
template<class T>
Node<T>::Node()
{
	next = nullptr;
}
// Constructor
template<class T>
Node<T>::Node(const T& anItem)
{
	item = anItem;
	next = nullptr;
}
// Constructor
template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr)
{
	item = anItem;
	next = nextNodePtr;
}
// Destructor
template<class T>
Node<T>::~Node()
{}
// Setter function for an item
template<class T>
void Node<T>::setItem(const T& anItem)
{
	item = anItem;
}
// setter function for next node
template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}
// getter function for an item
template<class T>
T Node<T>::getItem() const
{
	return item;
}
// getter function for next node
template<class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

#endif