#include<bits/stdc++.h>
#include<string>
using namespace std;

int max(int a, int b){return(a>b?a:b);}
//int lcs(char* x, char* y, int m, int n)
int lcs(string x, string y, int m, int n)
{
    if(m == 0 || n == 0){return 0;}
    if(x[m-1] == y[n-1]){return (1 + lcs(x,y,m-1,n-1));}
    else
        return(max(lcs(x,y,m-1,n),lcs(x,y,m,n-1)));
}

int main()
{
    string a,b;
    
    cout<<"Enter a and b \n";
    getline(cin,a);
    getline(cin,b);
    int m = a.length();
    int n = b.length();
/* 
    char x[m+1];   
    char y[n+1];

    strcpy(x,a.c_str());
    strcpy(y,b.c_str());
*/
    cout<<"Length of lcs:";
    cout<<lcs(a,b,m,n);  // lcs(x,y,m,n)

    return 0;
}
