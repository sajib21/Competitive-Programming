#include<bits/stdc++.h>
#define LIM 1000
#define MAX 500000
#define MX 500

using namespace std;

//#define new new

int main() {
    srand(time(NULL));

    freopen("1336i.txt", "w", stdout);

    int T = 20;
    while(T--) {
        int n,v,x;
        n = rand() % LIM + 1;
        v = rand() % 100 + 1;
        x = rand() % MAX + 1;

        cout << n << ' ' << v << ' ' << x << endl;

        bool flag[MAX+100] = {0};
        flag[x] = 1;

        for(int i=0; i<n; ) {
            int pos = rand() % MAX + 1;
            if(flag[pos]) continue;
            cout << pos << ' ' << rand() % MX + 1 << ' ' << rand() % MX + 1 << endl;
            flag[pos] = 1;
            ++i;
        }

        cout << endl;
    }
    cout << "0 0 0" << endl;
}
