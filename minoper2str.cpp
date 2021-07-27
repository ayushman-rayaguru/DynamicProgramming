// Minimum operation to convert from one string to other string

#include<iostream>
#include<cstring>
using namespace std;

int max(int a,int b){return(a>b?a:b);}
// static dp[20][20];
int LCS(string a,string b,int m,int n,int** dp)
{

    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {

            if(i == 0 || j == 0){dp[i][j] = 0;}
            else if(a[i-1] == b[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
            else{dp[i][j] = max(dp[i][j-1],dp[i-1][j]);}
        }
    }
    return dp[m][n];
}

int main()
{
    //memset(dp,-1,sizeof(dp));
    string a,b;
    cout<<"Enter first string: \n";
    getline(cin,a);
    cout<<"Enter second string: \n";
    getline(cin,b);

    int m = a.length();
    int n = b.length();

    int** dp = new int *[m+1];
    for(int i =0 ;i<m+1;i++)
    {
        dp[i] = new int [n+1];
        for(int j =0 ;j<n+1;j++)
        {
            dp[i][j] = 0;
        }
    }


    cout<<"The minimum operations: ";
    cout<<max(m,n) - LCS(a,b,m,n,dp);
    cout<<"\n"<<endl;
    for(int i =0 ;i<m+1;i++)
    {
        for(int j =0 ;j<n+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}