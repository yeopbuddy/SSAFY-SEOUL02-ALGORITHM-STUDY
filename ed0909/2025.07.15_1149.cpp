#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>>color(n);
	vector<vector<vector<int>>>cost(n, vector<vector<int>>(3, vector<int>(2, -1)));
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		color[i].push_back(r);
		color[i].push_back(g);
		color[i].push_back(b);
	}
	cost[0][0][0] = color[0][0];
	cost[0][0][1] = 0;
	cost[0][1][0] = color[0][1];
	cost[0][1][1] = 1;
	cost[0][2][0] = color[0][2];
	cost[0][2][1] = 2;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k)continue;
				if (cost[i][k][0] != -1 && cost[i][k][0] > cost[i - 1][j][0] + color[i][k]) {
					cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
					cost[i][k][1] = k;
				}
				else if (cost[i][k][0] == -1) {
					cost[i][k][0] = cost[i - 1][j][0] + color[i][k];
					cost[i][k][1] = k;
				}
			}
		}
	}
	int min = cost[n - 1][0][0];
	for (int i = 1; i < 3; i++) {
		if (min > cost[n - 1][i][0])min = cost[n - 1][i][0];
	}
	cout << min;


	return 0;
}