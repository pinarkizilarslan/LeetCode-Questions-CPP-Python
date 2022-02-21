# LeetCode Questions CPP and Python3
<br>

## Question 224: Basic Calculator
Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
**Note:** You are ***not*** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

Examples:
- `
Input: s = "1 + 1"
Output: 2
`<br>
- `
Input: s = " 2-1 + 2 "
Output: 3
`<br>
- `
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
`
<br>




## Question 432: All O'one Data Structure
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:
* `AllOne()` Initializes the object of the data structure.
* `inc(String key)` Increments the count of the string `key` by `1`. If `key` does not exist in the data structure, insert it with count `1`.
* `dec(String key)` Decrements the count of the string `key` by `1`. If the count of `key` is `0` after the decrement, remove it from the data structure. It is guaranteed that `key` exists in the data structure before the decrement.
* `getMaxKey()` Returns one of the keys with the maximal count. If no element exists, return an empty string `""`.
* `getMinKey()` Returns one of the keys with the minimum count. If no element exists, return an empty string `""`.
<br>




## Question 684: Redundant Connection
In this problem, a tree is an ***undirected graph*** that is connected and has no cycles. <br>
You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two ***different*** vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array `edges` of length n where `edges[i] = [ai, bi]` indicates that there is an edge between nodes ***ai*** and ***bi*** in the graph. <br>
Return ***an edge that can be removed so that the resulting graph*** is a tree of `n` nodes. If there are multiple answers, return the answer that occurs last in the input.
<br><br><br>




## Question 724: Find Pivot Index
Given an array of integers `nums`, calculate the ***pivot index*** of this array. <br>
The ***pivot*** index is the index where the sum of all the numbers ***strictly*** to the left of the index is equal to the sum of all the numbers ***strictly*** to the index's right. <br>
If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array. <br>
Return the ***leftmost pivot index***. If no such index exists, return -1.
<br><br><br>




## Question 788: Rotated Digits
An integer `x` is a ***good*** if after rotating each digit individually by 180 degrees, we get a valid number that is different from `x`. Each digit must be rotated - we cannot choose to leave it alone. <br>
A number is valid if each digit remains a digit after rotation. For example: <br>
* `0`, `1` and `8` rotate to themselves,
* `2` and `5` rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
* `6` and `9` rotate to each other, and
* the rest of the numbers do not rotate to any other number and become invalid.

Given an integer `n`, return the number of ***good*** integers in the range `[1, n]`.
<br><br><br>




## Question 797: All Paths From Source to Target
Given a directed acyclic graph (***DAG***) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node 0 to node n - 1 and return them in ***any order***.
<br>
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node `graph[i][j]`).
<br><br><br>




## Question 1029: Two City Scheduling
A company is planning to interview `2n` people. Given the array costs where `costs[i] = [aCosti, bCosti]`, the cost of flying the `ith` person to city ***a*** is aCosti, and the cost of flying the ith person to city ***b*** is bCosti. <br>
Return ***the minimum cost to fly every person to a city*** such that exactly `n` people arrive in each city.
<br><br><br>




## Question 1046: Last Stone Weight
You are given an array of integers `stones` where `stones[i]` is the weight of the i<sup>th</sup> stone. <br>
We are playing a game with the stones. On each turn, we choose the ***heaviest two stones*** and smash them together. Suppose the heaviest two stones have weights `x` and `y` with `x <= y`. The result of this smash is:
* If `x == y`, both stones are destroyed, and
* If `x != y`, the stone of weight ***x*** is destroyed, and the stone of weight ***y*** has new weight `y - x`.<br>

At the end of the game, there is ***at most one*** stone left.<br>
Return the smallest ***possible weight of the left stone***. If there are no stones left, return `0`.
<br><br><br>




## Question 1162: As Far from Land as Possible
Given an `n x n grid` containing only values `0` and `1`, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return `-1`. <br><br>
The distance used in this problem is the Manhattan distance: <br>
The distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.
<br><br><br>




## Question 1311: Get Watched Videos by Your Friends
There are `n` people, each person has a unique id between `0` and `n-1`. Given the arrays ***watchedVideos*** and ***friends***, where `watchedVideos[i]` and `friends[i]` contain the list of watched videos and the list of friends respectively for the person with `id = i`. <br><br>
Level `1` of videos are all watched videos by your friends, level `2` of videos are all watched videos by the friends of your friends and so on. In general, the level `k` of videos are all watched videos by people with the shortest path ***exactly*** equal to ***k*** with you. Given your `id` and the `level` of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 
<br><br><br>




## Question 1489: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
Given a weighted undirected connected graph with ***n*** vertices numbered from `0` to `n - 1`, and an array ***edges*** where `edges[i] = [ai, bi, weighti]` represents a bidirectional and weighted edge between nodes `ai` and `bi`. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight. <br><br>
Find ***all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST)***. An MST edge whose deletion from the graph would cause the MST weight to increase is called a ***critical edge***. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all. <br><br>
Note that you can return the indices of the edges in any order.
<br><br><br><br>




## Question 1496: Path Crossing
Given a string path, where `path[i] =` `N`, `S`, `E` or `W`, each representing moving one unit north, south, east, or west, respectively. You start at the origin `(0, 0)` on a 2D plane and walk on the path specified by path.
<br><br>
Return ***true*** if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. <br>
Return ***false*** otherwise.
<br><br><br>




## Question 1609: Even Odd Tree
A binary tree is named Even-Odd if it meets the following conditions: <br>
* The root of the binary tree is at level index 0, its children are at level index `1`, their children are at level index `2`, etc. <br>
* For every ***even-indexed level***, all nodes at the level have `odd` integer values in ***strictly increasing*** order (from left to right). <br>
* For every ***odd-indexed level***, all nodes at the level have `even` integer values in ***strictly decreasing*** order (from left to right). <br>

Given the `root` of a binary tree, return ***true*** if the binary tree is Even-Odd, otherwise return ***false***.
<br>
