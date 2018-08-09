#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define p_int pair<int, int>
using namespace std;

int main(){
    // 街の数、コスト上限、道の数
    int city_n, c_max, load_n;
    cin >> city_n >> c_max >> load_n;
    // 始点、終点、コスト、時間
    int s[load_n], t[load_n], c[load_n], time[load_n];
    REP(i, 0, load_n) cin >> s[i];
    REP(i, 0, load_n) cin >> t[i];
    REP(i, 0, load_n) cin >> c[i];
    REP(i, 0, load_n) cin >> time[i];

    // 現在地を縦軸、使った費用を横軸に取ってDP
    int dp[city_n + 1][c_max + 1];
    REP(i, 0, city_n + 1){
        REP(j, 0, c_max + 1){
            dp[i][j] = INT_MAX;
        }
    }
    dp[1][0] = 0;
    REP(i, 1, city_n) {
        REP(j, 0, c_max) {
          if (dp[i][j] == INT_MAX) continue;
          // i番の都市を始点とする辺を調べる
          REP(k, 0, load_n){
            if (i == s[k] && j + c[k] <= c_max){
              dp[t[k]][j + c[k]] = min(dp[t[k]][j + c[k]], dp[i][j] + time[k]);
            }
          }
        }
    }

    // dp[city_n][i]における最小値を返す
    int ans = INT_MAX;
    REP(i, 0, c_max + 1){
        ans = min(ans, dp[city_n][i]);
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
