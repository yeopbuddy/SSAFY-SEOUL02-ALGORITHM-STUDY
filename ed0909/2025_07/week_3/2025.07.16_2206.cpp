#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
	int y, x;
	int wall;
};

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void bfs(int n, int m, const vector<vector<int>>& map, vector<vector<vector<int>>>& dis) {
	queue<pos> q;
	q.push({ 0, 0, 1 });
	dis[0][0][1] = 1;

	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int wall = now.wall;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (map[ny][nx] == 1 && wall == 1 && dis[ny][nx][0] == -1) {
				dis[ny][nx][0] = dis[now.y][now.x][1] + 1;
				q.push({ ny, nx, 0 });
			}
			else if (map[ny][nx] == 0 && dis[ny][nx][wall] == -1) {
				dis[ny][nx][wall] = dis[now.y][now.x][wall] + 1;
				q.push({ ny, nx, wall });
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(2, -1)));

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			map[i][j] = row[j] - '0';
		}
	}

	bfs(n, m, map, dis);

	int result_with_wall = dis[n - 1][m - 1][1];
	int result_without_wall = dis[n - 1][m - 1][0];

	if (result_with_wall == -1 && result_without_wall == -1) {
		cout << -1;
	}
	else if (result_with_wall == -1) {
		cout << result_without_wall;
	}
	else if (result_without_wall == -1) {
		cout << result_with_wall;
	}
	else {
		cout << min(result_with_wall, result_without_wall);
	}

	return 0;
}