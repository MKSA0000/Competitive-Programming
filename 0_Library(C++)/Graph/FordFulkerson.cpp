#include"../INCLUDES.h"

struct Edge{
    int to,weight,rev;
    //rev indicates when this edge is added
};

class FordFulkerson{
private:
    vector<bool> isVisited;
    vector<vector<Edge>> Graph;
public:
    void init(int N){
        Graph.resize(N);
    }
    void add_edge(int from, int to, int weight){
        int g_to_size = Graph[to].size();
        int g_from_size = Graph[from].size();
        Graph[from].push_back(Edge{to,weight,g_to_size});
        Graph[to].push_back(Edge{from,weight,g_from_size});
    }
    int flow_dfs(int cur, int goal,int mincap){
        if (cur == goal){ 
            return mincap;
        }
        isVisited[cur] = true;
        for (auto& e:Graph[cur])
            if(!isVisited[e.to] && e.weight > 0){
                int d = flow_dfs(e.to, goal, min(mincap,e.weight));
                if (d > 0){
                    e.weight -= d;
                    Graph[e.to][e.rev].weight += d;
                    return d;
                }
            }
        return 0;
    }
    int max_flow(int start, int goal){
        int flow = 0;
        while (true){
            isVisited.resize(Graph.size(),false);
            int f = flow_dfs(start, goal, pint_INF); 
            if (f == 0){
                return flow;
            }
            flow += f;
        }
    }
};

int main() {
    int V, E; cin >> V >> E;
    FordFulkerson ff;
    ff.init(V);
    for (int i = 0; i < E; i++) {
        int u, v, c; cin >> u >> v >> c;
        ff.add_edge(u, v, c);
    }
    cout << ff.max_flow(0, V - 1) << endl;
}


template< typename flow_t >
struct FordFulkerson2 {
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector< vector< edge > > graph;
    vector< int > used;
    const flow_t INF;
    int timestamp;

    FordFulkerson(int n) : INF(numeric_limits< flow_t >::max()), timestamp(0) {
        graph.resize(n);
        used.assign(n, -1);
    }

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back(edge{ to, cap, (int)graph[to].size(), false, idx });
        graph[to].emplace_back(edge{ from, 0, (int)graph[from].size() - 1, true, idx });
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if (idx == t) return flow;
        used[idx] = timestamp;
        for (auto& e : graph[idx]) {
            if (e.cap > 0 && used[e.to] != timestamp) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        for (flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto& e : graph[i]) {
                if (e.isrev) continue;
                auto& rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

signed main() {
    string s; cin >> s;
    string t; cin >> t;
    string u; cin >> u;

    vector<int> Spool(26), Tpool(26), Upool(26);
    auto ctoi = [](char c) {
        int x = c - 'A';
        return x;
    };
    for (int i = 0; i < s.size(); i++) {
        Spool[ctoi(s[i])]++;
        Tpool[ctoi(t[i])]++;
        Upool[ctoi(u[i])]++;
    }
    int HfCap = s.size() / 2;
    FordFulkerson<int> ff(30);
    //source to sub sources
    ff.add_edge(0, 1, HfCap);
    ff.add_edge(0, 2, HfCap);
    //for each alphabet
    for (int i = 0; i < 26; i++) {
        int ff_ind = i + 3;
        ff.add_edge(1, ff_ind, Spool[i]);
        ff.add_edge(2, ff_ind, Tpool[i]);
        ff.add_edge(ff_ind, 29, Upool[i]);
    }
    int Mf = ff.max_flow(0, 29);
    if (Mf == s.size()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}