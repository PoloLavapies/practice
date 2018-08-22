#include <iostream>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;

int main(){
    int life, normal, special;
    cin >> life >> normal >> special;

    float dp[life + 1];
    dp[0] = 0;

    FOR(i, 1, life + 1){
        // aは通常技を使う際の残り攻撃回数,bは必殺技を使うときの残り攻撃回数
        float a, b;
        if (i < normal) a = 1;
        else a = 1 + dp[i - normal];
        if (i < special) b = 1.5;
        else b = 1.5 + dp[i - special];
        dp[i] = min(a, b);
    }
    cout << dp[life] << endl;

    return 0;
}