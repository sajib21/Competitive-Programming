#include<bits/stdc++.h>

using namespace std;

map<string,int>day,mon, cnt;

int main() {
    day["SUN"] = 1; day["MON"] = 2; day["TUE"] = 3;
    day["WED"] = 4; day["THU"] = 5; day["FRI"] = 6; day["SAT"] = 7;

    mon["JAN"] = 31; mon["FEB"] = 28; mon["MAR"] = 31; mon["APR"] = 30;
    mon["MAY"] = 31; mon["JUN"] = 30; mon["JUL"] = 31; mon["AUG"] = 31;
    mon["SEP"] = 30; mon["OCT"] = 31; mon["NOV"] = 30; mon["DEC"] = 31;

    int T;
    scanf("%d", &T);
    while(T--) {
        string ms, ds;
        cin >> ms >> ds;
        int d = day[ds]-1, m = mon[ms]-1, c = mon[ms];

        int ans = 0;
        for(int k=0; k<c; k++, d++) {
            d %= 7;
            if(d > 4) ans++;
        }
        printf("%d\n", ans);
    }

}
