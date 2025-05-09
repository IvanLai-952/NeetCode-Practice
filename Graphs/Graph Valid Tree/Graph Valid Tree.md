# [261. Graph Valid Tree - Medium](https://leetcode.com/problems/graph-valid-tree/description/)

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.


Example 1:

![image](https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg)

> Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]  
> Output: true  

Example 2:

![image](https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg)

> Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]  
> Output: false