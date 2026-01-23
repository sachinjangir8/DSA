#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, orient, steps;
};

int M, N;
vector<vector<char>> grid;

bool isFree(int i, int j) {
    return (i >= 0 && i < M && j >= 0 && j < N && grid[i][j] != 'H');
}

int solveSofa() {
    pair<int,int> startPos, endPos;
    int startOrient = -1, endOrient = -1;

    // Find start and end positions
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 's') {
                if (j+1 < N && grid[i][j+1] == 's') {
                    startPos = {i, j}; startOrient = 0; // Horizontal
                }
                if (i+1 < M && grid[i+1][j] == 's') {
                    startPos = {i, j}; startOrient = 1; // Vertical
                }
            }
            if (grid[i][j] == 'S') {
                if (j+1 < N && grid[i][j+1] == 'S') {
                    endPos = {i, j}; endOrient = 0; // Horizontal
                }
                if (i+1 < M && grid[i+1][j] == 'S') {
                    endPos = {i, j}; endOrient = 1; // Vertical
                }
            }
        }
    }

    // Visited[x][y][orient]
    vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(2, false)));
    queue<State> q;

    q.push({startPos.first, startPos.second, startOrient, 0});
    visited[startPos.first][startPos.second][startOrient] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        int x = cur.x, y = cur.y, o = cur.orient, steps = cur.steps;

        // Check goal
        if (x == endPos.first && y == endPos.second && o == endOrient) {
            return steps;
        }

        if (o == 0) { // Horizontal
            // Left
            if (isFree(x, y-1) && isFree(x, y)) {
                if (!visited[x][y-1][0]) {
                    visited[x][y-1][0] = true;
                    q.push({x, y-1, 0, steps+1});
                }
            }
            // Right
            if (isFree(x, y+2) && isFree(x, y+1)) {
                if (!visited[x][y+1][0]) {
                    visited[x][y+1][0] = true;
                    q.push({x, y+1, 0, steps+1});
                }
            }
            // Up
            if (isFree(x-1, y) && isFree(x-1, y+1)) {
                if (!visited[x-1][y][0]) {
                    visited[x-1][y][0] = true;
                    q.push({x-1, y, 0, steps+1});
                }
            }
            // Down
            if (isFree(x+1, y) && isFree(x+1, y+1)) {
                if (!visited[x+1][y][0]) {
                    visited[x+1][y][0] = true;
                    q.push({x+1, y, 0, steps+1});
                }
            }
            // Rotation H → V
            if (isFree(x,y) && isFree(x,y+1) && isFree(x+1,y) && isFree(x+1,y+1)) {
                if (!visited[x][y][1]) {
                    visited[x][y][1] = true;
                    q.push({x, y, 1, steps+1});
                }
                if (!visited[x][y+1][1]) {
                    visited[x][y+1][1] = true;
                    q.push({x, y+1, 1, steps+1});
                }
            }
        } else { // Vertical
            // Up
            if (isFree(x-1, y) && isFree(x, y)) {
                if (!visited[x-1][y][1]) {
                    visited[x-1][y][1] = true;
                    q.push({x-1, y, 1, steps+1});
                }
            }
            // Down
            if (isFree(x+2, y) && isFree(x+1, y)) {
                if (!visited[x+1][y][1]) {
                    visited[x+1][y][1] = true;
                    q.push({x+1, y, 1, steps+1});
                }
            }
            // Left
            if (isFree(x, y-1) && isFree(x+1, y-1)) {
                if (!visited[x][y-1][1]) {
                    visited[x][y-1][1] = true;
                    q.push({x, y-1, 1, steps+1});
                }
            }
            // Right
            if (isFree(x, y+1) && isFree(x+1, y+1)) {
                if (!visited[x][y+1][1]) {
                    visited[x][y+1][1] = true;
                    q.push({x, y+1, 1, steps+1});
                }
            }
            // Rotation V → H
            if (isFree(x,y) && isFree(x+1,y) && isFree(x,y+1) && isFree(x+1,y+1)) {
                if (!visited[x][y][0]) {
                    visited[x][y][0] = true;
                    q.push({x, y, 0, steps+1});
                }
                if (!visited[x+1][y][0]) {
                    visited[x+1][y][0] = true;
                    q.push({x+1, y, 0, steps+1});
                }
            }
        }
    }
    return -1; // Impossible
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    grid.assign(M, vector<char>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = solveSofa();
    if (ans == -1) cout << "Impossible\n";
    else cout << ans << "\n";

    return 0;
}
