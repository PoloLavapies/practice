#include <iostream>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;
const int INF = 1<<27;

int N, M;
int stay_cost[50];
int from, to, cost;
int wf[50][50];

int main(){
    cin >> N;
    FOR(i, 0, N){
        cin >> stay_cost[i]; 
    }
    cin >> M;
    // Warshall–Floyd
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if (i == j) wf[i][j] = 0;
            else wf[i][j] = INF;
        }
    }
    FOR(i, 0, M){
        cin >> from >> to >> cost; 
        // 無向グラフ
        wf[from][to] = cost;
        wf[to][from] = cost;
    }
    FOR(i, 0, N) FOR(f, 0, N) FOR(t, 0, N) wf[f][t] = min(wf[f][t], wf[f][i] + wf[i][t]);

    // 全探索
    int ans = INF;
    FOR(i, 1, N - 1){
        FOR(j, 1, N - 1){
            if (i == j) continue;
            ans = min(ans, wf[0][i] + stay_cost[i] + wf[i][j] + stay_cost[j] + wf[j][N-1]);
        }
    }

    cout << ans << endl;
}
