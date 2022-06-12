/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
#define INF 999
#define nv 4
void print(int matrix[][nv])
{
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
        {
            if(matrix[i][j]==INF)
            {
                cout<<"INF";
            }
            else
            {
                cout<<matrix[i][j];
            }
           
            
        }
         cout<<endl;
    }
}

void flyodwarshall(int graph[nv][nv])
{
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
        {
            for(int k=0;k<nv;k++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    
    print(graph);
}


int main()
{
    int graph[nv][nv]={{0,3,INF,5},{2,0,INF,4},{INF,1,0,INF},{INF,INF,2,0}
        
        
        
    };
    flyodwarshall(graph);
    
}