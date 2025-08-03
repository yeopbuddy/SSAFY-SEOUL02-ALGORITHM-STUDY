#include <iostream>
#include <string>

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m;
int used[26];
int map[20][20];

void find(int y, int x, int dist, int& max_dist) {
	if (dist > max_dist) max_dist = dist;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || used[map[ny][nx]] == 1)continue;
		used[map[ny][nx]] = 1;
		find(ny, nx, dist + 1,max_dist);
		used[map[ny][nx]] = 0;
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j] - 'A';
		}
	}
	int max_dist = 1;
	used[map[0][0]] = 1;
	find(0, 0, 1, max_dist);

	cout << max_dist;

	return 0;
}