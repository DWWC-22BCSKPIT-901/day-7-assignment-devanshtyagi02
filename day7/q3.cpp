#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
    // Base cases to stop recursion
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor || image[sr][sc] == newColor) {
        return;
    }

    // Update the color of the current pixel
    image[sr][sc] = newColor;

    // Explore the four adjacent pixels
    dfs(image, sr + 1, sc, newColor, originalColor); // Down
    dfs(image, sr - 1, sc, newColor, originalColor); // Up
    dfs(image, sr, sc + 1, newColor, originalColor); // Right
    dfs(image, sr, sc - 1, newColor, originalColor); // Left
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int originalColor = image[sr][sc];
    if (originalColor != color) { // Avoid infinite recursion if the target color is the same as the original color
        dfs(image, sr, sc, color, originalColor);
    }
    return image;
}

int main() {
    // Example 1
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr1 = 1, sc1 = 1, color1 = 2;
    vector<vector<int>> result1 = floodFill(image1, sr1, sc1, color1);
    cout << "Flood-filled image:\n";
    for (const auto& row : result1) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    // Example 2
    vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}};
    int sr2 = 0, sc2 = 0, color2 = 0;
    vector<vector<int>> result2 = floodFill(image2, sr2, sc2, color2);
    cout << "\nFlood-filled image:\n";
    for (const auto& row : result2) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
