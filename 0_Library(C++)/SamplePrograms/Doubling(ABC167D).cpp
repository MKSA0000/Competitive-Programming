#include"../INCLUDES.h"
/*
問題文

高橋王国には N個の町があります。町は 1 から Nまで番号が振られています。

それぞれの町にはテレポーターが 1
台ずつ設置されています。町 i(1≤i≤N) のテレポーターの転送先は町 Aiです。

高橋王は正の整数 Kが好きです。わがままな高橋王は、町 1 から出発してテレポーターをちょうど K回使うと、どの町に到着するかが知りたいです。

高橋王のために、これを求めるプログラムを作成してください。
*/
signed main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a; --a;
        A[i] = a;
    }

    int logK = 1;
    while ((1LL << logK) < K) logK++;

    vector<vector<int>> doubling(N,vector<int>(logK));

    for(int i = 0; i < N; i++){
        doubling[i][0] = A[i];
    }

   for(int k = 1; k < logK; k++){
       for(int i = 0; i < N; i++){
           doubling[i][k] = doubling[doubling[i][k-1]][k-1];
       }
   }

   int now = 0;
   for(int k = 0; K > 0; k++){
       //Note that the for loop above uses both k and K
       if(K & 1){
           now = doubling[now][k];
       }

       K = K >> 1;
       /*シフト演算の考え方
       0b0010111011
       これを右にずらすのが>>で
       左にずらすのが<<である
       */
   }

   cout << now + 1 << endl;
}