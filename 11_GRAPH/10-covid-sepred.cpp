#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int row, col, day;
};

class CovidSpread {
public:
    int minDaysToInfect(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<Cell> q;
        int healthy = 0; // count of healthy patients

        // Step 1: push all initially infected patients into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0}); // already infected
                }
                if (grid[i][j] == 1) healthy++;
            }
        }

        // Directions for neighbors (up, down, left, right)
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int days = 0;
        int infectedCount = 0;

        // Step 2: BFS Spread
        while (!q.empty()) {
            Cell curr = q.front();
            q.pop();
            days = max(days, curr.day);

            for (int k = 0; k < 4; k++) {
                int nr = curr.row + dr[k];
                int nc = curr.col + dc[k];

                // check boundaries & if healthy
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // infected now
                    infectedCount++;
                    q.push({nr, nc, curr.day + 1});
                }
            }
        }

        // Step 3: If all healthy patients got infected
        if (infectedCount == healthy)
            return days;
        else
            return -1; // some patients never got infected
    }
};

int main() {
    vector<vector<int>> hospital = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    CovidSpread cs;
    int result = cs.minDaysToInfect(hospital);

    if (result == -1)
        cout << "Not all patients can be infected\n";
    else
        cout << "All patients infected in " << result << " days\n";

    return 0;
}
