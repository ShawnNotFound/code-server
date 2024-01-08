n = 0
ans = 0

n = eval(input())

for i in range(n):
    tmp = 1
    for j in range(i + 1):
        tmp = tmp * (j + 1)
    ans = ans + tmp

print(ans)