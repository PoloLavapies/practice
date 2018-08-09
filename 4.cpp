#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int weight[n];
    int sum_weight = 0;
    for (int i = 0; i < n; i++){
        cin >> weight[i];
        sum_weight += weight[i];
    }
    
    if (sum_weight % 2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    int half_weight = sum_weight / 2;

    // 重さjを作れるか
    int dp[half_weight + 1];
    memset(dp, 0, sizeof(dp));
    int dp_tmp[half_weight + 1];
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        memset(dp_tmp, 0, sizeof(dp));
        int w = weight[i];
        for (int j = half_weight; j >= w; j--){
            dp[j] |= dp[j - w];
        }
    }
    if (dp[half_weight] == 1){
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}