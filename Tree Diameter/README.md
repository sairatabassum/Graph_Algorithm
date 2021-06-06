
## Tree Diameter

![Capture](https://user-images.githubusercontent.com/52861859/120920424-85851f00-c6e0-11eb-8ad8-a87cc0e6cbac.PNG)

<hr>

**Computing diameter tree of n-ary tree using bfs.**
```

1.  Run BFS to find the farthest node from the rooted / source tree. Let say it's X.

2.  Again run BFS from X to find farthest node from X . Let it be Y

3.  Distance between node X and Y is the diameter of a tree
```
