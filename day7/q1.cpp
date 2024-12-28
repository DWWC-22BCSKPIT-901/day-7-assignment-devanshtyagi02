#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    // The center of the star graph will appear in the first two edges.
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    }
    return edges[0][1];
}

int main() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << "The center of the star graph is: " << findCenter(edges) << endl;
    return 0;
}
