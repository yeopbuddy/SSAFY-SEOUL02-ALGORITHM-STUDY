#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct way {
	int to, cost;

	bool operator <(way right)const {
		return cost > right.cost;
	}
};

void dijk(vector<vector<way>>& map, vector<int>& dis, int start) {
	priority_queue<way>q;
	dis[start] = 0;
	q.push({ start,dis[start] });

	while (!q.empty()) {
		way now = q.top(); q.pop();
		for (int i = 0; i < map[now.to].size(); i++) {
			if (dis[map[now.to][i].to] != -1 && dis[map[now.to][i].to] <= now.cost)continue;
			if (dis[map[now.to][i].to] == -1) {
				dis[map[now.to][i].to] = now.cost + map[now.to][i].cost;
				q.push({ map[now.to][i].to,dis[map[now.to][i].to] });
			}
			else if (dis[map[now.to][i].to] != -1 && dis[map[now.to][i].to] > now.cost + map[now.to][i].cost) {
				dis[map[now.to][i].to] = now.cost + map[now.to][i].cost;
				q.push({ map[now.to][i].to,dis[map[now.to][i].to] });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e, k;
	cin >> n >> e >> k;
	vector<int>dis(n + 1, -1);
	vector<vector<way>>map(n + 1);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u].push_back({ v,w });
	}

	dijk(map, dis, k);

	for (int i = 1; i <= n; i++) {
		if (dis[i] == -1)cout << "INF\n";
		else cout << dis[i] << "\n";
	}

	return 0;
}