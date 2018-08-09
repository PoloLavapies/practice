#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <cmath>
#define REP(i,a,b) for(int i=(a); i<(b); i++)
using namespace std;

const double pi = 3.141592653589793;

void kakudo(double x, double y){
    // 逆三角関数
    double kakudo = atan2(y, x);
    //cout << setprecision(10) << kakudo * 180 / pi << endl;
    printf("%.10f\n", kakudo * 180 / pi);
}

int main(){
    int t;
    cin >> t;
    double x[t], y[t];
    REP(i ,0, t){
        double x_tmp, y_tmp;
        double sin55 = sin(pi * 55 / 180);
        double cos55 = cos(pi * 55 / 180);
        double sinm5 = sin(pi * (-5) / 180);
        REP(j, 0, 6){
            cin >> x_tmp >> y_tmp;
            // もともと(0,1)にあった点についてのみ考える
            // 第1象限にある点。2つある場合は、yが小さい方
            if (sinm5 < y_tmp && y_tmp < sin55 && cos55 < x_tmp && x_tmp < 1){
                x[i] = x_tmp;
                y[i] = y_tmp;
            }
        }
    }
    REP(i, 0, t){
        kakudo(x[i], y[i]);
    }

    return 0;
}