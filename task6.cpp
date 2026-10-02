// Shivam Kumar 555585 BSCS-15-D
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
	void InsertAtBeginning(int addData);
	void DeleteNode(int delData);
	void SearchNode(int searchData);
	int CountNodes();
	void PrintSecondNode();
};

void List::PrintList() {
	nodeptr* curr = head;
	cout << "list elements: ";
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
	nodeptr* newNode = new Node();
	newNode->data = addData; //add value to new node
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

void List::InsertAtBeginning(int addData) {
	nodeptr* newNode = new Node();
	newNode->data = addData; //initialise node

	newNode->next = head; //add to beginning
	head = newNode;

	if (tail == nullptr) { //if empty list then assign to tail too
		tail = newNode;
	}
}

void List::DeleteNode(int delData) {
	//if empty list
	if (head == nullptr) {
		cout << "cannot delete from empty list" << endl;
		return;
	}

	nodeptr* curr = head;
	nodeptr* prev = nullptr; //needed to chain list

	//search for node to delete
	while (curr != nullptr && curr->data != delData) {
		prev = curr;
		curr = curr->next;
	}

	//value not found
	if (curr == nullptr) {
		cout << "value not found in list" << endl;
		return;
	}

	//deleting head node
	if (curr == head) {
		head = head->next;
		//if only one node update head and tail
		if (head == nullptr) {
			tail = nullptr;
		}
	}
	else {
		//deleting middle or last node
		prev->next = curr->next;
		//if deleted node was tail update tail to prev
		if (curr == tail) {
			tail = prev;
		}
	}

	//release from memory
	delete curr;
}

void List::SearchNode(int searchData) {
	int count = 0; //counting variable
	if (head == nullptr) { //empty list checks
		cout << "cannot search empty list" << endl;
	}
	else {
		nodeptr* curr = head;
		while (curr != nullptr) { //check when list ends
			count++; //incrementing position
			if (curr->data == searchData) { //search value check
				cout << "element found at position " << count << endl;
				return; //end function
			}
			curr = curr->next;
		}
		cout << "value not found" << endl;
	}
}

int List::CountNodes() {
	nodeptr* curr = head;
	int count = 0; //counter
	while (curr != nullptr) {
		count++;
		curr = curr->next;
	}
	return count;
}

void List::PrintSecondNode() {
	if (head == nullptr || head->next == nullptr) { //check if empty list or one node list
		cout << "list length is fewer than 2 nodes" << endl;
	}
	else {
		cout << "second node value is " << head->next->data << endl; //print next node from heads data
	}
}

int main() {
	List myList;
	int choice = 0;
	int val;

	//menu loop
	while (choice != 8) {
		cout << "menu options" << endl;
		cout << "1 insert at beginning" << endl;
		cout << "2 insert at end" << endl;
		cout << "3 search by value" << endl;
		cout << "4 delete by value" << endl;
		cout << "5 display all nodes" << endl;
		cout << "6 count nodes" << endl;
		cout << "7 display second node" << endl;
		cout << "8 exit" << endl;
		cout << "enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "enter value to insert at beginning: ";
			cin >> val;
			myList.InsertAtBeginning(val);
			break;
		case 2:
			cout << "enter value to insert at end: ";
			cin >> val;
			myList.AddNode(val);
			break;
		case 3:
			cout << "enter value to search: ";
			cin >> val;
			myList.SearchNode(val);
			break;
		case 4:
			cout << "enter value to delete: ";
			cin >> val;
			myList.DeleteNode(val);
			break;
		case 5:
			myList.PrintList();
			break;
		case 6:
			cout << "total nodes " << myList.CountNodes() << endl;
			break;
		case 7:
			myList.PrintSecondNode();
			break;
		case 8:
			//release all remaining nodes before exiting
			myList.ClearList();
			cout << "exiting program" << endl;
			break;
		default:
			//handle invalid menu choices
			cout << "invalid choice try again" << endl;
		}

	}

	myList.ClearList();
	return 0;
}
