#include<bits/stdc++.h>

using namespace std;

struct en {

    int left, right;
} segment[100005];

bool cmp(en a, en b) {

    return a.right > b.right;
}

bool cmp2(en a, en b) {

    return a.left < b.left;
}


int main() {

    int t, m, n;
    bool brk = false, zero;
    scanf("%d", &t);
    for(int T=1; T<=t; T++) {

        if(T != 1) printf("\n");

        brk = false, zero=false;

        scanf("%d", &m);
        int l,r;
        for(n=0; ; ) {

            scanf("%d %d", &l,&r);
            if(!r && !l) {
                //n++;
                break;
            }
            if(r > 0 && l < m) {
                segment[n].left = l; segment[n].right = r;
                n++;
            }
        }
        sort(segment, segment+n, cmp);
//        for(int i=0; i<n; i++) printf("%d %d\n", segment[i].left, segment[i].right);

        vector<en>sol; //sol.push_back(segment[0]);
        r = INT_MAX, l = m;
        int ans = 0, mn = l;

//        if(segment[0].left <= 0) //goto HERE;
//            zero = true;

        for(int i=0; i<n; i++) {
                if(segment[i].right >= r) {
                    if(segment[i].left < l) {
                        l = segment[i].left;
                        sol.pop_back();
                        sol.push_back(segment[i]);
                        mn = l;
                    }
                }
                else if(segment[i].right < l) {
                        brk = true;
                        break;
                }
                else {
                    if(segment[i].left < l) {
                        r = l;
                        l = segment[i].left;
                        ///r = segment[i].right;
                        ans++;
                        sol.push_back(segment[i]);
//                        cout << "dhuklo " << segment[i].left << ' ' << segment[i].right << endl;
                        mn = l;

                    }
                }
//                cout << l << ' ' << r << ' ' << mn << endl;
                if(mn <= 0) break;
        }

        if(!brk) {
            if(mn <= 0) {
                printf("%d\n", ans);
                sort(sol.begin(), sol.end(), cmp2);
                int sz = sol.size();
                for(int i=0; i<sz; i++) printf("%d %d\n", sol[i].left, sol[i].right);
            }
            else printf("0\n");
        }
        else {
            printf("0\n");
        }


    }
    return 0;
}
