#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        string num;
        int sum = 0, cnt[12] = {0};

        cin >> num;
        int sz = num.size();
        for(int i=0; i<sz; i++) {
            sum += num[i] - '0';
            cnt[ num[i] - '0' ]++;
        }
        int multiples = (cnt[3]+cnt[6]+cnt[9]);

        if(sum % 3 == 0) {
            if( multiples % 2 == 0 ) printf("Case %d: T\n", t);
            else printf("Case %d: S\n", t);
        }
        else if(sum % 3 == 1) {
            if(cnt[1] || cnt[4] || cnt[7]) {
                if(multiples % 2 == 1) printf("Case %d: T\n", t);
                else printf("Case %d: S\n", t);
            }
            else printf("Case %d: T\n", t);
        }
        else {
            if(cnt[2] || cnt[5] || cnt[8]) {
                if(multiples % 2 == 1) printf("Case %d: T\n", t);
                else printf("Case %d: S\n", t);
            }
            else printf("Case %d: T\n", t);
        }
    }

    return 0;
}
