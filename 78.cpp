#include <iostream>
typedef long long int ll;
using namespace std;

ll n, k;
int cost = 0;
int stock = 0;
char box[50];

void buy_box(){
    for (int i = 0; i < n; i++){
        int ice = box[i];
        if (stock > 0){
            stock -= 1;
        } else {
            cost += 1;
        }
        if (ice == 2){
            stock += 2;
        } else if (ice == 1){
            stock += 1;
        } 
    }
}

int buy(int rest){
    int cost_rest = 0;
    for (int i = 0; i < rest; i++){
        int ice = box[i];
        if (stock > 0){
            stock -= 1;
        } else {
            cost_rest += 1;
        }
        if (ice == 2){
            stock += 2;
        } else if (ice == 1){
            stock += 1;
        } 
    }
    return cost_rest;
}

int main(){
    cin >> n >> k;
    string ices;
    cin >> ices;
    for (int i = 0; i < n; i++){
        int ice = ices[i] - '0';
        box[i] = ice;
    }
    if (n > k){
        cout << buy(k) << endl;    
        return 0;
    }
    buy_box();
    if (cost <= stock){
        cout << cost << endl;
    } else {
        int cost_sum = cost;
        cost_sum += (k / n - 1) * (cost - stock);
        cost_sum += buy(k % n);
        cout << cost_sum << endl;
    }
    
    return 0;
}