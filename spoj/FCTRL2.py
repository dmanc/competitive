T = int(input())
for i in range(T):
    N = int(input())
    ans = 1
    for i in range(1, N+1):
        ans *= i
    print(ans)

