#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define P pair<int, int>
#define INF 1<<27
using namespace std;

int N, life, ox, oy;
int map[250][250];
int cost[250][250];
int cost_oasis[250][250];

void dijkstra(){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    fill(cost[0], cost[200], INF);
    cost[0][0] = 0;
    // (最短距離, x + 300y)
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, 0));
    while (!(q.empty())){
        P top = q.top();
        q.pop();
        // 四方向を見る。更新できる場所があればpriority queueに追加する。
        int x, y;
        x = top.second % 300;
        y = top.second / 300;
        // 最短距離が更新されていた場合
        if (cost[x][y] < top.first) continue;
        FOR(i, 0, 4){
            int tmpx, tmpy;
            tmpx = x + dx[i];
            tmpy = y + dy[i];
            if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N) continue;
            if (cost[x][y] + map[tmpx][tmpy] < cost[tmpx][tmpy]){
                cost[tmpx][tmpy] = cost[x][y] + map[tmpx][tmpy];
                q.push(P(cost[tmpx][tmpy], tmpx + tmpy * 300));
            }
        }
    }
}

void dijkstra_oasis(){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    fill(cost_oasis[0], cost_oasis[200], INF);
    cost_oasis[ox][oy] = 0;
    // (最短距離, x + 300y)
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, ox + oy * 300));
    while (!(q.empty())){
        P top = q.top();
        q.pop();
        // 四方向を見る。更新できる場所があればpriority queueに追加する。
        int x, y;
        x = top.second % 300;
        y = top.second / 300;
        // 最短距離が更新されていた場合
        if (cost_oasis[x][y] < top.first) continue;
        FOR(i, 0, 4){
            int tmpx, tmpy;
            tmpx = x + dx[i];
            tmpy = y + dy[i];
            if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N) continue;
            if (cost_oasis[x][y] + map[tmpx][tmpy] < cost_oasis[tmpx][tmpy]){
                cost_oasis[tmpx][tmpy] = cost_oasis[x][y] + map[tmpx][tmpy];
                q.push(P(cost_oasis[tmpx][tmpy], tmpx + tmpy * 300));
            }
        }
    }
}

bool possible(){
    if (cost[N-1][N-1] < life) return true;
    if (ox == 0 && oy == 0){
        return false;
    }
    if (cost[ox][oy] >= life) return false;
    int new_life = (life - cost[ox][oy]) * 2;
    if (cost_oasis[N-1][N-1] < new_life) return true;
    return false;
}

int main(){
    cin >> N >> life >> oy >> ox;
    // 0オリジンにする
    if (!(ox == 0 && oy == 0)){
        ox -= 1;
        oy -= 1;
    } 
    FOR(i, 0, N){
        FOR(j, 0, N){
            cin >> map[i][j];
        }
    }
    dijkstra();
    if (!(ox == 0 && oy == 0)){
        dijkstra_oasis();
    }

    if (possible()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}