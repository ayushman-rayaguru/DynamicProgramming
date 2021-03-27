# include<bits/stdc++.h>
#include<cstring>
using namespace std;
int i,j;
int print_prime(int*arr,int n)
{
    for(i = 2 ;i<n;i++)
    {
        if(arr[i] == 1)
        {
            cout<<i<<",";
        }
    }
}


int main()
{   int f;
    cout<<"Enter first f : ";
    cin>>f;
    int* prime = new int[f];
    prime[0] = 0;
    prime[1] = 0;

    for(i = 2 ;i<f;i++)
    {
        prime[i] = 1;
    }
    
    for(i = 2;i <= f; i++)
    {
        if(prime[i] == 1)
        {
        for(j = 2; i*j <=f; j++)
        {
            prime[i*j] = 0;
        }
        }
    }
    print_prime(prime,f);
    delete[] prime;
    return 0;
}

