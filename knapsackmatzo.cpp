/*
Ques:Given is weight and values of n items
Aim : Put items in knapsack of weight W;to get maximum value of knapsack.
Note: you can't break item either 0(not enter) or 1(will enter).
01-knapsack matrix dp way(top-down approach)
tmp = table to store intermediate stages...
val[n] --> {0,...,n-1}
wt[n]  --> {0,...,n-1}
n - 1 ==> i
*/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int max(int a, int b){ return (a>b?a:b);}

int knapsack(int W, int wt[],int val[],int n)
{
    int t[n+1][W+1];
    for(int i = 0; i <= n; i++ )
    {
        for(int w = 0; w <= W; w++)
        {
            if(i==0 || w==0)
                t[i][w] = 0;
            else if(wt[i-1] <= w)
                t[i][w] = max(val[i - 1]+t[ i - 1][w - wt[i-1]],t[i-1][w]);
            else
                t[i][w] = t[i-1][w];
        }
    }
    return t[n][W];
}
int main()
{   
    
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<"max cost :"<<knapsack(W,wt,val,n);
    cout<<endl;
    return 0;
}
