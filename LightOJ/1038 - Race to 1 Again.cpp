#include<bits/stdc++.h>

using namespace std;

bool prime[100005] = {false};
double expct[100005];
int divCount[100005];

void sievePrime() {

    prime[1] = true;

    for(int i=4; i<=100000; i+=2) {
        prime[i] = true;
    }
    int lim = sqrt(100005);
    for(int i=3; i<=lim; i+=2) if(!prime[i]) {
        for(int j=i+i; j<=100000; j+=i) {
            prime[j] = true;
        }
    }

    //cout << "prime no prob" << endl;
}

void divExp() {

    for(int i=2; i<100005; i++) {
        //cout << i << endl;
        if(!prime[i]) {
            expct[i] = 2.0;
        }
        else {
            expct[i] = 1.0*(expct[i]+divCount[i]+2)/(divCount[i]+1);
        }

        for(int j=i+i; j<100005; j+=i) {
            expct[j] += expct[i];
            divCount[j]++;
        }
    }
}

int main() {

    sievePrime();
    divExp();

    int t,T;
    //cin >> T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        int n;
        //cin >> n;
        scanf("%d", &n);

        printf("Case %d: %.10lf\n", t, expct[n]);
    }

    return 0;

}
