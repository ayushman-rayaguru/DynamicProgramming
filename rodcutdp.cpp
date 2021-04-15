#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int static dp[10][10];
int max(int a, int b){ return (a>b?a:b);}

int knapsack(int L,int rodlength[],int price[], int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j <= L; j++)
        {
            if(rodlength[i-1] <= j)//remember!<----- error wt[i-1] <= j   j != max capacity.
                dp[i][j] = max(price[i - 1] + dp[i][j - rodlength[i - 1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];

        }
    }
    return dp[n][L];
}

int main()
{
    //17(6),5(2) -- ans
    memset(dp,0,sizeof(dp));
    int rodlength[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(rodlength) / sizeof(rodlength[0]);
    int L = 8;

    cout<<" "<<knapsack(L,rodlength,price,n);
    cout<<endl;

    for(int i = 0 ; i<=n;i++){
        for(int j = 0 ; j<=L ;j++)
        {cout<<dp[i][j]<<" ";}
        cout<<endl;}
        return 0;
}