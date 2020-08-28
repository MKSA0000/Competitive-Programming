#include"../INCLUDES.h"

struct Node{
public:
    int self_number;
    int rank;
    int parent;
    bool isVisited;
    vector<vector<int>> to_child; // {node_number,weight}
};

bool comp(const vector<int>& a,const vector<int>& b) {
    if(a[1] != b[1]){
        return a[1] > b[1];
    }else{
        return a[0] < b[0];
    }
}

//後退辺まで考慮したDjikstra　遅い
vector<int> Dijkstra(vector<Node> Graph_V,int start){
    vector<int> Cost(Graph_V.size(),pint_INF);
    priority_queue<vector<int>,vector<vector<int>>,decltype(&comp)> pq(&comp);
    Cost[start] = 0;
    Graph_V[start].parent = start;
    pq.push({start,0});
    vector<int> Max = {0,0}; //{NodeNumber,CostfromStart}

    while(!pq.empty()){
        int index = pq.top()[0]; pq.pop();
        Node u = Graph_V[index];

        for(int i = 0; i < u.to_child.size(); i++){
            if(Cost[u.self_number] + u.to_child[i][1] < Cost[u.to_child[i][0]]){
                Cost[u.to_child[i][0]] = Cost[u.self_number] + u.to_child[i][1];
                Graph_V[u.to_child[i][0]].parent = u.self_number;
                pq.push({u.to_child[i][0],Cost[u.to_child[i][0]]});

                if(Max[1] < Cost[u.to_child[i][0]]){
                    Max[0] = Graph_V[u.to_child[i][0]].self_number;
                    Max[1] = Cost[u.to_child[i][0]];
                }
            }
        }
    }

    return Max;
}
//startを起点にするDjikstra {NodeNumber,CostfromStart}
vector<int> Dijkstra(vector<Node> Graph_V,int start){
    vector<int> Cost(Graph_V.size(),pint_INF);
    priority_queue<vector<int>,vector<vector<int>>,decltype(&comp)> pq(&comp);
    Cost[start] = 0;
    pq.push({start,0});

    while(!pq.empty()){
        int parent = pq.top()[0]; pq.pop();
        Node u = Graph_V[parent];
        if (Graph_V[parent].isVisited == true) continue;
        Graph_V[parent].isVisited = true;
        for(vector<int> child : u.to_child){
            if(Cost[parent] + child[1] < Cost[child[0]]){
                Cost[child[0]] = Cost[parent] + child[1];
                pq.push({child[0],Cost[child[0]]});
            }
        }
    }

    return Cost;
}