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

int main() {
	List myList = List(); // create object
	myList.CreateThreeNodes();
	myList.PrintList();
	myList.ClearList();
}
