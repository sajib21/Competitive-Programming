#include <bits/stdc++.h>
#define pii pair<int,int>

#define MAX 2000100

using namespace std;

int divCount[1010];
int sorted[1010];

void sieveDiv() {

    for(int i=1; i<=1000; i++) {
        for(int j=i; j<=1000; j+=i) {
            divCount[j]++;
//            sorted[j].d++;
        }
    }
}

bool cmp (int a, int b) {

    if(divCount[a] == divCount[b]) return a > b;
    return divCount[a] < divCount[b];
}


int main()
{
    sieveDiv();

    for(int i=1; i<=1000; i++) sorted[i] = i;
    sort(sorted+1, sorted+1+1000, cmp);
//    for(int i=1; i<=10; i++) cout << sorted[i] << ' '; cout << endl;

    int T,t;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", t, sorted[n]);
    }

    return 0;
}
