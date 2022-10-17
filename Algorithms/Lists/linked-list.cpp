/*
 author: steven anthony  
 brief: linked list
 advantage: gives ability to traverse a list in forward direction 
*/

#include <iostream>
using namespace std;

class Node
{
  public: 
    int p; 		// index
    Node* next;		// pointer to the next node 
};

Node* newNode(int p)
{
	Node* node = new Node;
	node->p = p;
	node->next = nullptr;
	return node;
}

Node* constructList()
{
	Node* first = newNode(1);
	Node* second = newNode(2);
	Node* third = newNode(3);

	Node* head = first;
	first->next = second;
	second->next = third;

	return head;
}

void printList(Node* head)
{
	Node* ptr = head;
	while (ptr)
	{
		cout << ptr->p << " -> ";
		ptr = ptr->next;
	}
	cout << "nullptr \n";
}

int main() 
{
  Node *head = constructList();
  printList(head);
  return 0;
}
