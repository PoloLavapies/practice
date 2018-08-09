#include <iostream>
#include <vector>
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define RREP(i,a,b) for(int i=(a); i>(b); i--)
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin >> n;
    n /= 1000;
    int m;
    cin >> m;
    int amari = n % m; 
    // (m)人から(amari)を選ぶ選び方が答え。m C amariを計算する
    amari = min(amari, m - amari);
    // m C amariの計算における分子
    int bunshi[amari];
    REP(i, 0, amari){
        bunshi[i] = m - i;
    }
    // m C amariの計算における分母
    vector<int> bunbo;
    for (int i = 2; i <= amari; i++){
        int i_copy = i;
        int j = 2;
        while (j <= i){
            if (i_copy == 1) break;
            if (i_copy % j == 0){
                i_copy /= j;
                bunbo.push_back(j);
            } else {
                j += 1;
            }
        }
    }
    int bunbo_size = bunbo.size();
    REP(i, 0, bunbo_size){
        int j = bunbo[i];
        REP(i, 0, amari){
            if (bunshi[i] % j == 0){
                bunshi[i] = bunshi[i] / j;
                break;
            }
        }
    }
    ll ans = 1;
    REP(i, 0, amari){
        ans *= bunshi[i];
        ans %= 1000000000;
    }
    cout << ans << endl;
    return 0;
}