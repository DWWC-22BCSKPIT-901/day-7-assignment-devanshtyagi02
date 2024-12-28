#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Build the adjacency list
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // Use BFS to determine if a path exists
    queue<int> q;
    unordered_set<int> visited;

    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // If we reach the destination, return true
        if (current == destination) {
            return true;
        }

        // Explore neighbors
        for (const int& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    // If we exhaust all possibilities and don't find the destination, return false
    return false;
}

int main() {
    // Example 1
    int n1 = 6;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source1 = 0, destination1 = 5;
    cout << "Path exists: " << (validPath(n1, edges1, source1, destination1) ? "True" : "False") << endl;

    // Example 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}};
    int source2 = 0, destination2 = 2;
    cout << "Path exists: " << (validPath(n2, edges2, source2, destination2) ? "True" : "False") << endl;

    return 0;
}
