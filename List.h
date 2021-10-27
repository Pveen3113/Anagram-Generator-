#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;
template<class T>
class ListNode {
public:
	T value;
	ListNode<T>* next;
	ListNode<T>* down;
	ListNode<T>(T nodeValue) {
		value = nodeValue;
		next = nullptr;
		down=nullptr;
	}
};

template<class T>
class LinkedList
{
private:
	ListNode<T>* head;
public:
	LinkedList() { head = nullptr; }//constructor
	~LinkedList();//destructor
	void appendNode(T);//Function to add a new word
	void appendanag(T,T);//Function to add a new anagram
	void deleteNode(T);//Function too delete a word
	void deleteanag(T,T);//Function to delete anagram
	void update(T,T&);//Function to overwrite an existing word with a new word
	void append_behind(T,T);//Function to add a word behind another word 
	void printList()const;//Function to display all the words in the list 
	void print_all_anag()const;//Function to display all the words in the list with their respective anagrams
	void printanag(T)const;//Function to print all the anagrams of the particular word
	void searchanag(T,T);//Function to search the anagram of a particular word with an alphabet initial
	bool test(T);//Function to test wheter thw word exist
	bool testanag(T,T);//Function to test wheter the anagram exist
};
//Function to check wheter the word already exist
template <class T>
bool LinkedList<T>::test(T word)
{
	bool status;
	ListNode<T>* nodeptr;
	if (!head) { status=true; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr&& nodeptr->value!=word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
		    status=true;
		}
		else{status=false;}
	}
	return status;
}
//Function to chech wheter the anagram already exist
template<class T>
bool LinkedList<T>::testanag(T word,T anag)
{
	bool status;
	ListNode<T>* nodeptr;
	ListNode<T>* nodept;
	if (!head) { status=false; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr&& nodeptr->value!=word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			nodept=nodeptr;
			while(nodept->down && nodept->value!=anag)
			{
				nodept=nodept->down;
			}
			if(nodept->value==anag)
			{
				status=true;
			} 
		}
		else{status=false;}
	}
	return status;
}
//Function to add anagram to the respective word  
template<class T>
void LinkedList<T>::appendanag(T word, T anag) {
	ListNode<T>* nodeptr;
	ListNode<T>* newNode;
	newNode = new ListNode<T>(anag);

	if (!head) { cout << "empty list;"; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr&& nodeptr->value!=word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			while (nodeptr->down) {
			nodeptr = nodeptr->down;}
			nodeptr->down=newNode;
		}
	}
}

