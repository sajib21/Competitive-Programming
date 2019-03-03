int n;
int preference[2*LIM+10][2*LIM+10];
int canPrefList[LIM+10][LIM+10], comPrefList[2*LIM+10][LIM+10];
int canPrefListPtr[LIM+10], comEngageList[2*LIM+10] ;
stack<int>freeCan;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(preference, 0, sizeof(preference));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &canPrefList[i][j]);
                preference[i][ canPrefList[i][j] ] = j;
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &comPrefList[i][j]);
                preference[n+i][ comPrefList[i][j] ] = j;
            }
        }
        memset(comEngageList, 0, sizeof(comEngageList));
        for(int i=1; i<=n; i++) canPrefListPtr[i] = 1;
        for(int i=1; i<=n; i++) freeCan.push(i);
        while(!freeCan.empty()) {

            int can = freeCan.top();
            freeCan.pop();
            bool single = true;

            while(single) {
                int p = canPrefListPtr[can];
                int com = canPrefList[can][p];
                if(!comEngageList[com]) {
                    comEngageList[com] = can;
                    single = false;
                }
                else {
                    int pre = comEngageList[com];
                    if(preference[com][can] < preference[com][pre]) {
                        freeCan.push(pre);
                        comEngageList[com] = can;
                        single = false;
                    }
                }
                canPrefListPtr[can]++;
            }
        }
        printf("Case %d:", t);
        for(int i=n+1; i<=2*n; i++) printf(" (%d %d)", comEngageList[i], i);
        printf("\n");
    }
    return 0;
}
