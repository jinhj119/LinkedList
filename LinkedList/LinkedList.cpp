#include <iostream>
using namespace std;

class Node {
public:
	int Value;
	Node* Next;
};

void printList(Node* Nodeptr) {
	while (Nodeptr != NULL) {
		cout << Nodeptr->Value << endl;
		Nodeptr = Nodeptr->Next; // gets the next element
	}
}

void frontInsert(Node**head, int newValue) {
	// first we create a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	// then point the newNode to the first element of the linked list
	newNode->Next = *head;
	// then we make the head of the linked list into the newNode we created
	*head = newNode;

}

void endInsert(Node**head, int newValue) {
	// first create a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	// if linked list is empty, newNode will be head node
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	// find last node
	Node* last = *head;
	while (last->Next != NULL) {
		last = last->Next;
	}
	// insert newNode after last node
	last->Next = newNode;
}

void afterInsert(Node* previous, int newValue) {
	// check if previous node is NULL
	if (previous == NULL) {
		cout << "Previous can not be NULL";
		return;
	}
	// create newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	// insert newNode after previous
	newNode->Next = previous->Next;
	previous->Next = newNode;

}

int main() {
	
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;

	second->Value = 2;
	second->Next = third;

	third->Value = 3;
	third->Next = NULL;

	afterInsert(head, -1);
	afterInsert(second, -2);
	printList(head);

	system("pause>0");
}

//this is test branch