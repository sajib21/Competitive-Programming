n,k = map(int, input().split())
a = [int (i) for i in input().split()]

dp = [ []*n ]*n
for i in range(n):
    for j in range(n):
        dp[i][j] = -1

print(dp[0][0], dp[1][1])
