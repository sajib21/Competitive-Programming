#include<bits/stdc++.h>
#define LIM 1
#define MAX 1000000

using namespace std;

int main() {
    srand(time(NULL));

    freopen("aqi.txt", "w", stdout);

    int n = LIM;
    cout << n << endl;

    for(int i=0; i<n; i++) {
        cout << (rand()*rand())%MAX + 1 << ' ' << (rand()*rand())%MAX + 1 << endl;
    }
}
