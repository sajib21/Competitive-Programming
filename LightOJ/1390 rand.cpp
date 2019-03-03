#include<bits/stdc++.h>
#define LIM 10

using namespace std;

int main() {
    srand(time(NULL));
    freopen("1390i.txt", "w", stdout);

    int T = 20;
    cout << T << endl;
    while(T--) {
        cout << endl;

        int n = rand() % LIM + 1;
        int m = rand() % LIM + 1;
        cout << m << ' ' << n << endl;
        for(int i=0; i<m; i++) {
            cout << rand()%n+1 << ' ' << rand()%n+1 << endl;
        }
    }
}
