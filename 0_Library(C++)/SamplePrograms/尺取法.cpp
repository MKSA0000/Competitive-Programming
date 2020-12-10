#include"../INCLUDES.h"

void shakutori(){
    int n;
    int right = 0;     
    for (int left = 0; left < n; ++left) {
        while (right < n && (right を 1 個進めたときに条件を満たす)) {
            /* 実際に right を 1 進める */
            // ex: sum += a[right];
            ++right;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);

        /* left をインクリメントする準備 */
        // ex: if (right == left) ++right;
        // ex: else sum -= a[left];
    }
}

void ABC032C(){
    int N,K; cin >> N >> K;
    vector<int> vec(N);
    bool zflag = false;
    rep(i,N){
        cin >> vec[i];
        if(vec[i] == 0) zflag = true;
    }

    auto chakutori = [&](){
        int right = 0;
        int val = 1;
        int res = 0;
        for(int left = 0; left < N; left++){
            while(right < N && val * vec[right] <= K){
                val *= vec[right];
                right += 1;
                
                res = max(res,right-left);
            }

            if(right == left){
                val = vec[right];
                right++;
            }else{
                val /= vec[left];
                left++;
            }
        }
        return res;
    };
    int ans = chakutori();
    if(zflag){
        ans = N;
    }
    cout << ans << endl;
}

void ABC098D() {
    int N; cin >> N;
    vector<int> vec(N); rep(i, N) cin >> vec[i];
    auto chakutori = [&]() {
        int right = 0;
        int ssum = 0;
        int res = 0;
        for (int left = 0; left < N; left++) {
            while (right < N && (ssum ^ vec[right]) == ssum + vec[right]) {
                ssum += vec[right];
                right++;
            }
            if (right == left) {
                right++;
                ssum = 0;
            }
            res += right - left;
            ssum -= vec[left];
        }
        return res;
    };

    int ans = chakutori();
    cout << ans << endl;
    sysp;
}