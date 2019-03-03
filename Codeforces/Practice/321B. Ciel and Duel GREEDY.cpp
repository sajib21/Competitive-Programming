#include<bits/stdc++.h>
#define LIM 110

using namespace std;

char seq[10];
int n,m, a,d, ja[LIM], jd[LIM], ca[LIM], mark[LIM];

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%s %d", &seq, &x);
        if(seq[0] == 'A') ja[a++] = x;
        else jd[d++] = x;
    }
    for(int i=0; i<m; i++) scanf("%d", &ca[i]);

    sort(ja, ja+a);
    sort(jd, jd+d);
    sort(ca, ca+m);

    int ans = 0, temp = 0;

    int i=0, j=m-1;

    while(i < a && j >= 0) {
        if(ja[i] <= ca[j]) {
            temp += ca[j] - ja[i];
            i++; j--;
        }
        else break;
    }
    ans = max(ans, temp);

//    cout << "FIR " << ans << endl;

    temp = 0;

    i=0,j=0;
    while(i < m && j < d) {
        if(jd[j] < ca[i]) {
            mark[i] = 1;
            i++; j++;
        }
        else i++;
    }

    if(j == d) {

        i=0; j=0;
        while(i < a && j < m) {
            if(mark[j]) j++;
            else if(ja[i] <= ca[j]) {
                temp += ca[j] - ja[i];
                mark[j] = 1;
                i++; j++;
            }
            else j++;
        }

        if(i == a) {
            j = 0;
            while(j < m) {
                if(mark[j]) j++;
                else {
                    temp += ca[j];
                    j++;
                }
            }

        }

//        while(j >= 0) {
//            if(!mark[j]) temp += ca[j];
//            j--;
//        }

        ans = max(ans, temp);

    }

    printf("%d\n", ans);
}
