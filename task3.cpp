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
	int CountNodes();

	void SearchNode(int searchData); //task3
	void PrintSecondNode();
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

//task 3
void List::SearchNode(int searchData) {
	int count = 0; // counting variable
	if (head == nullptr) { //empty list checks
		cout << "Cannot search an empty list" << endl;
	} else {
		nodeptr* curr = head;
		while (curr != nullptr) { //check when list ends
			count++; //incrementing position
			if (curr->data == searchData) { //search value check
				cout << "Element found at position " << count << endl;
				return; // end function
			}
			curr = curr->next; //advance
		}
		cout << "Value not found" << endl;
	}
}

void List::PrintSecondNode() {
	if (head == nullptr || head == tail) //check if empty list or one node list
		cout << "List length is fewer than 2 nodes" << endl;
	else {
		cout << "Second node value is " << head->next->data << endl; //print the next node from head's data
	}
}

void main() {
	int testValues[] = { 0, 1, 4 };

	for (int t = 0; t < 3; t++) {
		int n = testValues[t];
		cout << "Testing with n = " << n << endl;

		List myList;

		for (int i = 0; i < n; i++) {
			int val;
			cout << "Enter integer " << (i + 1) << ": ";
			cin >> val;
			myList.AddNode(val);
		}

		myList.PrintList();
		cout << "Total node count: " << myList.CountNodes() << endl;

		myList.PrintSecondNode();
		myList.SearchNode(20);
		myList.SearchNode(99);

		myList.ClearList();
		cout << endl;
	}
}
