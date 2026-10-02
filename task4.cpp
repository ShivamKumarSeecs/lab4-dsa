// Shivam Kumar 555585
#include <iostream>
#include <iostream>
using namespace std;

class List {
private:
	typedef struct Node {
		int data;
		Node* next;
	} nodeptr;

	nodeptr* head;
	nodeptr* tail;

public:
	List() {
		head = nullptr;
		tail = nullptr;
	}

	void PrintList();
	void ClearList();
	void AddNode(int addData);

	void InsertAtBeginning(int addData); // task 4
};


void List::PrintList() {
	nodeptr* curr = head;
	cout << "List elements: ";
	while (curr != nullptr) {
		cout << curr->data << " -> "; //looping thru list
		curr = curr->next;
	}
	cout << "nullptr" << endl; //edn with nullptr
}
void List::ClearList() {
	nodeptr* curr = head;
	while (curr != nullptr) {
		nodeptr* nextNode = curr->next;
		delete curr; //clear from memory
		curr = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}
void List::AddNode(int addData) {
	cout << "Adding new Node with value " << addData << endl;
	nodeptr* newNode = new Node();
	newNode->data = addData; // add value to the newNode
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode; //create new node and list
	}
	else {
		//append
		tail->next = newNode;
		tail = newNode;
	}
}

//task 4
void List::InsertAtBeginning(int addData) {
	nodeptr* newNode = new Node();
	newNode->data = addData; //initialise node

	newNode->next = head; //add to the beginning
	head = newNode;

	if (tail == nullptr) { //if empty list then assign to tail too
		tail = newNode;
	}
}

void main() {
	List myList;

	cout << "Initial empty list:" << endl;
	myList.PrintList();
	cout << endl;

	//insert 20 at the beginning
	cout << "insert 20" << endl;
	myList.InsertAtBeginning(20);
	myList.PrintList();
	cout << endl;

	//insert 10 at the beginning
	cout << "insert 10" << endl;
	myList.InsertAtBeginning(10);
	myList.PrintList();
	cout << endl;

	//append 30 at the end
	cout << "append 30" << endl;
	myList.AddNode(30);
	myList.PrintList();
	cout << endl;

}
