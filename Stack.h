#include<iostream>
using namespace std;
template <class T>
class stackNode
{
	public:
		T value; // Node value
		stackNode<T> *next; // Pointer to the next node
		// Constructor
		stackNode (T nodeValue)
		{ 	value = nodeValue;
			next = nullptr;}
};

template <class T>
class stack {
	private:
		stackNode <T> *stackTop;
	public:
		T Top(); // return top value of the stack
		void Pop(); //delete the top of the stack
		void Push(T); //add new data to the stack
		bool IsEmptyStack();//to check wheter the stack IsFullStack();
		void destroyStack();//delete all nodes in the stack
		stack();//constructor
		~stack();//destructor
};
//constructor
template <class T>
stack <T> ::stack(){
	stackTop=NULL;
}
//destructor
template <class T>
stack <T> ::~stack()
{
	destroyStack();
}
//Function to return the top value in the stack
template <class T>
T stack <T> ::Top()
{
	if (!IsEmptyStack())
	return stackTop->value;
}
//Function to remove the top value
template <class T>
void stack <T> ::Pop()
{
	stackNode<T> *nodePtr;
	if (IsEmptyStack())
		cout <<"Stack is Empty...\n";
	else 
	{
		nodePtr=stackTop;
		stackTop=stackTop->next;
		delete nodePtr;
	}
}
//Function to insert a new value
template <class T>
void stack <T> ::Push(T newValue)
{
	stackNode<T> *newNode;
	newNode = new stackNode<T>(newValue);
	if (stackTop==NULL) //if (IsEmptyStack()
		stackTop=newNode;
	else 
	{
		newNode->next=stackTop;
		stackTop=newNode;
	}
}
//Function to check wheter the stack is empty 
template <class T>
bool stack <T> ::IsEmptyStack() 
{
	if (stackTop==NULL)
		return true;
	else
		return false;
}
//Function to detroy the stack 
template <class T>
void stack <T> ::destroyStack() 
{
	stackNode <T> *nodePtr;
	while (!IsEmptyStack()) //while (stackTop!=NULL) 
	{ 
		nodePtr=stackTop;
		stackTop=stackTop->next;
		delete nodePtr;
	}
}
