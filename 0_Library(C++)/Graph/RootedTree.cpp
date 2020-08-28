#include"../INCLUDES.h"

class RootedTree {
private:
    vector<vector<int>> Tree; // for each row {ID,ParentID,Value,Acc,DistanceToRoot}
    int Root;
public:
    RootedTree(int Size, int rt, bool isParentChildExplisit = false) { // parent is 0-indexed
        Tree.resize(Size);
        Root = rt;
        if (isParentChildExplisit) {
            for (int i = 0; i < Size; i++) {
                Tree[i] = { i,-1,0,-1,pint_INF };
            }
            Tree[Root][4] = 0;
        }
        else {
            for (int i = 0; i < Size; i++) {
                Tree[i] = { i,-1,0,-1 };
            }
        }
        Tree[Root][1] = Root;
        Tree[Root][3] = 0; // Initialize Sum

    }

    void AddChild(int p1, int p2) { // Usually p1 is Parent p2 is Child
        if (Tree[0].size() < 5) {// Disabled
            Tree[p2][1] = p1;
        }
        else {
            if (DistToRoot(p1) > DistToRoot(p2)) {
                // parent is p2
                Tree[p1][1] = p2;
                Tree[p1][4] = Tree[p2][4] + 1;
            }
            else {
                Tree[p2][1] = p1;
                Tree[p2][4] = Tree[p1][4] + 1;
            }
        }
    }

    void SetValue(int node, int value) {
        Tree[node][2] += value;
        if (node == Root) {
            Tree[node][3] += value;
        }
    }

    int FindValue(int node) {// Recursive Function
        int u = node;
        int v = Tree[u][1];
        if (u == v) return Tree[u][2];
        if (Tree[u][3] != -1) {
            return Tree[u][3];
        }
        else {
            Tree[u][3] = FindValue(v) + Tree[u][2];
        }

        return -1;
    }

    int DistToRoot(int node) {
        int u = node;
        int v = Tree[u][1];
        if (u == v) return Tree[u][4];
        if (v == -1) return pint_INF;
        if (Tree[v][4] < pint_INF) {
            Tree[u][4] = Tree[v][4] + 1;
            return Tree[u][4];
        }
        else {
            return pint_INF;
        }

        return -1;
    }

    int Value_for_Node(int node) {
        return Tree[node][3];
    }

};