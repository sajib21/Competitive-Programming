#include<bits/stdc++.h>
#define LIM 20
#define MAX 30
#define ll long long int

using namespace std;

int main() {
    srand(time(NULL));

    freopen("1411i.txt", "w", stdout);

    int T = 100;
    cout << T << endl << endl;

    while(T--) {
        cout << LIM << endl;
        ll n = LIM, m = LIM;
        while(m--) {
            char s[4]; int st,ed,v;
            int tmp = rand() % 5;
            st = rand() % LIM + 1;
            ed = min(LIM, rand() % LIM + st);
            v = rand() % MAX;
            if(rand()%2) v = -v;

            if(tmp == 0) cout << "C " << st << ' ' << ed << ' ' << v << endl;
            else if(tmp == 1) cout << "A " << st << ' ' << ed << endl;
            else if(tmp == 2) cout << "B " << st << ' ' << ed << endl;
            else              cout << "S " << st << ' ' << ed << endl;


        }
    }
}

