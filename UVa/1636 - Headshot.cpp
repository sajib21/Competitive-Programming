#include<bits/stdc++.h>

using namespace std;

int main() {
    char str[120];
    while(scanf("%s", str) != EOF) {
        int n = strlen(str);
        str[n] = str[0];
        int full=0, emty=0, safe = 0;
        double a,b;
        for(int i=0; i<n; i++) if(str[i] == '1') full++;
        for(int i=0; i<n; i++) {
            if(str[i] == '0' && str[i+1] == '0') safe++;
        }
        emty = n-full;

        a = (1.0*safe/emty);
        b = 1.0*emty/n;

//        cout << "INFO " << full << ' ' << emty << ' ' << safe << ' ' << a << ' ' << b << endl;

        if(a == b) printf("EQUAL\n");
        else if(a > b) printf("SHOOT\n");
        else printf("ROTATE\n");
    }
    return 0;
}
