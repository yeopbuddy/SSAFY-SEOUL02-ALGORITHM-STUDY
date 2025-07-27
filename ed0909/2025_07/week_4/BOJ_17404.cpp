#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>>color;

int dp(int start) {
	vector<vector<vector<int>>>cost(n, vector<vector<int>>(3, vector<int>(2, -1)));
	for (int i = 0; i < 3; i++) {
		if (i == start) {
			cost[0][i][0] = color[0][i]; // 첫번째 집 색칠하는데 든 비용
			cost[0][0][1] = start; // 어디서 왔는지 기록
		}
		else cost[0][i][0] = 1e9;
	}
	

	for (int i = 1; i < n; i++) {
		if (i == n - 1) {
			for (int t = 0; t < 3; t++) {
				cost[i][t][0] = 21e7;
			}
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k == j || k == start)continue;
					if (cost[i][k][0] == -1) { // 아직 칠하지 않았다면 비용 계산
						cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
					}
					else if (cost[i][k][0] != -1 && cost[i][k][0] > cost[i - 1][j][0] + color[i][k]) {
						cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
					}
				}
			}


		}

		else {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k == j)continue;
					if (cost[i][k][0] == -1) { // 아직 칠하지 않았다면 비용 계산
						cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
						cost[i][k][1] = k; // 현재 무슨 색으로 칠했는지 저장
					}
					else if (cost[i][k][0] != -1 && cost[i][k][0] > cost[i - 1][j][0] + color[i][k]) {
						cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
						cost[i][k][1] = k; // 현재 무슨 색으로 칠했는지 저장
					}
				}
			}
		}
	}
	return min(cost[n - 1][0][0], min(cost[n - 1][1][0], cost[n - 1][2][0]));
}

int main() {

	cin >> n;
	color.resize(n);

	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		color[i].push_back(r);
		color[i].push_back(g);
		color[i].push_back(b);
	}

	int result = min(dp(0), min(dp(1), dp(2)));
	cout << result;

	return 0;
}