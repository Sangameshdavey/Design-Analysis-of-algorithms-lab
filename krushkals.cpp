#include<bits/stdc++.h>
using namespace std;

class DSU
{
    public:
   int *parent;
   int *rank;
   
   DSU(int v)
   {
   		parent=new int[v];
   		rank=new int[v];
   		
       for(int i=0;i<v;i++)
       {
           parent[i]=i;
           rank[i]=0;
       }
   }
   
   int findParent(int v)
   {
       if(parent[v]==v)
       {
           return v;
       }
       parent[v]=findParent(parent[v]);
       return  parent[v];
   }
   
   void _union(int x,int y)
   {
       int p1=findParent(x);
       int p2=findParent(y);
       
       if(p1!=p2)
       {
           if(rank[p1]>rank[p2])
           {
               parent[p2]=p1;
           }
           else if(rank[p2]>rank[p1])
           {
               parent[p1]=p2;
           }
           else
           {
               parent[p1]=p2;
               rank[p2]++;
           }
       }
       
   }
};


int main()
{
    int v=4;int e=5;
    vector<vector<int>> graph(e,vector<int>(3)) ;
    DSU dsu(v);
    for(int i=0;i<e;i++)
    {
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    }
    sort(graph.begin(),graph.end());
    for (auto x : graph) {
        if (!(dsu.findParent(x[1]) == dsu.findParent(x[2]))){
            dsu._union(x[1], x[2]);
            cout << x[1] << " " << x[2] << " " << x[0] << endl;
        }
    }
    
}
