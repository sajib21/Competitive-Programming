#include<bits/stdc++.h>
#define MAX 100

using namespace std;

char ch[] = {'A',  'C' , 'G', 'T' };

int main() {
    srand(time(NULL));
    freopen("11512i.txt", "w", stdout);
    int T = 100;
    cout << T << endl;
    while(T--) {
        int n = rand() % MAX;
        for(int i=0; i<n; i++) cout << ch[rand()%4];
        cout << endl;
    }
}
