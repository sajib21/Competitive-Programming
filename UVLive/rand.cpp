#include<bits/stdc++.h>
#define LIM 10

using namespace std;

int main() {
    freopen("in.txt", "w", stdout);

    srand(time(NULL));

    int n,m;
    int t = 10;

    while(t--) {
        n = rand() % LIM + 2;
        m = rand() % n + 1;
        cout << n << ' ' << m << endl;

        for(int i=0; i<n; i++) {
            int x = rand() % 3;
            if(x == 0) cout << "R";
            if(x == 1) cout << "P";
            if(x == 2) cout << "S";
        } cout << endl;

        for(int i=0; i<m; i++) {
            int x = rand() % 3;
            if(x == 0) cout << "R";
            if(x == 1) cout << "P";
            if(x == 2) cout << "S";
        } cout << endl;

        cout << endl;
    }
}
