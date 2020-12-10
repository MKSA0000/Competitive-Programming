#include"../INCLUDES.h"

class Node{
public:
    int self_number;
    int rank;
    int parent;
    vector<pair<int,int>> to_child; // first = node_Number, second = cost;
};

class Edge{
    vector<int> to; //{to_where, weight}
};
