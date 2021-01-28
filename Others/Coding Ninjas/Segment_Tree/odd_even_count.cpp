/**
 * Counting Even/Odd

Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/


#include<bits/stdc++.h>
using namespace std;

struct OddEvenArray{
    int odd, even;
};

void buildOddEvenTree(int *arr, OddEvenArray *tree, int start, int end, int treeNode){
    // cout << treeNode << endl;
    if(start == end){
        if(arr[start] % 2 == 0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
            return;
        }
        else{
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
            return;
        }
    }
    int mid = start + ((end - start)/2);
    buildOddEvenTree(arr,tree,start,mid,2*treeNode);
    buildOddEvenTree(arr,tree,mid+1,end,(2*treeNode)+1);
    tree[treeNode].odd = tree[2*treeNode].odd + tree[(2*treeNode)+1].odd;
    tree[treeNode].even = tree[2*treeNode].even + tree[(2*treeNode)+1].even;
}

int queryOddEvenTree(OddEvenArray *tree, int start, int end, int treeNode,int left, int right, bool isEven){
    // cout << start << " " << end << endl;
    if(start > right || end < left){
        return 0;
    }

    if(start >= left && end <= right){
        if(isEven == true){
            return tree[treeNode].even;
        }
        else{
            // cout << tree[treeNode].odd << endl;
            return tree[treeNode].odd;
        }
    }
    int mid = start + (end-start)/2;
    int ans1 = queryOddEvenTree(tree, start, mid, 2*treeNode, left, right, isEven);
    int ans2 = queryOddEvenTree(tree, mid + 1, end, 2*treeNode + 1, left, right, isEven);
    return ans1 + ans2;
}

void updateOddEvenTree(int *arr, OddEvenArray *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        if(value%2 == 0){
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else{
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }
    int mid = start + (end-start)/2;
    if(idx > mid){
        updateOddEvenTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }
    else{
        updateOddEvenTree(arr,tree,start,mid,2*treeNode,idx,value);
    }
    tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode+1].odd;
    tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode+1].even;
}

void printOddEvenTree(OddEvenArray *tree, int m){
    for(int i = 1; i <= m; i ++){
        cout << tree[i].odd << " " << tree[i].even << endl;
    }
    cout << endl;
}

int main() {

	// Write your code here
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    OddEvenArray *tree = new OddEvenArray[4*n+1];
    for(int i = 0; i <= 4*n; i ++){
        tree[i].odd = 0;
        tree[i].even = 0;
    }
    buildOddEvenTree(arr,tree,0,n-1,1);
    
    // printOddEvenTree(tree,2*n+1);
    
    int m;
    cin >> m;
    // printOddEvenTree(tree,2*n+1);
    for(int i = 0; i < m; i ++){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 0){
            updateOddEvenTree(arr,tree,0,n-1,1,x-1,y);
            // printOddEvenTree(tree,2*n+1);
        }
        else if(type == 1){
            // bool isEven = true;
            int result = queryOddEvenTree(tree, 0, n-1, 1, x-1, y-1, true);
    		cout << result << endl;
        }
        else{
            // bool isEven = false;
            int result = queryOddEvenTree(tree, 0, n-1, 1, x-1, y-1, false);
    		cout << result << endl;
            
        }
    }
    return 0;
}