#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int y, x, cnt;
};

int cnt = 21e7, n;
vector<int>m;
vector<vector<int>>map;

int find(int a) {
    if (a == m[a])return m[a];
    else return m[a] = find(m[a]);
}

void Union(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (roota != rootb)m[rootb] = roota;
}

void bfs(int y, int x, vector<vector<int>>&temp, int dy[], int dx[]) {
    queue<point> q;
    q.push({ y, x, 0 });
    int mom = find(y * n + x);

    while (!q.empty()) {
        point now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (map[ny][nx] > 0 && find(ny * n + nx) == mom) continue;
            if (map[ny][nx] == 1 && find(ny * n + nx) != mom) {
                cnt = now.cnt;
                return;
            }
            if (map[ny][nx] == 0) {
                if (temp[ny][nx] > 0)continue;
                temp[ny][nx] = now.cnt + 1;
                q.push({ ny, nx, now.cnt + 1 });
            }
        }
    }
}


int main() {

    cin >> n;
    map.resize(n, vector<int>(n));
    m.resize(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            m[i * n + j] = i * n + j;
        }
    }
    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0)continue;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || map[ny][nx] == 0)continue;
                Union(i * n + j, ny * n + nx);
            }
        }
    }

    int min = 21e7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0)continue;
            int flag = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || map[ny][nx] == 1)continue;
                flag = 1;
                break;
            }
            if (flag > 0) {
                vector<vector<int>>temp = map;
                cnt = 21e7;
                bfs(i, j, temp, dy, dx);
                if (cnt < min)min = cnt;
            }
        }
    }

    cout << min;

    return 0;
}