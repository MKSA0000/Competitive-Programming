#include"../INCLUDES.h"

int dist(vi from, vi to) {
    return abs(to[0] - from[0]) + abs(to[1] - from[1]) + max(0LL, to[2] - from[2]);
}

struct state {
public:
    int cur;
    bitset<20> b;
    state() {}
    state(int c, bitset<20> d) { cur = c, b = d; }
};

struct compmy {
public:
    bool operator()(const state& lhs, const state& rhs) const {
        if (lhs.cur != rhs.cur) {
            return lhs.cur < rhs.cur;
        }
        else {
            int l = lhs.b.to_ullong();
            int r = rhs.b.to_ullong();
            return l < r;
        }
    }
};

typedef map<state, int, compmy> Mmap;

signed main() {
    int N; cin >> N;
    vector<vector<int>> cities(N,vi(3));
    rep(i, N) cin >> cities[i][0] >> cities[i][1] >> cities[i][2];
    vector<vector<int>> distij(N, vi(N));//dist from i to j
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distij[i][j] = dist(cities[i], cities[j]);
        }
    }
    vector<Mmap> floors(N);
    Mmap floor;
    state init = { 0,bitset<20>(1)};
    floors[0][init] = 0;
    for (int i = 0; i < N - 1; i++) {
        // fill the next floor
        for (auto iter = floors[i].begin(); iter != floors[i].end(); iter++) {
            state ustat = iter->first;
            int cost = iter->second;
            int u = ustat.cur;
            bitset<20> ubs = ustat.b;

            for (int v = 0; v < N; v++) {
                if (ubs[v] == false) {
                    //visit v
                    ubs[v] = true;
                    state tmp = { v,ubs };
                    //
                    if (floors[i + 1].find(tmp) == floors[i + 1].end()) {
                        floors[i + 1][tmp] = cost + distij[u][v];
                    }
                    else {
                        floors[i + 1][tmp] = min(floors[i + 1][tmp], cost + distij[u][v]);
                    }
                    ubs[v] = false;
                }
            }
        }
    }

    int ans = pll_INF;
    for (auto iter = floors[N - 1].begin(); iter != floors[N - 1].end(); iter++) {
        int d = iter->second + distij[iter->first.cur][0];
        ans = min(d, ans);
    }
    cout << ans << endl;
    sysp;
   
}

簡易はコレ
vector<map<int, int, greater<int>>> vec; // ind_kindergaten -> rating

