#include"INCLUDES.h"

inline int sum_of_digits(ll x){
  int sum = 0;
  while(x){
    sum += (x % 10);
    x /= 10;
  }

  return sum;
}

inline int ctoi(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	}
	else {
		return -1;
	}
}

inline char itoc(int i) {
	char c;
	c = 'a' + i;
	return c;
}

string fillZero(string s, int zeros,int direction = 0) { //0のとき右にくっつける 1で左につける 
    if(direction == 1){
		string z;
    	for (int i = 0; i < zeros; i++) {
        z += "0";
    	}
    	return s + z;
	}else if(direction == 0){
		string z;
    	for (int i = 0; i < zeros; i++) {
        z += "0";
    	}
    	return z + s;
	}	
}

string set_with_zero(string s, int length) {// lengh桁になるまでゼロを左につける
    int a = s.size();
    return fillZero(s, length - a,1);
}