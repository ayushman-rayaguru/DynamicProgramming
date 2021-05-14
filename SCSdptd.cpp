#include<bits/stdc++.h>
using namespace std;
int static dp[20][20] ={0};

int scs(string a ,string b , int m , int n)
{
    for(int i = 1 ; i < m + 1;i++)
    {
        for(int j = 1 ; j < n + 1;j++)
        {
            if(a[i-1] == b[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
            else {dp[i][j] = max(dp[i][j-1],dp[i-1][j]);}
        }
    }

    return ((m + n) - dp[m][n]);
}


int main()
{    //ACE,BCDE  -->A B C D E
    string a,b;
    cout<<"Enter a and b \n";
    getline(cin,a);
    getline(cin,b);
    int m = a.length();
    int n = b.length();
    cout<<"Length of scs:";
    cout<<scs(a,b,m,n);  
    cout<<endl;

    //dp table
    for(int i = 0;i < m+1;i++)
    {
        for(int j =0;j < n+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}