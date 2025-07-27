#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int64_t to, cost;

	bool operator<(node right)const {
		return cost > right.cost;
	}
};

void dijk(vector<vector<node>>map, vector<int64_t>& dist, vector<int>list, int store, int limit) {
	priority_queue<node>q;
	for (int i = 0; i < store; i++) {
		dist[list[i]] = 0;
		q.push({ list[i],0 });
	}

	while (!q.empty()) {
		node now = q.top(); q.pop();
		int here = now.to;
		int64_t cost = now.cost;

		if (dist[here] != -1 && dist[here] < cost)continue;

		for (int i = 0; i < map[here].size(); i++) {
			int nt = map[here][i].to;
			int64_t nc = cost + map[here][i].cost;
			if (nc > limit)continue;

			if (dist[nt] == -1) {
				dist[nt] = nc;
				q.push({ nt,nc });
			}
			else if (dist[nt] != -1 && dist[nt] > nc) {
				dist[nt] = nc;
				q.push({ nt,nc });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<node>>map(n + 1);
	vector<int64_t>distm(n + 1, -1);
	vector<int64_t>dists(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from].push_back({ to,cost });
		map[to].push_back({ from,cost });
	}
	int mac, star, x, y;
	cin >> mac >> x;
	vector<int>mac_list(mac);
	for (int i = 0; i < mac; i++)cin >> mac_list[i];
	cin >> star >> y;
	vector<int>star_list(star);
	for (int i = 0; i < star; i++)cin >> star_list[i];

	dijk(map, distm, mac_list, mac, x);
	dijk(map, dists, star_list, star, y);

	int64_t dist = -1;
	for (int i = 1; i <= n; i++) {
		if (distm[i] == 0 || dists[i] == 0 || distm[i] == -1 || dists[i] == -1)continue;
		if (dist != -1 && dist > distm[i] + dists[i]) dist = distm[i] + dists[i];
		else if (dist == -1)dist = distm[i] + dists[i];
	}

	cout << dist;

	return 0;
}