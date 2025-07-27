#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MX = 100001;
const int MXP = 20;

int N;
vector<int> adj[MX];
int parent[MX][MXP];
int depth[MX];
ll result;
vector<int> bfs;

void init(){
	for(int i=1; i<MX; i++){
		adj[i].clear();
		depth[i] = 0;
		for(int j=0; j<MXP; j++){
			parent[i][j] = 0;
		}
	}
	bfs.clear();
	result = 0;
}

void input(){
	cin >> N;
	int n;
	for(int i=2; i<=N; i++){
		cin >> n;
		adj[n].push_back(i);
		parent[i][0] = n;
	}
}

void get_bfs(){
	queue<int> q;
	q.push(1);

	while(!q.empty()){
		int now = q.front(); q.pop();

		bfs.push_back(now);

		for(const int &nxt : adj[now]){
			q.push(nxt);
			depth[nxt] = depth[now] + 1;
		}
	}
}

void set_parent(){
	for(int x=1; x<=N; x++){
		for(int i=1; i<MXP; i++){
			parent[x][i] = parent[parent[x][i-1]][i-1];
		}
	}
}

int get_lca(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	for(int i=MXP-1; i>=0; i--){
		if(depth[a] - (1<<i) >= depth[b]){
			a = parent[a][i];
		}
	}
	if(a == b) return a;

	for(int i=MXP-1; i>=0; i--){
		if(parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
		
	}
	return parent[a][0];
}

void solution(){
	get_bfs();
	set_parent();

	for(int i=1; i<N; i++){
		int a = bfs[i-1];
		int b = bfs[i];
		int cp = get_lca(a, b);
		if(cp == -1) {
			cout << "error\n";
			return;
		}

		result += depth[a] + depth[b] - 2*depth[cp];
	}
}

int main(void){
	int T; cin >> T;
	for(int t=1; t<=T; t++){
		init();
		input();
		solution();

		cout << '#' << t << ' ' << result << '\n';
	}

	return 0;
}