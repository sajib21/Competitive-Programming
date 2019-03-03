#include<bits/stdc++.h>

using namespace std;

int main() {

    string num;
    cin >> num;
    int sz = num.size();

    int p = 1, ans = 0, i;
    for(i=0; i<sz && num[i] <= '1'; i++){
        num[i] -= '0';
    }
    for( ; i<sz; i++) num[i] = 1;

    for(i=sz-1; i>=0; i--) {
        ans += num[i]*p;
        p *= 2;
    }

    printf("%d\n", ans);

    return 0;
}
