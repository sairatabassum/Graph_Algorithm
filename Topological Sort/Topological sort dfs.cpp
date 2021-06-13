#include <bits/stdc++.h>
using namespace std;

vector< int > graph[1000];
bool visited[1000];

vector< int > top;

void dfs(int source)
{


    visited[source] = 1;
    for(int i = 0; i<graph[source].size(); i++)
    {
        int curr = graph[source][i];
        if(visited[curr] == 0)
        {
            dfs(curr);
        }
    }
    /// Topological sort
    top.push_back(source);

}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);

    }

    for(int i = 1; i<=nodes; i++)
    {
        if(visited[i] == 0)
            dfs(i);
    }

    reverse(top.begin(), top.end());
    cout<<"Topological sort using dfs: ";

    for(int i = 0; i<top.size(); i++)
    {
        cout<<top[i]<<' ';
    }
}
