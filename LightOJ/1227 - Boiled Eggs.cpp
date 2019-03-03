#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
//freopen("output.txt","w",stdout);
    int test;

    cin>>test;

    for(int t=1; t<=test; t++) {
        int n,p,q;

        cin>>n>>p>>q;
        int arr[n+10];
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        int cont=0;
        int sum=0;
        for(int i=0; i<min(p,n); i++) {
            if(sum+arr[i]>q)
                break;
            sum=sum+arr[i];


            cont++;
        }
        printf("Case %d: %d\n",t,cont);


    }
    return 0;
}
