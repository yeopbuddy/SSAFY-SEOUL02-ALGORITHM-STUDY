#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

using namespace std;
struct node {
	int y, x;
	int time;
};
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int n, m, T, D;

void bfs_go(int y, int x, vector<vector<int>>& dist_go, vector<vector<int>>map) {
	queue<node>q;
	q.push({ y,x,0 });
	dist_go[y][x] = 0;
	
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || abs(map[ny][nx] - map[now.y][now.x]) > T)continue;

			if (map[now.y][now.x] < map[ny][nx]) {
				int nt = now.time + ((map[now.y][now.x] - map[ny][nx]) * (map[now.y][now.x] - map[ny][nx]));
				if (dist_go[ny][nx] == -1) {
					dist_go[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
				else if (dist_go[ny][nx] != -1 && dist_go[ny][nx] > nt) {
					dist_go[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
			}
			else {
				int nt = now.time + 1;
				if (dist_go[ny][nx] == -1) { 
					dist_go[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
				else if (dist_go[ny][nx] != -1 && dist_go[ny][nx] > nt) {
					dist_go[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
			}
		}
	}
}

void bfs_back(int y, int x, vector<vector<int>>& dist_back, vector<vector<int>>map) {
	queue<node>q;
	q.push({ y,x,0 });
	dist_back[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || abs(map[ny][nx] - map[now.y][now.x]) > T)continue;

			if (map[now.y][now.x] <= map[ny][nx]) {
				int nt = now.time + 1;
				if (dist_back[ny][nx] == -1) {
					dist_back[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
				else if (dist_back[ny][nx] != -1 && dist_back[ny][nx] > nt) {
					dist_back[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
			}
			else {
				int nt = now.time + ((map[now.y][now.x] - map[ny][nx]) * (map[now.y][now.x] - map[ny][nx]));
				if (dist_back[ny][nx] == -1) {
					dist_back[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
				else if (dist_back[ny][nx] != -1 && dist_back[ny][nx] > nt) {
					dist_back[ny][nx] = nt;
					q.push({ ny,nx,nt });
				}
			}
		}
	}
}

int main() {

	cin >> n >> m >> T >> D;
	vector<vector<int>>map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			if (temp[j] >= 'A' && temp[j] <= 'Z') {
				map[i][j] = temp[j] - 'A';
			}
			else map[i][j] = temp[j] - 'a' + 26;
		}
	}
	vector<vector<int>>dist_go(n, vector<int>(m, -1));
	vector<vector<int>>dist_back(n, vector<int>(m, -1));

	bfs_go(0, 0, dist_go, map);
	bfs_back(0, 0, dist_back, map);
	int max_h = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist_go[i][j] + dist_back[i][j] > D || dist_go[i][j] == -1 || dist_back[i][j] == -1)continue;
			if (max_h < map[i][j])max_h = map[i][j];
		}
	}
	cout << max_h;

	return 0;
}