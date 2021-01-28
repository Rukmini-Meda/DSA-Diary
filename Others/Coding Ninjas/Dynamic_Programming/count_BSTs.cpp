/**
 * Count BSTs

Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5

*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    long long int dp[n+1]={0};
    int m = 1000000007;
    
    dp[0] = 1; 
    dp[1] = 1; 
  
    for (int i = 2; i <= n; i++) { 
        for (int j = 1; j <= i; j++) { 
          dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
            dp[i] = dp[i]%m;
        } 
    } 
  
    return dp[n]; 

    

}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
