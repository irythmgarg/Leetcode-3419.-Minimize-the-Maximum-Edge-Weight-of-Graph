# Leetcode-3419.-Minimize-the-Maximum-Edge-Weight-of-Graph
# 🚀 Minimum Maximum Weight Problem (C++ Solution)

This repository contains an efficient C++ solution to find the **minimum maximum weight** needed to reach all nodes from the starting node (node `0`) in a directed graph.

---

## ✨ Problem Statement

Given a directed graph where each edge has a weight, determine the minimum value of maximum weight allowed such that all nodes are reachable from node 0 **using only edges with weight ≤ maximum weight**.

The solution uses **Binary Search** combined with **Depth-First Search (DFS)**.

---

## 💡 Approach

1. **Graph Construction**: 
   - Build a **reverse graph** to traverse backwards from each node.

2. **Binary Search**:
   - Search for the minimum possible maximum weight between the minimum and maximum edge weights.

3. **Validation**:
   - Use DFS to check whether all nodes are reachable under the current weight constraint.

---

## 📚 Algorithms Used

- **Depth-First Search (DFS)** for graph traversal.
- **Binary Search** for optimizing the search over possible maximum weights.

---

## 🔥 Code Highlights

- Neat and clean modular functions (`dfs()`, `isValid()`, `minMaxWeight()`).
- Graph represented using an **unordered map** of adjacency lists.
- **Efficient time complexity** due to binary search strategy.

---

📦 Example
Input:
n = 5
edges = { {0, 1, 5}, {1, 2, 3}, {2, 3, 4}, {3, 4, 2} }

Output:
5
All nodes become reachable from node 0 when maximum allowed weight is 5.

🙌 Contribution
Feel free to fork, raise issues, or suggest improvements!
Pull requests are warmly welcome. ❤️
