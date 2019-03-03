#include<bits/stdc++.h>

using namespace std;

map<int,int>frontColorCnt, backColorCnt;
vector<int> frontColor, backColor;

int main() {

    int n;

    scanf("%d", &n);
    int l = (n+1)/2;

    int f,b;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &f,&b);

//        if(f == b) {
//            sameColorCnt[f]++;
//            sameColor.push_back(f);
//        }
//        else {
            frontColorCnt[f]++;
            if(f != b) backColorCnt[b]++;
            frontColor.push_back(f); ///EKHONO SAME COLOR HOLE KI HOBE OI CASE THIK KORA HOY NAI!!!
            backColor.push_back(b);
//        }

    }

    int ans = INT_MAX;

    int sz = frontColor.size();
    for(int i=0; i<sz; i++) {
        int nowFront = frontColor[i];
        if(frontColorCnt[nowFront] >= l) {
            printf("0\n");
            return 0;
        }
        else {
            if(frontColorCnt[nowFront] + backColorCnt[nowFront]>= l) {
                ans = min(ans, l-frontColorCnt[nowFront]);
            }
        }
    }

    sz = backColor.size();
    for(int i=0; i<sz; i++) {
        int nowColor = backColor[i];
        if(backColorCnt[nowColor] >= l) {
            if(l <= ans) {
                ans = l;
                break;
            }
        }
    }

//    sz = sameColor.size();
//    for(int i=0; i<sz; i++) {
//        int nowFront = sameColor[i];
//        if(frontColorCnt[nowFront] + sameColorCnt[nowFront] >= l) {
//            printf("0\n");
//            return 0;
//        }
//        else {
//            if(frontColorCnt[nowFront] + backColorCnt[nowFront] + sameColorCnt[nowFront] >= l) {
//                ans = min(ans, l-frontColorCnt[nowFront]-sameColorCnt[nowFront]);
//            }
//        }
//    }

    if(ans != INT_MAX) printf("%d\n", ans);
    else printf("-1\n");

    return 0;

}
