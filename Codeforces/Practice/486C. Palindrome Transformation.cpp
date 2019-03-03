#include<bits/stdc++.h>
#define baccha hobe na baccha hobe na baccha hobe na jiboneo hobe na likha rakh khatay

using namespace std;

int main() {

    int len, init, an;
    string seq;
    cin >> len >> init;
    init--;
    cin >> seq;

    int mid = len/2;
    int lft = 1000000, rgt = -1000000;
    int i;

    int ans = 0;
    if(init <mid) {
        for(int i=0; i<mid && i <=init; i++) {
            if(seq[i] != seq[len-i-1]) {
                lft = min(lft,i);
                int temp = 26 - max(seq[i], seq[len-i-1]) + min(seq[i], seq[len-i-1]);
                ans += min( abs(seq[i] - seq[len-i-1]), temp );

            }//cout << " a " << ans << endl;
        }
        if(lft == 1000000) lft = init;
        for(int i=mid-1; i> init; i--) {
            if(seq[i] != seq[len-i-1]) {
                rgt = max(rgt, i);
                int temp = 26 - max(seq[i], seq[len-i-1]) + min(seq[i], seq[len-i-1]);
                ans += min( abs(seq[i] - seq[len-i-1]), temp );
            }//cout << " b " << ans << endl;
        }
        if(rgt == -1000000) rgt = init;
        ans += 2*min(rgt-init, init-lft) + max(rgt-init, init-lft);//cout << " total " << ans << endl;
    }

    else{
        for(int i=mid; i<len && i <=init; i++) {
            if(seq[i] != seq[len-i-1]) {
                lft = min(lft,i);
                int temp = 26 - max(seq[i], seq[len-i-1]) + min(seq[i], seq[len-i-1]);
                ans += min( abs(seq[i] - seq[len-i-1]), temp );
            }//cout << seq[i] << ' ' << seq[len-i-1] <<  " a " << ans << endl;
        }
        if(lft == 1000000) lft = init;
        for(int i=len-1; i> init; i--) {
            if(seq[i] != seq[len-i-1]) {
                rgt = max(rgt,i);
                int temp = 26 - max(seq[i], seq[len-i-1]) + min(seq[i], seq[len-i-1]);
                ans += min( abs(seq[i] - seq[len-i-1]), temp );
            }//cout << seq[i] << ' ' << seq[len-i-1] <<  " b " << ans << endl;
        }
        if(rgt == -1000000) rgt = init;
        //cout << lft << init << rgt << endl;
        ans += 2*min(rgt-init, init-lft) + max(rgt-init, init-lft);//
    }
    //printf("%d\n", ans);
    cout << ans << endl;
    return 0;
}
//asdsadlkkjshdkj
