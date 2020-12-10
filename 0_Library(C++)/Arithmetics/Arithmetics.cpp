#include"../INCLUDES.h"

int opow(int a, int b) {
	int ans = 1;
	rep(i, b) {
		ans *= a;
	}

	return  ans;
}

int gcd(int a, int b) {
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int gcd_of_all(vi v){
  int l = v.size();

  int temp = v[0];
  for(int i = 0; i < l ; i++){
    temp = gcd(temp,v[i]);
  }

  return temp;
}


int lcm(int a, int b){
	int GCD = gcd(a,b);
	return a*b/GCD;
}

int lcm_of_all(vector<int> v){
    int temp = v[0];
    for(int elem: v){
      temp = lcm(temp,elem);
    }
    return temp;
}

int ExactFloor(int x,int p){
	return (x+p-1)/p;
}