#include<bits/stdc++.h>
using namespace std;

/// Check (x,y) lies inside board or not
bool isInside( int x, int y, int N )
{

    if( x >= 1 && x<=N && y>=1 && y<=N )
    {
        return true;
    }
    return false;
}



int BFS( int N, int src_x1, int src_y1, int des_x2, int des_y2 )
{

    /// All eight possible movements
    int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int dy[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

    queue< pair < pair<int,int> ,int> >q;
    bool visited[N+1][N+1] = {false};

    /// Push starting position with distance 0
    q.push( make_pair (make_pair(src_x1,src_y1) ,0) );

    /// Visit starting position
    visited[src_x1][src_y1] = true;

    while(!q.empty())
    {

        /// dequeue front
        pair< pair<int,int>,int > cur = q.front();
        q.pop();

        int x = cur.first.first;
        int y = cur.first.second;
        int dist = cur.second;

        /// Current cell equal to destination cell
        if(x == des_x2 && y == des_y2)
        {
            return dist;
        }

        /// check for all eight possible movements for a knight
        /// adjacent cell
        for(int i=0; i<8; i++)
        {

            /// coordinate of new cell
            int new_x1 = x + dx[i];
            int new_y1 = y + dy[i];

            /// Check the new cell is inside and not visited
            if( isInside( new_x1,new_y1,N )  && !visited[new_x1][new_y1] )
            {

                visited[new_x1][new_y1] = true;
                q.push( make_pair( make_pair(new_x1,new_y1) ,dist+1 ) );

            }

        }


    }
    /// if unable to reach destination
    return -1;

}


int main()
{
    int N, src_x1, src_y1, des_x2, des_y2;

    cout<<"Enter N: ";
    cin>>N;

    cout<<"Enter source coordinates: ";
    cin>>src_x1>>src_y1;

    cout<<"Enter destination coordinates: ";
    cin>>des_x2>>des_y2;

    cout<<"Minimum step to reach destination: "<<BFS(N,src_x1,src_y1,des_x2,des_y2);

}
