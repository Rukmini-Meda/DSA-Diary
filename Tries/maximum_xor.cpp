#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode *left,*right;
};

void insert(int n,TrieNode *head){
    TrieNode *current = head;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(current->left == NULL){
                current->left = new TrieNode();
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = new TrieNode();
            }
            current = current->right;
        }
    }
} 

int findMaxXorPair(TrieNode *head,int *arr,int n){
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++){
        int value = arr[i],curr_xor=0;
        TrieNode *current = head;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;
            if(bit == 0){
                if(current->right != NULL){
                    curr_xor += 1<<j;
                    current = current->right;
                }
                else{
                    current = current->left;
                }
            }
            else{
                if(current->left != NULL){
                    curr_xor += 1<<j;
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
        }
        max_xor = max(curr_xor,max_xor);
    }
    return max_xor;
}

int main(){

    int n=6;
    int arr[6] = {8,1,2,15,10,5};
    TrieNode *head = new TrieNode();
    for(int i=0;i<n;i++){
        insert(arr[i],head);
    }
    cout << findMaxXorPair(head,arr,n) << endl;
    return 0;
}