/**
 *          Reversing a linked list
 * --------------------------------------------------------------
 * This is the implementation of reversing a linked list.
 * Time complexity - O(n)
 * Space complexity -  O(1)
*/

// Including required libraries
#include<bits/stdc++.h>

using namespace std;

// Class declaration of a node in a linked list
class Node{
    public:
    int value;
    Node *next;
};

// Adding a node to the linked list
Node* add_node(Node* head, int val){
    Node* child = new Node();
    child->value = val;
    Node* temp = head;

    // If head is null
    if(temp == NULL){
        return child;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = child;
    return head;
}

// Printing the linked list
void print_nodes(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "/";
    cout << endl;
}

// Reversing the list
Node* reverse_list(Node *head){
    Node* prev = NULL, *curr = head, *temp = head;
    while(temp != NULL){
        temp = temp->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

// Driver method of the program
int main(){

    // Input
    int n;
    cout << "Enter number of nodes:" << endl;
    cin >> n;
    cout << "Enter nodes:" << endl;
    int temp;
    Node *head = NULL;
    
    // Input of list
    for(int i = 0; i < n; i ++){
        cin >> temp;
        head = add_node(head,temp);
    }

    cout << "The linked list is:" << endl;
    print_nodes(head);
    
    // Reversing the list
    head = reverse_list(head);

    // Output
    cout << "After reversing, the linked list is: " << endl;
    print_nodes(head);
    return 0;
}