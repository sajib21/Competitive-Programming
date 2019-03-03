#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<stdio.h>



//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
using namespace std;
#define getcx getchar_unlocked
inline void S( int &n )//fast input function
{
    n=0;
    int ch=getcx();
    int sign=1;
    while( ch < '0' || ch > '9' )
    {
        if(ch=='-')sign=-1;
        ch=getcx();
    }

    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}




int main() {

    int t,T;

    int n,w, i, x;
    int arr[50005];
    int range, mv;

    //scanf("%d", &T);
    S(T);
    for(t=1; t<=T; t++) {

        //scanf("%d %d", &n,&w);
        S(n); S(w);

//        int arr[n+3];

        for(i=0; i<n; i++) {
            //int y;
            //scanf("%*d %d", &arr[i]);
            S(x); S(arr[i]);
        }
        //sort(coY.begin(), coY.end());
        sort(arr, arr+n);

        range = arr[0] + w;
        mv = 1;
        for(i=0; i<n; i++) {
            if(arr[i] > range) {
                range = arr[i] + w;
                mv++;
            }
        }

        printf("Case %d: %d\n", t, mv);
    }

    return 0;
}

