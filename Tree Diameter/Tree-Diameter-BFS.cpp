#include<bits/stdc++.h>
using namespace std;

int diameter[10005];

int bfs(int src, vector<int> ve[], int n)
{

    int visited[n+1], dia_value = 0, indx_value = src;
    queue<int>q;

    for( int i=0; i<=n; i++)
    {
        visited[i] = 0;
        diameter[i] = 0;
    }

    q.push(src);
    visited[src] = 1;

    while(!q.empty())
    {

        int cur_node = q.front();
        q.pop();

        for( int i=0; i<ve[cur_node].size(); i++)
        {

            int adjcnt_node = ve[cur_node][i];

            if( visited[adjcnt_node] == 0)
            {

                visited[adjcnt_node] = 1;
                diameter[adjcnt_node] += diameter[cur_node]+1;
                q.push(adjcnt_node);

                /// Maximum diameter value
                if( diameter[adjcnt_node] > dia_value)
                {

                    dia_value = diameter[adjcnt_node];
                    indx_value = adjcnt_node;
                }


            }
        }


    }

    return indx_value;



}

int findDiameter(vector<int> ve[], int n, int src)
{

    int first_node = bfs(src, ve, n);
    int second_node = bfs(first_node, ve, n);
    int dia = diameter[second_node];

    return dia;

}


int main()
{
    int n,e,u,v,src;
    cout<<"Enter number of nodes: ";
    ///n<10004
    cin>>n;

    vector<int> ve[n+1];

    cout<<"Enter number of edges: ";
    cin>>e;

    ///Take input connection of graphs
    for( int i=0; i<e; i++)
    {
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    cout<<"Enter source: ";
    cin>>src;

    cout<<"Diameter of n-ary tree is "<<findDiameter(ve,n,src);
}
