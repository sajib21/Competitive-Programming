#include<bits/stdc++.h>

using namespace std;

int n,a;
set<int>Y;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        Y.insert(a);
    }

    while(true) {
        int cur = *Y.rbegin();
        cur /= 2;
        while(cur && Y.find(cur) != Y.end()) cur /= 2;
        if(!cur) break;

        Y.erase( (--Y.end()) );
        Y.insert(cur);
    }

    for(auto it : Y) {
        printf("%d ", it);
    }
    cout << endl;
}
