#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> bfsTraversal; // Result of BFS
    vector<bool> visited(V, false); // To track visited nodes
    queue<int> q;

    // Start BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfsTraversal.push_back(current);

        // Traverse neighbors in the same order as in the adjacency list
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsTraversal;
}

int main() {
    // Example: Graph with 5 vertices
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2, 3}, // Adjacency list for vertex 0
        {0, 4},    // Adjacency list for vertex 1
        {0, 4},    // Adjacency list for vertex 2
        {0},       // Adjacency list for vertex 3
        {1, 2}     // Adjacency list for vertex 4
    };

    vector<int> result = bfsOfGraph(V, adj);

    // Print the BFS traversal
    cout << "BFS Traversal: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

