#include<bits/stdc++.h>

using namespace std;

int m;
bool weight[12];

bool dp[12][12][1010];
vector<int>q;

void printSol() {

    printf("YES\n%d", q[0]);
    int sz = q.size();
    for(int i=1; i<sz; i++) printf(" %d", q[i]);
    printf("\n");
}

bool isPossible(int lastTaken, int weightToCover, int left) {

    if(!left) {
        printSol();
        return true;
    }

    if(dp[lastTaken][weightToCover][left]) return false;

    bool temp = false;
    for(int i=weightToCover+1; i<=10; i++) {
        if(weight[i] == 1 && i != lastTaken) {
            q.push_back(i);
            temp = temp | isPossible(i, i-weightToCover, left-1);
            if(temp) return true;
            else {
                q.pop_back();
            }
        }
    }

    dp[lastTaken][weightToCover][left] = true;
    return false;
}


int main() {

    char t;
    for(int i=1; i<=10; i++) {
        scanf("%c", &t);
        weight[i] = t - '0';
    }
    scanf("%d", &m);

    if(!isPossible(0, 0, m)) {
        printf("NO\n");
    }
}
