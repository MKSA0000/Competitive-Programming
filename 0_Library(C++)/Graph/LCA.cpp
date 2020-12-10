#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;


struct Edge {
    vector<int> to; //{to_where, weight}
};

class LCA {
private:
    vector<vector<int>> Ancestor; // 2**k先の親のindexを格納する2次元配列
    vector<int> Dist; //rootからの距離
    vector<int> isVisited;
public:
    void init(const vector<vector<Edge>>& vec, int root = 0) {
        int V = vec.size();
        int logK = 1;
        while ((1 << logK) < V) logK++;

        Ancestor.resize(V);
        for (auto& anc : Ancestor) {
            anc.resize(logK, -1);
        }

        Dist.resize(V, -1);
        isVisited.resize(V, false);

        CalcDist(vec, root);

        for (int k = 0; k < logK - 1; k++) {
            for (int i = 0; i < V; i++) {
                if (Ancestor[i][k] < 0) {
                    Ancestor[i][k + 1] = -1;
                }
                else {
                    Ancestor[i][k + 1] = Ancestor[Ancestor[i][k]][k];
                }
            }
        }

    }

    void CalcDist(const vector<vector<Edge>>& vec, int start = 0) {
        Dist[start] = 0;
        Ancestor[start][0] = start;
        isVisited[start] = true;

        stack<int> st;
        st.push(start);
        while (!st.empty()) {
            int u = st.top(); st.pop();
           
            for (auto eg : vec[u]) {
                int v = eg.to[0];
                int w = eg.to[1];

                if (!isVisited[v]) {
                    Ancestor[v][0] = u;
                    isVisited[v] = true;
                    Dist[v] = Dist[u] + w;
                    st.push(v);
                }
            }
        }
    }

    int query(int u, int v) {
        // find lca of u,v
        if (Dist[u] < Dist[v]) {
            swap(u, v);
        }

        int K = Ancestor[0].size();
        for (int k = 0; k < K; k++) {
            if ((Dist[u] - Dist[v]) >> k & 1) {
                //uの深さがvより0b1100101001深いならば...のノリ
                u = Ancestor[u][k];
            }
        }

        if (u == v) {
            return u;
        }

        for (int k = K - 1; k > -1; k--) {
            if (Ancestor[u][k] != Ancestor[v][k]) {
                u = Ancestor[u][k];
                v = Ancestor[v][k];
            }
        }
        return Ancestor[u][0];
    }
};

int main() {
    int N; cin >> N;
    vector<vector<Edge>> Graph(N);
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int k = 0; k < K; k++) {
            int c; cin >> c;
            Edge e; e.to = { c,1 };
            Graph[i].push_back(e);
        }
    }

    LCA lca;
    lca.init(Graph, 0);

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}