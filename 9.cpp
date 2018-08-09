#include <iostream>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define max_int 2147483647;
using namespace std;

int N;
// a[i]は自分のレベル*2000+戦闘回数 b[i]は相手のレベル
// t[i]はループのたびa[i]をコピー
int a[1500], b[1500], t[1500];

// 次に先頭に出すモンスターを選ぶ
int which_next_battle(){
    int min = max_int;
    int next_battle = 0;
    FOR(i, 0, N){
        if (t[i] < min){
            min = t[i];
            next_battle = i;
        }
    }
    return next_battle;
}


int max_battle_from_i(int i){
    int max_battle_count = 0;
    FOR(j, 0, N){
        int next_battle = which_next_battle();
        int enemy = b[(j + i) % N];
        t[next_battle] += (enemy / 2) * 2000 + 1;
        max_battle_count = max(max_battle_count, t[next_battle] % 2000);
    }
    return max_battle_count;
}

int main() {
    cin >> N;
    FOR(i, 0, N){
        int tmp;
        cin >> tmp;
        a[i] = tmp * 2000;
    }
    FOR(i, 0, N){
        cin >> b[i];
    }

    int min_max_battle = max_int;
    // i番目から戦闘開始
    FOR(i, 0, N){
        FOR(i, 0, N){
            t[i] = a[i];
        }
        int max_battle = max_battle_from_i(i);
        min_max_battle = min(min_max_battle, max_battle);
    }
    cout << min_max_battle << endl;
}