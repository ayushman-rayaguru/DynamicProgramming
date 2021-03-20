/*
Ques:Given is weight and values of n items
Aim : Put items in knapsack of weight W;to get maximum value of knapsack.
Note: you can't break item either 0(not enter) or 1(will enter).
01-knapsack memoization way
tmp = table to store intermediate stages...
val[n] --> {0,...,n-1}
wt[n]  --> {0,...,n-1}
n - 1 ==> i
*/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int max(int a, int b){ return (a>b?a:b);}
const size_t R = 20;
const size_t C = 20;
int tmp[R][C],i,j;

int init_tmp(int tmp[R][C])
{
    for(i=0;i<R;i++)
    {
        for(j =0;j<C;j++)
        {
        tmp[i][j] = -1;
        }
    }
}

int alloc(void)
{
    for(i=0;i<R;i++)
    {
        for(j =0;j<C;j++)
        {
        cout<<tmp[i][j]<<" ";
        }
    }
}

//memset(tmp,-1,sizeof(tmp[0][0]) * R * C);

int knapsack(int w, int wt[],int val[],int n)
{
    if(n==0 || w ==0)
    {
        return 0;
    }
    if(tmp[n][w]!=-1){
        return tmp[n][w];
    }

    if(wt[n-1]<=w)
    {
        tmp[n][w] =  max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
        return tmp[n][w];
    }
    else
    {
        tmp[n][w] = knapsack(w,wt,val,n-1);
        return tmp[n][w];
    }
}


int main()
{   init_tmp(tmp);
    char ch;
    int val[] = {5,10,15,20};
    int wt[] = {40,10,30,20};
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<"max cost :"<<knapsack(w,wt,val,n);
    cout<<endl;
    cout<<"want to see allocation: (y/n) ";
    cin>>ch;
    if (ch =='y'){ alloc();}
    else
    return 0;
}



