from queue import Queue

n = int(input())
a = [int(i) for i in input().split()]
a.append(1000000)

nxt = []
for i in range(n):
    nxt.append(i+1)

pre = [0]
for i in range(1, n+1):
    pre.append(i-1)

# print("BUG")

ans = 0
q = Queue()
q.put(-1);
i = n-1
while i > 0:
    if a[i] < a[i-1]:
        q.put(i)
    i -= 1

while not q.empty():
    cur = q.get()

    # print(cur, pre[cur], nxt[cur])
    # input()

    if cur == -1:
        if(q.empty()):
            break
        q.put(-1)
        ans += 1
        continue

    nxt[ pre[cur] ] = nxt[cur]
    pre[ nxt[cur] ] = pre[cur]
    if(a[ pre[cur] ] > a[ nxt[cur] ]):
        q.put(nxt[cur])

print(ans)
