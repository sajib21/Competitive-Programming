#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

ll palCnt[20], palCumCnt[20];
string a,b;

ll sz1, sz2, cnt1, cnt2;

int palCount(string num) {

//    cout << num << endl;

    int sz = num.size();
    int i = 0 , j = sz - 1;
    int cnt = 0;
    cnt += palCumCnt[sz-1];
//    cout << "INT " << cnt << endl;

    bool vitore = false;
    bool boro = false;
    while(i <= j) {
//        cout << "NOW " << i << ' ' << j << ' ' << num[i] << endl;
        if(i == j) {
            cnt += num[i] - '0';
            if(boro) cnt++;
            break;
        }
        if(j-i+1 >= 2) {
            if(vitore) cnt += max(0, num[i] - '0') * palCnt[j-i+1 - 2];
            else cnt += max(0, num[i] - '1') * palCnt[j-i+1 - 2];
//            cout << cnt << endl;
        }
//        if(num[j] <= num[i]) break;
//        if(num[j] > num[i]) {
//            cnt += palCnt[j-i+1 - 2];
//             cout << cnt << endl;
//            break;
//        }
        boro = num[i] < num[j];
        vitore = true;
        i++; j--;
    }
//    cout << "RET " << cnt << endl;
    return cnt;
}

int main() {

    palCnt[0] = 1; palCnt[1] = palCnt[2] = 10;
    palCumCnt[0] = 0; palCumCnt[1] = 9, palCumCnt[2] = 18;
    for(int i=3; i<18; i++) palCnt[i] = 10*palCnt[i-2];
    for(int i=3; i<18; i++) palCumCnt[i] = palCumCnt[i-1] + palCnt[i] - palCnt[i-2];
//    for(int i=1; i<18; i++) cout << palCnt[i] << ' ' ; cout << endl;
//    for(int i=1; i<18; i++) cout << palCumCnt[i] << ' ' ; cout << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int i,j;
        cin >> a >> b;
//        if(a == )
        sz1 = a.size(); sz2 = b.size();
        if(a > b) swap(a,b);

        cnt1 = palCount(a);
        cnt2 = palCount(b);
//        cout << cnt1 << ' ' << cnt2 << endl;
//        cout << cnt2 - cnt1 << endl;
        string tmp = a;
        reverse(tmp.begin(), tmp.end());
        if(tmp == a) cnt1--;
        printf("Case %d: %lld\n", t, cnt2-cnt1);
    }

    return 0;
}

