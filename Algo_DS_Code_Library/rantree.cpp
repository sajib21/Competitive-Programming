#include<bits/stdc++.h>
#define LIM 200
#define MAX 20
#define MXX 50

using namespace std;

int main() {
    srand(time(NULL));

    freopen("in.txt", "w", stdout);

    int n = rand() % LIM + 2;
    int q = rand() % LIM + 2;
    scanf("%d", &n);
    cout << n << ' ' << q << endl;

    for(int i=2; i<=n; i++) {
        int j = rand() % (i-1) + 1;
        cout << i << ' ' << j << ' ' << rand()%MAX+1 << endl;
    }

    while(q--) {
        int u = rand() % n + 1;
        int w = rand() % (MXX) + 1;

        cout << u << ' ' << w << endl;
    }
}
