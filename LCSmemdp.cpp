#include<bits/stdc++.h>
#include<string>
using namespace std;

int static dp[100][100];
int max(int a, int b){return(a>b?a:b);}
int lcs(string x, string y, int m, int n)
{
    
    if(m == 0 || n == 0){return 0;}
    if(dp[m][n] != -1){return dp[m][n];} // return from dp table if calculated
    if(x[m-1] == y[n-1]){return dp[m][n] = (1 + lcs(x,y,m-1,n-1));} // store in dp value
    else
        return dp[m][n] = (max(lcs(x,y,m-1,n),lcs(x,y,m,n-1)));
}

int main()
{
    string a,b;
    memset(dp,-1,sizeof(dp));
    cout<<"Enter a and b \n";
    getline(cin,a);
    getline(cin,b);
    int m = a.length();
    int n = b.length();
    cout<<"Length of lcs:";
    cout<<lcs(a,b,m,n);  

    return 0;
}
