/**
 * Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4

*/


#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    int **dp = new int*[row];
    for(int i=0;i<row;i++){
        dp[i] = new int[col];
    }
    
    for(int i=0;i<col;i++){
        dp[0][i] = 1 - arr[0][i];
    }
    
    for(int i=0;i<row;i++){
        dp[i][0] = 1 - arr[i][0];
    }
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j] == 0){
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int result = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result = max(result,dp[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return result;
    
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}