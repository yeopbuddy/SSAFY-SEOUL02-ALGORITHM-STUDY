#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

	for (int i = 1; i <= n; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (dist[from][to] > cost)
			dist[from][to] = cost;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == 1e9) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
