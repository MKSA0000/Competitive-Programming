#include"../INCLUDES.h"

static const int MaxNode = 100;
static const int White = 0;
static const int Gray = 1;
static const int Black = 2;

int n, tt;
vvi M(MaxNode, vi(MaxNode));
vi color(MaxNode), d(MaxNode), f(MaxNode), nt(MaxNode);

int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;
    if (M[u][v]) {
      return v;
    }
  }
  return -1;
}

void dfs_visit(int r) {
  for (int i = 0; i < n; i++) {
    nt[i] = 0;
  }

  stack<int> S;
  S.push(r);
  color[r] = Gray;
  d[r] = ++tt;

  while (!S.empty()) {
    int u = S.top();
    int v = next(u);
    if (v != -1) {
      if (color[v] == White) {
        color[v] = Gray;
        d[v] = ++tt;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = Black;
      f[u] = ++tt;
    }
  }
}

void dfs() {
  for (int i = 0; i < n; i++) {
    color[i] = 0;
    nt[i] = 0;
  }
  tt = 0;

  for (int u = 0; u < n; u++) {
    if (color[u] == White) {
      dfs_visit(u);
    }
  }

  //For degug
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }

}

int main() {
  int u, k, v;
  cin >> n;
  rep(i, n)rep(j, n) M[i][j] = 0;
  for (int i = 0; i < n; i++) {//隣接リストから隣接行列
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  dfs();
}
