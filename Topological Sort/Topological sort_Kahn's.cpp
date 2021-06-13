#include <bits/stdc++.h>
using namespace std;

void kahns(int n, vector<int> ve[], int in_degree[])
{

    vector<int> top;
    queue<int>q;

    for(int i=1; i<=n; i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {

        int cur = q.front();
        top.push_back(cur);
        q.pop();

        for(int i=0; i<ve[cur].size(); i++)
        {

            int adj = ve[cur][i];
            in_degree[adj]--;

            if(in_degree[adj] == 0)
            {
                q.push(adj);
            }

        }



    }

    cout<<"Topological Sort: ";
    for(int i=0 ; i<n; i++)
    {
        cout<<top[i]<<' ';
    }

}


int main()
{
    int n, e, x, y;

    cout<<"Enter number of node and edge: ";
    cin>>n>>e;

    vector<int> ve[n+1];
    int in_degree[n+1] = {0};

    for(int i=0; i<e ; i++)
    {
        cin>>x>>y;
        ve[x].push_back(y);
        /// x->y
        in_degree[y]++;
    }

    ///Kahn’s algorithm for Topological Sorting
    kahns(n,ve,in_degree);




}

