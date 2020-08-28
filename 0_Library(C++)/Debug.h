#include"INCLUDES.h"

template<typename T>
void pprint_d2(vector<vector<T>>& vec){
  for(auto& v: vec){
    for(auto& elem: v){
      cout << elem << " ";
    }
    cout << endl;
  }
}
