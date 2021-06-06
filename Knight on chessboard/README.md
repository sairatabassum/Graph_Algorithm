
## Minimum steps to reach destination by a Knight 

![daba](https://user-images.githubusercontent.com/52861859/120898057-1dd0c480-c64b-11eb-950e-cc59a6e856a6.PNG)

<hr>

 **Given a square chessboard N x N dimensions, Co-ordinates of the knight position and target position.**
**Shortest path in unweighted graph. That's why, we use Bfs.**
```
1.  Find all possible position where a knight can reach from its position.

2.  The knight can not go outside the chessboard, Check the possible position is inside the board or not

3.  Create a cell constructor that will store cells (x, y, distance) in a pair from knight's starting position / STL (pair + queue)

4.  Same as BFS , Create queue and visited array , push the knight's starting cell value in queue and visited the starting cell

5.  Until the queue is empty or the knight reaches the target location , the loop will continue

6.  Pop from the queue, store the value before pop then check the (x, y) co-ordinates is equal to target position

7.  Visit all the possible locations from current cell , increase the distance if its not visited and inside the board


```




