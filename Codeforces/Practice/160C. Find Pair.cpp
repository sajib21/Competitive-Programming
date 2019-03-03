#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n, a[LIM];
long long k;
map<int,int>koyta;

int main() {
    scanf("%d %lld", &n, &k); k--;
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        koyta[ a[i] ]++;
    }
    sort(a, a+n);
//    unique(a, a+n);
//    for(int i=0; i<n; i++) printf("%d ", a[i]); cout << endl;

    for(auto it : koyta) {
        int x = it.first, y = it.second;
        if(k < 1LL*n*y) {
            for(int i=0; ; i++) {
                if(k < y) {
                    printf("%d %d\n", x, a[i]);
                    return 0;
                }
                else k -= y;
            }
        }
        else k -= 1LL*n*y;
    }

}

