#include"../INCLUDES.h"

inline int sum_of_digits(ll x){
  int sum = 0;
  while(x){
    sum += (x % 10);
    x /= 10;
  }

  return sum;
}

int ctoi(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	}
	else {
		return -1;
	}
}

int Nctoi(char c){
	if('0' <= c && c <= '9'){
		return c - '0';
	}else{
		return 0;
	}
}
char itoc(int i) {
	char c;
	c = 'a' + i;
	return c;
}

string fillZero(string s, int zeros,int direction = 0) { //0のときゼロを右にくっつける 1で左につける 
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

int Exact_converter(string s, int powoffset=9) { // string10進数変換器
	int res = 0;
	auto isdot = [](char c) {
		if (c == '.') return true;
		else return false;
	};
	int ind = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (isdot(s[i])) ind = i;
	}

	auto ctoi = [](char c) {
		int x = c - '0'; return x;
	};

	auto pow = [](int p) {
		int tmp = 1; rep(i, p) tmp *= 10;
		return tmp;
	};

	for (int d = 0; d < s.size(); d++) {
		if (d < ind) {
			int pp = ind - d - 1;
			res += ctoi(s[d]) * pow(pp+powoffset);
		}
		else if (d == ind) {
			continue;
		}
		else {
			int pp = d - ind;
			res += ctoi(s[d]) * pow(powoffset-pp);
		}
	}

	return res;
}