#include<bits/stdc++.h>
using namespace std;
int dp[20][20];
int knapsack(int sum,int coin[],int n)
{
    int i ,j;
   
    for(i =0; i <=n  ; i++ )
    { 
        for(j =0; j <=sum ;j++)
        { 
            if(i>=1 & j == 0)
                {dp[i][j] = 1;}
            else if(coin[i - 1] < sum) //special case: here we take sum instead of j
                {dp[i][j] =  dp[i][j - coin[i-1]] + dp[i-1][j];}
            else
                {dp[i][j] = dp[i-1][j];}

        }
    
    }
    return dp[n][sum];
}

int main()
{   //11111,2111,311,221,32, sum =5
    //1111111,211111,31111,2221,223,22111,331,3211 sum =7
    memset(dp,0,sizeof(dp));
    int coin[] = {1,2,3};
    int sum = 7;
    int n = sizeof(coin)/sizeof(coin[0]);
    cout<<"max no of ways:  "<<knapsack(sum,coin,n);
    cout<<endl;

    for(int i =0 ; i <=n  ; i++ )
    { for(int j =0; j <=sum ;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }   

    return 0;
}

