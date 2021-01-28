/**
 * StairCase Problem

A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274

*/
#include <iostream>
using namespace std;

long helper(int n,long int* arr){
    if(n<0){
        return 0;
    }
    if(n == 0 || n == 1){
        return 1;
    }
    if(arr[n]>0){
        return arr[n];
    }
    arr[n] = helper(n-1,arr)+helper(n-2,arr)+helper(n-3,arr);
    return arr[n];
}

long staircase(int n)
{
	//Write your code here
    long int* arr = new long int[n+1]();
    return helper(n,arr);
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}