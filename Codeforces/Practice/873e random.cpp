#include<bits/stdc++.h>
#define lim 15
#define mx  15

using namespace std;

int main() {

    srand(time(NULL));

    int n = rand() % lim;
    cout << n << endl;

    int last = 0;

    while(n) {
        int x = rand() % mx;
//        if(x >= last) {
            cout << x << ' ';
            last = x;
            n--;
//        }
    }
    cout << endl;
}
