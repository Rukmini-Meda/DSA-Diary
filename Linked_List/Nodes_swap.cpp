/**
 *       Implementation of Nodes swap in a linked list
 * --------------------------------------------------------------
 * This is the implementation of swapping two nodes in a linked list.
 * Assumption: All nodes have distinct values
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

// Swapping two nodes in a linked list
Node* swap_nodes(Node* head,int val1,int val2){

    // Initialization 
    Node* prev1 = NULL, *prev2 = NULL,*curr1 = NULL,*curr2 = NULL;
    Node* temp = head;

    // Searching for val1 in the list
    while(temp != NULL){
        if(temp->value == val1){
            curr1 = temp;
            break;
        }
        prev1 = temp;
        temp = temp->next;
    }

    // Searching for val2 in the list
    temp = head;
    while(temp != NULL){
        if(temp->value == val2){
            curr2 = temp;
            break;
        }
        prev2 = temp;
        temp = temp->next;
    }

    // If both val1, val2 are not present in the list
    if(curr1 == NULL || curr2 == NULL){
        return head;
    }
    
    // If either one is head
    if(curr1 == head || curr2 == head){
        if(curr1 == head){
            prev2->next = curr1;
            temp = curr1->next;
            curr1->next = curr2->next;
            curr2->next = temp;
            head = curr2;
        }
        else{
            prev1->next = curr2;
            temp = curr1->next;
            curr1->next = curr2->next;
            curr2->next = temp;
            head = curr1;
        }
        return head;
    }

    // If both are present and not head
    prev1->next = curr2;
    prev2->next = curr1;
    temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
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
    
    // Input of values to swap
    cout << "Enter value of nodes that have to be swapped:" << endl;
    int val1, val2;
    cin >> val1 >> val2;
    // Swapping nodes
    head = swap_nodes(head,val1,val2);
    // Output
    cout << "After swapping, the linked list is: " << endl;
    print_nodes(head);
    return 0;
}