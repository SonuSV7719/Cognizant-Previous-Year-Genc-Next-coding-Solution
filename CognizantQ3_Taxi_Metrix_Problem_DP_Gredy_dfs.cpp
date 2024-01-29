/*
    Problem Statement-  A taxi can take multiple passengers to the railway station at the same time.On the way back to the starting point,the taxi driver may pick up additional passengers for his next trip to the airport.A map of passenger location has been created,represented as a square matrix.

    The Matrix is filled with cells,and each cell will have an initial value as follows:

    A value greater than or equal to zero represents a path.
    A value equal to 1 represents a passenger.
    A value equal to -1 represents an obstruction.
    The rules of motion of taxi are as follows:

    The Taxi driver starts at (0,0) and the railway station is at (n-1,n-1).Movement towards the railway station is right or down,through valid path cells.
    After reaching (n-1,n-1) the taxi driver travels back to (0,0) by travelling left or up through valid path cells.
    When passing through a path cell containing a passenger,the passenger is picked up.once the rider is picked up the cell becomes an empty path cell. 
    If there is no valid path between (0,0) and (n-1,n-1),then no passenger can be picked.
    The goal is to collect as many passengers as possible so that the driver can maximize his earnings.
    

    Sample Input 0

    4  

    4 

    0 0 0 1

    1 0 0 0

    0 0 0 0

    0 0 0 0

    Sample Output 0

    2

    Explanation 0

    The driver can contain a maximum of 2 passengers by taking the following path (0,0) → (0,1) → (0,2) → (0,3) → (1,3) → (2,3) → (3,3) → (3,2) → (3,1) → (3,0) → (2,0) → (1,0)  → (0,0)

    

    

    Sample Input 1

    3   

    3    

    0 1 -1 

    1 0 -1

    1 1 1

    Sample Output 1

    5

    Explanation 1

    The driver can contain a maximum of 5 passengers by taking the following path (0,0) → (0,1) → (1,1) → (2,1) → (2,2) → (2,1) → (2,0) → (1,0) → (0,0)


*/

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
