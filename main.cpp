#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include<iostream>
#include<malloc.h>
#include<fstream>
using namespace std;

void dispstart();//display start option
void selection_error();//display if the selection made is invalid
void check_filename(string &, fstream &);
void check_selection(int&);//input validation for 2 choices
void check_selection_switch(int&);//input validation for switch case
void check_word(string &word, LinkedList<string>&List);//input validation to check wheter the name exist
void check_alpha(string&alpha);//Function to check wheter the word cointains only one character
void adding_word_selection();//display adding word seelection options
void generate(int, string& , queue<char> q , stack<string>&s);//Function to stack an anagram
void sizetwo(string, queue<char> q, stack<string> &s);//Functions to generate anagram for two letter word
void sizethree(string word, queue<char> q , stack<string> &s);//Functions to generate anagram for three letter word
void sizefour(string word, queue<char> q , stack<string> &s);//Functions to generate anagram for four letter word
void sizefive(string word, queue<char> q , stack<string> &s);//Functions to generate anagram for five letter word
void anagram(string word, queue<char> q , stack<string> &s);//Functions to generate anagram
void storeanagram(string word, LinkedList<string> &List, stack<string>&s);//Function to store anagram
void clearanagram(string word, LinkedList<string> &List, stack<string>&s);//Function to clear thhe anagram list
void swap(string &a, string &b);//Fuction to swap two words

