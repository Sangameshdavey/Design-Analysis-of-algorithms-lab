#include<bits/stdc++.h>
using namespace std;
#define V 5
int minkey(int key[],bool visited[])
{
    int mindex=0;
    int min=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false && key[i]<min )
        {
            min=key[i];
            mindex=i;
        }
    }
    return mindex;
}

void printmst(int parent[],int graph[V][V])
{
    cout<<endl;
    cout<<"edge"<<"     "<<"weight";
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"--"<<i<<"  "<<graph[i][parent[i]]<<endl;
    }
    
}

void prims(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];
    
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        visited[i]=false;
        
    }
    key[0]=0;
    parent[0]=-1;
    
    for(int i=0;i<V-1;i++)
    {
        int u=minkey(key,visited);
        visited[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && visited[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
        
    }
    printmst(parent,graph);
}

int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    prims(graph);
 
    return 0;
}