#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr,int* tree,int start,int end,int index){
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    int mid = start + (end-start)/2;
    buildTree(arr,tree,start,mid,(index*2));
    buildTree(arr,tree,mid+1,end,(index*2)+1);
    tree[index] = tree[(index*2)+1] + tree[index*2];
}

void updateTree(int* arr,int* tree,int start,int end,int index,int idx,int value){
    if(start == end){
        arr[idx] = value;
        tree[index] = value;
        return;
    }
    int mid = start + (end-start)/2;
    if(idx > mid){
        updateTree(arr,tree,mid+1,end,(index*2)+1,idx,value);
    }
    else{
        updateTree(arr,tree,start,mid,2*index,idx,value);
    }
    tree[index] = tree[index*2]+tree[(index*2)+1];
}

int queryTree(int* tree,int si,int ei,int index,int left,int right){
    //Completely outside given range
    if(si>right || ei<left){
        return 0;
    }
    //Completely inside given range
    if(si>=left && ei<=right){
        return tree[index];
    }
    //Partially inside and outside given range
    int mid = si + (ei-si)/2;
    int ans1 = queryTree(tree,si,mid,index*2,left,right);
    int ans2 = queryTree(tree,mid+1,ei,(index*2)+1,left,right);
    return ans1+ans2;
}
//Always take the size of segment tree to be 4*n not 2*n;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int* tree = new int[n*2];
    buildTree(arr,tree,0,n-1,1);
    updateTree(arr,tree,0,n-1,1,2,10);
    for(int i=1;i<n*2;i++){
        cout << tree[i] << " ";
    }
    int ans = queryTree(tree,0,n-1,1,2,4);
    cout << "Sum between interval " << ans << endl;
    return 0;
}