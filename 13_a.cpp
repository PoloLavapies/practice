// 参考:http://mmxsrup.hatenablog.com/entry/2016/09/01/164211Ú

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int w, h;
int b[110][110]; //もとの行列を保持
bool d[110][110]; //一度調べた部分を記録
int used[110][110];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool flag = false;

// pyとpxは戻ることになる向き
void dfs(int y, int x, int py, int px, int num){
    d[y][x] = true; used[y][x] = 1;
    rep(i, 4){
        int nowy = y + dy[i], nowx = x + dx[i];
        if(nowy < 0 || h <= nowy || nowx < 0 || w <= nowx) continue; //枠をはみ出る
        if(nowy == py && nowx == px) continue; //戻るの禁止
        if(b[nowy][nowx] != num) continue; //同じ数字ではない
        // すでに通った場所ならflagをtureに(閉路が存在するということ)
        if(used[nowy][nowx]){
            flag = true;
            return;
        }
        dfs(nowy, nowx, y, x, num);
    }
    return;
}

int main(void){
    cin >> w >> h;
    rep(i, h)rep(j, w) cin >> b[i][j];
    rep(i, h)rep(j, w){
        // 一度調べた場合continue
        if(d[i][j]) continue;
        // usedを初期化
        rep(a, 110)rep(b, 110) used[a][b] = 0;
        dfs(i, j, -1, -1, b[i][j]);
    }
    if(flag) printf("possible\n");
    else printf("impossible\n");
    return 0;
}