#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Islands {
public:
    int r, c;
    int rows[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cols[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool valid(int x, int y) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    int countIslands(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    count++;
                    // start BFS from this land
                    q.push({i, j});
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        // check all 8 directions
                        for (int k = 0; k < 8; k++) {
                            int nx = x + rows[k];
                            int ny = y + cols[k];

                            if (valid(nx, ny) && grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,1},
        {0,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}
    };

    Islands isl;
    cout << "Number of islands = " << isl.countIslands(grid) << endl;

    return 0;
}
