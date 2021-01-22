#include <bits/stdc++.h>
using namespace std;

///Create a vector to store connection of nodes
vector<int>ve[101];
///Create a color array to store colors of node
int color[101];
///Create visit array to store which node visited
bool vis[101];



///Using dfs if graph is bipartite or not
///It returns true , if not then returns false
bool dfs(int sources)
{

    for(int i=0; i<ve[sources].size(); i++)
    {

        int cu=ve[sources][i];
        ///If current vertex is not visited
        if(vis[cu]==false)
        {
            ///Marked the vertex as visited
            vis[cu]=true;

            ///Assign opposite color
            color[cu]=1-color[sources];

            ///If any point the function returns false
            if(!dfs(cu))
                return false;
        }
        ///If current vertex visited & two adjacent vertex's color is same
        else if(color[cu]==color[sources])
            return false;

    }
    ///All adjacent vertices can be colored with different color
    return true;
}

int main()
{
    int v,e;
    cout<<"Enter a number of vertex: ";
    cin>>v;

    cout<<"Enter a number of edges: ";
    cin>>e;

    ///Take input connection of graphs
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    ///color[-1] indicates that no color
    for(int i=0; i<=e; i++)
    {
        color[i]=-1;
    }

    int sources;
    cin>>sources;


    color[sources]=1;

    if(dfs(sources)==true)
        cout<<"bipartite graph"<<endl;
    else
        cout<<"non bipartite graph"<<endl;



}
