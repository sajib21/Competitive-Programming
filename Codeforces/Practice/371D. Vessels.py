n = int(input())
a = [int(i) for i in input().split()] + []*(200000)
nxt = [int(i+1) for i in range(n)] + []*(200000)
val = [0]*(n+200000)

def f(cur, v):
    if cur >= n: return n
    cap = a[cur] - val[cur]
    if(cap > v):
        val[cur] += v
        return cur
    else:
        val[cur] += cap
        nxt[cur] = f(nxt[cur], v-cap)
        return nxt[cur]


q = int(input())
while q > 0:
    q = q-1
    c = [int(i) for i in input().split()]
    if c[0] == 1:
        # print(c[1], c[2])
        f(c[1]-1, c[2])
    else:
        # x = int(input())
        print(val[ c[1]-1 ])

    # print(val)