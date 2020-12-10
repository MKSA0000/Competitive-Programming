#include"../INCLUDES.h"

struct Node {
public:
    int indeg = 0;
    vector<int> to;
};

vector<int> TopologicalSort(vector<Node>& Graph) {
    // Return topologically soreted vector of indices from 1st to end
    int N = Graph.size();
    stack<int> st;
    for (int i = 0; i < N; i++) {
        for (auto& nind : Graph[i].to) {
            Graph[nind].indeg++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (Graph[i].indeg == 0) st.push(i);
    }

    vector<int> ind_sorted;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        ind_sorted.push_back(u);

        for (auto& nind : Graph[u].to) {
            Graph[nind].indeg--;
            if (Graph[nind].indeg == 0) st.push(nind);
        }
    }

    if(ind_sorted.size() != Graph.size()){
        return vector<int>();
    }else{
        return ind_sorted;
    }
}