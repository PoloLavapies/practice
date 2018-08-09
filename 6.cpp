#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;

/*
二重ループを使っている箇所は、しゃくとり法を使って簡潔な処理にできる
*/

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
// stringを使わずに、再帰を使った方が簡潔に書ける
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

// primesにおけるprimes[i]からの最長部分を求める
int how_long(int i, vector<int> prime_hash){
    set<int> tmp;
    FOR(j, i, prime_hash.size()){
        if (tmp.find(prime_hash[j]) == tmp.end()){
            tmp.insert(prime_hash[j]);                
        } else {
            break;
        }
    }
    return tmp.size();
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
    FOR(i, 0, primes.size()){
        int length = how_long(i, prime_hash);
        if (length >= max_length){
            max_length = length;
            max_start = primes[i];
        }
    }
    cout << max_start << endl;
    return 0;
}