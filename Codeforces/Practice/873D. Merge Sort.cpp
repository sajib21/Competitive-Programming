#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,k;
vi sol;

void f(int i, int j) {
//    cout << "IN " << k << endl;
//    for(int p=i; p<=j; p++) cout << p << ' '; cout << endl;
//    getchar();
    if(k == 0 || i==j) {
        while(i <= j) sol.pb(i++);
        return;
    }
    int m = (i+j)/2;
    k -= 2;
    f(m+1,j);
    f(i,m);
}

int main() {
    scanf("%d %d", &n,&k);
    if(k%2==0) {
        cout << -1 << endl;
        return 0;
    }

    k--;
    f(1, n);

    if(k != 0) cout << -1 << endl;
    else {
        bool ff = false;
        for(int i=0; i<sol.size(); i++) {
            if(ff) printf(" ");
            ff = true;
            printf("%d", sol[i]);
        }
        printf("\n");
    }
}
