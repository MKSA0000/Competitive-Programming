#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include"../INCLUDES.h"

struct Edge {
    vector<int> to; //{to_where, weight}
};

ll ans = 0;
void recursion(vector<vector<Edge>>& Graph,int cur,vi& isVisited){
    vi myisVisited = isVisited;
    myisVisited[cur] = 1;
    
    int blcnt = 0;
    for(auto bl: myisVisited){
        if(bl == true) blcnt++;
    }
    if(Graph.size() == blcnt){
        ans++;
        return;
    }

    for(auto e: Graph[cur]){
        // e is type Edge
        if(myisVisited[e.to[0]] == 0){
            recursion(Graph,e.to[0],myisVisited);
        }
    }
}
int main(){
    int N,M; cin >> N >> M;
    vector<vector<Edge>> Graph(N);
    for (int i = 0; i < M; i++) {
      int a,b; cin >> a >> b;
      --a; --b;
      Edge e_a; e_a.to = {b,1};
      Edge e_b; e_b.to = {a,1};
      Graph[a].push_back(e_a);
      Graph[b].push_back(e_b);
    }
    vi isVisited(N,false);
    recursion(Graph,0,isVisited);

    cout << ans << endl;
    sysp;
}