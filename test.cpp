#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> st{3, 1, 4};
    auto itr = st.find(4);
    cout << itr << endl;

    return 0;
}
