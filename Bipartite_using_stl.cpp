#include <bits/stdc++.h>
using namespace std;

///Create a vector to store connection of nodes
///Create a color array to store colors
vector<int>ve[10];
int color[10]; ///0=blue;1=red

///using bfs if graph is bipartite then
///it return true , if not then return false

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

        for (int i=0; i<ve[u].size(); i++)
        {
            int cu;
            cu=ve[u][i];


        /// Return false if there is a self-loop
            if(cu==u)
                return false;

       ///Assign color to adjacent cu of u
            if(color[cu]==-1)
            {

                color[cu]=1-color[u];
                q.push(cu);
            }
      ///if two adjacent vertex is same color
      ///there is an edge between cu and u. u is source node
            else if(color[cu]==color[u])
                    return false;


        }

    }
}


int main()
{


    int v,e;
    cout<<"Enter number of vertices: ";
    cin>>v;

    cout<<"Enter number of edges: ";
    cin>>e;
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
