#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int shortestPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return -1;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pii> q;

    q.push({0, 0});
    dist[0][0] = 1;  

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist[n-1][m-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0}
    };

    cout << shortestPath(grid) << endl;

    return 0;
}
