#include <bits/stdc++.h>
using namespace std;

/*
Level of graph from source vertex using bfs
*/



///Create a vector to store connection of vertex
vector<int>ve[101];
///Create visit array to store which vertex visited
bool vis[101];
///Create distance array to store distance from source vertex
int dis[101]= {0};


void bfs(int s)
{

/// Mark the source vertex as visited and update distance
    vis[s]=1;
    dis[s]=0;

/// Create a queue for explore vertex
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {

        /// Dequeue a vertex from queue and store it
        int node=q.front();
        q.pop();

        /// Get all adjacent vertices of the dequeued
        ///If a adjacent has not been visited,
        /// then mark it visited and enqueue it and update distance
        for (int i=0; i<ve[node].size(); i++)
        {
            int cu=ve[node][i];
            if(vis[cu]==0)
            {
                vis[cu]=1;
                q.push(cu);
                dis[cu]=dis[node]+1;
            }
        }

    }



}


int main()
{

    int n,e;
    cout<<"Enter the number of vertex: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>e;

    ///Take input connection of graphs
    for(int i=0; i<e; i++)
    {

        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);


    }

    int source;
    cout<<"Enter source:";
    cin>>source;
    bfs(source);

    cout<<"from vertex "<<source<<endl;
    /// Display all vertex and their levels
    for(int i=1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<" is: "<<dis[i]<<endl;
    }





}
