#include"../INCLUDES.h"

class DisjointSet{
private:
  vector<int> rank,parent;
public:
  DisjointSet(int size){
    rank.resize(size,0);
    parent.resize(size,0);

    for(int i = 0; i < size; i++){
      makeSet(i);
    }
  }

  void makeSet(int x){
    parent[x] = x;
    rank[x] = 0;
  }

  bool isSame(int x, int y){
    return findSet(x) == findSet(y);
  }

  void unite(int x, int y){
    link(findSet(x),findSet(y));
  }

  void link(int x, int y){ // x and y are guaranteed to be a root
    if(rank[x] > rank[y]){
      parent[y] = x;
    }else{
      parent[x] = y;
      if(rank[x] == rank[y]){
        rank[y]++;
      }
    }
  }

  int findSet(int x){
    if(x != parent[x]){
      parent[x] = findSet(parent[x]);
    }

    return parent[x];
  }
};
