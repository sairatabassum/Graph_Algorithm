#include <bits/stdc++.h>
using namespace std;

bool visited[100];

/// Diameter of tree & Node at maximum distance
int max_dis = -1, max_node = -1;

void DFS( vector< int > ve[], int source, int d)
{

    visited[source] = true;

    if( d > max_dis )
    {
        max_node = source;
        max_dis = d;
    }

    /// DFS
    for( int i = 0; i<ve[source].size(); i++)
    {
        int curr = ve[source][i];

        if( visited[curr] == false)
        {
            DFS( ve, curr, d+1);
        }
    }

}
int main()
{

    int n, e, source;
    cout << "Enter the number of vertex: ";
         cin >> n;

    cout << "Enter the number of edges: ";
         cin >> e;

    vector<int> ve[n+1];


    ///Take input connection of graphs
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    cout << "Enter Source:";
    cin >> source;

    /// Applying DFS from source node
    DFS( ve, source, 0);

    ///making every node unvisited for applying DFS twice
    max_dis = -1;

    for( int i = 1; i<=n ; i++)
    {

        visited[i] = false;
    }

    /// Applying DFS to the Maximum distance Node from the source
    DFS( ve, max_node, 0);

    cout<<"The diameter of tree is: "<< max_dis << endl;
}
