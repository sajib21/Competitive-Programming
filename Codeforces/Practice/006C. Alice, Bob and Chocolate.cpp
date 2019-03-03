#include<bits/stdc++.h>

using namespace std;

int tim[100005];

int main() {

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &tim[i]);

    int aliceTime = 0, bobTime = 0;
    int aliceEat = 0, bobEat = 0;
    int a=0 ,b=n-1;

    while(a <= b) {

        if(aliceTime <= bobTime) {
            aliceEat++;
            aliceTime += tim[a];
            a++;
        }
        else {
            bobEat++;
            bobTime += tim[b];
            b--;
        }
    }

    cout << aliceEat << ' ' << bobEat << endl;

    return 0;

}
