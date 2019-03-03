#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n, cnt=0;
        string fld;
        scanf("%d", &n);
        cin >> fld;
        fld += "##";


        for(int i=0; i<n; i++) {
            if(fld[i] == '.') {
                cnt++;
                fld[i] = fld[i+1] = fld[i+2] = '#';
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }


    return 0;

}
