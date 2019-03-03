#include<bits/stdc++.h>
#define LIM 100005

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

void search(string text, string pattern) {
    string concat = pattern + "$" + text;
    int l = concat.length();

    genZ(concat);

    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length())
            cout << "Pattern found at index "
                 << i - pattern.length() -1 << endl;
    }
}

int main() {
    text = "GEEKS FOR GEEKS";
    pattern = "GEEK";

//    genZ();
    search(text, pattern);

//    cout << "Z" << endl;
//    for(int i=0; i<pattern.size(); i++) cout << Z[i] << ' ';
//    cout << endl;

    return 0;
}
