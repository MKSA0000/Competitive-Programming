#include"../INCLUDES.h"

template<typename T_n>
inline T_n Accumulate(T_n input){
  T_n v(input.size());
  v[0] = input[0];
  for(int i = 1;i < input.size(); i++){
    v[i] = v[i-1] + input[i];
  }

  return v;
}

template<typename T_n>
inline T_n rAccumulate(T_n input){
  const int l = input.size();
  T_n v(l);
  v[l- 1] = input[l -1];
  for(int i = l - 2; i >= 0; i--){
    v[i] = v[i+1] + input[i];
  }

  return v;
}


inline int v_max_index(vi &x){
  vi::iterator iter = max_element(ALL(x));
  return distance(x.begin(),iter);
}

template<typename T_n>
inline void zero_fill(T_n& input){
  rep(i,input.size()){
    input[i] = 0;
  }
}

inline int vpa_index_1(vector<pii>& vpa, int Key){// Key以下 && 最大の要素のインデックス
  int i = 0;
  for(;vpa[i+1].second <= Key; i++){
  }
  return i;
}

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> operator+(const vi& v1, const vi& v2) {
	return { v1[0] + v2[0],v1[1] + v2[1] };
}

bool isWithin(const vector<int>& coordinate,int& H,int& W){
    int y = coordinate[0];
    int x = coordinate[1];
    if(-1 < y && y < H){
        if(-1 < x && x < W){
            return true;
        }
    }
    return false;
}

vector<int> vero_one_compression(const vector<int>& vec){
  int prev = vec[0];
  vector<int> res;
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] == prev){
      res.back()++;
    }else{
      res.push_back(1);
      prev = vec[i];
    }
  }

  return res;
}