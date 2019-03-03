#include<bits/stdc++.h>
#define LIM 1000006

using namespace std;

int n, a[LIM], v[LIM];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n); reverse(a, a+n);

//    for(int i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

    int i=0, j=n/2, ans=0;
    while(j < n) {
//        cout << i << ' ' << j  << ' ' << ans << endl;

        if(v[i]) i++;
        else if(v[j])j++;
        else if(a[i] >= 2*a[j]) {
//            ans++;
            v[j] = 1;
            i++; j++;
        }
        else j++;
    }

    for(int k=0; k<n; k++) if(!v[k]) ans++;

    cout << ans << endl;
}
