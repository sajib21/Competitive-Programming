#include<bits/stdc++.h>
#define ll long long int
#define LIM 30000000

using namespace std;

int n;
ll ans[LIM+10];

int main() {

    for(int g=1; g<=LIM; g++) {
        for(int a=g+g; a<=LIM; a+=g) {
            int b = a - g;
//                cout << g << ' ' << a << ' ' << b << ' ' << (a^b) << endl;
            if( (a^b) == g) {
//                    cout << "ADD!" << endl; getchar();
                ans[a]++;
            }
        }
    }
    for(int i=1; i<=LIM; i++) ans[i] += ans[i-1];


    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", t, ans[n]);
    }
    return 0;
}
