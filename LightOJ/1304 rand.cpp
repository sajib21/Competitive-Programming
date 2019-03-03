#include<bits/stdc++.h>
#define LIM 7

using namespace std;

int main() {
    srand(time(NULL));
    freopen("1304i.txt", "w", stdout);

    int T = 20;
    cout << T << endl;
    while(T--) {
        cout << endl;

        int n = rand() % LIM + 1;
        int m = rand() % LIM + 1;
        cout << m << ' ' << n << endl;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int c = rand() % 100;
                if(c < 40) cout << ".";
                else if(c < 70) cout << "R";
                else cout << "W";
            }
            cout << endl;
        }
    }
}
