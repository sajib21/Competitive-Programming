#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,t;
    string seq;
    cin >> n >> t;
    cin >> seq;
    int sz = seq.size();
    for(int i=0; i<t; i++) {
        for(int j=1; j<sz; j++) {
            if(seq[j] == 'G' && seq[j-1] == 'B') {
                swap(seq[j], seq[j-1]);
                j++;
            }
        }
    }

    cout << seq << endl;

    return 0;
}
