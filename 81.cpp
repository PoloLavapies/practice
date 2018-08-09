#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    ll sum_ll = 0;
    ll sum_double = 0;
    string a;

    for (int i = 0; i < N; i++) {
        cin >> a;
        int minus = a.find("-");
        // 正の数の場合
        if (minus == string::npos){
            int comma = a.find(".");
            // 小数の場合
            if (comma == string::npos) {
                sum_ll += stoll(a);
            // 整数の場合
            } else {
                sum_ll += stoll(a.substr(0, comma));
                string a_double = a.substr(comma + 1);
                for (int j = a_double.length(); j < 10; j++) {
                    a_double += "0";
                }
                sum_double += stoll(a_double);
            }
        // 負の数の場合
        } else {
            a = a.substr(1);
            int comma = a.find(".");
            // 小数の場合
            if (comma == string::npos) {
                sum_ll -= stoll(a);
            // 整数の場合
            } else {
                sum_ll -= stoll(a.substr(0, comma));
                string a_double = a.substr(comma + 1);
                for (int j = a_double.length(); j < 10; j++) {
                    a_double += "0";
                }
                sum_double -= stoll(a_double);
            }
        }
    }
    
    /*
    cout << sum_ll << endl;
    cout << sum_double << endl;
    */
    
    // 整数部分、小数部分について、0以上か以下で4パターンに場合分け
    string sum_double_str = to_string(sum_double);
    if (sum_ll == 0 && sum_double >= 0 ){
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            sum_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
        }
    } else if (sum_ll == 0 && sum_double < 0 ){
        sum_double_str = sum_double_str.substr(1);
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            ll sum_double_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_ll =  -sum_double_ll;
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
        } else {
            sum_ll = 0;
            cout << "-";
        }
    } else if (sum_ll > 0 && sum_double >= 0 ){
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            ll sum_double_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_ll += sum_double_ll;
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
        }
    } else if (sum_ll > 0 && sum_double < 0) {
        sum_double_str = sum_double_str.substr(1);
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            ll sum_double_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_ll -= sum_double_ll;
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
            if (sum_double_str != "0000000000") {
                sum_ll -= 1;
                sum_double_str = to_string(10000000000 - stoll(sum_double_str));
            }
        } else {
            sum_ll -= 1;
            sum_double_str = to_string(10000000000 - sum_double);
        }
    } else if (sum_ll < 0 && sum_double >= 0 ) {
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            ll sum_double_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_ll += sum_double_ll;
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
            if (sum_double_str != "0000000000") {
                sum_ll += 1;
                sum_double_str = to_string(10000000000 - stoll(sum_double_str));
            }
        } else {
            if (sum_double_str != "0") {
                sum_ll += 1;
                sum_double_str = to_string(10000000000 - sum_double);
            }
        }
    } else if (sum_ll < 0 && sum_double < 0 ) {
        sum_double_str = sum_double_str.substr(1);
        int sum_double_str_len = sum_double_str.length();
        if (sum_double_str_len > 10){
            ll sum_double_ll = stoll(sum_double_str.substr(0, sum_double_str_len - 10));
            sum_ll -= sum_double_ll;
            sum_double_str = sum_double_str.substr(sum_double_str_len - 10);
        }
    }
    for (int j = sum_double_str.length(); j < 10; j++) {
        sum_double_str = "0" + sum_double_str;
    }

    cout << sum_ll << "." << sum_double_str << endl;

    return 0;
}