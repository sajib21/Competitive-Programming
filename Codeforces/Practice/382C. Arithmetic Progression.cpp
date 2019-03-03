#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, num[100005], dif;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &num[i]);

    if(n==1) {
        printf("-1\n");
        return 0;
    }

    sort(num, num+n);

    int d1 = min(num[1]-num[0], num[n-1]-num[n-2]), d1cnt=0, d2=1000000000, d2cnt;
    bool con = false;
    int vitor = -1;

    for(int i=1; i<n; i++) {
        dif = num[i]-num[i-1];
        if(dif == d1) {

        }
        else if(dif == 2*d1) {
            if(con == false) {
                con = true;
                vitor = i;
            }
            else {
                printf("0\n");
                return 0;
            }
        }
        else {
            printf("0\n");
            return 0;
        }

//        if(!dif) {
//            if(n==2) printf("1\n%d\n", num[i]);
//            else printf("0\n");
//        }
    }

    if(con == true) {
        printf("1\n%d\n", num[vitor]-d1);
        return 0;
    }

    vector<int>ans;
    ans.push_back(num[0]-d1);

    if(n==2) {
        if(d1%2) {

        }
        else {
            if(d1) {
                ans.push_back(num[0] + d1/2);
            }
        }
    }

    if(d1) {
        ans.push_back(num[n-1]+d1);
    }

    int sz=ans.size();
    printf("%d\n%d", sz, ans[0]);
    for(int i=1; i<sz; i++) printf(" %d", ans[i]);
    printf("\n");

    return 0;


}
