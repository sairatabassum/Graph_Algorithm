## Kahn’s algorithm for Topological Sorting
If Graph has at least one cycle , Topological sorting is not possible
```

1.  Compute in-degree (number of incoming edges)

2.  Pick all the vertices with in-degree as 0 and add them into a queue

3.  Like BFS ,Until the queue is empty , The loop will continue

4.  Store current node  then pop the value

> queue.front()

5.  After that traverse each of the adjacency list of current node

6.  Decrease in-degree by 1 for all its neighboring nodes.

7.  If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.



```
## Recommendation

- ### [Topological_sorting](https://en.wikipedia.org/wiki/Topological_sorting)


- ### [Kahn's Algorithm for Topological Sort](https://www.youtube.com/watch?v=7CTpoVNIc8o&t=318s)

