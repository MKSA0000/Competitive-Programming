#include "../INCLUDES.h"

inline int v_max_index(vi &x)
{
  vi::iterator iter = max_element(ALL(x));
  return distance(x.begin(), iter);
}

template <typename T_n>
inline void zero_fill(T_n &input)
{
  rep(i, input.size())
  {
    input[i] = 0;
  }
}

inline int vpa_index_1(vector<pii> &vpa, int Key)
{ // Key以下 && 最大の要素のインデックス
  int i = 0;
  for (; vpa[i + 1].second <= Key; i++)
  {
  }
  return i;
}

bool compare_by_second(pair<int, int> a, pair<int, int> b)
{
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return a.first < b.first;
  }
}