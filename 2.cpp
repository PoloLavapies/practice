#include <iostream>
#include <complex>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ll long long int

int main(){
    ll N;
    cin >> N;
    int bitxor = 0;
    FOR(i, 2, N + 1){
        int count = 0;
        while (N % i == 0){
            N /= i;
            count++;
        }
        bitxor ^= count;
        if (N == 1) break;
    }
    
    if (bitxor) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}