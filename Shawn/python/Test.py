import random
c = 0
t = 10 ** 8

for i in range(t):
    if(i % (10 ** 7) == 0):
        print(i)
    a = random.uniform(-1, 1)
    b = random.uniform(-1, 1)
    d = a ** 2 + b ** 2
    if d <= 1:
        c = c + 1
s = c / t * 4
print(s)
