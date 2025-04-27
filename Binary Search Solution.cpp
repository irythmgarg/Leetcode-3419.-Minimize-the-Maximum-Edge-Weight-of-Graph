// Author: [Ridham Garg]
// Description: C++ Solution to find the minimum maximum weight 
//              to reach all nodes from node 0, using Binary Search and DFS.

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Depth First Search to traverse the graph
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& graph, vector<bool>& visited, int& maxWeight) {
        visited[node] = true;
        
        for (auto neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int cost = neighbor.second;
            
            // Traverse if the edge cost is within the allowed maximum weight
            if (!visited[nextNode] && cost <= maxWeight) {
                dfs(nextNode, graph, visited, maxWeight);
            }
        }
    }

    // Check if the graph is fully connected under a maximum weight constraint
    bool isValid(int n, unordered_map<int, vector<pair<int, int>>>& graph, int& maxWeight) {
        vector<bool> visited(n, false);

        // Start DFS from node 0
        dfs(0, graph, visited, maxWeight);

        // If any node is not visited, return false
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
    
    // Main function to find the minimum possible maximum weight
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<pair<int, int>>> graph;

        // Build graph (reverse edges)
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[to].push_back({from, weight});
        }

        int low = 0;
        int high = 0;

        // Find the highest weight among all edges
        for (auto& edge : edges) {
            high = max(high, edge[2]);
        }

        int answer = -1;

        // Binary Search to find the minimum maximum weight
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(n, graph, mid)) {
                answer = mid;
                high = mid - 1; // Try to find a smaller maximum weight
            } else {
                low = mid + 1; // Increase the maximum weight
            }
        }

        return answer;
    }
};
