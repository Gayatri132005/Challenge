#include <bits/stdc++.h>
using namespace std;

// Function to find all paths from top-left to bottom-right
void solve(int n, int m, int r, int c, string path, vector<string> &ans, vector<vector<int>> &grid) {
    // Check boundaries or if the cell is blocked
    if (r >= n || c >= m || grid[r][c] == 0)
        return;

    // If reached the destination
    if (r == n - 1 && c == m - 1) {
        ans.push_back(path);
        return;
    }

    // Move right
    solve(n, m, r, c + 1, path + "R", ans, grid);

    // Move down
    solve(n, m, r + 1, c, path + "D", ans, grid);
}

// Function to initiate path-finding
vector<string> findPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<string> ans;
    if (grid[0][0] == 1) {
        solve(n, m, 0, 0, "", ans, grid);
    }
    return ans;
}

// Main function
int main() {
    vector<vector<int>> grid = {
        {1, 0, 0,0},
        {1, 1, 0,0},
        {1, 1, 0,0},
        {0, 1, 1,1}
    };

    vector<string> paths = findPath(grid);

    cout << "All possible paths from top-left to bottom-right are:\n";
    for (string path : paths) {
        cout << path << endl;
    }

    return 0;
}
