/**
 *      Implementation of merging two sorted lists
 * -------------------------------------------------------------
 * Time Complexity - O(n+m)
 * Space complexity - O(1)
*/

// Importing required libraries
#include<bits/stdc++.h>
using namespace std;

// Class definition of a node in a list
class Node{
    public:
    int value;
    Node* next;
};

// Merging two sorted linked lists
Node* merge_sorted_lists(Node* headA,Node* headB){
    // Head of the final merged list
    Node* head = new Node();
    Node* dummy = head;
    Node* temp1 = headA, *temp2 = headB;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->value <= temp2->value){
            dummy->next = temp1;
            temp1 = temp1->next;
        }
        else{
            dummy->next = temp2;
            temp2 = temp2->next;
        }
        dummy = dummy->next;
    }
    while(temp1 != NULL){
        dummy->next = temp1;
        dummy = dummy->next;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        dummy->next = temp2;
        dummy = dummy->next;
        temp2 = temp2->next;
    }
    return head->next;
}

// Utility function to print the linked list
void print_list(Node* head){
    Node* temp = head;
    if(temp == NULL){
        cout << "List is NULL" << endl;
    }
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
}

// Method for inserting a node into the list
Node* insert_node(Node* head,int val){
    Node* node = new Node();
    node->value = val;
    if(head == NULL){
        return node;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

// Driver method of the program
int main(){
    // Input
    cout << "Enter number of integers in the sorted list A:" << endl;
    int n;
    cin >> n;
    cout << "Enter the integers:" << endl;
    int temp;
    Node* headA = NULL;
    for(int i=0;i<n;i++){
        cin >> temp;
        headA = insert_node(headA,temp);
    }
    cout << "Enter number of integers in the sorted list B:" << endl;
    int m;
    cin >> m;
    cout << "Enter the integers:" << endl;
    Node* headB = NULL;
    for(int i=0;i<m;i++){
        cin >> temp;
        headB = insert_node(headB,temp);
    }
    Node* head = NULL;
    head = merge_sorted_lists(headA,headB);
    // Output
    cout << "The merged list is:" << endl;
    print_list(head);
    return 0;
}