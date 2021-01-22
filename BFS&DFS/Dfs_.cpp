#include <bits/stdc++.h>
using namespace std;

/*
Depth First Search Traversal
*/

///Create a vector to store connection of vertex
vector<int>ve[101];
///Create visit array to store which vertex visited
bool vis[101];


void dfs(int s)
{

    /// Mark the current vertex as visited and print it
    vis[s]=1;
    cout<<s<<' ';

    /// Recursive  for all the vertices adjacent
    for(int i=0; i<ve[s].size(); i++)
    {

        int next=ve[s][i];
        if(vis[next]==0)
        {
            dfs(next);
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
        ve[v].push_back(u);


    }

    int source;
    cout<<"Enter source:";
    cin>>source;
    dfs(source);

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==1)
        {
            cout<<i<<" is visited"<<endl;
        }
        else
        {
            cout<<i<<" is not visited"<<endl;
        }
    }


}
