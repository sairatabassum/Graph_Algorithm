#include <bits/stdc++.h>
using namespace std;

/*
Iterative Depth First Traversal of Graph
*/

///Create a vector to store connection of vertex
vector<int>ve[101];
///Create visit array to store which vertex visited
bool vis[101];

void dfs(int source)
{

    stack<int>stck;
    /// Push the current source vertex.
    stck.push(source);

    while(!stck.empty())
    {
        ///Store and pop the current vertex
        int current=stck.top();
        stck.pop();

        if(vis[current]==false)
        {
            vis[current]=true;
            cout<<current<<' ';
        }
        ///All adjacent vertices of the popped current vertex
        ///If adjacent vertices has not been visited, then push it to the stack
        for(int i=0; i<ve[current].size(); i++)
        {

            if(vis[ve[current][i]]==false)
            {
                stck.push(ve[current][i]);
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
    dfs(source);



}

