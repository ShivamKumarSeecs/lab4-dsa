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

	void CreateThreeNodes();
	void PrintList();
	void ClearList();
	void AddNode(int addData); //task 2
	int CountNodes();
};

void List::CreateThreeNodes() {
	cout << "Creating Three Nodes" << endl;

	for (int i = 1; i <= 3; i++) {
		//dynamically allocate a new node
		nodeptr* newNode = new Node();

		//get input for the node's data
		cout << "Enter Num " << i << ": ";
		cin >> newNode->data;
		newNode->next = nullptr;

		//link the node into the list
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode; // chaining tail
			tail = newNode;
		}
	}
	cout << "Three nodes successfully created" << endl;
}

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
int List::CountNodes() {
	nodeptr* curr = head;
	int count = 0; ///counter
	cout << "List elements: ";
	while (curr != nullptr) {
		count++;
		curr = curr->next;
	}
	return count; //retrun
}

int main() {
	int testValues[] = { 0, 1, 5 };

	for (int t = 0; t < 3; t++) {
		int n = testValues[t];
		cout << "Testing with n = " << n << endl;

		List myList; //create a new list

		//loop to read and append
		for (int i = 0; i < n; i++) {
			int val;
			cout << "Enter integer " << (i + 1) << ": ";
			cin >> val;
			myList.AddNode(val);
		}

		// Display the list and its count
		myList.PrintList();
		cout << "Total node count: " << myList.CountNodes() << endl;

		myList.ClearList();
		cout << endl;
	}
}
