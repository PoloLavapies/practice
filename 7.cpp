#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

bool is_prime(int n){
    float n_root = sqrt((float)n);
    for(int i = 2; i <= (int)n_root; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int N;
    cin >> N;
    // 渡って来たら負ける...0 渡って来たら勝てる...1
    int dp[10001];
    memset(dp, 0, sizeof(dp));
    // 2 ≤ i ≤ nのiについて、それ以下の素数jを引いた時に、dp[i-j]が0となるjがあれば1。そうでなければ0。
    for(int i = 2; i <= N; i++){
        for(int j = i - 2; j >= 2; j--){
            if (!(is_prime(j))) continue;
            if (dp[i - j] == 0){
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[N] == 1) cout << "Win" << endl;
    else cout << "Lose" << endl;

    return 0;
}