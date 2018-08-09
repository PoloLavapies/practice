#include <iostream>
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define ll long long int
using namespace std;

// 交差点の始点で待つ時間を求める
// ansは始点に到着した時点での経過時間
int solve(int ans, int x, int w, int t){
    int wait;
    // 信号が変わった回数
    int turn = ans / t;
    if (turn % 2 == 1) {
        return (turn + 1) * t - ans;
    } else {
        // 信号が変わるまでの残り時間
        int nokori = (turn + 1) * t - ans;
        if (nokori >= w) return 0;
        else return nokori + t;
    }
}

int main(){
    int n, l;
    cin >> n >> l;
    ll ans = 0;
    int now = 0;
    REP(i, 0, n){
        int x, w, t;
        cin >> x >> w >> t;
        // 交差点の始点まで移動
        ans += (x - now);
        now = x;
        // 交差点の始点で待つ時間を加算
        ans += solve(ans, x, w, t);
    }
    ans += (l - now);

    cout << ans << endl;
    return 0;
}