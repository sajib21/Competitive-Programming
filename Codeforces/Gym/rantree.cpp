#include<bits/stdc++.h>
#define ll long long int

#define LIM 2000
//#define MAX 1000000000
//#define MXX 100000000000000LL
#define MAX 1000000000
#define MXX 100000000000000LL

using namespace std;

int main() {
    srand(time(NULL));

    freopen("in.txt", "w", stdout);

    int n = rand() % LIM + 2;
    int q = rand() % LIM + 2;
//    scanf("%d", &n);
    cout << n << ' ' << q << endl;

    for(int i=2; i<=n; i++) {
        int j = rand() % (i-1) + 1;
        cout << i << ' ' << j << ' ' << (1LL*rand()*rand()*rand())%MAX+1 << endl;
    }

    while(q--) {
        int u = rand() % n + 1;
        ll w;
        int temp = rand()%4;
        if(temp==0)      w = (1LL*rand()*rand()*rand()*rand()) % (MXX) + 1;
        else if(temp==1) w = (1LL*rand()*rand()*rand()) % (MXX) + 1;
        else if(temp==2) w = (1LL*rand()*rand()) % (MXX) + 1;
        else if(temp==3) w = (1LL*rand()) % (MXX) + 1;


        cout << u << ' ' << w << endl;
    }
}
