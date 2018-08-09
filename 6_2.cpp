#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;

// 素数かどうか調べる
int if_prime(int n){
    if (n == 1) return 0;
    int root_n = sqrt(n);
    FOR(i, 2, root_n + 1){
        if (n % i == 0) return 0;
    }
    return 1;
}

// hash値を調べる
int to_hash(int n){
    while (true){
        string a;
        a = to_string(n);
        if (a.length() == 1) return n;
        n = 0;
        FOR(i, 0, a.length()){
            n += (a[i] - '0');
        }
    }
}

int main(){
    int k, n;
    cin >> k >> n;
    // 素数のvector
    vector<int> primes;
    FOR(i, k, n + 1){
        if (if_prime(i)) primes.push_back(i);
    }
    // 素数のhash値のvector
    vector<int> prime_hash;
    FOR(i, 0, primes.size()){
        prime_hash.push_back(to_hash(primes[i]));
    }
    // 最長部分を求める
    int max_length = 0;
    int max_start = -1;
    // 最長部分を求める
    int dp[10];
    memset(dp, 0, sizeof(dp));
    // 内側のループを抜けた状態では[start, end)がハッシュ値がすべて異なる最長区間
    int start = 0;
    int end = 0;
    while (start < primes.size()){
        while (end < primes.size()) {
            if (dp[prime_hash[end]] == 0) {
                dp[prime_hash[end]] = 1;
                end += 1;
            } else {
                break;
            }
        }
        if (end - start >= max_length){
            max_start = primes[start];
            max_length = end - start;
        }
        dp[prime_hash[start]] = 0;
        start += 1; 
    }
    cout << max_start << endl;
    return 0;
}