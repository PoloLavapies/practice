#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = 1;
    // 全探索の過程で通った点を保持
    int already[N + 1];
    memset(already, 0, sizeof(already));
    already[1] = 1;
    // x回目の移動で行ける行き先の列挙を繰り返す
    vector<int> vec;
    vec.push_back(1);
    while(true){
        // vecにNが含まれていたら終了
        for (int i = 0; i < vec.size(); i++){   
            if (vec[i] == N){
                cout << ans << endl;
                return 0;
            }
        }
        // vecが空なら-1を出力して終了
        if (vec.size() == 0) {
            cout << -1 << endl;
            return 0;
        }

        // vecに含まれる全地点から、新たに行ける全地点をnew_vecに追加
        ans += 1;
        vector<int> new_vec;
        for (int i = 0; i < vec.size(); i++){
            int p = vec[i];
            // ビット表現した時の1の個数を調べる
            int move = 0;
            int tmp = p;
            while (tmp){
                move += tmp & 1;
                tmp = tmp >> 1;
            }
            if (0 < p - move && p - move < N + 1 && already[p - move] == 0){
                new_vec.push_back(p - move);
                already[p - move] = 1;
            }
            if (0 < p + move && p + move< N + 1 && already[p + move] == 0){
                new_vec.push_back(p + move);
                already[p + move] = 1;
            }
        }
        vec = new_vec;
    }
}
