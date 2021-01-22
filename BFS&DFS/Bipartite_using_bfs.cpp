#include <bits/stdc++.h>
using namespace std;

///Create a vector to store connection of nodes
vector<int>ve[10];

///Create a color array to store colors
int color[10]; ///0=blue;1=red

///Using bfs if graph is bipartite or not
///It returns true , if not then returns false
bool bfs(int source)
{

    queue<int>q;
    color[source]=1;
    q.push(source);

    while(!q.empty())
    {
        int u;
        u=q.front();
        q.pop();

        ///Get all adjacent vertices of the dequeued
        for (int i=0; i<ve[u].size(); i++)
        {
            int cu;
            cu=ve[u][i];


            ///Return false if there is a self-loop
            if(cu==u)
                return false;

            ///Assign color to adjacent node
            if(color[cu]==-1)
            {
                ///Assign opposite color
                color[cu]=1-color[u];
                q.push(cu);
            }

            ///If two adjacent vertex is same color
            ///There is an edge between cu and u.u is current source node
            else if(color[cu]==color[u])
                return false;


        }

    }
    // All adjacent vertices can be colored with different color 
    return true;
}


int main()
{


    int v,e;
    cout<<"Enter number of vertices: ";
    cin>>v;

    cout<<"Enter number of edges: ";
    cin>>e;

    ///Take input connection of graphs
    for(int i=0; i<e; i++)
    {

        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);


    }

    ///color[-1] indicates that no color
    for(int i=0; i<v; i++)
    {
        color[i]=-1;
    }

    int sources;
    cin>>sources;


    if(bfs(sources)==1)
        cout<<"Bipartite graph"<<endl;
    else
        cout<<"non Bipartite"<<endl;


}
