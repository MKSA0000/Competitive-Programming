#include"../INCLUDES.h"

struct FenwickTree { //data are managed with 1-indexing
public:
    vector<int> data;
    int Size;
    FenwickTree(int _N) {
        _N++;
        Size = _N;
        data.resize(_N, 0);
    }

    void add(int pos, int val) { //arguents are 1-indexed
        pos++;
        while (pos < Size) {
            data[pos] += val;
            pos += (pos & -pos);
        }
    }

    int rangesum(int From, int To) {//Closed Range [From,To] with 0-index
        To++; From++;
        int left = allsum(To);
        int right = allsum(From-1);
        return left - right;
    }
private:
    int allsum(int pos) { //1-indexed [0,pos]
        //We usually dont use this function outside class
        int s = 0;
        while (pos > 0) {
            s += data[pos];
            pos -= (pos & -pos);
        }
        return s;
    }
};