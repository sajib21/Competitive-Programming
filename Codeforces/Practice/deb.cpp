#include<bits/stdc++.h>
#define LIM 200000

using namespace std;

string seq, code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
//    cout << code.size() << endl;
    srand(time(NULL));

    freopen("test.txt", "w", stdout);

    int n,m = 1;

    cout << LIM << ' ' << 1 << endl;
    for(int i=0; i<LIM; i++) {
        cout << code[ rand()%62 ] ;
    }
    cout << endl;

    cout << 1 << ' ' << LIM << ' ' << code[ rand()%62 ] << endl;
}
