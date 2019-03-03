#include<bits/stdc++.h>
#define LIM 1000006
using namespace std;

string text, pattern;
int Z[LIM];

void genZ(string pattern) {
    int n = pattern.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R<n && pattern[R-L] == pattern[R]) R++;
            Z[i] = R-L;
            R--;
        }
        else {
            k = i-L;

            if (Z[k] < R-i+1) Z[i] = Z[k];

            else {
                L = i;
                while (R<n && pattern[R-L] == pattern[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main() {
    cin >> pattern;
    genZ(pattern);

    int a=0,b;
    for(int i=1; i<pattern.size(); i++) {
//        int x = pattern.size() - Z[i];
//        if(Z[i] ) {
            if(Z[i] > a) {
                a = Z[i];
                b = i;
            }
//        }
    }
    if(!a) {
        cout << "Just a legend" << endl;
        return 0;
    }

    for(int i=1; i<pattern.size(); i++) {
        if(i == b) continue;
        if(Z[i] == pattern.size()-i && Z[i] <= a) {
            cout << pattern.substr(i, Z[i]);
            return 0;
        }
    }

    cout << "Just a legend" << endl;

}
