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

class UnionFind {
protected:
    vector<vector<int>> Graph;// {ID,Value,ParentID,Height}
    vector<bool> isClosed;
    vector<int> gsize;
public:
    void push(int x) {
        int i = Graph.size();
        Graph.push_back({ i,x,i,1 });
        isClosed.push_back(false);
        gsize.push_back(1);
    }
    void unite(int x, int y) {
        if(root(x) == root(y)){
            isClosed[root(x)] = true;
            isClosed[root(y)] = true;
        }
        int hx = Graph[root(x)][3];
        int hy = Graph[root(y)][3];
        if (hx < hy) {
            Graph[root(x)][2] = root(y);
            gsize[root(y)] += gsize[root(x)];
            gsize[root(x)] = -1;
            flatten(x, root(y));
        }
        else if(hx == hy){
            Graph[root(y)][2] = root(x);
            gsize[root(x)] += gsize[root(y)];
            gsize[root(y)] = -1;
            Graph[root(x)][3]++;
            flatten(y, root(x));
        }
        else {
            Graph[root(y)][2] = root(x);
            gsize[root(x)] += gsize[root(y)];
            gsize[root(y)] = -1;
            flatten(y, root(x));
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void flatten(int x, int rootid) {
        int parentid = Graph[x][0];
        while (Graph[parentid][0] != Graph[parentid][2]) {
            Graph[parentid][2] = rootid;
            int next = Graph[parentid][2];
            parentid = next;
        }
    }
    int root(int x) {
        int parentid = Graph[x][0];
        while (Graph[parentid][0] != Graph[parentid][2]) {
            int next = Graph[parentid][2];
            parentid = next;
        }
       
        return parentid;
    }
    int count_groups(){
        int cnt = 0;
        for(int i = 0; i < Graph.size(); i++){
            if(Graph[i][2] == Graph[i][0]){
                cnt++;
            }
        }
        return cnt;
    }
    vector<vector<int>> group_indices() {
        vector<vector<int>> groups(Graph.size());
        for (int i = 0; i < Graph.size(); i++) {
            groups[root(i)].push_back(i);
        }
        return groups;
    }
};

int main() {
    int n, q; cin >> n >> q;
    UnionFind uf;
    for (int i = 0; i < n; i++) {
        uf.push(i);
    }
    for (int i = 0; i < q; i++) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        }
        if (com == 1) {
            cout << uf.same(x, y) << endl;
        }
    }
}