//Function to add a new word 
template<class T>
void LinkedList<T>::appendNode(T word) {
	ListNode<T>* nodePtr;
	ListNode<T>* newNode;
	newNode = new ListNode<T>(word);
	if (!head) {
		head = newNode;
	}

	else {
		nodePtr = head;

		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

//Function to delete a Node
template<class T>
void LinkedList<T>::deleteNode(T word) {
	ListNode<T>* nodePtr;
	ListNode<T>* previous;

	if (!head) {
		cout << "The list is empty." << endl;
	}

	if (head->value == word) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}

	else {
		nodePtr = head;
		previous = nullptr;

		while (nodePtr != nullptr && nodePtr->value != word) {
			previous = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr) {
			previous->next = nodePtr->next;
			delete nodePtr;
		}

	}
}
//Function to delete anagram in a word
template<class T>
void LinkedList<T>::deleteanag(T word, T anag)
{	ListNode<T>* nodePtr;
	ListNode<T>* previous;

	if (!head) {
		cout << "The list is empty." << endl;
	}

	if (head->value == word) {
		previous=nullptr;
		nodePtr=nodePtr->down;
		while(nodePtr!=nullptr&&nodePtr->value!=anag)
		{
			previous=nodePtr;
			nodePtr=nodePtr->down;
		}
	}

	else {
		nodePtr = head;
		previous = nullptr;

		while (nodePtr != nullptr && nodePtr->value != word) {
			previous = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(nodePtr)
		{
			previous=nodePtr;
			nodePtr=nodePtr->down;
			while(nodePtr!=nullptr&&nodePtr->value!=anag)
			{
			previous=nodePtr;
			nodePtr=nodePtr->down;
			}
		}
	}
	if (nodePtr) {
		previous->down = nodePtr->down;
		delete nodePtr;
	}
	
}

template<class T>
void LinkedList<T>::append_behind(T word , T words)
{
	if(test(words))
	{
	
		ListNode<T>* newNode;
		newNode = new ListNode<T>(word);
		ListNode<T>* nodeptr;
		ListNode<T>* previous=nullptr;
			nodeptr = head;
			 do
			{
				previous=nodeptr;
				nodeptr = nodeptr->next;
			}while (previous != nullptr&& previous->value!=words);
			if (previous)
			{
			
				previous->next = newNode;
				newNode->next=nodeptr;
			}
	}
	else{cout<<"The word entered do not exist"<<endl;
	}
	
}
//Function to update the existing word with new word
template<class T>
void LinkedList<T>::update(T word, T &updated)
{
	ListNode<T>* nodeptr;
	string temp;
	if (!head) { cout << "empty list;"; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr && nodeptr->value != word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			cout << "Enter the updated name" << endl;
			cin >> temp;
			updated=temp;
			nodeptr->value = updated;
		}
	}
}
//Function to print only the words in the list
template<class T>
void LinkedList<T>::printList()const {
	ListNode<T>* nodePtr;
	int c=1;
	if (!head) {
		cout << "The list is empty" << endl;
	}

	else {
		nodePtr = head;
		while (nodePtr) {
			cout <<c<<")"<< nodePtr->value << endl;
			nodePtr = nodePtr->next;
			c++;
		}
	}
}
//Function to print all anagram of all the words in the list
template<class T>
void LinkedList<T>::print_all_anag()const {
	ListNode<T>* nodePtr;
	string word;
	int c=1;

	if (!head) {
		cout << "The list is empty" << endl;
	}

	else {
		nodePtr = head;
		while (nodePtr) {
			word=nodePtr->value;
			cout <<c<<")"<< nodePtr->value << endl;
			printanag(word);
			nodePtr = nodePtr->next;
			cout<<endl;
			c++;
		}
	}
}

//Function to print all anagrams of a word 
template<class T>
void LinkedList<T>::printanag(T word)const {
	ListNode<T>* nodeptr;
	ListNode<T>* anag;
	int c=1;

	if (!head) { cout << "empty list"; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr&& nodeptr->value!=word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			anag=nodeptr;
			if(anag->down==nullptr)
				cout<<"sorry unable to generate anagram for word more than 5 letters"<<endl;
			else
			{
				cout<<"The anagram of the word :"<<word<<endl;
				while(anag->down!=nullptr)
				{
					anag=anag->down;
					cout<<c<<")"<<anag->value<<endl;
					c++;	
				}
			}
		}
		else{cout<<"The name searched is not in the list";}
	}
	
}
//Function to search anagram that starts from a particular alphabets 
template<class T>
void LinkedList<T>:: searchanag(T word , T alpha){
	ListNode<T>* nodeptr;
	ListNode<T>* anag;
	string temp , check;
	int c=1;
	if (!head) { cout << "empty list"; }
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr&& nodeptr->value!=word)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			anag=nodeptr;
			while(anag->down!=nullptr)
			{
				anag=anag->down;
				temp=anag->value;
				check=temp[0];
				if(check==alpha)
				{
					cout<<c<<")"<<anag->value<<endl;
					c++;
				}	
			}
			if(c==1)
				cout<<"The anagram that start with character "<<alpha<<" is not available"<<endl;
		}
		else{cout<<"The name searched is not in the list";}
	}
	
}

//destructor
template<class T>
LinkedList<T>::~LinkedList() {
	ListNode<T>* nodePtr;
	ListNode<T>* nodept;
	ListNode<T>* nextNode;
	ListNode<T>* nextnod;

	nodePtr = head;
	nodept=nodePtr;

	while (nodePtr != nullptr) {
		nextNode = nodePtr->next;
		while(nodept!=nullptr)
		{
			nextnod=nodept->down;
			delete nodept;
			nodept=nextnod;
		}
		delete nodePtr;
		nodePtr = nextNode;
	}
}
