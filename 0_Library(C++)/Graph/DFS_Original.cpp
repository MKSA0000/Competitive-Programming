#include"../INCLUDES.h"

#define MaxNode 100
#define White 0
#define Gray 1
#define Black 2

int N, tt;
vvi M(MaxNode, vi(MaxNode, 0));
vi color(MaxNode), d(MaxNode), f(MaxNode);

int next(int node_index) {
	for (int v = 0; v < N; v++) {
		if (M[node_index][v] && color[v] == White) {
			return v;
		}
	}

	return -1;
}

void dfs(int node_from) {
	stack<int> S;
	S.push(node_from);
	color[node_from] = Gray;
	d[node_from] = ++tt;

	while (!S.empty()) {
		int u = S.top();
		int v = next(u);

		if (v != -1) {
			if (color[v] == White) {
				color[v] = Gray;
				d[v] = ++tt;
				S.push(v);
			}
		}
		else {
			S.pop();
			color[u] = Black;
			f[u] = ++tt;
		}
	}
}

int main() {
	int u, k, v;
	cin >> N;
	rep(i, N)rep(j, N) M[i][j] = 0;
	for (int i = 0; i < N; i++) {//隣接リストから隣接行列
		cin >> u >> k;
		u--;
		for (int j = 0; j < k; j++) {
			cin >> v;
			v--;
			M[u][v] = 1;
		}
	}
	dfs(0);
	for (int i = 0; i < N; i++) {
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
	}
}
