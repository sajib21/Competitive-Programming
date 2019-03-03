#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int in = 0, a=0, b=0;
        while(in < s.size()) {
            if(s[in] == 'X') {
                a++;
                while(in<s.size() && s[in] == 'X') in++;
            }
            else {
                b++;
                while(in<s.size() && s[in] == 'O') in++;
            }
        }
        if(a >= b) printf("X\n");
        else printf("O\n");
    }
}
