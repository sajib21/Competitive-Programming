#include<bits/stdc++.h>

using namespace std;

int main() {

    string seq;
    cin >> seq;
    int sz = seq.size();

    vector<int> l,r;

    for(int i=0; i<sz; i++) {
        if(seq[i] == 'l') {
            l.push_back(i+1);
        }
        else {
            r.push_back(i+1);
        }
    }

    int sr = r.size(), sl = sz-sr;

    for(int i=0; i<sr; i++) printf("%d\n", r[i]);
    for(int i=sl-1; i>=0; i--) printf("%d\n", l[i]);

    return 0;
}
