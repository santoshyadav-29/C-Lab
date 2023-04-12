// Linkedlist implementation
#include <iostream>
using namespace std;

class Node {
public:
	int data;
    Node * next;

	// Default contructor!
	Node()
	{
		data = 0;
		next = NULL;
	}


    // parametrized constructor!
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlist {
    Node* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    void insertNode(int);
    void printList();
    void deleteNode(int);
};

void Linkedlist::insertNode(int data)
{

    Node* newNode = new Node(data);
  
    // Assigning to Head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
//    Traverse till the end 
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}

void Linkedlist::printList()
{
    Node* temp = head;
  
//    Checking If the list is empty
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list
    while (temp != NULL) {
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}
void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
  
    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
  
    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range"<< endl;
        return;
    }
  
    // Declare a temporary variable
    temp1 = head;
  
//    Removing the Head
    if (nodeOffset == 1) {
  
        // Update head
        head = head->next;
        delete temp1;
        return;
    }
  
    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
  
    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;
  
    // Delete the node
    delete temp1;
}



// Driver Code
int main()
{
     Linkedlist list;
  
    // Inserting nodes
    list.insertNode(1);
    list.insertNode(3);
    list.insertNode(50);

    
  
    cout << "Elements of the list are: ";
  
    // Print the list
    list.printList();
    cout << endl;
  
    // Delete node at position 2.
    list.deleteNode(2);
  
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
	return 0;
}
