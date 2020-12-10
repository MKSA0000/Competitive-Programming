#include"../INCLUDES.h"

struct Node {
public:
    int parent;
    int rank = -1;
    bool isVisited;
    vector<vector<int>> to_child; // {node_number,weight}
};

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] > b[1];
    }else {
        return a[0] < b[0];
    }
}

//後退辺まで考慮したDjikstra
vector<int> Dijkstra(vector<Node>& Graph_V, int start) {
    int N = Graph_V.size();
    vector<int> Cost(N, pint_INF);
    vector<bool> isVisited(N, false);
    priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq(&comp);
    Cost[start] = 0;
    Graph_V[start].parent = start;
    pq.push({ start,0 });
    vector<int> Max = { 0,0 }; //{NodeNumber,CostfromStart}

    while (!pq.empty()) {
        int u = pq.top()[0]; pq.pop();
        Node node_u = Graph_V[u];

        if (isVisited[u]) { continue; }

        for (auto& edge : Graph_V[u].to_child) {
            int v = edge[0];
            int weight = edge[1];
            if (chmin(Cost[v], Cost[u] + weight)) {
                Graph_V[v].parent = u;
                pq.push({ v,Cost[v] });
            }
            if (chmax(Max[1], Cost[v])) {
                Max[0] = v;
            }
        }
    }
    return Cost;
}

//startを起点にするDjikstra {NodeNumber,CostfromStart}
struct Edge{
public:
    map<int,int> to; //set vector<int> でも vector<vector<int>> でもok
};
vector<int> Dijkstra(vector<Edge>& Graph, int stind) {
    int V = Graph.size();
    vector<int> Dist(V, pint_INF);
    vector<int> isVisited(V, false);
    priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq(&comp);
    // Idx, Distance
    Dist[stind] = 0;
    pq.push({ stind,0 });

    while (!pq.empty()) {
        int u = pq.top()[0]; pq.pop();
        if (isVisited[u]) continue;
        isVisited[u] = true;

        for (auto& [nind, weight] : Graph[u].to) {
            if (chmin(Dist[nind], Dist[u] + weight)) {
                pq.push({ nind,Dist[nind] });
            }
        }
        
    }
    return Dist;
}


int AbsEditDist(string left, string right) {
    int diff = 0;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != right[i]) diff++;
    }
    return diff;
}

signed main() {
    string first, last; cin >> first >> last;
    int N; cin >> N;
    vector<string> vstring(N + 2); // [0] is first [1] is last
    vector<Node> graph(N + 2);

    vstring[0] = first; vstring[1] = last;
    for (int i = 2; i < N + 2; i++) {
        cin >> vstring[i];
    }

    for (int i = 0; i < N+2; i++) {
        for (int j = i + 1; j < N+2; j++) {
            int dist = AbsEditDist(vstring[i], vstring[j]);
            if (dist < 2) {
                graph[i].to_child.push_back({ j,dist });
                graph[j].to_child.push_back({ i,dist });
            }
        }
    }
    auto dijk = Dijkstra(graph, 0);
    if (dijk[1] == pint_INF) {
        cout << -1 << endl;
    }
    else {
        if (first == last) {
            cout << 0 << endl;
            cout << first << endl << first << endl;
        }
        else {
            int rind = 1;
            vector<string> ans;
            while (rind != 0) {
                ans.push_back(vstring[rind]);
                rind = graph[rind].parent;
            }
            ans.push_back(vstring[0]);
            reverse(ALL(ans));
            cout << ans.size() - 2 << endl;
            for (auto& ss : ans) {
                cout << ss << endl;
            }
        }
    }

}