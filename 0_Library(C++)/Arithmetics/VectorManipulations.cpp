#include "../INCLUDES.h"

template <typename T>
vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs)
{
  assert(lhs.size() == rhs.size());
  vector<T> res(lhs.size());
  for (int i = 0; i < lhs.size(); i++)
  {
    res[i] = lhs[i] + rhs[i];
  }
  return res;
}

template <typename T>
vector<T> operator-(const vector<T> &lhs, const vector<T> &rhs)
{
  assert(lhs.size() == rhs.size());
  vector<T> res(lhs.size());
  for (int i = 0; i < lhs.size(); i++)
  {
    res[i] = lhs[i] - rhs[i];
  }
  return res;
}

bool isWithin(const vector<int> &coordinate, int &H, int &W)
{
  int y = coordinate[0];
  int x = coordinate[1];
  if (-1 < y && y < H)
  {
    if (-1 < x && x < W)
    {
      return true;
    }
  }
  return false;
}

template <typename T, typename S>
bool isWithin(const vector<T> &coor, const vector<vector<S>> table)
{
  T y = coor[0];
  T x = coor[1];
  S H = table.size();
  S W = table[0].size();
  if (-1 < y && y < H)
  {
    if (-1 < x && x < W)
    {
      return true;
    }
  }
  return false;
}

vector<int> zero_one_compression(const vector<int>& vec){
    int prev = vec[0];
    vector<int> res; res.push_back(0);
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == prev){
            res.back()++;
        }
        else{
            res.push_back(1);
            prev = vec[i];
        }
    }
    return res;
}

template <typename T>
bool isEqual(vector<T> &lhs, vector<T> &rhs)
{
  assert(lhs.size() == rhs.size() && lhs[0].size() == rhs[0].size());

  int h = lhs.size();
  int w = lhs[0].size();
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (lhs[i][j] != rhs[i][j])
      {
        return false;
      }
    }
  }
  return true;
}