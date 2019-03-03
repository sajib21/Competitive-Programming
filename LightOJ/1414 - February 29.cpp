#include<bits/stdc++.h>

using namespace std;

string ara[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        string mon1, mon2;
        int day1,day2, year1,year2;
        cin >> mon1; scanf("%d, %d", &day1, &year1);
        cin >> mon2; scanf("%d, %d", &day2, &year2);

        if(mon2 == ara[0]) year2--;
        else if(mon2 == ara[1] && day2 < 29) year2--;

        if(mon1 == ara[0]) year1--;
        else if(mon1 == ara[1]) year1--;

        printf("Case %d: %d\n", t, ( year2/4 - year2/100 + year2/400 ) - ( year1/4 - year1/100 + year1/400 )  );
    }

    return 0;

}
