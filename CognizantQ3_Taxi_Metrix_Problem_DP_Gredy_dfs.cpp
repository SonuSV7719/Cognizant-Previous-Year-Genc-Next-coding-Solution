#include <bits/stdc++.h>
using namespace std;

unordered_map<string, pair<int, int>> path = {
    {"right", {0, 1}},
    {"down", {1, 0}},
    {"up", {-1, 0}},
    {"left", {0, -1}}
};

bool isValidPath(int curRow, int curCol, string p, vector<vector<int>>& mat, int n, int m) {
    if (curRow + path[p].first >= 0 && curRow + path[p].first < n &&
        curCol + path[p].second >= 0 && curCol + path[p].second < m &&
        mat[curRow + path[p].first][curCol + path[p].second] != -1) {
        return true;
    }
    return false;
}

int maxPassenger(vector<vector<int>>& mat, int n, int m) {
    int passengerCount = 0;

    // Round from start to end
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isValidPath(i, j, "right", mat, n, m) && mat[i][j] == 1) {
                passengerCount++;
                mat[i][j] = 0;
            } else if (isValidPath(i, j, "down", mat, n, m) && mat[i][j] == 1) {
                passengerCount++;
                mat[i][j] = 0;
            }
        }
    }

    // Round 2 end to start
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (isValidPath(i, j, "up", mat, n, m) && mat[i][j] == 1) {
                passengerCount++;
                mat[i][j] = 0;
            } else if (isValidPath(i, j, "left", mat, n, m) && mat[i][j] == 1) {
                passengerCount++;
                mat[i][j] = 0;
            }
        }
    }

    return passengerCount;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize the matrix with size n x m
    vector<vector<int>> mat(n, vector<int>(m, 0));

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maxPassenger(mat, n, m);
    return 0;
}
