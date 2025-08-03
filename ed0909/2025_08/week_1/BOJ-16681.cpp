#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct node {
    int to;
    int64_t cost;

    bool operator < (node right)const {
        return cost > right.cost;
    }
};

void dijk(int start, vector<int64_t>& dist, vector<vector<node>>map, vector<int>h) {
    priority_queue<node>q;
    dist[start] = 0;
    q.push({ start,0 });

    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (dist[now.to] != -1 && dist[now.to] < now.cost)continue;

        for (int i = 0; i < map[now.to].size(); i++) {
            if (h[now.to] >= h[map[now.to][i].to])continue;
            int here = map[now.to][i].to;
            int64_t cost = now.cost + map[now.to][i].cost;
            if (dist[here] == -1) {
                dist[here] = cost;
                q.push({ here,cost });
            }
            else if (dist[here] > cost) {
                dist[here] = cost;
                q.push({ here,cost });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d, e;
    cin >> n >> m >> d >> e;
    vector<vector<node>>map(n + 1);
    vector<int>h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].push_back({ to,cost });
        map[to].push_back({ from,cost });
    }

    vector<int64_t>dist_home(n + 1, -1);
    vector<int64_t>dist_go(n + 1, -1);

    dijk(1, dist_home, map, h);
    dijk(n, dist_go, map, h);

    int64_t max_s = LLONG_MIN;
    int flag = 0;

    for (int i = 2; i < n; i++) {
        if (dist_home[i] == -1 || dist_go[i] == -1)continue;
        int64_t feel = (h[i] * e) - ((dist_home[i] + dist_go[i]) * d);
        if (max_s < feel) {
            max_s = feel;
            flag = 1;
        }
    }

    if (flag == 1)cout << max_s;
    else cout << "Impossible";

    return 0;
}