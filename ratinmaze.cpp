#include<bits/stdc++.h>
#include<stdio.h>
#define n 5
using namespace std;
int maze[n][n],sol[n][n];

int read_mat(int maze[n][n])
{
    cout<<"enter the walls path and cheese :"<<endl;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {
            cin>>maze[i][j];
        }
    }
}

int display_mat(int maze[n][n])
{   int e = 0;
    cout<<endl;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {   
            cout<<maze[i][j]<<" ";

        }
        cout<<endl;
    }
}

bool validstep(int maze[n][n],int x,int y)
{
    if(x < n && x>=0 && y < n && y >=0 && maze[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}

bool rightpath(int maze[n][n],int sol[n][n], int x ,int y)
{
    if(x == n-1 && y == n-1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if(validstep(maze,x,y) == true)
    {
        if(sol[x][y] == 1) // already traced path
        return false;
    

    sol[x][y] = 1; // marking 1 to first valid path.

    if(rightpath(maze,sol,x+1,y) == true)
        return true;

    if(rightpath(maze,sol,x,y+1) == true)
        return true;

    if(rightpath(maze,sol,x-1,y) == true)
        return true;

    if(rightpath(maze,sol,x,y-1) == true)
        return true;
    
    sol[x][y] = 0;
    return false;
    }
    return false;
}


int path(int maze[n][n])
{
    int sol[n][n] = {0};

    if(rightpath(maze,sol,0,0) == false)
        {cout<<"\n Path doesn't exist"<<endl;;
        return false;}
    display_mat(sol);
    return true;
}

int main()
{
    read_mat(maze);
    cout<<endl<<endl<<path(maze);
    return 0;
}

