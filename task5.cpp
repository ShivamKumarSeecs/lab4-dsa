// Shivam Kumar 555585 BSCS-15-D
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

	void DeleteNode(int delData); // task5
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

//task 5
void List::DeleteNode(int delData) {
	//if empty list
	if (head == nullptr) {
		cout << "Cannot delete from empty list" << endl;
		return;
	}

	nodeptr* curr = head;
	nodeptr* prev = nullptr; //needed to chain list

	//search for the node to delete
	while (curr != nullptr && curr->data != delData) {
		prev = curr;
		curr = curr->next;
	}

	//value not found
	if (curr == nullptr) {
		cout << "Value not found in list." << endl;
		return;
	}

	// deleting the head node
	if (curr == head) {
		head = head->next;
		// if only one node, update head and tail
		if (head == nullptr) {
			tail = nullptr;
		}
	}
	//deleting a middle or last node
	else {
		prev->next = curr->next;
		// If the deleted node was the tail, update tail to prev
		if (curr == tail) {
			tail = prev;
		}
	}

	//release from memory
	delete curr;
}

int main() {
	List myList;

	//test 1 deleting from empty list
	cout << "test 1 deleting from empty list" << endl;
	myList.DeleteNode(10);
	myList.PrintList();
	cout << endl;

	//adding nodes 10 20 20 30 to list
	myList.AddNode(10);
	myList.AddNode(20);
	myList.AddNode(20);
	myList.AddNode(30);
	cout << "initial list populated" << endl;
	myList.PrintList();
	cout << endl;

	//test 2 deleting value that is not present
	cout << "test 2 deleting missing value 99" << endl;
	myList.DeleteNode(99);
	myList.PrintList();
	cout << endl;

	//test 3 deleting first instance of duplicate value 20
	cout << "test 3 deleting first instance of 20" << endl;
	myList.DeleteNode(20);
	myList.PrintList();
	cout << endl;

	//test 4 deleting first node 10
	cout << "test 4 deleting first node 10" << endl;
	myList.DeleteNode(10);
	myList.PrintList();
	cout << endl;

	//test 5 deleting last node 30
	cout << "test 5 deleting last node 30" << endl;
	myList.DeleteNode(30);
	myList.PrintList();
	cout << endl;

	//test 6 deleting only remaining node 20
	cout << "test 6 deleting  node 20" << endl;
	myList.DeleteNode(20);
	myList.PrintList();
	cout << endl;

	return 0;
}
