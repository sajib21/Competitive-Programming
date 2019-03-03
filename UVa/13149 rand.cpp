#include<bits/stdc++.h>
#define LIM 10

using namespace std;

int n,m, a,b;
string s;

int main() {
    freopen("in.txt", "w", stdout);

    int t = 10;
    cout << t << endl << endl;

    while(t) {
        n = rand() % LIM + 1;
        m = rand() % LIM + 1;

        if(n < 2) continue;

        for(int i=0; i<n; i++) {
            if(rand()%2) cout << "0";
            else cout << "1";
        }
        cout << " " << m << endl;

        a = rand()%(n-1); b = rand()%(n-1);
        if(a > b) swap(a,b);

//        if(a == b) continue;

        cout << a << ' ';
        for(int i=1; i<m; i++) {
            if(rand()%2) cout << "D";
            else cout << "R";
        }
        cout << endl;

        cout << b << ' ';
        for(int i=1; i<m; i++) {
            if(rand()%2) cout << "D";
            else cout << "R";
        }
        cout << endl;

        cout << endl;

        t--;
    }

}
