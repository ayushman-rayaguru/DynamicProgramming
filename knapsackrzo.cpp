/*
Ques:Given is weight and values of n items
Aim : Put items in knapsack of weight W;to get maximum value of knapsack.
Note: you can't break item either 0(not enter) or 1(will enter).
01-knapsack recursion way
val[n] --> {0,...,n-1}
wt[n]  --> {0,...,n-1}
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){ return (a>b?a:b);}


int knapsack(int w, int wt[],int val[],int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }

    if(wt[n-1]<=w)
    {
        return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
    }
    else
    {
        return knapsack(w,wt,val,n-1);
    }
}
int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knapsack(w,wt,val,n);
    return 0;
}


