#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct node {
	int64_t to, cost;

	bool operator<(node right) const {
		return cost > right.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, m, k;
	cin >> n >> m >> k;
	vector<vector<node>>map(n + 1);
	vector<int64_t> dist(n + 1, LLONG_MAX);

	for (int64_t i = 0; i < m; i++) {
		int64_t from, to, cost;
		cin >> from >> to >> cost;
		map[to].push_back({ from, cost });
	}

	priority_queue<node> pq;

	for (int64_t i = 0; i < k; i++) {
		int64_t center;
		cin >> center;
		dist[center] = 0;
		pq.push({ center, 0 });
	}

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		int64_t here = now.to;
		int64_t cost = now.cost;

		if (cost > dist[here]) continue;

		for (int64_t i = 0; i < map[here].size();i++) {
			int64_t nt = map[here][i].to;
			int64_t nc = cost + map[here][i].cost;

			if (dist[nt] > nc) {
				dist[nt] = nc;
				pq.push({ nt, nc });
			}
		}
	}
	int64_t cost = 0, idx = 0;
	for (int64_t i = 1; i <= n; i++) {
		if (cost < dist[i]) {
			cost = dist[i];
			idx = i;
		}
	}
	cout << idx << "\n" << cost;

	return 0;
}