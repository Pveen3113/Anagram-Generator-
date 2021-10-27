#include<iostream>
using namespace std;

template <class T>
class queueNode
{
	public:
		T value; // Node value
		queueNode<T> *next; // Pointer to the next node
		// Constructor
		queueNode (T nodeValue)
		{ value = nodeValue;
		next = nullptr;}
};
template <class T>
class queue {
	private:
		queueNode<T> *qFront;//front pointer
		queueNode<T> *qRear;//last pointer
	public:
		void enQueue(T);//Function to queue 
		void deQueue();//Function to remove objects from the queue
		T front(); //to return front value of a Queue
		bool IsEmpty();//Function to check wheter the queue is empty
		void destroyQueue();//Function to erase all the nodes in the queue list
		queue();//constructor
		~queue();//destructor
};
//Function to queue
template <class T>
void queue <T>::enQueue(T newValue)
{
	queueNode<T> *newNode;
	newNode = new queueNode<T>(newValue);
	if (qFront==NULL)
	{
		qFront=newNode;
		qRear=newNode;
	}
	else 
	{
		qRear->next=newNode;
		qRear=newNode;
	}
}
//Function to remove objects from the queue
template <class T>
void queue <T>::deQueue()
{
	queueNode<T> *nodePtr;
	if (qFront==NULL)
	{
		cout << "Queue is Empty...\n";
	}
	else 
	{
		nodePtr=qFront;
		qFront=qFront->next; //eqv to nodePtr->next
		delete nodePtr;
	}
}
//to return front value of a Queue
template <class T>
T queue <T>::front() 
{
	return qFront->value;
}
//Function to check wheter the queue is empty
template <class T>
bool queue<T>::IsEmpty() 
{
	if (qFront==NULL)
		return true;
	else
		return false;
}
//Function to erase all the nodes in the queue list
template <class T>
void queue <T>::destroyQueue()
{
	queueNode<T> *nodePtr;
	while (!IsEmpty())
	{ //while (qFront!=Null)
		nodePtr=qFront;
		qFront=qFront->next;
		delete nodePtr;
	}
}
//construsctor
template <class T>
queue <T>::queue()
{
	qFront=NULL;
	qRear=NULL;
}
//destructor
template <class T>
queue <T>::~queue()
{
	destroyQueue();
}
