#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int to;
	int cost;

	bool operator< (node right) const {
		return cost > right.cost;
	}
};

void dijk(int start, vector<int>&dist, vector<vector<node>>map) {
	priority_queue<node>q;
	dist[start] = 0;
	q.push({ start,0 });

	while (!q.empty()) {
		node now = q.top(); q.pop();
		for (int i = 0; i < map[now.to].size(); i++) {
			int next = map[now.to][i].to;
			if (dist[next] == -1) {
				dist[next] = now.cost + map[now.to][i].cost;
				q.push({ next,dist[next] });
			}
			else if (dist[next] != -1 && dist[next] > now.cost + map[now.to][i].cost) {
				dist[next] = now.cost + map[now.to][i].cost;
				q.push({ next,dist[next] });
			}
		}
	}
}

int main() {

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<node>>map(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from].push_back({ to,cost });
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		vector<int>dist1(n + 1, -1);
		vector<int>dist2(n + 1, -1);
		dijk(i, dist1, map);
		dijk(x, dist2, map);
		int time = dist1[x] + dist2[i];
		if (time > max)max = time;
	}
	cout << max;

	return 0;
}