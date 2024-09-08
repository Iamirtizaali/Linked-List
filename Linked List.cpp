#include <iostream>
using namespace std;
//
//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node(int data=0);
//	~Node();
//
//private:
//
//};
//
//Node::Node(int data)
//{
//	this->data=data;
//	this->next = NULL;
//}
//
//Node::~Node()
//{
//}
//
//void insertAtHead(Node* &head, int data){
//	Node* n = new Node(data);
//	n->next = head;
//	head = n;
//}
//
//void insertAtTail(Node* &tail, int data){
//	Node* n = new Node(data);
//	tail->next = n;
//	tail = n;
//
//}
//
//void print(Node* head){
//	while(head!=NULL){
//		cout<<head->data<<"-->";
//		head = head->next;
//	}
//	cout<<endl;
//}
//
//void insertAtCenter(Node* &head, int idx, int d) {
//	
//	Node* temp = head;
//	int count = 0;
//	while (count<idx-1)
//	{
//		temp = temp->next;
//		count++;
//	}
//	Node* newNode = new Node(d);
//	newNode->next = temp;
//	temp->next = newNode;
//
//}
//
//void insertAtPosition(Node*& head, int data,int idx) {
//	int count = 0;
//	Node* temp = head;
//	Node* prev = head;
//	if (head==NULL)
//	{
//		Node* newNode = new Node(data);
//		head = newNode;
//		return;
//	}
//	while (temp->next!=NULL && count<idx-1)
//	{
//		prev = temp;
//		temp = temp->next;
//		count++;
//	}
//	if (temp->next==NULL && count<idx-2)
//	{
//		cout << "count is: " << count << endl;
//		cout << "Wrong value"<<endl;
//		return;
//	}
//	if (idx==1)
//	{
//		Node* newNode = new Node(data);
//		newNode->next = head;
//		head = newNode;
//		return;
//	}
//	if (temp->next==NULL)
//	{
//		Node* newNode = new Node(data);
//		temp->next = newNode;
//		return;
//	}
//
//	Node* newNode = new Node(data);
//	prev->next = newNode;
//	newNode->next = temp->next;
//
//}
//
//
//int main() {
//	Node* node1 = new Node(10);
//	cout<<node1->data<<endl;
//	cout<<node1->next<<endl;
//	Node* head=node1;
//	Node* tail=node1;
//	print(head);
//	insertAtHead(head, 20);
//	print(head);
//	insertAtTail(tail, 30);
//	print(head);
//	insertAtTail(tail, 60);
//	print(head);
//	insertAtPosition(head, 23, 5);
//	print(head);
//	return 0;
//}

class Node
{
	int value;
	Node* next;
public:
	Node(int value = 0) {
		this->value = value;
		this->next = NULL;
	};
	void setValue(int value) {
		this->value = value;
	}
	int getValue() {
		return value;
	}
	void setNext(Node* next) {
		this->next = next;
	}
	Node* getNext() {
		return this->next;
	}

private:

};

class List
{
	Node* head;
public:
	List() {
		this->head = NULL;
	};
	void insertAtStart(int value) {
		if (this->head==NULL)
		{
			Node* newNode = new Node(value);
			this->head = newNode;
			cout << "headaer value is " << head->getValue() << endl;
		}
		else
		{
			Node* newNode = new Node(value);
			newNode->setNext(head);
			head = newNode;
		}
	}
	void insertAtEnd(int value) {
		if (this->head == NULL)
		{
			Node* newNode = new Node(value);
			this->head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->getNext()!=NULL)
			{
				temp = temp->getNext();
			}
			Node* newNode = new Node(value);
			temp->setNext(newNode);
		}
	}
	/*void insertAtPosition(int value, int position) {
		if (head==NULL)
		{
			Node* newNode = new Node(value);
			head = newNode;
		}
		else
		{
			if (position==1)
			{
			Node* newNode = new Node(value);
			newNode->setNext(head);
			head = newNode;
			}
			int count = 0;
			Node* prev = head;
			Node* temp = head;
			while (temp->getNext()!=NULL && count<position-1)
			{
				prev = temp;
				temp=temp->getNext();
				count++;
			}
			if (temp->getNext() == NULL && count < position - 2)
			{
				cout << "Wrong value" << endl;
				return;

			}
			if (temp->getNext()==NULL && count<position-1)
			{
				Node* newNode = new Node(value);
				temp->setNext(newNode);
			}
			else
			{

				Node* newNode = new Node(value);
				newNode->setNext(temp);
				prev->setNext(newNode);
			}
		}
	}*/
	void insertAtPosition(int value, int position) {
		if (position < 1) {
			cout << "Invalid position!" << endl;
			return;
		}

		Node* newNode = new Node(value);

		// Case 1: Inserting at the head of the list
		if (position == 1) {
			newNode->setNext(head);
			head = newNode;
			return;
		}

		// Case 2: Inserting at any other position
		Node* temp = head;
		int count = 0;  // Start counting from 1 since position is 1-based

		while (temp != NULL && count < position - 2) {
			temp = temp->getNext();
			count++;
		}

		// If temp is NULL, it means the position is out of bounds
		if (temp == NULL) {
			cout << "Position out of bounds!" << endl;
			delete newNode;
			return;
		}

		// Insert the new node at the correct position
		newNode->setNext(temp->getNext());
		temp->setNext(newNode);
	}

	void displayList() {
		cout << "head is " << head << endl;
		Node* temp = head;
		while ( temp!=NULL)
		{
			cout << temp->getValue() << "-->";
			temp=temp->getNext();
		}
		cout << endl;
	}
	void deleteNodebyIndex(int index) {
		if (index < 1) {
			cout << "Invalid index!" << endl;
			return;
		}

		Node* temp = head;

		// Case 1: Deleting the head node
		if (index == 1 && head != NULL) {
			head = head->getNext();
			delete temp;
			return;
		}

		Node* prev = NULL;
		int count = 0;

		// Traverse to the node before the one we want to delete
		while (temp != NULL && count < index-1) {
			prev = temp;
			temp = temp->getNext();
			count++;
		}

		// If temp is NULL, the index is out of bounds
		if (temp == NULL) {
			cout << "Index out of bounds!" << endl;
			return;
		}

		// Delete the node and update the next pointer
		prev->setNext(temp->getNext());
		delete temp;
	}

private:

};




int getValue() {
	int value=0;
	cout << "Enter the value: ";
	cin >> value;
	return value;
}
int getIndex() {
	int idx=0;
	cout << "Enter the index: ";
	cin >> idx;
	return idx;
}
int main() {
	List l1;
	do
	{
		cout << "Enter 1 to print list" << endl;
		cout << "Enter 2 to insert value at start" << endl;
		cout << "Enter 3 to insert value at end" << endl;
		cout << "Enter 4 to insert value at position" << endl;
		cout << "Enter 5 to delete value " << endl;
		cout << "Enter 6 to Exit" << endl;
		cout << "Enter your choice: ";
		int choice=0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			l1.displayList();
			break;
		case 2:
			l1.insertAtStart(getValue());
			break;
		case 3:
			l1.insertAtEnd(getValue());
			break;
		case 4:
			l1.insertAtPosition(getValue(), getIndex());
			break;
		case 5:
			l1.deleteNodebyIndex(getIndex());
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Wrong Choice" << endl;
			break;
		}
	} while (true);
	return 0;
}