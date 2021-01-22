#include <bits/stdc++.h>
using namespace std;

/*
 Breadth First Search Traversal
*/



///Create a vector to store connection of vertex
vector<int>ve[101];
///Create visit array to store which vertex visited
bool vis[101];



void bfs(int s)
{

/// Mark the source vertex as visited
    vis[s]=1;


/// Create a queue for explore vertex
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {

        /// Dequeue a vertex from queue and store it and print it
        int node=q.front();
        cout<<node<<' ';
        q.pop();

        /// Get all adjacent vertices of the dequeued
        ///If a adjacent has not been visited,
        /// then mark it visited and enqueue it
        for (int i=0; i<ve[node].size(); i++)
        {
            int cu=ve[node][i];
            if(vis[cu]==0)
            {
                vis[cu]=1;
                q.push(cu);
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

}
