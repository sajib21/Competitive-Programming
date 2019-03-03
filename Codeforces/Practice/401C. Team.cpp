#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    string num;
    //cin >> n >> m;
    scanf("%d %d", &n, &m);

    if(m < n-1 || m > 2*(n+1)) {cout << "-1" << endl; return 0; }

    if(m == n-1) {//num = num + "0", n--;
        printf("0");
        n--;
    }

    if(m > n) {
        int p = min(m-n, n);
        m -= 2*p;
        n -= p;
        while(p-- > 0) //num = num + "110";
            printf("110");
    }
    //cout << n << ' ' << m << endl;
    while(m > 0 || n > 0) {
        if(m-- > 0) //num = num + "1";
            printf("1");
        if(n-- > 0) //num = num + "0";
            printf("0");
    }
    printf("\n");
    //cout << num << endl;

    return 0;

}
