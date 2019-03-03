#include<bits/stdc++.h>
#define LIM 10005
#define ALPH 5

using namespace std;

int main() {
    srand(time(NULL));

    freopen("12191i.txt", "w", stdout);

    int T = 10;
    while(T--) {
        int n = rand() % LIM + 1;
        for(int i=0; i<n; i++) cout << (char) (rand()%ALPH + 'a');
        cout << endl << endl;
    }
    cout << "*" << endl;
}