int main() {
	LinkedList<string> List;//declare object for list
	queue<char> q;//declare object for queue
	stack<string> s;//declare object for stack
	fstream inputFile;
	int start, swutch , select , k , choose=1;
	string filename, word , words;
	cout<<" ANAGRAM GENERATOR "<<endl;
	cout<<" WELCOME "<<endl;
	cout << "Please enter the FILENAME" << endl;
	cin >> filename;
	filename += ".txt";//add txt to the filename
	check_filename(filename,inputFile);
	while (!inputFile.eof())//loop till the end of the file
	{
		inputFile >> word;
		anagram(word,q,s);//generate anagram of each word
		List.appendNode(word);//add the word into the list
		storeanagram(word,List,s);//add the anagrms generated of the word to the word
	}
	inputFile.close();//close file

	dispstart();//display start function 
	cin >> start;
	check_selection(start);//input validation for rthe input start 
	system("CLS");
	while (start != 2)
	{
		cout << " Select an option below "<<endl;
		cout << "1) Display all the words" << endl;
		cout << "2) Delete a word" << endl;
		cout << "3) Display all the anagrams of a particular word with specified alphabet initial" << endl;
		cout << "4) ADD a new word " << endl;
		cout << "5) Update the existing word"<<endl;
		cout << "6) Search for a word to get their anagrams"<<endl;
		cout << "7) Delete only an anagram from the anagram list of the word"<<endl;
		cout << "8) EXIT "<<endl;
		cin >> swutch;
		check_selection_switch(swutch);//input validation for the switch case choices
		switch (swutch)
		{	
		case 1:
			system("CLS");
			cout<<"You have selected option 1"<<endl;
			cout<<"SELECT"<<endl;
			cout<<"1) ALL WORDS WITH ANAGRAMS"<<endl;
			cout<<"2) ONLY WORDS"<<endl;
			cin>>select;
			check_selection(select);// input validation for the selection
			if(select==1)
				List.print_all_anag();//display all the anagrams of all the words  in the list with their respective words
			else
				List.printList();//display all the words in thhe list
			break;
		case 2:
			system("CLS");
			cout<<"You have selected option 2"<<endl;
			cout << "Enter the word that you want to delete" << endl;
			cin >> word;
			check_word(word,List);//check wheter the word exist
			List.deleteNode(word);//delete the word
			cout<<"The current words after deleting process "<<endl;
			List.printList();//display the remaining words after the deleting process
			break;
		case 3:
			system("CLS");
			cout<<"You have selected option 3"<<endl;
			cout<<"Enter the word"<<endl;
			cin>>word;
			check_word(word,List);//check wheter the word exist
			k=word.size();
			if(k>5)
				cout<<"Sorry the word contains more than 5 alphabets , so the anagrams is unavailable"<<endl;
			else
			{
				cout<<"Enter the first character of the anagram to be displayed"<<endl;
				cin>>words;
				check_alpha(words);//input validate wheter the it is a single character alphabet 
				system("CLS");//clear screem
				List. searchanag(word,words);//display the anagrams of the particualr word respectively with the choice of first letter by the eser
			}
			break;
		case 4:
			system("CLS");
			cout<<"You have selected option 4"<<endl;
			cout << "Enter the new word to be added" << endl;
			cin >> word;
			if(List.test(word))//Test if the word already exist
			{
				cout<<"The word cannot be added because its already exist "<<endl;
			}
			else
			{
				adding_word_selection();//display the adding word selection option 
				cin>>select;
				check_selection(select);//input validate the selection
				if(select==1)//if selection is 1 
				{	
					anagram(word,q,s);//generate anagram for the word 
					List.appendNode(word);//add the word into the list 
					storeanagram(word,List,s);//store the anagrams of the word
					cout<<"The word has been added"<<endl;
					
				}
				else
				{
					cout<<"Enter the word so that new word will be added after it "<<endl;
					cin>> words;
					check_word(words,List);
					List.append_behind(word,words);//add the new word behind an existing word
					anagram(word,q,s);//generate anagram for the word
					storeanagram(word,List,s);//store the anagrams of the word
					cout<<"The word is  added now"<<endl;
				}
				cout<<endl;
				cout<<"The current list of word"<<endl;
				List.printList();
			}
			break;
		case 5:
			system("CLS");
			cout<<"You have selected option 5"<<endl;
			cout<<"Enter the word"<<endl;
			cin>>word;
			check_word(word,List);//check does the word exist
			anagram(word,q,s);//generate anagramm for the word 
			clearanagram(word,List,s);//clear all the anagrams for the word
			List.update(word,words);//update the existing word with the new word 
			anagram(words,q,s);//generate anagram with the new updated word
			storeanagram(words,List,s);//store the anagram for the new updated word 
			cout<<"The word is updated "<<endl;
			break;
		case 6: 
			system("CLS");
			cout<<"You have selected option 6"<<endl;
			cout<<"Enter the word"<<endl;
			cin>>word;
			check_word(word,List);
			List.printanag(word);
			break;
		
		case 7:
			system("CLS");
			cout<<"You have selected option 7"<<endl;
			cout<<"Enter the word"<<endl;
			cin>>word;
			check_word(word,List);//check wheter the word exist
			k=word.size();
			if(k>5)
				cout<<"Anagram is not available for this word"<<endl;
			else
			{
				List.printanag(word);//print all the anagrams of the word
				cout<<"The list of anagrams of the word are as above"<<endl;
				cout<<"Enter anag word that you want to delete"<<endl;
				cin>>words;
				while(!List.testanag(word,words)&&choose!=2)//check wheter the anagram exist
				{
					cout<<"The anagram of that word is either not found or no longer available"<<endl;
					cout<<"Select the option"<<endl;
					cout<<"1) Try again"<<endl;
					cout<<"2) back to menu"<<endl;
					cin>>choose;
					if(choose==1)//if the user wants to try again 
					{
						check_selection(choose);//input validate the selection
						cout<<"Enter the anag again"<<endl;
						cin>>words;
						List.testanag(word,words);// Check does the anagram exist
					}
				}
				system("CLS");
				if(List.testanag(word,words))//if the anagam exist it will be deleted 
				{
					List.deleteanag(word,words);//delete the anagram
				     cout<<"The anagram will be deleted"<<endl;
				     cout<<endl;
				     cout<<"The current anagram list after deleting the anag "<<words<<endl;
				     List.printanag(word);//display all the anagarms of that  word
				}
			
			}
		}
		dispstart();//display the start option 
		cin >> start;
		check_selection(start);//input validate the option chosen
		system("cls");
	}	
	cout<<"THANK YOU     *_*"<<endl;
	cout<<"*** PLEASE COME AGAIN ****"<<endl;
}
//Function to display the start option
void dispstart()
{
	cout << "Please select an option below to start the program" << endl;
	cout << "1) START" << endl;
	cout << "2) EXIT" << endl;
}
//Function to input validate a two choice selection
void check_selection(int& silect)
{
	while (silect != 1 && silect != 2)
	{
		selection_error();
		cin >> silect;
	}
}
//Function to check the selection of switch case
void check_selection_switch(int&silect)
{
	while (silect != 1 && silect != 2 &&silect != 3 &&silect != 4 &&silect != 5&&silect!=6&&silect!=7&&silect!=8)
	{
		selection_error();// display the selection made is an error
		cin >> silect;
	}
	
}
//Function to check wheter the file exist
void check_filename(string &filename, fstream &inputFile)
{
	inputFile.open(filename.c_str(), ios::in);//open file
	while(!inputFile)//while the inputfile doesnt  exist , ask the user to input the filename that exist
	{
		cout<<"The file name does not exist"<<endl;
		cout<<"Please try again "<<endl;
		cin>>filename;
		filename += ".txt";// add  the word txt behind the  filename
		inputFile.open(filename.c_str(), ios::in);
		system("CLS");
	}
	
}
//Function to check whether the word exist 
void check_word(string &word,LinkedList<string> &List )
{
	while(!List.test(word))
	{
		cout<<"The word entered is not in the list"<<endl;
		cout<<"Please try again "<<endl;
		cin>>word;
	}
}
//Function to check whether the input is a single character 
void check_alpha(string&alpha)
{
	int size;
	size=alpha.size();
	while(size!=1)
	{
		cout<<"Please make sure it is a single character alphabet "<<endl;
		cout<<"Please try again"<<endl;
		cin>>alpha;
		size=alpha.size();
	}
}
//Function to display if the selection made is invalid
void selection_error()
{
	cout << " INVALID SELECTION" << endl;
	cout << "Please try again " << endl;
}
//Function to display adding word selection 
void adding_word_selection()
{
	cout<<"Where do you want to add the word"<<endl;
	cout<<"1) add at the end of the list "<<endl;
	cout<<"2) After an existing word "<<endl;
}
void  generate(int c , string&word , queue<char> q , stack<string>&s)
{
	char temp;
	string test;
	for(int i=0 ; i<c ; i++)
	{
	   temp=word[i];//stroe the ith character
	   q.enQueue(temp);//queue up the character
	}
	for(int i=0 ; i<c ; i++)
	{
	   temp=q.front();//store the return of the first character
	   test+=temp;//accumulate each character to produce an anagram of the word
	   q.deQueue();//dequeue the character from the list 
	}
	s.Push(test);//push the anagram of the word into the stack
	
}
//Function to generate anagram of a word that contains two letters
void sizetwo(string word, queue<char> q , stack<string> &s)
{
	int c=2;
	generate(c,word,q ,s);
	swap(word[0],word[1]);
	generate(c,word,q ,s);
}
//Function to generate anagram of a word that contains three letters
void sizethree(string word, queue<char> q , stack<string> &s)
{
	int c=3;
	generate(c,word,q ,s);//call the generate function
	swap(word[0],word[1]);// swap the character in the words
	generate(c,word,q ,s);
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	swap(word[0],word[1]);
	generate(c,word,q ,s);
}
//Function to generate anagram of a word that contains four letters
void sizefour(string word, queue<char> q , stack<string> &s)
{
	int c=4;
	generate(c,word,q ,s);//call the generate function
	//1
	swap(word[0],word[1]);// swap the character in the words
	generate(c,word,q ,s);
	//2
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//3
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//4
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//5
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//6
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//7
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	//8
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//9
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//10
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//11
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//12
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	//13
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//14
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//15
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//16
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//17
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//18
	swap(word[1],word[2]);
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	//19
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//20
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//21
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//22
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//23
	swap(word[2],word[3]);
	generate(c,word,q ,s);
}
//Function to generate anagram of a word that contains five letters
void sizefive(string word, queue<char> q , stack<string> &s)
{
	int c=5;
	//1
	generate(c,word,q ,s);//call the generate function
	//2
	swap(word[3],word[4]);// swap the character in the words
	generate(c,word,q ,s);
	//3
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//4
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//5
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//6
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//7
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//8
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//9
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//10
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//11
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//12
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//13
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//14
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//15 
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//16
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//17
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//18
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//19
	swap(word[1],word[4]);
	generate(c,word,q ,s);
	//20
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//21
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//22
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//23
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//24
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//25
	swap(word[0],word[3]);
	generate(c,word,q ,s);
	//26
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//27
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//28
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//29
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//30
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//31
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//32
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//33
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//34
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//35
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//36
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//37
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//38
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//39
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//40
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//41
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//42
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//43
	swap(word[1],word[4]);
	generate(c,word,q ,s);
	//44
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//45
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//46
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//47
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//48
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//49
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	//50
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//51
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//52
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//53
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//54
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//55
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//56
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//57
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//58
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//59
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//60
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//61
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//62
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//63
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//64
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//65
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//66
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//67
	swap(word[1],word[4]);
	generate(c,word,q ,s);
	//68
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//69
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//70
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//71
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//72
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//73
	swap(word[0],word[1]);
	generate(c,word,q ,s);
	//74
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//75
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//76
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//77
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//78
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//79
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//80
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//81
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//82
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//83
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//84
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//85
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//86
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//87
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//88
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//89
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//90
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//91
	swap(word[1],word[4]);
	generate(c,word,q ,s);
	//92
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//93
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//94
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//95
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//96
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//97
	swap(word[0],word[4]);
	generate(c,word,q ,s);
	//98
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//99
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//100
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//101
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//102
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//103
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//104
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//105
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//106
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//107
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//108
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//109
	swap(word[1],word[2]);
	generate(c,word,q ,s);
	//110
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//111
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//112
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//113
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//114
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//115
	swap(word[4],word[1]);
	generate(c,word,q ,s);
	//116
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//117
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//118
	swap(word[3],word[4]);
	generate(c,word,q ,s);
	//119
	swap(word[2],word[3]);
	generate(c,word,q ,s);
	//120
	swap(word[3],word[4]);
	generate(c,word,q ,s);
}
//Function to generate anagrams of a word
void anagram(string word, queue<char> q , stack<string> &s)
{ 
	int size;
	size=word.size();
	if(size==2)
	{
		sizetwo(word,q,s);//generate anagram for word size two
	}
	else if(size==3)
	{
		sizethree(word,q,s);//generate anagram for word size three
	}
	else if(size==4)
	{
		sizefour(word,q,s);//generate anagram for word size four
	}
	else if(size==5)
	{
		sizefive(word,q,s);//generate anagram for word size five
	}
}
//Function to store the anagrams of a word
void storeanagram(string word, LinkedList<string> &List, stack<string>&s)
{
	int size;
	string anag;
	size=word.size();//calculate the size of the word
	if(size==2)
	{
		List.appendanag(word,word);
			for(int i=0 ; i<2;i++)
			{
				anag=s.Top();//return the anagram from the stack
				if(!List.testanag(word,anag))//check if the anagram already exist
				{
					List.appendanag(word,anag);//store the anagram
				}
				s.Pop();//remove the top anagram from the stack
			}
			s.destroyStack();//clear all the anagram in the stack
	}
	else if(size==3)
	{
		List.appendanag(word,word);
			for(int i=0 ; i<6;i++)
			{
				anag=s.Top();
				if(!List.testanag(word,anag))
				{
					List.appendanag(word,anag);
				}
				s.Pop();
			}
			s.destroyStack();
	}
	
	else if(size==4)
	{
		List.appendanag(word,word);
			for(int i=0 ; i<24 ;i++)
			{
				anag=s.Top();
				if(!List.testanag(word,anag))
				{
					List.appendanag(word,anag);
				}
				s.Pop();
			}
			s.destroyStack();
	}
	
	else if(size==5)
	{
		List.appendanag(word,word);
			for(int i=0 ; i<119;i++)
			{
				anag=s.Top();
				if(!List.testanag(word,anag))
				{
					List.appendanag(word,anag);
				}
				s.Pop();
			}
			s.destroyStack();
	}
}
//Function to delete all the anagrams stored of a word
void clearanagram(string word, LinkedList<string> &List, stack<string>&s)
{
	int size;
	string anag;
	size=word.size();//calculate the size of the word
	if(size==2)
	{
		for(int i=0 ; i<2;i++)
		{
			anag=s.Top();//return the anagram from the stack
			List.deleteanag(word,anag);
			s.Pop();//remove the top word of the stack
		}
			s.destroyStack();//clear the stack 
	}
	else if(size==3)
	{
			for(int i=0 ; i<6;i++)
			{
				anag=s.Top();
				List.deleteanag(word,anag);
				s.Pop();
			}
			s.destroyStack();
	}
	
	else if(size==4)
	{
			for(int i=0 ; i<24;i++)
			{
				anag=s.Top();
				List.deleteanag(word,anag);
				s.Pop();
			}
			s.destroyStack();
	}
	
	else if(size==5)
	{
			for(int i=0 ; i<120;i++)
			{
				anag=s.Top();
				List.deleteanag(word,anag);
				s.Pop();
				}
			s.destroyStack();
	}
}
//Function to swap the position of two letters in a word
void swap(string &a, string &b) 
{
   string t = a;
   a = b;
   b = t; 
}

