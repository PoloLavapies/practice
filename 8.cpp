#include <iostream>
#define REP(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;

void solve(int N, int K) {
    if ((N - 1) % (K + 1) == 0){
        cout << "Lose" << endl;
    } else {
        cout << "Win" << endl;
    }
}

int main() {
    int P;
    cin >> P;
    int N[P], K[P];
    REP(i, 0 ,P){
        cin >> N[i] >> K[i];
    }
    REP(i, 0, P){
        solve(N[i], K[i]);
    }

    return 0;
}