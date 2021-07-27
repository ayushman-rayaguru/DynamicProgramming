#include<bits/stdc++.h>
using namespace std;
bool static dp[20][20] = {true}; //  dp matrix 
bool knapsack(int arr[],int sum,int n)
{
    for(int i = 0 ;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
            if(i==0 && j>0){dp[i][j] = false;}
            else if(j == 0){dp[i][j] = true ;}
            else if(arr[i-1] <= j){dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j] ; }
            else {dp[i][j] = dp[i-1][j];}       
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {3,7,1};
    int sum = 4;
    int n = sizeof(arr) / sizeof(n);
    cout<<"The result is:  "<<knapsack(arr,sum,n);
    cout<<endl;
    for(int i = 0 ;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}
