#include <bits/stdc++.h>

using namespace std;

int rep[40];
int rnk[40];

int represent(int ch) {
    if(rep[ch] == ch) return rep[ch];
    else return rep[ch] = represent(rep[ch]);
}

void uni(int a, int b) {
    int pa = represent(a), pb = represent(b);
    if(rnk[pa] >= rnk[pb]) {
        rep[pb] = pa;
        if(rnk[pa] == rnk[pb]) rnk[pa]++;
    }
    else {
        rep[pa] = pb;
    }
}

int main() {
    int t;
    cin >> t;
    getchar(); getchar();

    for(int q = 0; q<t; q++) {
        int f = 1;
        char l = getchar(); getchar();
        int last = l - 'A' + 1;
        for(int i = 0; i<last; i++) {
            rep[i] = i;
            rnk[i] = 0;
        }

        string ed;
        while(getline(cin, ed) && !ed.empty()) {

            int x = ed[0] - 'A', y = ed[1] - 'A';
            //cout << "bug" << endl;
            if(represent(x) != represent(y)) {
                uni(x, y);
                last--;
            }
        }

        if(q) cout << "\n";
        cout << last << endl;
    }

    return 0;
}
