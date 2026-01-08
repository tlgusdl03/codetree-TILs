
n, k = map(int, input().split())
nums = [0] + list(map(int, input().split()))


inf = int(1e9)
dp = [[-inf for _ in range(k + 1)] for _ in range(n + 1)]

dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(k + 1):
        if nums[i] >= 0:
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i], nums[i])
        else:
            if j - 1 >= 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[i], nums[i])
            
ans = 0
for row in dp:
    ans = max(ans, max(row))

print(ans)