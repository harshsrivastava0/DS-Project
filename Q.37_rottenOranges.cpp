#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<Point> rotten;
    int freshCount = 0;
    int minutes = 0;

    // Enqueue all rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                rotten.push(Point(i, j));
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges, return 0 (already rotten)
    if (freshCount == 0) {
        return 0;
    }

    const vector<int> dx = {-1, 0, 1, 0};
    const vector<int> dy = {0, -1, 0, 1};

    while (!rotten.empty()) {
        int n = rotten.size();

        for (int i = 0; i < n; i++) {
            Point p = rotten.front();
            rotten.pop();

            for (int k = 0; k < 4; k++) {
                int nx = p.x + dx[k];
                int ny = p.y + dy[k];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rotten.push(Point(nx, ny));
                    freshCount--;

                    if (freshCount == 0) {
                        return minutes + 1;
                    }
                }
            }
        }

        minutes++;
    }

    return -1; // Some fresh oranges cannot be rotten
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int minutes = orangesRotting(grid);
    if (minutes == -1) {
        cout << "Some fresh oranges cannot be rotten." << endl;
    } else {
        cout << "Minutes needed for all oranges to become rotten: " << minutes << endl;
    }

    return 0;
}
