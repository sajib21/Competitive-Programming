const int maxN = 3e8+5;
const int maxL = 5e5;
const int maxS = maxL/10;

bool isP[maxS+5];
bool large[maxL+5];
int prmCnt = 0;
vector<int>pr;

void smallSieve()
{
    for(int i=0; i<=maxS; i++) isP[i] = 1;

    for(int i=2; i<=maxS; i++)
    {
        if(isP[i])
        {
            pr.push_back(i);
            for(int j=i+i; j<=maxS; j+=i) isP[j] = 0;
        }
    }
    prmCnt = pr.size();
}

void segSieve(int l,int r)
{
    if(l>=r) return;
    for(int i=0; i<=maxL; i++) large[i] = 1;

    for(int i=0; i<prmCnt; i++)
    {
        int p = pr[i];
        for(int j=(l+p-1)/p * p; j<r; j+=p)
        {
            large[j-l] = 0;
        }
    }

}
