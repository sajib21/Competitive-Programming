int n,k, ara[LIM+10];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &ara[i]);
    scanf("%d", &k);

    deque<int>dq;

    for(int i=0; i<k-1; i++) {
        while(!dq.empty() && ara[dq.back()] < ara[i]) dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k-1; i<n; i++) {
        while(!dq.empty() && ara[dq.back()] < ara[i]) dq.pop_back();
        dq.push_back(i);
        if(i > k-1) printf(" ");
        printf("%d", ara[dq.front()]);
        while(!dq.empty() && dq.front() <= i-k+1) dq.pop_front();
    }
    printf("\n");

    return 0;
}
