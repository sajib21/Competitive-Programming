int n, h[LIM+10];

int histogram(int n, int h[]) { ///ASSUMES N = SIZE, H = ARA (0 BASED)
    stack<int>stk;
    int i = 0, ans=0;
    while(i < n) {
        if(stk.empty() || h[stk.top()] <= h[i]) stk.push(i++);
        else {
            int tp = stk.top();
            stk.pop();
            ans = max(ans, h[tp] * (stk.empty()? i : i-stk.top()-1));
        }
    }
    while(!stk.empty()) {
        int tp = stk.top();
        stk.pop();
        ans = max(ans, h[tp] * (stk.empty()? i : i-stk.top()-1));
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &h[i]);
        printf("Case %d: %d\n", t, histogram(n, h));
    }
    return 0;
}
