
#include<bits/stdc++.h>
using namespace std;

void BellmanFord(int graph[][3],int v,int e,int src)
{
    int distance[v];
    for(int i=0;i<v;i++)
    {
        distance[i]=INT_MAX;
    }
    
    distance[src]=0;
    
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=graph[j][0];
            int v=graph[j][1];
            int w=graph[j][2];
            if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
            {
                distance[v]=distance[u]+w;
            }
        }
    }
    for(int j=0;j<e;j++)
    {
        int u=graph[j][0];
        int v=graph[j][1];
        int w=graph[j][2];
        if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
        {
            cout<<"negative cycle is presaent";
        }
    }
    
    for(int i=0;i<v;i++)
    {
        cout<<endl<<distance[i];
    }
}
int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };
 
    BellmanFord(graph, V, E, 0);
    return 0;
}