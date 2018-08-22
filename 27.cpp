#include <iostream>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define INF 1<<25;
using namespace std;

int calc_min_ita(int* v, int a, int b, int c){
    int dp[31];
    FOR(i, 0, 31){
        dp[i] = INF;
    }
    dp[0] = 0;
    FOR(i, 1, 31){
        int min_i = INF;
        if(i >= a) min_i = min(min_i, 1 + dp[i - a]);
        if(i >= b) min_i = min(min_i, 1 + dp[i - b]);
        if(i >= c) min_i = min(min_i, 1 + dp[i - c]);
        dp[i] = min_i;
    }
    int score = 0;
    FOR(i, 0, 4){
        score += dp[v[i]];
    }
    return score;
}

int main(){
    int v[4];
    FOR(i, 0, 4){
        cin >> v[i];
    }
    int min_ita = INF;
    FOR(a, 1, 31){
        FOR(b, a, 31){
            FOR(c, b, 31){
                min_ita = min(min_ita, calc_min_ita(v, a, b, c));
            }
        }
    }
    cout << min_ita << endl;

    return 0;
}