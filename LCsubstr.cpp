#include<bits/stdc++.h>
#include<string>
using namespace std;
int dp[20][20];
int result = 0;
int lcstr(string x,string y,int m,int n)
{
    for(int i = 0;i < m+1 ; i++){
        for(int j = 0;j < n+1;j++){if(i == 0 || j == 0){dp[i][j] = 0;}}
    }
    for(int i = 1; i<m+1; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                 dp[i][j] = 0;
                 result = max(result,dp[i][j]);
        }
    }

    return result;
   
}

int main()
{
    string a,b;
    memset(dp,-1,sizeof(dp));

    cout<<"Enter strings: \n";
    getline(cin,a);
    getline(cin,b);

    int m = a.length();
    int n = b.length();

    cout<<"The LC substring: "<<lcstr(a,b,m,n);
    cout<<endl;
    
    for(int i = 0;i<m;i++)
    {for(int j = 0;j<n;j++){cout<<dp[i][j]<<" ";}
        cout<<endl;}

    return 0;
}