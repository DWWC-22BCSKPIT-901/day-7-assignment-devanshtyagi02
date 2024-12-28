#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustCounts(n + 1, 0);

    for (const auto& t : trust) {
        int a = t[0], b = t[1];
        trustCounts[a]--; // a trusts someone, so decrease their trust score
        trustCounts[b]++; // b is trusted, so increase their trust score
    }

    for (int i = 1; i <= n; ++i) {
        if (trustCounts[i] == n - 1) {
            return i; // The judge is trusted by everyone except themselves
        }
    }

    return -1; // No judge found
}

int main() {
    // Example 1
    vector<vector<int>> trust1 = {{1, 2}};
    cout << "The town judge is: " << findJudge(2, trust1) << endl;

    // Example 2
    vector<vector<int>> trust2 = {{1, 3}, {2, 3}};
    cout << "The town judge is: " << findJudge(3, trust2) << endl;

    // Example 3
    vector<vector<int>> trust3 = {{1, 3}, {2, 3}, {3, 1}};
    cout << "The town judge is: " << findJudge(3, trust3) << endl;

    return 0;
}
